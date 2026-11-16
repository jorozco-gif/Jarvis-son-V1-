#include <iostream>
#include "proceso.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Uso: jarvis-medir <programa> [argumentos...]\n";
        return 2;
    }

    const std::vector<std::string> args(argv + 1, argv + argc);
    const ResultadoProceso r = ejecutar(args, "", false);

    if (!r.lanzado) {
        std::cerr << "No se pudo crear el proceso\n";
        return 1;
    }

    std::cout << "\n[medicion] ms=" << r.duracion_ms
              << " codigo_salida=" << r.codigo_salida
              << " memoria_pico_kb=" << r.memoria_pico_kb
              << "\n";

    return r.codigo_salida;
}
