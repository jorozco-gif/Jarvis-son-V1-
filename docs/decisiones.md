# Decisiones del equipo · Jarvis-son V1

Aquí se registran los valores que el Plan de desarrollo y la Guía explicativa dejan abiertos. Cada decisión indica de dónde sale. Si una decisión cambia, se agrega una fila nueva con la fecha y el motivo; las anteriores no se borran.

- **Registro inicial:** 15 de noviembre de 2026, sobre el commit `4cbbbd2`.
- **Responsable del registro:** Estudiante 2 · Gestión y Evaluación.

## 1. Decisiones vigentes

Son las que ya están aplicadas en el código o en la documentación del repositorio.

### Organización

| Decisión | Valor | Dónde consta |
|---|---|---|
| Carpetas fuera del repositorio | `../jarvis-modelos` (pesos), `../jarvis-tmp` (temporales) y `../jarvis-logs` (tiempos) | `include/config.hpp`, `models/manifest.json` |
| Carpeta de ejecución | El orquestador se ejecuta desde `~/jarvis-son`, porque las rutas son relativas | `include/config.hpp` |

### Audio

| Decisión | Valor | Dónde consta |
|---|---|---|
| Duración de la grabación | 8 s (el Plan propone de 5 a 8 s) | `include/config.hpp`, `docs/contrato-audio.md` |
| Duración mínima y tolerancia | Mínimo 1 s; tolerancia de 0,5 s sobre el límite | `include/config.hpp` |
| Conversión con FFmpeg | `-ac 1 -ar 16000 -c:a pcm_s16le`: mono, 16 kHz, PCM s16le | `include/config.hpp` |

### STT

| Decisión | Valor | Dónde consta |
|---|---|---|
| Modelo | `ggml-tiny.bin` multilingüe, con idioma español (`-l es`) y sin marcas de tiempo | `include/config.hpp`, `docs/contrato-stt.md` |
| Tiny en lugar de base | Se mantiene tiny. En las muestras comparadas, base no mejoró la utilidad con ruido y usó más tiempo y memoria (3183 ms y 292 288 KB, frente a 1676 ms y 181 308 KB) | `docs/evaluacion-stt.md` |
| Corrección del texto | El usuario puede corregir la transcripción antes de enviarla al SLM | `include/config.hpp` |

### SLM

| Decisión | Valor | Dónde consta |
|---|---|---|
| Modelo y cuantización | Qwen3.5-0.8B Q4_0 (GGUF) | `models/manifest.json` |
| Contexto y salida | 1024 tokens de contexto y 96 de salida máxima | `include/config.hpp`, `docs/contrato-slm.md` |
| Modo de ejecución | Una petición por proceso, pensamiento desactivado e instrucciones en un mensaje de sistema separado de la pregunta | `include/config.hpp`, `docs/evaluacion-slm.md` |
| Longitud del texto | Máximo 600 bytes por texto | `include/config.hpp` |

### TTS y reproducción

| Decisión | Valor | Dónde consta |
|---|---|---|
| Voz | Piper `vits-piper-es_MX-claude-high` con sherpa-onnx, 1 hilo y salida a 22 050 Hz | `docs/contrato-tts.md`, `docs/evaluacion-tts.md` |
| Fallback de Android | Desactivado. El comando de Termux:API sigue pendiente | `include/config.hpp` |
| Reproducción del WAV | `termux-media-player play`. Los documentos del curso no fijan esta herramienta | `include/config.hpp` |

### Versiones y registro

| Decisión | Valor | Dónde consta |
|---|---|---|
| Revisiones de los motores | whisper.cpp `5922450…`, llama.cpp `e574a17…` (build 12407) y sherpa-onnx `1a9d234…` | `models/manifest.json` |
| Registro de tiempos | Columnas `sesion,turno,etapa,ms,codigo_salida,memoria_pico_kb,audio_s`. `turno_procesamiento` suma la conversión, el STT, el SLM y el TTS | `docs/evaluacion-integracion.md` |
| Escala de calidad del SLM | Adecuada, Parcialmente adecuada, Imprecisa e Incorrecta | `docs/evaluacion-integracion.md` |

## 2. Propuestas pendientes de acordar

Estas propuestas vienen de la guía del Estudiante 2. No están aprobadas. Cuando el equipo las acuerde, pasan a la sección 1 con su fecha.

| Tema | Propuesta |
|---|---|
| Criterio de transcripción «utilizable» | Conserva la intención y todas las palabras clave de la pregunta, de modo que no haría falta corregirla antes del SLM |
| Normalización para el WER | Quitar la puntuación y pasar a minúsculas. Decidir si las tildes cuentan y aplicarlo siempre igual |
| WER global | Suma de sustituciones, borrados e inserciones de una condición, dividida entre la suma de las palabras de referencia |
| Método de percentiles | p50 = mediana. p95 = valor en la posición ⌈0,95 × n⌉ de la lista ordenada. Siempre se reporta n |
| Fallos en la latencia | Se calcula solo con las filas que tienen código de salida 0, y los fallos se reportan aparte |
| Conjuntos de frases | A: 20 frases en silencio a velocidad normal. B, C y D: ruido moderado, habla rápida y acentos, con frases del conjunto A |
| Condición de ruido | Misma fuente, mismo volumen y misma distancia en toda la sesión. El porcentaje del control de volumen no se presenta como decibelios |
| Escala auditiva del TTS | De 1 a 5, con una descripción por nivel, para pronunciación, ritmo y naturalidad. La aplica el Estudiante 1 |
| Nombres de documentos | `docs/instalacion.md`, `docs/limitaciones.md` y `docs/reporte-v1.md` |
| Manifiesto | Agregar un campo para la licencia de los runtimes y registrar Whisper base como «evaluado, no usado en V1» |
| `.gitignore` | Agregar las extensiones de pesos y audio (`.gguf`, `.bin`, `.onnx`, `.wav`) y la carpeta `espeak-ng-data/` |
| Flujo de cambios | Ramas breves con PR revisado por la otra persona, y `main` protegida cuando exista la CI |
| Herramienta de formato para la CI | Los documentos del curso no la fijan; el equipo debe elegirla |
| Tag de la release | `v1.0` |
| Nombre del repositorio | El Plan lo llama `jarvis-son`. Cambiarlo es opcional y solo puede hacerlo la cuenta propietaria |
