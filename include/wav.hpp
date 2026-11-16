#pragma once
#include <string>

struct InfoWav {
    bool leido = false;
    std::string error;
    int formato = 0;
    int canales = 0;
    int frecuencia = 0;
    int bits = 0;
    double duracion_s = 0.0;
};

InfoWav leerWav(const std::string& ruta);

bool cumpleFormatoStt(const InfoWav& w, std::string& motivo);
