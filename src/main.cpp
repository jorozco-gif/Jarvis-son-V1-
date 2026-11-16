// src/main.cpp — Orquestador C++ de Jarvis-son V1.
//
// Máquina de estados por turnos:
//   Listo → Grabando → Transcribiendo → Generando → Hablando → Listo / Error
// Cada etapa termina antes de iniciar la siguiente (STT → SLM → TTS).
// No hay escucha continua ni barge-in: mientras habla el TTS, se pide esperar.
// Los temporales se borran al completar o al fallar; el registro guarda
// tiempos y códigos de salida, nunca el texto de la conversación.
#include <algorithm>
#include <termios.h>
#include <unistd.h>

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "config.hpp"
#include "proceso.hpp"
#include "salida_slm.hpp"
#include "espera.hpp"
#include "wav.hpp"

namespace fs = std::filesystem;

namespace {

enum class Estado { Listo, Grabando, Transcribiendo, Generando, Hablando, Error };

const char* nombreEstado(Estado e) {
    switch (e) {
        case Estado::Listo: return "LISTO";
        case Estado::Grabando: return "GRABANDO";
        case Estado::Transcribiendo: return "TRANSCRIBIENDO (STT)";
        case Estado::Generando: return "GENERANDO (SLM)";
        case Estado::Hablando: return "HABLANDO (TTS)";
        case Estado::Error: return "ERROR";
    }
    return "?";
}

// ---------- Temporales del turno ----------
const std::string TMP_CAPTURA = cfg::DIR_TMP + "/captura_original";
const std::string TMP_ENTRADA = cfg::DIR_TMP + "/entrada.wav";
const std::string TMP_RESPUESTA = cfg::DIR_TMP + "/respuesta.wav";
std::string tmpDiagnostico(const std::string& etapa) { return cfg::DIR_TMP + "/" + etapa + ".err"; }

void limpiarTemporales() {
    std::error_code ec;
    for (const auto& e : fs::directory_iterator(cfg::DIR_TMP, ec)) fs::remove_all(e.path(), ec);
}

// Garantiza la limpieza al salir del turno por cualquier camino (éxito o error).
struct GuardiaLimpieza {
    ~GuardiaLimpieza() { limpiarTemporales(); }
};

// ---------- Texto ----------
// Convierte saltos de línea y caracteres de control en espacios y recorta.
std::string limpiarTexto(const std::string& s) {
    std::string r;
    bool espacio = false;
    for (unsigned char c : s) {
        if (c < 0x20 || c == 0x7F || c == ' ') { espacio = !r.empty(); continue; }
        if (espacio) { r += ' '; espacio = false; }
        r += static_cast<char>(c);
    }
    return r;
}

// Validación antes de pasar texto como argumento: sin guiones iniciales
// (no puede confundirse con una opción) y con longitud acotada sin cortar UTF-8.
std::string sanearArgumento(std::string s) {
    s = limpiarTexto(s);
    const auto inicio = s.find_first_not_of("- ");
    s = (inicio == std::string::npos) ? "" : s.substr(inicio);
    if (s.size() > cfg::TEXTO_MAX_BYTES) {
        std::size_t n = cfg::TEXTO_MAX_BYTES;
        while (n > 0 && (static_cast<unsigned char>(s[n]) & 0xC0) == 0x80) --n;
        s.resize(n);
    }
    return s;
}

// Si la herramienta repite el prompt al inicio de su salida, se quita.
std::string quitarEco(const std::string& salida, const std::string& prompt) {
    if (!prompt.empty() && salida.rfind(prompt, 0) == 0) return limpiarTexto(salida.substr(prompt.size()));
    return salida;
}

std::string pistaDiagnostico(int codigo) {
    if (codigo == 127) return "No se encontró o no se pudo ejecutar el programa: revisa la ruta en include/config.hpp.";
    if (codigo == 128 + 9)
        return "El sistema terminó el proceso (señal 9). Posible cierre por memoria (OOM): regístralo, "
               "no lo ocultes; reduce contexto/salida o cierra otras apps y repite.";
    if (codigo > 128) return "El proceso terminó por una señal del sistema: revisa el diagnóstico.";
    return "Revisa el diagnóstico (stderr) y los argumentos de esta etapa en include/config.hpp.";
}

// Descarta lo que se haya tecleado mientras el TTS hablaba (V1 no admite barge-in).
void descartarEntradaPendiente() {
    if (isatty(STDIN_FILENO)) tcflush(STDIN_FILENO, TCIFLUSH);
}

// ---------- Registro de tiempos (sin texto de la conversación) ----------
class Registro {
public:
    Registro() : sesion_(std::chrono::duration_cast<std::chrono::seconds>(
                             std::chrono::system_clock::now().time_since_epoch()).count()) {
        fs::create_directories(cfg::DIR_LOGS);
        const std::string ruta = cfg::DIR_LOGS + "/tiempos.csv";
        const bool nuevo = !fs::exists(ruta);
        archivo_.open(ruta, std::ios::app);
        if (nuevo) archivo_ << "sesion,turno,etapa,ms,codigo_salida,memoria_pico_kb,audio_s\n";
    }
    void anotar(int turno, const std::string& etapa, long long ms, int codigo, long mem_kb, double audio_s) {
        archivo_ << sesion_ << ',' << turno << ',' << etapa << ',' << ms << ',' << codigo << ','
                 << mem_kb << ',' << audio_s << '\n';
        archivo_.flush();  // si Android cierra el proceso, lo anotado no se pierde
    }

private:
    long long sesion_;
    std::ofstream archivo_;
};

// ---------- Orquestador ----------
class Orquestador {
public:
    int iniciar() {
        std::cout << "Jarvis-son V1 — asistente de voz local por turnos\n";
        while (true) {
            cambiar(Estado::Listo);
            std::cout << "Pulsa Enter para hablar (q + Enter para salir): " << std::flush;
            std::string linea;
            if (!std::getline(std::cin, linea) || linea == "q" || linea == "Q") break;
            ++turno_;
            turno() ? ++completos_ : ++fallidos_;
            std::cout << "Turno " << turno_ << " | completos: " << completos_
                      << " | con error: " << fallidos_ << "\n";
        }
        std::cout << "Fin de la sesión.\n";
        return 0;
    }

private:
    Registro registro_;
    Estado estado_ = Estado::Listo;
    int turno_ = 0, completos_ = 0, fallidos_ = 0;

    void cambiar(Estado e) {
        estado_ = e;
        std::cout << "\n[" << nombreEstado(e) << "]\n";
    }

    // Estado ERROR: muestra etapa, código de salida y siguiente paso de diagnóstico.
    bool fallo(const std::string& etapa, int codigo, const std::string& paso, const std::string& diag = "") {
        cambiar(Estado::Error);
        registro_.anotar(turno_, etapa, 0, codigo, 0, 0);
        std::cout << "Etapa: " << etapa << " | Código de salida: " << codigo << "\n"
                  << "Siguiente paso: " << paso << "\n";
        if (!diag.empty()) {
            std::ifstream f(diag);
            std::string linea, ultimas[8];
            int n = 0;
            while (std::getline(f, linea)) ultimas[n++ % 8] = linea;
            if (n > 0) std::cout << "Últimas líneas del diagnóstico:\n";
            for (int i = (n > 8 ? n - 8 : 0); i < n; ++i) std::cout << "  " << ultimas[i % 8] << "\n";
        }
        return false;
    }

    // Lanza una herramienta local con argumentos permitidos y verifica su código de salida.
    bool correr(const std::string& etapa, const cfg::Argv& plantilla,
                const std::map<std::string, std::string>& valores, bool capturar,
                ResultadoProceso& r, double audio_s = 0) {
        std::string pendiente;
        if (!comandoListo(plantilla, pendiente))
            return fallo(etapa, -1, "Comando no configurado: completa «" + pendiente +
                                        "» en include/config.hpp con la fuente oficial.");
        const auto modelo = valores.find("{MODELO}");
        if (modelo != valores.end() && modelo->second.find('<') != std::string::npos)
            return fallo(etapa, -1, "Ruta de modelo pendiente: «" + modelo->second + "».");
        if (modelo != valores.end() && !fs::exists(modelo->second))
            return fallo(etapa, -1, "No existe el modelo «" + modelo->second + "». Descárgalo fuera de Git.");

        const auto argv = expandir(plantilla, valores);
        if (argv.empty()) return fallo(etapa, -1, "La plantilla usa un marcador sin valor.");

        const std::string diag = tmpDiagnostico(etapa);
        r = ejecutar(argv, diag, capturar);
        if (!r.lanzado) return fallo(etapa, -1, "No se pudo crear el proceso (memoria o límites del sistema).");
        registro_.anotar(turno_, etapa, r.duracion_ms, r.codigo_salida, r.memoria_pico_kb, audio_s);
        if (r.codigo_salida != 0) return fallo(etapa, r.codigo_salida, pistaDiagnostico(r.codigo_salida), diag);
        return true;
    }

    bool turno() {
        GuardiaLimpieza guardia;   // borra temporales al terminar, pase lo que pase
        ResultadoProceso r;
        long long procesamiento_ms = 0;  // convertir + STT + SLM + TTS (sin tiempo del usuario)

        // ---- GRABANDO: clip corto iniciado por el usuario ----
        cambiar(Estado::Grabando);
        std::cout << "Habla ahora (máximo " << cfg::SEGUNDOS_GRABACION << " s)...\n";
        if (!correr("grabar", cfg::CMD_GRABAR,
                    {{"{SALIDA}", TMP_CAPTURA}, {"{SEGUNDOS}", std::to_string(cfg::SEGUNDOS_GRABACION)}},
                    false, r))
            return false;
        if (!esperarFinGrabacion(cfg::SEGUNDOS_GRABACION + 5)) {
            ejecutar({"termux-microphone-record", "-q"},
                     tmpDiagnostico("detener_grabacion"), false);
            return fallo("grabar", -1,
                         "No se pudo confirmar el final de la grabación.");
        }

        if (!fs::exists(TMP_CAPTURA) || fs::file_size(TMP_CAPTURA) == 0)
            return fallo("grabar", -1, "No se creó el audio: revisa el permiso de micrófono de Termux:API.");

        // Normalizar a WAV PCM s16le, mono, 16 kHz
        if (!correr("convertir", cfg::CMD_CONVERTIR, {{"{ENTRADA}", TMP_CAPTURA}, {"{SALIDA}", TMP_ENTRADA}},
                    false, r))
            return false;
        procesamiento_ms += r.duracion_ms;
        fs::remove(TMP_CAPTURA);

        // Validar formato y duración (contrato de audio)
        const InfoWav w = leerWav(TMP_ENTRADA);
        std::string motivo;
        if (!cumpleFormatoStt(w, motivo)) return fallo("validar_wav", -1, "WAV inválido: " + motivo + ".");
        if (w.duracion_s < cfg::DURACION_MIN_S || w.duracion_s > cfg::SEGUNDOS_GRABACION + cfg::TOLERANCIA_S)
            return fallo("validar_wav", -1, "Duración fuera de rango (" + std::to_string(w.duracion_s) + " s).");

        // ---- TRANSCRIBIENDO: Whisper debe producir texto ----
        cambiar(Estado::Transcribiendo);
        if (!correr("stt", cfg::CMD_STT, {{"{MODELO}", cfg::MODELO_STT}, {"{ENTRADA}", TMP_ENTRADA}}, true, r,
                    w.duracion_s))
            return false;
        procesamiento_ms += r.duracion_ms;
        fs::remove(TMP_ENTRADA);  // el audio ya no se necesita
        std::string texto = limpiarTexto(r.salida);
        if (texto.empty()) return fallo("stt", 0, "Transcripción vacía: repite la frase más cerca del micrófono.");

        std::cout << "Transcripción: " << texto << "\n";
        if (cfg::PERMITIR_CORRECCION) {
            std::cout << "Enter para aceptar o escribe la corrección: " << std::flush;
            std::string correccion;
            std::getline(std::cin, correccion);
            correccion = limpiarTexto(correccion);
            if (!correccion.empty()) texto = correccion;
        }
        texto = sanearArgumento(texto);
        if (texto.empty()) return fallo("stt", 0, "El texto quedó vacío tras validarlo.");

        // ---- GENERANDO: respuesta breve y acotada ----
        cambiar(Estado::Generando);
        const std::string prompt = texto;
        if (!correr("slm", cfg::CMD_SLM,
                    {{"{MODELO}", cfg::MODELO_SLM},
                     {"{CONTEXTO}", std::to_string(cfg::CONTEXTO_TOKENS)},
                     {"{MAX_TOKENS}", std::to_string(cfg::SALIDA_MAX_TOKENS)},
                     {"{TEXTO}", prompt}},
                    true, r))
            return false;
        procesamiento_ms += r.duracion_ms;
        std::string respuesta = sanearArgumento(extraerRespuestaSlm(r.salida, prompt));
        respuesta.erase(std::remove(respuesta.begin(), respuesta.end(), '*'), respuesta.end());
        if (respuesta.empty()) return fallo("slm", 0, "Respuesta vacía: revisa el prompt y el límite de tokens.");
        std::cout << "Jarvis-son: " << respuesta << "\n";

        // ---- HABLANDO: generar y reproducir voz; luego liberar temporales ----
        cambiar(Estado::Hablando);
        std::cout << "(Espera a que termine la respuesta: en V1 no se puede interrumpir.)\n";
        if (cfg::USAR_TTS_FALLBACK) {
            if (!correr("tts_fallback", cfg::CMD_TTS_FALLBACK, {{"{TEXTO}", respuesta}}, false, r)) return false;
            procesamiento_ms += r.duracion_ms;  // en el fallback incluye la reproducción
        } else {
            if (!correr("tts", cfg::CMD_TTS,
                        {{"{MODELO}", cfg::MODELO_TTS}, {"{SALIDA}", TMP_RESPUESTA}, {"{TEXTO}", respuesta}},
                        false, r))
                return false;
            procesamiento_ms += r.duracion_ms;  // hasta que el audio está listo
            if (!fs::exists(TMP_RESPUESTA))
                return fallo("tts", -1, "El TTS terminó pero no creó el audio de respuesta.");
            if (!correr("reproducir", cfg::CMD_REPRODUCIR, {{"{ENTRADA}", TMP_RESPUESTA}}, false, r))

                return false;

            if (!esperarFinReproduccion(120)) {
                ejecutar({"termux-media-player", "stop"},
                         tmpDiagnostico("detener_reproduccion"), false);
                return fallo("reproducir", -1,
                             "No se pudo confirmar el final de la reproducción.");
            }

        }
        descartarEntradaPendiente();
        registro_.anotar(turno_, "turno_procesamiento", procesamiento_ms, 0, 0, w.duracion_s);
        return true;
    }
};

}  // namespace

int main() {
    std::error_code ec;
    fs::create_directories(cfg::DIR_TMP, ec);
    if (ec) {
        std::cerr << "No se pudo crear " << cfg::DIR_TMP << ": " << ec.message() << "\n";
        return 1;
    }
    limpiarTemporales();  // restos de una ejecución interrumpida
    Orquestador orquestador;
    return orquestador.iniciar();
}
