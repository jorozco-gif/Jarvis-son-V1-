# Jarvis-son V1 · Guía de tareas del Estudiante 2 (Gestión y Evaluación)

COTECNOVA · Inteligencia Artificial · Docente: Ing. Felipe Gutiérrez Isaza · Cartago, Valle del Cauca · 2026

Esta guía se basa exclusivamente en dos documentos del curso: la «Guía explicativa y glosario técnico» (en adelante, **Guía**) y el «Plan de desarrollo» (en adelante, **Plan**) de Jarvis-son V1. El estado del repositorio corresponde al commit `4cbbbd2` del 15 de noviembre de 2026 de [jorozco-gif/Jarvis-son-V1-](https://github.com/jorozco-gif/Jarvis-son-V1-).

**Actualización del 15 de noviembre de 2026:** ya se publicaron el README inicial (tarea 0.4), las plantillas de issues y PR (tarea 1.1) y `docs/decisiones.md` (tarea 0.5). La tabla de la sección 2 refleja ese avance.

---

## Tu rol en el proyecto

**No programas ni usas el aplicativo: solo documentas.** Te encargas de cuatro frentes:

1. El repositorio de GitHub y la colaboración.
2. Las métricas, que calculas a partir de los datos que te entrega el Estudiante 1.
3. Las grabaciones de prueba: diseñas el corpus, el protocolo y el formato de registro, y documentas los resultados. Las grabaciones las hace el Estudiante 1.
4. La documentación del manifiesto de modelos.

Además, revisas cada pull request del Estudiante 1, porque «una persona distinta de quien implementó revisa el pull request» (Plan p. 5). El Estudiante 1 revisa los tuyos, ya que «ambas revisan los PR de la otra» (Plan p. 4).

Este reparto sustituye al reparto sugerido para dos personas del Plan (p. 4, estudiantes A y B). El Estudiante 1 tiene el teléfono, hace toda la programación e integración y ejecuta todas las pruebas. Tú organizas, documentas y publicas.

### Qué no haces

- No escribes C++, CMake, scripts ni flujos de CI.
- No usas el aplicativo Jarvis-son ni el teléfono. No grabas, no hablas en las pruebas, no escuchas la voz para evaluarla y no ejecutas el orquestador ni ningún comando.
- No repites las pruebas de los PR. Los revisas con la evidencia escrita que adjunta el Estudiante 1.

Cuando una tarea necesite un archivo técnico, como el flujo de CI en `.github/workflows/` o los scripts de `scripts/`, abres la issue, se la asignas al Estudiante 1 y revisas su PR.

### Lo que te entrega el Estudiante 1

Todo dato de ejecución te llega por escrito. Pídelo con una issue cuando lo necesites.

| Dato | Para qué lo usas | Sección |
|---|---|---|
| Registro de tiempos (CSV) de cada sesión | Latencia, p50/p95 y memoria pico | 4 |
| Registro por frase de las grabaciones, en el formato que tú le das | Tasa de utilizables, WER y RTF | 4.5 y 5 |
| Respuestas del SLM por escrito, con tiempo, tokens/s y memoria | Evaluación de calidad de la Etapa 4 | 3 |
| Evaluación auditiva de la voz, hecha con la escala del equipo | Ficha de la voz de la Etapa 5 | 3 |
| Tamaño en bytes de cada archivo de modelo y de voz | Manifiesto | 6 |
| Lista de la sesión oficial ya completada | Reporte V1 | 7 |
| `docs/instalacion.md` y `docs/limitaciones.md` | README, reporte y release | 3 y 7 |
| Confirmación de que los temporales quedaron borrados | Control de privacidad | 5.2 |

### Convenciones

| Marca | Significado |
|---|---|
| **[VERIFICAR]** | Los documentos nombran la herramienta o la función, pero no el procedimiento exacto. Consúltalo en la fuente oficial que citan, indicada entre comillas «…». |
| **[DECISIÓN DEL EQUIPO]** | Valor o criterio que los documentos dejan abierto. La guía propone uno y debe quedar registrado en `docs/decisiones.md`. |
| (Guía §n) / (Plan, Etapa n) | Origen del requisito dentro de los documentos. |

---

## 1. Reglas que rigen todo tu trabajo

1. **No subir pesos.** En Git no entran los archivos GGUF, de Whisper ni de voz. GitHub admite 25 MiB por archivo desde el navegador y 100 MiB desde la línea de comandos, y por encima de 100 MiB exige Git LFS. El GGUF de Qwen pesa 563 MB. Se publican el enlace y el manifiesto, no los pesos (Guía §8; Plan p. 5).
2. **No subir datos privados.** No se publican tokens, grabaciones, transcripciones privadas ni identificadores del teléfono (Plan p. 5 y Etapa 7).
3. **Consentimiento documentado.** Las grabaciones que hace el Estudiante 1 usan frases cortas, consentidas y sin datos sensibles, y los temporales se borran (Guía §3 y §11; Plan, Etapa 3). Tú dejas constancia del consentimiento.
4. **Comparar en las mismas condiciones.** Se usan el mismo teléfono y las mismas frases de prueba (Guía §9).
5. **No extrapolar.** Se publican las métricas del equipo exacto, sin generalizarlas a todos los teléfonos de 3 GB (Plan, Etapa 7). El teléfono de prueba reporta 7,85 GB de RAM total, según `docs/inventario-dispositivo.md`.
6. **Ser honesto.** Que una demo responda una vez no demuestra estabilidad (Guía §9). Los fallos se reportan, y un cierre por memoria se registra, no se oculta (Guía §7). La rúbrica le da a este punto el 20 %.

---

## 2. Estado actual del repositorio

| Elemento que pide el Plan (p. 5) | Estado al 15 de noviembre de 2026 | Responsable |
|---|---|---|
| Repositorio | Existe y es público, con el nombre `Jarvis-son-V1-`. El Plan lo llama `jarvis-son`; cambiar el nombre es opcional y solo lo puede hacer la cuenta propietaria [DECISIÓN DEL EQUIPO]. | Estudiante 2 |
| GitHub Project con 5 columnas | No existe. | Estudiante 2 |
| Una issue por etapa | No hay issues. | Estudiante 2 |
| Ramas breves y PR | Todos los commits están directamente en `main`. | Ambos |
| `main` protegida (revisión y CI) | Sin protección. Configurarla requiere permiso de administrador del repositorio. | Estudiante 2 con la cuenta propietaria |
| Plantillas de Issues y PR | Creadas en `.github/`. | Estudiante 2 |
| `README.md` | Versión inicial publicada. Falta enlazar la instalación y las limitaciones cuando existan. | Estudiante 2 |
| `models/manifest.json` | Existe, sin pesos. Faltan la licencia y el tamaño (sección 6). | Estudiante 2 |
| `.github/workflows/` (CI) | No existe. | Estudiante 1 lo crea y el Estudiante 2 lo revisa |
| `scripts/` | No existe. | Estudiante 1 |
| `docs/` | Hay contratos, evaluaciones, inventario, mediciones y `decisiones.md`. Faltan el reporte, la instalación, las limitaciones y el diagrama. | Ambos |
| Release V1 | No existe. | Estudiante 2 |

---

## 3. Tareas por etapa

Las etapas 0 a 6 ya tienen avance técnico. Tu trabajo en ellas es dejar registro, completar la evidencia y verificar. Cuando registres hoy una etapa que ya se hizo, indícalo así en la issue: «registrada después de completar la etapa». No simules fechas ni un historial que no ocurrió.

### Etapa 0 · Organizar el proyecto

**Objetivo (Plan):** establecer acuerdos de trabajo y registrar el estado inicial del teléfono.

**0.1 Crea el GitHub Project** con las columnas Pendiente, Listo, En curso, Revisión y Hecho (Plan p. 5). Vincúlalo al repositorio [VERIFICAR] en «GitHub · Projects». Significado de las columnas [DECISIÓN DEL EQUIPO]:

| Columna | La tarjeta está aquí cuando… |
|---|---|
| Pendiente | está registrada, pero sin criterios completos. |
| Listo | tiene objetivo, criterios de aceptación y responsable, y puede empezar. |
| En curso | alguien trabaja en su rama. |
| Revisión | hay un PR abierto esperando revisión. |
| Hecho | el PR se integró y la evidencia está en el repositorio. |

**0.2 Abre una issue por etapa** con objetivo, criterios de aceptación y responsable (Plan p. 5). El texto sale del Plan:

| Issue | Objetivo (Plan) | Criterios de aceptación (evidencia del Plan) | Responsable |
|---|---|---|---|
| Etapa 0 · Organizar el proyecto | Establecer acuerdos de trabajo y registrar el estado inicial del teléfono | Repositorio con README, tablero e inventario del teléfono; roles, ramas protegidas e issues iniciales | Estudiante 2, con el inventario del Estudiante 1 |
| Etapa 1 · Preparar Termux y el dispositivo | Dejar el entorno reproducible antes de añadir modelos | Guía paso a paso; evidencia de que el compilador y el micrófono funcionan | Estudiante 1 (revisa el Estudiante 2) |
| Etapa 2 · Capturar y normalizar audio | Crear una entrada de audio uniforme para STT | Comando reproducible; un clip de prueba sin datos personales | Estudiante 1; el protocolo de grabación es del Estudiante 2 |
| Etapa 3 · Reconocimiento de voz (STT) | Convertir la entrada normalizada en texto español que pueda inspeccionarse | 20 frases de evaluación; al menos 18 utilizables en silencio; resultados también con ruido | Estudiante 1 graba y ejecuta; el Estudiante 2 documenta el corpus, el registro de grabaciones y las métricas |
| Etapa 4 · Modelo de lenguaje pequeño (SLM) | Producir una respuesta breve y relevante a partir de la transcripción | 10 preguntas cortas; latencia por turno; memoria máxima; licencia, origen y SHA-256 en el manifiesto | Estudiante 1 ejecuta; el Estudiante 2 redacta las preguntas y documenta la evaluación y el manifiesto |
| Etapa 5 · Síntesis de voz (TTS) | Leer la respuesta del SLM sin depender de una conexión a Internet | Muestra de audio local; identificación exacta de la voz; ficha de licencia y limitaciones | Estudiante 1 en la parte técnica y la evaluación auditiva; el Estudiante 2 redacta la ficha |
| Etapa 6 · Orquestador C++ | Conectar las etapas con estados claros, errores visibles y limpieza de temporales | Diagrama de estados; compilación reproducible; un turno funcional de voz a voz | Estudiante 1 (revisa el Estudiante 2) |
| Etapa 7 · Integración y evaluación | Demostrar un recorrido completo y reportar resultados observables | 10 turnos consecutivos sin OOM; prueba en modo avión; p50 y p95 por etapa; memoria máxima; release V1 y reporte | Estudiante 1 hace la prueba y completa la lista; el Estudiante 2 documenta las métricas, el reporte y la release |

Abre además estas issues de gestión: «Plantillas de Issues y PR», «Protección de main y CI», «Manifiesto: licencias, tamaños y revisiones», «Corpus y protocolo de grabación», «README y manual», «Reporte V1» y «Release V1».

**0.3 Revisa el inventario** (`docs/inventario-dispositivo.md`). Debe tener modelo, versión de Android, arquitectura, RAM y espacio libre (Plan, Etapa 0), y no debe tener IMEI, número de serie ni identificadores. El inventario actual cumple, pero deja pendiente confirmar si los 7,85 GB son RAM física. Pide esa confirmación al Estudiante 1.

**0.4 Escribe el README inicial.** El glosario de la Guía lo define como el documento con «propósito, instalación, ejecución y contribución». Secciones mínimas:

1. Propósito y alcance de la V1: por turnos, sin escucha continua ni interrupciones (Plan p. 2).
2. Requisitos: Android 13+ (API 33), ARM64, Termux y Termux:API, y el teléfono de prueba documentado.
3. Instalación: enlace a `docs/instalacion.md`, que entrega el Estudiante 1.
4. Ejecución.
5. Modelos: enlace a `models/manifest.json` y la advertencia de que los pesos no están en Git.
6. Privacidad: qué no se publica y cómo se borran los temporales.
7. Limitaciones conocidas: enlace a `docs/limitaciones.md`.
8. Contribución: flujo issue → rama → commit → PR → CI → merge (Guía §8).
9. Roles del equipo.

**0.5 Abre `docs/decisiones.md`.** Registra ahí cada [DECISIÓN DEL EQUIPO], con fecha y motivo:

- Rutas fuera del repositorio.
- Grabación de 8 s.
- Contexto de 1024 tokens y salida de 96.
- Uso de tiny en lugar de base.
- Voz `es_MX-claude-high`.
- Criterio de «utilizable», método de percentiles y normalización del WER.

La estructura del Plan pide «decisiones» en `docs/` (Plan p. 5).

**Etapa terminada cuando** el repositorio tiene README, tablero, roles, issues y el inventario revisado (Plan, Etapa 0).

### Etapa 1 · Preparar Termux y el dispositivo

1. **Crea las plantillas de Issues y PR** con descripción, pasos de prueba, evidencia y limitaciones (Plan p. 5). Ubícalas donde GitHub las reconoce, normalmente en la carpeta `.github/` [VERIFICAR] en la documentación de GitHub. Son archivos de texto, no código:

   ```text
   PLANTILLA DE ISSUE
   Etapa: (0–7)
   Objetivo:
   Criterios de aceptación:
   - [ ]
   Responsable:
   Evidencia esperada:
   ```

   ```text
   PLANTILLA DE PULL REQUEST
   Descripción del cambio:
   Issue relacionada: #
   Pasos de prueba (en el teléfono documentado):
   Evidencia (salida, métricas, enlace al documento):
   Limitaciones conocidas:
   Lista de privacidad:
   - [ ] Sin pesos de modelos ni de voz (.gguf, .bin, .onnx, espeak-ng-data)
   - [ ] Sin grabaciones (.wav) ni transcripciones privadas
   - [ ] Sin tokens, contraseñas ni identificadores del teléfono
   ```

   Al revisar un PR del Estudiante 1 no repites la prueba. Compruebas que los pasos y la evidencia estén escritos y sean coherentes con los criterios de la issue.

2. **Revisa la guía paso a paso** del Estudiante 1 (`docs/instalacion.md`). Comprueba que diga de dónde salen Termux y Termux:API, ya que deben venir de una fuente oficial (Plan, Etapa 1). Comprueba también que muestre la evidencia de que el compilador y el micrófono funcionan.

**Etapa terminada cuando** la guía de instalación está integrada por PR con tu revisión.

### Etapa 2 · Capturar y normalizar audio

1. **Escribe el protocolo de grabación** (sección 5) antes de cualquier sesión de prueba, para que el Estudiante 1 lo aplique.
2. **Verifica la evidencia:** el comando reproducible debe aparecer en `docs/contrato-audio.md` y no solo en `include/config.hpp`. Además, el clip de prueba no debe contener datos personales.
3. **Comprueba que no se subió audio:** ningún PR debe incluir archivos `.wav` ni grabaciones originales.

### Etapa 3 · Reconocimiento de voz (STT)

1. **Prepara el corpus** de frases con su referencia escrita exacta (sección 5).
2. **Define el criterio de «utilizable»** antes de evaluar [DECISIÓN DEL EQUIPO]. Propuesta: la transcripción es utilizable si conserva la intención y todas las palabras clave de la pregunta, de modo que no haría falta corregirla antes del SLM.
3. **Entrega al Estudiante 1 las fichas de frases y el formato de registro.** Él graba, ejecuta y llena una fila por frase. Tú recibes el registro y lo pasas a `docs/evaluacion-stt.md`.
4. **Calcula**, a partir de ese registro, la tasa de transcripciones utilizables por condición, el WER y el RTF (sección 4).
5. **Corrige las inconsistencias actuales:**
   - `docs/contrato-stt.md` dice 10/20 y `docs/evaluacion-stt.md` dice 18/20.
   - El 18/20 mezcla condiciones: solo 5 frases son en silencio a velocidad normal.
   - Las frases 4, 10 y 17 tienen veredictos dudosos o ambiguos. La 10 se marca como utilizable aunque su nota dice que «altera elementos principales».
   - Vuelve a evaluarlas con el criterio declarado y deja constancia del cambio.
6. **Documenta la comparación entre tiny y base** que ya existe: mismo WAV, tiempo y memoria. Recuerda que base solo se compara «si hay margen» (Plan, Etapa 3).

**Etapa terminada cuando** hay 20 frases en silencio evaluadas con el mismo criterio, al menos 18 utilizables, y los resultados con ruido, habla rápida y acentos se reportan por separado.

### Etapa 4 · Modelo de lenguaje pequeño (SLM)

1. **Escribe las 10 preguntas cortas** junto con su respuesta de referencia, antes de la prueba. `docs/evaluacion-slm.md` ya tiene 10 preguntas con corrección; consérvalas para poder comparar (Guía §9).
2. **Clasifica por escrito la calidad** de las respuestas que te entrega el Estudiante 1, con una escala fija. El repositorio ya usa una en `docs/evaluacion-integracion.md`: Adecuada, Parcialmente adecuada, Imprecisa e Incorrecta. Mantenla.
3. **Registra las métricas** que entrega el Estudiante 1: latencia por turno, memoria máxima y tokens/s (sección 4).
4. **Completa la entrada de Qwen en el manifiesto** con licencia, origen y SHA-256. Es un requisito explícito de esta etapa (Plan, Etapa 4). Ver la sección 6.

### Etapa 5 · Síntesis de voz (TTS)

1. **Escribe la ficha de la voz:**
   - Identificación exacta: `vits-piper-es_MX-claude-high`, archivo `es_MX-claude-high.onnx`.
   - Motor y revisión.
   - Idioma y variante regional.
   - Tamaño y licencia.
   - Funcionamiento sin red.
   - Limitaciones (Plan, Etapa 5).
2. **Define la escala de la evaluación auditiva** de pronunciación, ritmo y naturalidad (Plan, Etapa 5) [DECISIÓN DEL EQUIPO], por ejemplo del 1 al 5 con una descripción por nivel. El Estudiante 1 escucha la voz en el teléfono y aplica la escala; tú documentas los resultados en la ficha. «Voz latina» es una meta de calidad regional, no una propiedad automática de cualquier voz en español (Guía §5).
3. **Registra que el fallback de Android** (TTS de Termux:API) es «solo de demostración» y «puede no funcionar offline» (Plan pp. 3 y 8). En el repositorio está desactivado.

### Etapa 6 · Orquestador C++

1. **Revisa el PR del diagrama de estados:** Listo → Grabando → Transcribiendo → Generando → Hablando → Listo/Error (Plan, Etapa 6).
2. **Abre la issue de CI** para que el Estudiante 1 cree el flujo en `.github/workflows/` que compile y revise el formato (Plan p. 5). La herramienta de formato no la fijan los documentos [DECISIÓN DEL EQUIPO]. Revisa el PR y confirma en GitHub que la comprobación termina en verde.
3. **Protege `main`** cuando la CI exista: exige revisión de un PR y que la CI pase antes de integrar (Plan p. 5). Esto lo configura la cuenta propietaria del repositorio [VERIFICAR] en la documentación de GitHub.
4. **Pide al Estudiante 1 que configure su nombre en Git.** Dos commits aparecen como «unknown», y la rúbrica valora los «aportes del equipo».

### Etapa 7 · Integración y evaluación en el móvil

1. **Prepara la lista de la sesión oficial** (sección 7.1). La completa el Estudiante 1 durante la prueba y te la devuelve con el CSV.
2. **Calcula p50 y p95 por etapa**, la memoria máxima y los errores (sección 4), a partir del CSV de esa sesión.
3. **Redacta el reporte V1** (sección 7.2).
4. **Publica la release V1** (sección 7.3).

---

## 4. Métricas: cómo calcularlas sin programar

Los datos crudos salen del registro de tiempos del orquestador. En el repositorio está publicado como `docs/mediciones/tiempos-integracion.csv`, con las columnas `sesion,turno,etapa,ms,codigo_salida,memoria_pico_kb,audio_s`. Contiene solo tiempos, códigos y memoria, sin texto de las conversaciones (Plan, Etapa 6).

Al interpretar el CSV, ten en cuenta lo que ya documenta `docs/evaluacion-integracion.md`:

- `turno_procesamiento` suma la conversión, el STT, el SLM y la síntesis TTS. No incluye la grabación, la corrección manual ni la espera de reproducción.
- `grabar` y `reproducir` miden el comando de inicio, no la tarea completa.
- `memoria_pico_kb` es la memoria de cada proceso hijo, no la de toda la aplicación.

### 4.1 Latencia, p50 y p95

La Guía §9 define la latencia como el «tiempo transcurrido entre inicio y resultado de una etapa o turno». p50 y p95 son los percentiles 50 y 95, y hay que «reportar muestras y unidad».

1. Toma la columna `ms` de una etapa y de la sesión oficial. Usa solo las filas con `codigo_salida` igual a 0 y reporta los fallos por separado [DECISIÓN DEL EQUIPO].
2. Ordena los valores de menor a mayor y cuenta las muestras (n).
3. **p50 (mediana):** si n es impar, es el valor central. Si n es par, es el promedio de los dos valores centrales.
4. **p95:** usa el valor en la posición ⌈0,95 × n⌉ de la lista ordenada (método del rango más cercano) [DECISIÓN DEL EQUIPO: declara el método en el reporte]. Con n entre 1 y 19, esa posición es la última, así que el p95 coincide con el máximo. Por eso es obligatorio reportar n.
5. Escribe el resultado así: «STT: p50 = … ms, p95 = … ms (n = 10)».

**Ejemplo con los datos actuales (solo ilustra el método).** Estos 14 valores de `turno_procesamiento` provienen de sesiones separadas, no de 10 turnos consecutivos, y no son el resultado oficial:

8564, 9489, 10025, 10225, 10802, 11181, 11435, 11808, 11929, 13049, 14682, 15117, 15617, 16208 ms (n = 14)

- p50 = (11435 + 11808) / 2 = **11 621,5 ms**.
- p95: posición ⌈0,95 × 14⌉ = ⌈13,3⌉ = 14, que corresponde a **16 208 ms**.

### 4.2 Memoria pico observada

Es el «máximo registrado durante la prueba; no es la RAM total del teléfono» (Guía §9). Para cada etapa, toma el mayor valor de `memoria_pico_kb` y repórtalo en KB. Hasta ahora, el valor más alto es el del SLM, con 1 253 100 KB.

Recuerda también que un GGUF de 563 MB en almacenamiento no significa 563 MB de RAM (Plan p. 11).

### 4.3 RTF del STT

RTF = tiempo de procesamiento ÷ duración del audio. Si es menor que 1, el procesamiento fue más rápido que la duración del audio en esa prueba (Guía §9). Usa la fila `stt`: columna `ms` ÷ 1000 ÷ columna `audio_s`.

Ejemplo de `docs/evaluacion-stt.md`, frase 1: 1673 ms y 8,192 s, de modo que RTF = 1,673 ÷ 8,192 = 0,204.

### 4.4 Tokens/s del SLM

Es la velocidad de generación del SLM y «no equivale a la latencia total de voz a voz» (Guía §9). La entrega el Estudiante 1 a partir de la salida de llama.cpp.

Por ejemplo, en la pregunta 1 de `docs/evaluacion-slm.md` la generación fue de 7,3 tokens/s, pero el proceso del SLM tardó 10 722 ms en total, sin contar STT ni TTS.

### 4.5 WER y tasa de transcripciones utilizables

WER = (sustituciones + borrados + inserciones) ÷ palabras de la referencia (Guía, glosario).

**Paso 1. Normaliza los dos textos [DECISIÓN DEL EQUIPO].** Propuesta:

- Quita los signos de puntuación (¿ ? ¡ ! . ,).
- Pasa todo a minúsculas.
- Decide si las tildes cuentan y aplícalo siempre igual.

**Paso 2. Compara palabra por palabra y cuenta:**

- S (sustituciones): una palabra cambiada por otra.
- D (borrados): una palabra que falta.
- I (inserciones): una palabra que sobra.

**Paso 3. Divide** S + D + I entre el número de palabras de la referencia (N).

**Ejemplos con frases del repositorio:**

| Frase | Referencia normalizada (N) | Transcripción normalizada | Conteo | WER |
|---|---|---|---|---|
| 3 | cuál es la diferencia entre memoria y almacenamiento (8) | cuál es la diferencia entre **de** memoria y almacenamiento | I = 1 | 1/8 = 0,125 |
| 5 | dime tres ventajas de procesar datos en el teléfono (9) | **vime** tres ventajas de procesar datos en el teléfono | S = 1 | 1/9 = 0,111 |
| 2 | explícame qué es un modelo de lenguaje (7) | explícame **que** es un modelo de lenguaje | S = 1 si cuentan las tildes; 0 si no | 0,143 o 0 |

La frase 2 muestra por qué la regla de tildes se decide antes de evaluar y se declara en el reporte.

**WER global [DECISIÓN DEL EQUIPO]:** suma S + D + I de todas las frases de una condición y divide entre la suma de sus N.

**Tasa de transcripciones utilizables:** cuenta las frases utilizables entre el total de cada condición, por ejemplo «silencio: 19/20». Reporta el WER o la tasa, o ambos, pero «no resumir todo en una sola anécdota» (Guía §3).

---

## 5. Grabaciones de prueba

### 5.1 Corpus

| Conjunto | Contenido | Para qué sirve |
|---|---|---|
| A · Silencio | 20 frases cortas a velocidad normal en ambiente silencioso | Criterio de aceptación: al menos 18 de 20 utilizables (Plan, criterios mínimos) |
| B · Ruido moderado | Frases del conjunto A con ruido de fondo | «Reportar también resultados con ruido» (Plan) |
| C · Habla rápida | Frases del conjunto A dichas rápido | Condición separada (Guía §3) |
| D · Acentos | Frases del conjunto A con acentos distintos | Condición separada (Guía §3) |

**Reglas del corpus:**

- **Tamaño de B, C y D [DECISIÓN DEL EQUIPO].** El repositorio actual usa 5 por condición. Repetir las frases de A permite comparar condiciones con los mismos textos (Guía §9).
- **Contenido de las frases:** deben ser cortas, sobre el tema del curso y sin nombres, direcciones, números de contacto ni otros datos personales (Plan, Etapa 3). La referencia exacta se escribe antes de grabar.
- **Estado actual:** las 5 frases en silencio a velocidad normal que ya existen se pueden reutilizar. Faltan 15 más para completar el conjunto A.

### 5.2 Protocolo de una sesión de grabación

Tú redactas el protocolo y el Estudiante 1 lo aplica. Tú no estás en la ejecución ni eres hablante en las pruebas.

**Lo que debe fijar el protocolo antes de la sesión:**

1. Las fichas de las frases con la referencia exacta, que le entregas al Estudiante 1.
2. Un código para cada hablante (H1, H2…). Los hablantes son el Estudiante 1 u otras personas que den su consentimiento; tú lo registras fuera del repositorio. En el repositorio solo aparece el código (Guía §11: «Grabar con autorización»).
3. Las condiciones, que no deben cambiar durante la sesión:
   - Mismo teléfono y misma configuración (whisper.cpp con tiny multilingüe, idioma español y clips de 8 s).
   - Misma posición del hablante [DECISIÓN DEL EQUIPO].
4. Para el ruido, siempre la misma fuente, el mismo volumen y la misma distancia. En el repositorio, el volumen del PC varió entre el 16 % y el 30 % entre frases. Fija un solo valor. El porcentaje del control de volumen no equivale a decibelios, y así debe decirse.
5. Para los acentos, que se anote si son naturales o imitados. La frase 20 actual lo tiene pendiente.

**Durante la sesión.** El Estudiante 1 graba, ejecuta y llena una fila por frase con este formato, que tú le entregas. Los campos marcados los completas tú después:

| Campo | Ejemplo |
|---|---|
| Frase y conjunto | 7 · A |
| Hablante | H1 |
| Condición | silencio, velocidad normal |
| Referencia | (texto exacto) |
| Transcripción | (copiada tal cual sale) |
| Duración del WAV | 8,192 s |
| Tiempo | ms |
| Memoria pico | KB |
| Código de salida | 0 |
| RTF | (lo calculas tú) |
| Utilizable | sí o no, con el motivo (lo decides tú con el criterio declarado) |
| S / D / I / N y WER | (lo calculas tú) |

**Después de la sesión:**

1. El Estudiante 1 confirma por escrito que la carpeta de temporales (`../jarvis-tmp`) quedó vacía, y tú lo dejas registrado (Plan, Etapa 6).
2. Publica solo las referencias y las transcripciones de las frases de prueba consentidas, nunca el audio (Plan, Etapa 7).
3. Si una grabación se conserva un tiempo para comparar tiny y base sobre el mismo WAV, debe quedar fuera del repositorio y borrarse al terminar (Plan p. 11).

---

## 6. Documentación del manifiesto (`models/manifest.json`)

La Guía §11 exige registrar para cada modelo el nombre exacto, la versión o revisión, la URL de origen, el formato o la cuantización, la licencia, el tamaño, el SHA-256 y la forma de descargarlo.

### 6.1 Estado actual campo por campo

| Campo (Guía §11) | whisper-tiny | qwen-0.8b-q4_0 | piper-es_MX-claude-high |
|---|---|---|---|
| Nombre exacto | Sí (`ggml-tiny.bin`) | Sí (`Qwen3.5-0.8B-Q4_0.gguf`) | Sí (`es_MX-claude-high.onnx` y archivos asociados) |
| Versión o revisión | Del motor sí; del archivo no (la URL apunta a `main`) | Del motor sí; del archivo no (la URL apunta a `main`) | Del motor sí; del paquete no (publicación `tts-models`) |
| URL de origen | Sí | Sí | Sí |
| Formato o cuantización | Variante «tiny multilingüe» | Q4_0 | No se declara de forma explícita |
| **Licencia** | **Falta** (`null`) | **Falta** (`null`) | **Falta** (`null`, «modelo y dependencias») |
| **Tamaño** | **Falta** | **Falta** (el Plan indica 563 MB publicados) | **Falta** |
| SHA-256 | Sí, coincide con el publicado | Sí, coincide con el publicado | Calculado localmente; no hay huellas publicadas por el proveedor |
| Forma de descarga | Sí | Sí | Sí (paquete `.tar.bz2`) |

### 6.2 Tareas

1. **Licencias.** Revisa por separado el runtime, el modelo y la voz (Guía §11).
   - Fuentes: «whisper.cpp», «llama.cpp», «Qwen3.5-0.8B GGUF oficial» y «sherpa-onnx · Piper TTS», además de la página de origen registrada en el campo `fuente` de cada entrada.
   - Copia el nombre de la licencia tal como aparece publicado y la URL donde lo encontraste.
   - Si no la encuentras, deja el estado como pendiente y regístralo en las limitaciones. Nunca la supongas.
   - El manifiesto actual no tiene un campo para la licencia de los runtimes; agrégalo [DECISIÓN DEL EQUIPO].
2. **Tamaño.** Pide al Estudiante 1 el tamaño en bytes de cada archivo, tal como quedó en el teléfono, y contrástalo con el publicado. Para Qwen, la referencia es 563 MB (Plan p. 3).
3. **Revisión del archivo.** Las URL con `main` pueden cambiar, como advierte el propio manifiesto. Registra la revisión o fecha de publicación del archivo si la fuente oficial la muestra [VERIFICAR]. Si no, el SHA-256 sigue siendo la referencia que identifica el archivo verificado.
4. **Huellas de la voz.** Comprueba si sherpa-onnx publica huellas del paquete [VERIFICAR]. Si no las publica, mantén la nota actual: `"sha256_publicados_independientemente": false`.
5. **Whisper base.** Se usó en las comparaciones. Decide si se registra como «evaluado, no usado en V1» [DECISIÓN DEL EQUIPO]. La Guía pide registrar cada modelo.
6. **Coherencia.** Las huellas del manifiesto deben coincidir con las de `docs/evaluacion-tts.md` y con las de cualquier otro documento.

El manifiesto lo editas tú por PR. Pide al Estudiante 1 que confirme, al revisarlo, que el archivo sigue siendo válido. Nunca agregues pesos a `models/`.

---

## 7. Cierre: prueba oficial, reporte y release V1

### 7.1 Lista de la sesión oficial (Etapa 7)

Tú la redactas y se la entregas al Estudiante 1 antes de la prueba. Él la marca durante la sesión y te la devuelve junto con el CSV. Tú no participas en la ejecución.

- [ ] Modelos y voz descargados antes de empezar.
- [ ] Modo avión activado durante toda la sesión. El Plan pide además comprobar que no aparecen llamadas a red; el método no lo fijan los documentos [VERIFICAR].
- [ ] Las mismas 10 preguntas de la Etapa 4, preparadas en fichas.
- [ ] Una sola sesión del orquestador con 10 turnos consecutivos. Al final se anota el contador de completos y fallidos.
- [ ] Ningún cierre por memoria (OOM) ni pérdida del estado. Si ocurre alguno, se anota el turno, la etapa y el código y se registra en `docs/limitaciones.md` (Guía §7).
- [ ] Cada respuesta se reproduce en voz, sin solapar el TTS con la inferencia (Plan, criterios mínimos).
- [ ] Cuántos turnos necesitaron corrección manual de la transcripción.
- [ ] Carpeta de temporales vacía al terminar. No se graba ni se fotografía nada que muestre identificadores del teléfono.
- [ ] El Estudiante 1 entrega el CSV de esa sesión.

### 7.2 Reporte V1 (`docs/reporte-v1.md`) [DECISIÓN DEL EQUIPO: nombre]

La evidencia de la Etapa 7 es un «reporte reproducible de rendimiento, calidad y problemas», que debe anotar «teléfono, SoC, RAM, versión Android, modelos, cuantización, duración de audio y limitaciones» (Plan, Etapa 7). Estructura:

1. **Equipo de prueba:** marca y modelo, SoC, RAM total y disponible, Android y arquitectura, tomados de `docs/inventario-dispositivo.md`, con la advertencia de que no es un teléfono de 3 GB.
2. **Software y modelos:** revisiones de whisper.cpp, llama.cpp y sherpa-onnx, modelos, cuantización y voz, con enlace al manifiesto.
3. **Condiciones de la prueba:** modo avión, 10 turnos consecutivos, duración del audio (8 s) y frases usadas.
4. **Rendimiento:** tabla por etapa con p50, p95, n y unidad (sección 4.1), memoria pico por etapa en KB, RTF del STT y tokens/s del SLM. Explica qué incluye `turno_procesamiento`.
5. **Calidad:**
   - STT: tasa utilizable y WER por condición.
   - SLM: evaluación de las 10 preguntas con la escala fija.
   - TTS: evaluación auditiva hecha por el Estudiante 1 con la escala del equipo.
6. **Problemas y limitaciones:** resumen de `docs/limitaciones.md`, del Estudiante 1, con el estado de cada riesgo del Plan (p. 11):

   | Riesgo (Plan p. 11) | Qué reportar |
   |---|---|
   | Memoria limitada u OOM | Resultado de los 10 turnos consecutivos y memoria pico; teléfono de 7,85 GB |
   | Calidad desigual de STT | Tasas por condición; corrección manual (9 de 10 en la integración actual) |
   | TTS sin soporte offline | Resultado en modo avión; estado del fallback |
   | Audio privado | Temporales borrados; ningún audio en el repositorio |
   | Modelo o voz redistribuidos | Estado de las licencias en el manifiesto |

7. **Privacidad:** qué no se publicó y por qué.
8. **Cómo reproducirlo:** enlaces a `docs/instalacion.md`, al manifiesto y al tag de la release.

### 7.3 Release V1

La Guía §8 define la release como una «versión etiquetada con instrucciones, manifiesto y limitaciones». El Plan pide «release V1 con guía de instalación, manifiesto y limitaciones conocidas».

**Condiciones previas:**

- Todas las issues de las etapas 0 a 7 están en Hecho o tienen su pendiente documentado como limitación.
- La CI está en verde en `main`.
- El README, la instalación, el manifiesto, las limitaciones y el reporte están integrados por PR.

**Pasos:**

1. Crea la release desde `main` con un tag [DECISIÓN DEL EQUIPO: por ejemplo `v1.0`] y el título «Jarvis-son V1».
2. Escribe las notas con:
   - Qué hace la V1 y qué queda fuera de alcance (Plan p. 2).
   - Enlace a la instalación.
   - Enlace al manifiesto.
   - Limitaciones conocidas.
   - Enlace al reporte.
   - Teléfono de prueba.
   - Estado de las licencias.
3. **No adjuntes pesos, audios ni datos del teléfono a la release.** Sus archivos adjuntos también son públicos.

---

## 8. Cronograma del Estudiante 2

El Plan titula su tabla «Cronograma de dos semanas», pero la organiza en cuatro bloques (1/2 a 4/2), y la Guía §10 los presenta como semanas 1 a 4. Aquí se conservan los rótulos del Plan.

| Bloque (Plan) | Tus tareas | Evidencia al cierre |
|---|---|---|
| 1/2 | Project, issues, plantillas, README inicial, roles, revisión del inventario y protocolo de grabación | Repositorio inicial organizado |
| 2/2 | Corpus de frases y formato de registro, documentación de las sesiones de STT, 10 preguntas del SLM con referencia, primera tabla de latencia y RAM, y manifiesto de Whisper y Qwen | Pruebas de texto y notas de latencia y RAM |
| 3/2 | Escala auditiva y ficha de la voz, revisión del PR del orquestador, issue de CI y protección de `main` | Primer turno de voz a voz documentado |
| 4/2 | Lista de la sesión oficial y su documentación, p50 y p95, reporte, README y manual, y release V1 | Release de GitHub y reporte con limitaciones |

Ritmo (Plan p. 10): cierra una tarea pequeña por PR, con evidencia. Si un modelo falla, documenta la causa y la alternativa antes de ampliar el alcance.

### Prioridades inmediatas (estado al 15 de noviembre de 2026)

La parte técnica está en la Etapa 7, así que el orden recomendado es:

1. Project, issues de las etapas 0 a 7 (retroactivas) y plantillas.
2. Manifiesto: licencias, tamaños y revisiones. Sin esto no puede haber release.
3. Criterio de «utilizable», normalización del WER y conjunto A completo de 20 frases en silencio.
4. Lista para la sesión oficial de 10 turnos consecutivos en modo avión, que ejecuta el Estudiante 1.
5. Métricas, reporte y README.
6. CI (la crea el Estudiante 1), protección de `main` y release V1.

---

## 9. Lista de verificación final del Estudiante 2

- [ ] El GitHub Project tiene las 5 columnas y cada etapa tiene su issue con objetivo, criterios y responsable.
- [ ] Hay plantillas de Issues y PR con descripción, pasos de prueba, evidencia y limitaciones.
- [ ] Todos los cambios entran por PR revisado por la otra persona, y `main` está protegida con revisión y CI.
- [ ] El README tiene propósito, instalación, ejecución y contribución.
- [ ] El manifiesto tiene licencia, tamaño, SHA-256, origen, revisión y forma de descarga para cada modelo y voz, sin pesos.
- [ ] Al menos 18 de 20 frases en silencio son utilizables con un criterio declarado, y se reportan también ruido, habla rápida y acentos.
- [ ] Hay p50 y p95 por etapa con n y unidad, memoria pico, RTF y tokens/s de la sesión oficial.
- [ ] El reporte V1 incluye equipo, modelos, cuantización, duración del audio, problemas y limitaciones, sin extrapolar a otros teléfonos.
- [ ] La release V1 está publicada con instrucciones, manifiesto y limitaciones.
- [ ] No hay grabaciones, transcripciones privadas, tokens ni identificadores en el repositorio ni en la release.

---

## 10. Tu peso en la rúbrica (Plan p. 10)

| Criterio | Peso | Tu aporte |
|---|---|---|
| Arquitectura e integración | 25 % | Revisión de PR y verificación de la evidencia (lo construye el Estudiante 1) |
| Ejecución móvil | 25 % | Documentación de la sesión oficial y de la ficha del equipo (la ejecución es del Estudiante 1) |
| Evaluación y honestidad | 20 % | Métricas, criterios declarados, calidad y fallos reportados |
| GitHub y colaboración | 15 % | Issues, Project, PR, revisión, CI y release |
| Documentación y privacidad | 15 % | README, manifiesto, licencias, reporte y control de privacidad |

---

## 11. Fuentes oficiales citadas por los documentos

Los PDF citan estas fuentes por su nombre, pero no incluyen las direcciones web. Las URL de origen de cada modelo ya están registradas en `models/manifest.json`.

| Fuente (nombre en los documentos) | La necesitas para |
|---|---|
| GitHub · Projects | Tablero y columnas (Etapa 0) |
| GitHub · tamaño de archivos | Regla de no subir pesos |
| whisper.cpp · uso, formato y memoria | Licencia del runtime y del modelo tiny |
| llama.cpp · Android/Termux; llama.cpp · cuantización | Licencia del runtime; significado de Q4_0 |
| Qwen3.5-0.8B GGUF oficial | Licencia, tamaño (563 MB) y origen del modelo |
| sherpa-onnx · Piper TTS | Licencia del runtime y de la voz; huellas del paquete |
| Android · relación entre versión y API level | Ficha del equipo (Android 13 = API 33) |
