#pragma once

#include <map>
#include <string>
#include <vector>

struct ResultadoProceso {
    bool lanzado = false;
    int codigo_salida = -1;
    long long duracion_ms = 0;
    long memoria_pico_kb = 0;
    std::string salida;
};

std::vector<std::string> expandir(
    const std::vector<std::string>& plantilla,
    const std::map<std::string, std::string>& valores);

bool comandoListo(
    const std::vector<std::string>& plantilla,
    std::string& pendiente);

ResultadoProceso ejecutar(
    const std::vector<std::string>& argv,
    const std::string& archivo_diagnostico,
    bool capturar_stdout);
