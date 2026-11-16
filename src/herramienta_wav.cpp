#include <iostream>
#include "wav.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Uso: jarvis-wav <archivo.wav>\n";
        return 2;
    }

    const InfoWav w = leerWav(argv[1]);
    if (!w.leido) {
        std::cout << "FALLA: " << w.error << "\n";
        return 1;
    }

    std::cout << "formato=" << w.formato
              << " (1=PCM) canales=" << w.canales
              << " frecuencia=" << w.frecuencia
              << " Hz bits=" << w.bits
              << " duracion=" << w.duracion_s << " s\n";

    std::string motivo;
    if (!cumpleFormatoStt(w, motivo)) {
        std::cout << "FALLA: " << motivo << "\n";
        return 1;
    }

    std::cout << "OK: WAV PCM s16le, mono, 16 kHz\n";
    return 0;
}
