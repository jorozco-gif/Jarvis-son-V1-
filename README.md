# Jarvis-son V1

Asistente de voz local, por turnos, para teléfonos Android de gama baja. Es un proyecto académico de la asignatura Inteligencia Artificial de COTECNOVA (docente: Ing. Felipe Gutiérrez Isaza · Cartago, Valle del Cauca · 2026).

## Propósito y alcance

Jarvis-son V1 escucha una frase, la transcribe, genera una respuesta breve y la lee en voz alta, todo en el teléfono y sin conexión una vez descargados los modelos.

| Bloque | Recibe | Entrega | Herramienta |
|---|---|---|---|
| Captura | Voz del usuario | WAV PCM s16le, mono, 16 kHz | Termux:API + FFmpeg |
| STT | Audio WAV | Transcripción en español | whisper.cpp · modelo tiny multilingüe |
| SLM | Transcripción + instrucciones | Respuesta breve en texto | llama.cpp · Qwen3.5-0.8B Q4_0 (GGUF) |
| TTS | Respuesta escrita | Audio de voz sintetizada | sherpa-onnx · voz Piper `es_MX-claude-high` |

Un orquestador en C++ ejecuta las etapas una después de otra (STT → SLM → TTS) y termina cada proceso antes de iniciar el siguiente. Los estados son Listo → Grabando → Transcribiendo → Generando → Hablando → Listo/Error.

**Fuera de alcance en la V1:**

- Palabra de activación y escucha continua.
- Interrumpir la voz mientras habla (barge-in).
- Acciones sensibles del sistema: la V1 solo conversa.
- Igualar la fluidez de un asistente en la nube.

## Requisitos

- Android 13 o superior (API 33) con arquitectura ARM64.
- Termux y Termux:API instalados desde una fuente oficial y emparejados.
- Compilador C++, CMake, Git y FFmpeg dentro de Termux.
- whisper.cpp, llama.cpp y sherpa-onnx compilados en el teléfono, en las revisiones registradas en [`models/manifest.json`](models/manifest.json).

### Equipo de prueba documentado

Las pruebas se hicieron en un Xiaomi Redmi Note 14 5G con Android 16, aarch64 y SoC MediaTek Dimensity 7025 Ultra. El teléfono reporta 7,85 GB de RAM total, con entre 2,5 y 3 GB disponibles. Los detalles están en [`docs/inventario-dispositivo.md`](docs/inventario-dispositivo.md).

Este teléfono tiene más RAM que el objetivo de 3 GB del proyecto, así que los resultados no se deben extrapolar a todos los teléfonos de 3 GB.

## Organización de carpetas en el teléfono

Los pesos, los audios temporales y los registros quedan fuera del repositorio:

```text
~/  (carpeta personal de Termux)
├── jarvis-son/        ← este repositorio
├── jarvis-modelos/    ← modelo Whisper, GGUF de Qwen y voz Piper (fuera de Git)
├── jarvis-tmp/        ← temporales del turno (se borran siempre)
├── jarvis-logs/       ← tiempos por etapa, sin texto de conversaciones
├── whisper.cpp/
├── llama.cpp/
└── sherpa-onnx/
```

## Instalación

La secuencia exacta de comandos de las etapas 1 a 5 está pendiente: la entregará el Estudiante 1 en `docs/instalacion.md`. Mientras tanto, las rutas, revisiones, URL de descarga y huellas SHA-256 de cada componente están en [`models/manifest.json`](models/manifest.json).

## Compilación y ejecución

Desde `~/jarvis-son`, porque las rutas del código son relativas a esa carpeta:

```bash
cmake -B build
cmake --build build
./build/jarvis-son
```

El proyecto genera cuatro ejecutables:

| Ejecutable | Para qué sirve |
|---|---|
| `prueba-compilador` | Comprueba que el compilador C++ funciona (Etapa 1) |
| `jarvis-wav` | Valida el formato y la duración del WAV (Etapa 2) |
| `jarvis-medir` | Mide tiempo, código de salida y memoria pico de un comando (Etapas 3 y 4) |
| `jarvis-son` | Orquestador por turnos (Etapa 6) |

La configuración de los comandos y los límites está en [`include/config.hpp`](include/config.hpp).

## Modelos

Los pesos no se suben a Git. GitHub admite 25 MiB por archivo desde el navegador y 100 MiB desde la línea de comandos, y el GGUF de Qwen pesa 563 MB.

El manifiesto [`models/manifest.json`](models/manifest.json) registra, para cada modelo, el nombre, el origen, la revisión del motor, la URL de descarga y el SHA-256. Las licencias y los tamaños todavía están pendientes de documentar.

## Estado y evaluaciones

| Documento | Contenido |
|---|---|
| [`docs/contrato-audio.md`](docs/contrato-audio.md), [`docs/contrato-stt.md`](docs/contrato-stt.md), [`docs/contrato-slm.md`](docs/contrato-slm.md), [`docs/contrato-tts.md`](docs/contrato-tts.md) | Contratos entre etapas |
| [`docs/evaluacion-stt.md`](docs/evaluacion-stt.md) | Evaluación de 20 frases, con comparación entre tiny y base |
| [`docs/evaluacion-slm.md`](docs/evaluacion-slm.md) | 10 preguntas con latencia, tokens/s y memoria pico |
| [`docs/evaluacion-tts.md`](docs/evaluacion-tts.md) | Síntesis de voz sin conexión |
| [`docs/evaluacion-integracion.md`](docs/evaluacion-integracion.md) | 10 turnos de voz a voz sin internet |
| [`docs/mediciones/tiempos-integracion.csv`](docs/mediciones/tiempos-integracion.csv) | Tiempos, códigos de salida y memoria por etapa |
| [`docs/decisiones.md`](docs/decisiones.md) | Decisiones del equipo |

### Limitaciones conocidas

- Los 10 turnos de integración se hicieron en sesiones separadas. La prueba de 10 turnos consecutivos en una sola sesión, en modo avión, está pendiente.
- 9 de 10 turnos de integración necesitaron corregir a mano la transcripción.
- La calidad de las respuestas del modelo de lenguaje no está aprobada: varias respuestas son incorrectas o imprecisas.
- Las licencias del runtime, los modelos y la voz están pendientes de verificar.
- Faltan el cálculo de p50 y p95 por etapa, la CI y la release V1.

El registro completo de limitaciones y fallos, incluidos los cierres por memoria (OOM), lo entregará el Estudiante 1 en `docs/limitaciones.md`.

## Privacidad

- No se publican grabaciones, transcripciones privadas, tokens ni identificadores del teléfono.
- Solo se graba con consentimiento.
- Los audios temporales se borran al terminar cada turno, incluso si falla.
- El registro de tiempos guarda solo tiempos, códigos de salida y memoria, sin el texto de las conversaciones.

## Cómo contribuir

1. Abre o toma una issue con objetivo, criterios de aceptación y responsable.
2. Trabaja en una rama breve, por ejemplo `feat/stt`.
3. Haz commits pequeños con mensajes claros.
4. Abre un pull request con la plantilla del repositorio: descripción, pasos de prueba, evidencia y limitaciones.
5. Otra persona del equipo revisa el PR antes de integrarlo.

Antes de cada commit, confirma que no incluye pesos (`.gguf`, `.bin`, `.onnx`), audio (`.wav`), tokens ni datos del teléfono.

Las tareas de cada etapa están en las issues [#1](https://github.com/jorozco-gif/Jarvis-son-V1-/issues/1) a [#8](https://github.com/jorozco-gif/Jarvis-son-V1-/issues/8).
El avance de todas las tareas se sigue en el tablero [Jarvis-son V1](https://github.com/users/santiagoarias-beep/projects/1), con las columnas Pendiente, Listo, En curso, Revisión y Hecho.

## Equipo

| Rol | Responsabilidad |
|---|---|
| Estudiante 1 · Ingeniería y Código (Juan Sebastián Orozco Rios) | Teléfono, programación, integración técnica y ejecución de todas las pruebas |
| Estudiante 2 · Gestión y Evaluación (Santiago Ospina Arias) | Repositorio, métricas, documentación de las grabaciones de prueba y manifiesto. No programa ni usa el aplicativo. |


