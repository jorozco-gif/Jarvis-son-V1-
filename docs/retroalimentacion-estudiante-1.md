# Jarvis-son V1 · Retroalimentación del Estudiante 1 (Ingeniería y Código)

COTECNOVA · Inteligencia Artificial · Docente: Ing. Felipe Gutiérrez Isaza · Cartago, Valle del Cauca · 2026

Esta revisión se hizo directamente sobre el repositorio [jorozco-gif/Jarvis-son-V1-](https://github.com/jorozco-gif/Jarvis-son-V1-), en el commit `4cbbbd2` del 15 de noviembre de 2026. Los criterios provienen de la «Guía técnica del Estudiante 1», del «Plan de desarrollo» (en adelante, **Plan**) y de la «Guía explicativa y glosario técnico» (en adelante, **Guía**). No se modificó nada en el repositorio.

---

## 1. Ajustes a la descripción de la captura

La captura del navegador traducía algunos nombres. El estado real es el siguiente:

| Lo que muestra la captura | Lo que hay en el repositorio |
|---|---|
| Carpetas «documentos, incluir, modelos, src, pruebas» | `docs/`, `include/`, `models/`, `src/` y `tests/`. Los nombres están en inglés, como pide el Plan (p. 5), y la traducción la hizo el navegador. |
| «LÉAME.md» con el mensaje «inventario iniciar el dispositivo» | `README.md` solo contiene el título `# Jarvis-son-V1-`. La frase que ves al lado es el mensaje del último commit que modificó el archivo, no su contenido. |
| 4 commits | Hay 4 commits, todos directamente en `main`. No hay ramas, pull requests, issues, releases ni flujos de CI. |
| Último commit «Registra modelos con revisión y huellas verificadas» | El título exacto es «Registra modelos con revisiones y huellas verificadas». |

---

## 2. Hitos logrados según la estructura y el contenido

### Comparación con la estructura inicial del Plan (p. 5)

| Ruta que pide el Plan | Estado |
|---|---|
| `src/` · `include/` (orquestador, interfaces, configuración) | **Presente:** `main.cpp`, `proceso`, `wav`, `config.hpp`, `espera.hpp`, `salida_slm.hpp` y las dos utilidades. |
| `models/manifest.json` (nombre, origen, licencia, checksum; no los pesos) | **Presente**, sin pesos. Faltan la licencia y el tamaño (ver sección 3). |
| `docs/` · `tests/` (diagrama, decisiones, pruebas reproducibles) | **Parcial:** hay contratos, evaluaciones, inventario y mediciones. Faltan el diagrama de estados y el registro de decisiones. |
| `scripts/` (instalación, descarga verificada, utilidades) | **No existe.** |
| `.github/workflows/` (CI de compilación y formato) | **No existe.** |

### Avance por etapa

| Etapa | Evidencia que exige el Plan | Qué hay en el repositorio | Estado |
|---|---|---|---|
| 0 · Organizar | Repositorio con README, tablero e inventario del teléfono | [`docs/inventario-dispositivo.md`](https://github.com/jorozco-gif/Jarvis-son-V1-/blob/main/docs/inventario-dispositivo.md) completo y sin identificadores. El README solo tiene el título y no hay tablero. | Inventario logrado; README y tablero pendientes (el tablero le corresponde al Estudiante 2). |
| 1 · Termux y dispositivo | Guía paso a paso y evidencia de que el compilador y el micrófono funcionan | `CMakeLists.txt` y `tests/prueba_compilador.cpp`. El micrófono funciona, como lo demuestra la prueba de audio de la Etapa 2. | **Parcial:** falta la guía paso a paso con los comandos de instalación. |
| 2 · Audio | Comando reproducible y un clip sin datos personales | [`docs/contrato-audio.md`](https://github.com/jorozco-gif/Jarvis-son-V1-/blob/main/docs/contrato-audio.md) recoge la salida de `jarvis-wav` (PCM s16le, mono, 16 kHz, 8,192 s) y deja constancia de que el audio se borró. | **Logrado** técnicamente. Los comandos de grabación y conversión solo están en `include/config.hpp`, no en la documentación. |
| 3 · STT | 20 frases; meta: al menos 18 utilizables en silencio | [`docs/evaluacion-stt.md`](https://github.com/jorozco-gif/Jarvis-son-V1-/blob/main/docs/evaluacion-stt.md) tiene 20 frases con referencia, tiempo, memoria pico y RTF, y una comparación entre tiny y base. | **Parcial:** el resultado de 18/20 mezcla condiciones (ver 2.1). |
| 4 · SLM | Prueba repetible con 10 preguntas cortas, latencia por turno y memoria máxima | [`docs/evaluacion-slm.md`](https://github.com/jorozco-gif/Jarvis-son-V1-/blob/main/docs/evaluacion-slm.md) tiene 10 preguntas con tiempo, tokens/s y memoria pico (entre 1 232 748 y 1 250 588 KB por proceso), además de ajustes exploratorios. | **Logrado** técnicamente. La calidad no está aprobada, y así se declara honestamente. |
| 5 · TTS | Muestra de audio local, identificación exacta de la voz y ficha de licencia y limitaciones | [`docs/evaluacion-tts.md`](https://github.com/jorozco-gif/Jarvis-son-V1-/blob/main/docs/evaluacion-tts.md) con sherpa-onnx y la voz Piper `es_MX-claude-high`. Hay prueba sin conexión y huellas SHA-256. | **Parcial:** falta la ficha de licencia. |
| 6 · Orquestador | Diagrama de estados, compilación reproducible y un turno de voz a voz | `src/main.cpp` define los estados Listo, Grabando, Transcribiendo, Generando, Hablando y Error. El CSV registra turnos completos de voz a voz. | **Parcial:** falta el diagrama de estados. |
| 7 · Integración | Release V1 y reporte reproducible | [`docs/evaluacion-integracion.md`](https://github.com/jorozco-gif/Jarvis-son-V1-/blob/main/docs/evaluacion-integracion.md) (10 turnos sin internet), el manifiesto con huellas y [`docs/mediciones/tiempos-integracion.csv`](https://github.com/jorozco-gif/Jarvis-son-V1-/blob/main/docs/mediciones/tiempos-integracion.csv). | **En curso** (ver 2.2). |

Lo más valioso del trabajo es lo siguiente:

- Cuatro de los cinco contratos de la Guía §10 están escritos: audio, STT, SLM y TTS. Falta el de integración.
- Las rutas de los modelos están fuera del repositorio (`../jarvis-modelos`).
- Los fallos de calidad del SLM se documentan sin maquillarlos, lo que suma en el criterio «Evaluación y honestidad», que vale el 20 % de la rúbrica.

Como comprobación adicional, el proyecto se compiló en un equipo Linux con g++ y el mismo `CMakeLists.txt`. Los cuatro ejecutables compilaron. Solo apareció una advertencia: la función `quitarEco` de `main.cpp` está definida pero no se usa. Esta prueba no reemplaza la compilación en el teléfono, pero indica que la CI es viable.

### 2.1 Observaciones de honestidad en la evaluación STT

- **Composición del conjunto:** el criterio del Plan es «≥18/20 frases silenciosas transcritas de forma utilizable; reportar también resultados con ruido». El conjunto actual tiene 5 frases en silencio a velocidad normal, 5 con habla rápida (también en silencio), 5 con ruido y 5 con acentos. El 18/20 mezcla las cuatro condiciones que la Guía §3 pide separar, de modo que la meta de 20 frases en silencio todavía no está medida.
- **Documentos que se contradicen:** `docs/contrato-stt.md` dice «Conjunto principal mixto: 10/20 transcripciones utilizables», mientras que `docs/evaluacion-stt.md` concluye 18 de 20.
- **Veredictos dudosos:**
  - La frase 4 se marca como utilizable con la transcripción «¿para que se rebuen con compilador?».
  - La frase 10 se marca como utilizable aunque la propia nota dice que «altera elementos principales».
  - La frase 17 dice «no utilizable con errores; conserva la comparación».
  - El criterio de «utilizable» se debe definir antes de evaluar y aplicarse igual a todas las frases.
- **Corrección manual:** 9 de 10 turnos de integración necesitaron corregir la transcripción a mano. Ese dato sugiere que el criterio usado en la evaluación STT fue generoso.

El recálculo con un criterio declarado le corresponde al Estudiante 2 (métricas). El Estudiante 1 aporta los datos.

### 2.2 Por qué la Etapa 7 sigue en curso

- **Turnos en una misma sesión:** el CSV tiene 17 sesiones y la que más turnos tiene cuenta solo 2. Los 10 turnos de `evaluacion-integracion.md` se hicieron «en sesiones separadas». El criterio del Plan es «10 turnos consecutivos completos sin OOM ni pérdida del estado», así que falta una sesión con 10 turnos seguidos.
- **Modo avión:** los documentos dicen «sin internet». El Plan exige que la prueba use modo avión y que se compruebe que no aparecen llamadas a red. Hay que dejarlo escrito de forma explícita.
- **Pendientes de la release:** aún faltan p50/p95 por etapa, la CI, las licencias y la release V1.

---

## 3. Advertencia sobre la carpeta `models/`

**Estado verificado:** `models/` solo contiene `manifest.json`, de 4975 bytes. En todo el historial, el archivo más grande es `src/main.cpp`, con 14 144 bytes, así que nunca se subió un peso. Los modelos están en `../jarvis-modelos`, fuera del repositorio.

### Por qué ahí solo debe estar el manifiesto

1. **Límites de GitHub:** 25 MiB por archivo desde el navegador, hasta 100 MiB desde la línea de comandos y Git LFS por encima de 100 MiB (Guía §8). El GGUF de Qwen Q4_0 pesa 563 MB (Plan p. 3), por lo que GitHub rechazaría el envío por su tamaño. La regla del Plan aplica a todos los pesos, incluidos los que pesan menos de 100 MiB: «enlazar descarga, no versionar pesos en Git» (Plan p. 11).
2. **Licencias y redistribución:** el repositorio es público, y subir un peso equivale a redistribuirlo. En el manifiesto, la licencia de los tres modelos figura como `pendiente_de_verificacion`. El Plan pide revisar la licencia de cada modelo, voz y runtime antes de redistribuir (p. 11; Guía §11).
3. **Reproducibilidad:** el manifiesto registra la URL de origen y el SHA-256. Con eso, cualquiera puede descargar el mismo archivo y comprobar que no cambió (Guía, glosario «SHA-256»). Esa es la forma que pide la Guía §8: «Publicar enlace y manifiesto, no los pesos».
4. **Historial:** un archivo que entra en un commit queda en el historial de Git aunque luego se borre. Evitar que entre es mucho más fácil que sacarlo después.

### Recomendación preventiva [DECISIÓN DEL EQUIPO]

El `.gitignore` actual solo excluye `/build/`. Como segunda barrera, conviene agregar las extensiones de pesos y audio del proyecto (`.gguf`, `.bin`, `.onnx`, `.wav`) y la carpeta `espeak-ng-data/`. Así, aunque alguien copie por error un modelo dentro del repositorio, Git no lo propondrá para el commit.

---

## 4. Documentación y reporte que le faltan al Estudiante 1

Lo que sigue es documentación y reporte, no código nuevo. Corresponde a los puntos 7.6 y 7.7 de la Guía técnica del Estudiante 1 y a la evidencia de la Etapa 7 del Plan: «Release V1 y reporte reproducible de rendimiento, calidad y problemas», con «guía de instalación, manifiesto y limitaciones conocidas».

### 4.1 Secuencia exacta de comandos de instalación (Etapas 1 a 5)

Es el entregable 7.6. La release debe documentar la instalación (Plan, criterios de aceptación) y la Etapa 1 exige una «guía paso a paso».

**Contenido:** los comandos reales, en el orden en que se ejecutaron en el teléfono.

| Etapa | Qué debe quedar escrito |
|---|---|
| 1 | El origen oficial de Termux y Termux:API, el emparejamiento entre ambos, la actualización de paquetes, la instalación del compilador C++, CMake, Git y FFmpeg, y la prueba del permiso de micrófono. |
| 2 | El comando de grabación con Termux:API, el comando de conversión con FFmpeg a WAV mono de 16 kHz y la validación con `jarvis-wav`. |
| 3 | La obtención de whisper.cpp en la revisión `5922450…`, su compilación, la descarga de `ggml-tiny.bin` desde la fuente oficial y la comprobación del SHA-256. |
| 4 | La obtención de llama.cpp en la revisión `e574a17…`, su compilación, la descarga de `Qwen3.5-0.8B-Q4_0.gguf` y la comprobación del SHA-256. |
| 5 | La obtención de sherpa-onnx en la revisión `1a9d234…`, su compilación (`build-piper`), la descarga del paquete de voz `vits-piper-es_MX-claude-high` y la comprobación de las huellas. |
| 6 | La compilación del orquestador con CMake desde `~/jarvis-son`. |

**Reglas para redactarla:**

- Copia los comandos tal como se ejecutaron. No los reconstruyas de memoria.
- Para cada paso, indica la salida esperada y los errores que aparecieron, junto con su solución. Por ejemplo, el aviso sobre copiar `espeak-ng-data` en Android que registra `evaluacion-tts.md`.
- No incluyas tokens, rutas personales ni identificadores del teléfono.

**Ubicación [DECISIÓN DEL EQUIPO]:** `docs/instalacion.md`. El README y la release la enlazarán.

### 4.2 Registro de limitaciones y fallos, incluidos los cierres por memoria (OOM)

Es el entregable 7.7: «Registrar el cierre; no ocultarlo» (Guía §7). En el criterio de honestidad, la rúbrica valora que se reporten «calidad, latencia, RAM y fallos».

**Formato de cada entrada:** fecha, sesión, etapa, código de salida, memoria pico, qué pasó, causa (si se conoce) y mitigación aplicada. Para la mitigación, usa las del Plan (p. 11): procesos secuenciales, contexto y salida cortos y medición en el teléfono real.

**Datos que ya existen y deben quedar registrados:**

| Hecho | Origen |
|---|---|
| No se ha observado ningún código 137 (posible OOM) en las 125 filas del CSV. Aun así, la falta de OOM todavía no se ha demostrado para el criterio, porque no se han hecho 10 turnos consecutivos en una misma sesión. | `tiempos-integracion.csv` |
| Hay 4 fallos del SLM con código −1 (fallo del orquestador) en las sesiones `1794775351` y `1794775570`. | CSV |
| Hay 2 fallos del TTS con código 255 en la sesión `1794776457`. | CSV |
| Memoria pico por proceso hijo: SLM 1 253 100 KB, TTS 438 536 KB, STT 182 036 KB y conversión 41 488 KB. Es la memoria de cada proceso, no la de todo el sistema. | CSV y `evaluacion-integracion.md` |
| El teléfono reporta 7,85 GB de RAM total, no 3 GB. El riesgo de OOM en un teléfono de 3 GB no está evaluado y los resultados no se deben extrapolar (Plan, Etapa 7). Falta confirmar si es memoria física. | `inventario-dispositivo.md` |
| 9 de 10 turnos necesitaron corrección manual del STT, y la calidad del SLM no está aprobada. | `evaluacion-integracion.md`, `evaluacion-slm.md` |
| Aviso sobre `espeak-ng-data` en Android. | `evaluacion-tts.md` |
| `CMD_TTS_FALLBACK` sigue con un valor `<…>` pendiente, y el fallback está desactivado. | `include/config.hpp` |
| Las licencias del runtime, los modelos y la voz están pendientes. | `models/manifest.json` |

**Ubicación [DECISIÓN DEL EQUIPO]:** `docs/limitaciones.md`. El reporte final y la release lo enlazarán.

### 4.3 Otros pendientes de documentación técnica

1. **Prueba oficial de 10 turnos consecutivos.** Hazla en una sola sesión y en modo avión, con el contador final `completos: 10`. Documenta las condiciones y entrega el CSV de esa sesión al Estudiante 2 para calcular p50/p95. Si aparece un OOM, se registra en el punto 4.2.
2. **Diagrama de estados** (evidencia de la Etapa 6): Listo → Grabando → Transcribiendo → Generando → Hablando → Listo/Error. Debe incluir qué provoca cada transición hacia Error y qué temporales se borran en cada caso.
3. **Contrato de integración** (Guía §10). Es el único de los cinco contratos que falta: errores, tiempos, cancelación y política para los archivos temporales.
4. **Comando reproducible de la Etapa 2.** Pasa los comandos de grabación y conversión de `config.hpp` a `docs/contrato-audio.md`.
5. **Datos para el manifiesto.** Entrega al Estudiante 2 el tamaño en bytes de cada archivo de modelo y de voz. Lo necesita para completar el campo «tamaño» (Guía §11).
6. **Identidad en Git.** Dos commits aparecen con el autor «unknown». Configura tu nombre en Git para que tus aportes se vean en el criterio «GitHub y colaboración», que vale el 15 % de la rúbrica.
7. **Desde ahora, todo cambio por rama y PR**, por ejemplo `feat/...`, con la revisión del Estudiante 2 (Plan p. 5).
8. **Evidencia de ejecución por escrito para el Estudiante 2.** El Estudiante 2 no usa el aplicativo ni el teléfono, solo documenta. Por eso todas las pruebas las ejecutas tú y le entregas los resultados por escrito:
   - El CSV de cada sesión.
   - El registro por frase de las grabaciones, en el formato que él te dé.
   - Las respuestas del SLM con tiempo, tokens/s y memoria.
   - Tu evaluación auditiva de la voz, con la escala del equipo.
   - La lista de la sesión oficial ya completada.
   - La confirmación de que los temporales quedaron borrados.
