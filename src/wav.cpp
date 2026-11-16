#include "wav.hpp"

#include <cstdint>
#include <fstream>

namespace {

std::uint32_t leerU32(const unsigned char* b) {
    return b[0] | (b[1] << 8) | (b[2] << 16) |
           (static_cast<std::uint32_t>(b[3]) << 24);
}

std::uint16_t leerU16(const unsigned char* b) {
    return static_cast<std::uint16_t>(b[0] | (b[1] << 8));
}

}

InfoWav leerWav(const std::string& ruta) {
    InfoWav w;
    std::ifstream f(ruta, std::ios::binary);
    if (!f) {
        w.error = "no se pudo abrir el archivo";
        return w;
    }

    unsigned char cab[12];
    if (!f.read(reinterpret_cast<char*>(cab), 12) ||
        std::string(reinterpret_cast<char*>(cab), 4) != "RIFF" ||
        std::string(reinterpret_cast<char*>(cab + 8), 4) != "WAVE") {
        w.error = "no es un contenedor WAV (RIFF/WAVE)";
        return w;
    }

    bool hay_fmt = false;
    unsigned char bloque[8];
    while (f.read(reinterpret_cast<char*>(bloque), 8)) {
        const std::string id(reinterpret_cast<char*>(bloque), 4);
        const std::uint32_t tam = leerU32(bloque + 4);

        if (id == "fmt ") {
            unsigned char fmt[16];
            if (tam < 16 || !f.read(reinterpret_cast<char*>(fmt), 16)) {
                w.error = "bloque fmt incompleto";
                return w;
            }
            w.formato = leerU16(fmt);
            w.canales = leerU16(fmt + 2);
            w.frecuencia = static_cast<int>(leerU32(fmt + 4));
            w.bits = leerU16(fmt + 14);
            hay_fmt = true;
            f.seekg(tam - 16 + (tam & 1), std::ios::cur);
        } else if (id == "data") {
            if (!hay_fmt || w.frecuencia <= 0 ||
                w.canales <= 0 || w.bits <= 0) {
                w.error = "bloque data antes de un fmt válido";
                return w;
            }
            const double bytes_por_segundo =
                static_cast<double>(w.frecuencia) *
                w.canales * (w.bits / 8.0);
            w.duracion_s = tam / bytes_por_segundo;
            w.leido = true;
            return w;
        } else {
            f.seekg(tam + (tam & 1), std::ios::cur);
        }
    }
    w.error = "no se encontró el bloque de datos de audio";
    return w;
}

bool cumpleFormatoStt(const InfoWav& w, std::string& motivo) {
    if (!w.leido) {
        motivo = w.error;
        return false;
    }
    if (w.formato != 1) {
        motivo = "la codificación no es PCM";
        return false;
    }
    if (w.bits != 16) {
        motivo = "no es de 16 bits";
        return false;
    }
    if (w.canales != 1) {
        motivo = "no es mono";
        return false;
    }
    if (w.frecuencia != 16000) {
        motivo = "la frecuencia no es 16.000 Hz";
        return false;
    }
    return true;
}
