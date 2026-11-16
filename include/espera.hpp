#pragma once
#include "proceso.hpp"
#include <chrono>
#include <string>
#include <thread>

inline bool esperarFinGrabacion(int limite_segundos) {
    using namespace std::chrono;
    const auto limite = steady_clock::now() + seconds(limite_segundos);

    while (steady_clock::now() < limite) {
        const auto r = ejecutar(
            {"termux-microphone-record", "-i"}, "", true);
        if (!r.lanzado || r.codigo_salida != 0) return false;

        std::string estado;
        for (char c : r.salida) {
            if (c != ' ' && c != '\n' && c != '\r' && c != '\t')
                estado += c;
        }

        if (estado == "{\"isRecording\":false}") return true;
        if (estado.find("\"isRecording\":true") == std::string::npos)
            return false;

        std::this_thread::sleep_for(milliseconds(250));
    }
    return false;
}

inline bool esperarFinReproduccion(int limite_segundos) {
    using namespace std::chrono;
    const auto limite = steady_clock::now() + seconds(limite_segundos);

    while (steady_clock::now() < limite) {
        const auto r = ejecutar(
            {"termux-media-player", "info"}, "", true);
        if (!r.lanzado || r.codigo_salida != 0) return false;

        if (r.salida.find("No track currently!") != std::string::npos)
            return true;
        if (r.salida.rfind("Status: Playing", 0) != 0)
            return false;

        std::this_thread::sleep_for(milliseconds(250));
    }
    return false;
}
