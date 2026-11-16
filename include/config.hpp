// include/config.hpp — Configuración del orquestador Jarvis-son V1.
//
// Cada comando externo se declara como una lista argv: un elemento = un argumento.
// Nunca se arma una línea de shell con el texto transcrito.
//
// Marcadores (cada uno se reemplaza por UN argumento completo):
//   {ENTRADA} {SALIDA} {MODELO} {TEXTO} {SEGUNDOS} {CONTEXTO} {MAX_TOKENS}
//
// Valores entre < > = PENDIENTES. Los documentos del curso no fijan su sintaxis
// exacta: tómala de la fuente oficial indicada en cada comentario.
// El orquestador se niega a ejecutar una etapa que todavía tenga valores < >.
#pragma once
#include <cstddef>
#include <string>
#include <vector>

namespace cfg {

using Argv = std::vector<std::string>;

// ---------- Carpetas (fuera del repositorio: ni audio ni pesos en Git) ----------
inline const std::string DIR_TMP  = "../jarvis-tmp";   // temporales del turno (se borran)
inline const std::string DIR_LOGS = "../jarvis-logs";  // tiempos por etapa, sin texto

// ---------- Modelos (descargados fuera de Git; datos en models/manifest.json) ----------
// Fuente: «whisper.cpp · uso, formato y memoria». Modelo tiny MULTILINGÜE (sin sufijo .en).
inline const std::string MODELO_STT = "../jarvis-modelos/ggml-tiny.bin";
// Fuente: «Qwen3.5-0.8B GGUF oficial». Archivo Q4_0 (563 MB publicados).
inline const std::string MODELO_SLM = "../jarvis-modelos/Qwen3.5-0.8B-Q4_0.gguf";
// Fuente: «sherpa-onnx · Piper TTS». Voz Piper en español validada en la Etapa 5.
inline const std::string MODELO_TTS = "../jarvis-modelos/vits-piper-es_MX-claude-high/es_MX-claude-high.onnx";

// ---------- Límites del plan ----------
inline constexpr int    SEGUNDOS_GRABACION  = 8;     // Etapa 2: clips de 5–8 s
inline constexpr double DURACION_MIN_S      = 1.0;   // valor del equipo: descarta clips vacíos
inline constexpr double TOLERANCIA_S        = 0.5;   // margen sobre el límite de grabación
inline constexpr int    CONTEXTO_TOKENS     = 1024;  // Etapa 4: iniciar con 1.024 tokens
inline constexpr int    SALIDA_MAX_TOKENS   = 96;    // Etapa 4: rango 64–96 tokens
inline constexpr std::size_t TEXTO_MAX_BYTES = 600;  // valor del equipo: frase corta
inline constexpr bool   PERMITIR_CORRECCION = true;  // Etapa 3: permitir corregir el texto
inline constexpr bool   USAR_TTS_FALLBACK   = false; // true = TTS de Android vía Termux:API (solo demo)

// Instrucción del SLM (Etapa 4): español latino neutro y respuestas cortas.
inline const std::string INSTRUCCION_SLM =
    "Eres Jarvis-son, un asistente de voz. Responde en español latino neutro, "
    "con una respuesta breve de una o dos frases. Pregunta del usuario: ";

// ---------- Comandos ----------

// Captura — Fuente: «Termux:API · micrófono y TTS».
// La ilustración de la Etapa 1 del plan muestra un comando que empieza por "termux-microphone".
// Confirma en la fuente oficial cómo se fija el archivo, el límite de duración
// y cómo se sabe que la grabación terminó.
inline const Argv CMD_GRABAR = {
    "termux-microphone-record",
    "-f", "{SALIDA}",
    "-l", "{SEGUNDOS}"};

// Normalización con FFmpeg: 1 canal (mono), 16.000 Hz, PCM s16le (Guía §2).
inline const Argv CMD_CONVERTIR = {
    "ffmpeg", "-y", "-i", "{ENTRADA}",
    "-ac", "1", "-ar", "16000", "-c:a", "pcm_s16le", "{SALIDA}"};

// STT — Fuente: «whisper.cpp · uso, formato y memoria».
// Debe dejar la transcripción en stdout (contrato STT).
inline const Argv CMD_STT = {
    "../whisper.cpp/build/bin/whisper-cli",
    "-m", "{MODELO}",
    "-f", "{ENTRADA}",
    "-l", "es",
    "-nt", "-np"};

// SLM — Fuente: «llama.cpp · Android/Termux».
// Una sola petición: el proceso genera la respuesta por stdout y termina.
inline const Argv CMD_SLM = {
    "../llama.cpp/build/bin/llama-cli",
    "-m", "{MODELO}",
    "-c", "{CONTEXTO}",
    "-n", "{MAX_TOKENS}",
    "--jinja",
    "--chat-template-kwargs", R"({"enable_thinking":false})",
    "--reasoning-budget", "0",
    "--single-turn",
    "--simple-io",
    "--no-display-prompt",
    "--system-prompt",
    "Eres Jarvis-son, un asistente de voz. Responde en español latino neutro, de forma breve y directa, en una o dos frases.",
    "-p", "{TEXTO}"};

// TTS — Fuente: «sherpa-onnx · Piper TTS». Genera un WAV con la voz elegida.
inline const Argv CMD_TTS = {
    "../sherpa-onnx/build-piper/bin/sherpa-onnx-offline-tts",
    "--vits-model=" + MODELO_TTS,
    "--vits-tokens=../jarvis-modelos/vits-piper-es_MX-claude-high/tokens.txt",
    "--vits-data-dir=../jarvis-modelos/vits-piper-es_MX-claude-high/espeak-ng-data",
    "--output-filename=" + DIR_TMP + "/respuesta.wav",
    "{TEXTO}"};

// Reproducción del WAV generado. Los documentos no fijan la herramienta:
// es el «modo de reproducción» del contrato TTS que define el equipo.
inline const Argv CMD_REPRODUCIR = {"termux-media-player", "play", "{ENTRADA}"};

// Fallback de demostración — Fuente: «Termux:API · micrófono y TTS».
// Usa el motor instalado en Android; puede no funcionar sin red.
inline const Argv CMD_TTS_FALLBACK = {"<comando-TTS-de-Termux:API>", "{TEXTO}"};

}  // namespace cfg
