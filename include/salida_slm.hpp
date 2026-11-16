#pragma once
#include <string>

inline std::string extraerRespuestaSlm(
    const std::string& salida, const std::string& pregunta) {
    const std::string marcador = "> " + pregunta + "\n";
    const auto posicion = salida.find(marcador);
    if (posicion == std::string::npos) return {};

    const auto inicio = posicion + marcador.size();
    const auto fin = salida.find("\n[ Prompt:", inicio);
    if (fin == std::string::npos) return {};

    return salida.substr(inicio, fin - inicio);
}
