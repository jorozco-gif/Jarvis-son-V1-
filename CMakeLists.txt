cmake_minimum_required(VERSION 3.16)
project(jarvis_son VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra)
include_directories(include)

# Etapa 1: prueba del compilador C++
add_executable(prueba-compilador tests/prueba_compilador.cpp)

# Etapa 2: validador del WAV normalizado (formato y duración)
add_executable(jarvis-wav src/herramienta_wav.cpp src/wav.cpp)

# Etapas 3 y 4: medición de un comando (tiempo, código de salida, memoria pico)
add_executable(jarvis-medir src/herramienta_medir.cpp src/proceso.cpp)

# Orquestador principal
add_executable(jarvis-son
    src/main.cpp
    src/proceso.cpp
    src/wav.cpp
)
