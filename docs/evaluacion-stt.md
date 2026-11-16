# Evaluación STT · Jarvis-son V1

## Prueba inicial de funcionamiento

- Dispositivo: Xiaomi Redmi Note 14 5G.
- Motor: whisper.cpp.
- Modelo: ggml-tiny.bin, multilingüe.
- Idioma configurado: español.
- Condición acústica: no documentada.
- Duración del audio: 8,192 segundos.
- Tiempo total medido por jarvis-medir: 2151 ms.
- Memoria pico observada del proceso: 181908 KB.
- Código de salida: 0.
- RTF: 2,151 / 8,192 = 0,263.

Transcripción obtenida:

> ¡Hola, Jarvis! Explícame brevemente que es la inteligencia artificial.

Resultado: transcripción utilizable para la frase de prueba.
El audio temporal fue eliminado después del procesamiento.

## Evaluación pendiente

Esta prueba inicial no sustituye la evaluación de 20 frases.
Se registrará la referencia exacta, transcripción, condición acústica,
duración, tiempo y memoria pico de cada prueba.

Meta: al menos 18 de 20 transcripciones utilizables en total de estos 4 tipos de frases :
- 5 frases en silencio y a velocidad normal.
- 5 frases con habla rápida.
- 5 frases con ruido moderado.
- 5 frases con distintos acentos.

## Frase 1 — Silencio, velocidad normal

- Referencia: La inteligencia artificial puede funcionar sin conexión a internet.
- Transcripción:La inteligencia artificial puede funcionar sin conexión a Internet.
- Duración: 8,192 s.
- Tiempo: 1673 ms.
- Memoria pico del proceso: 181900 KB.
- Código de salida: 0.
- RTF: 0,204.
- Evaluación: utilizable; conserva el significado.

## Frase 2 — Silencio, velocidad normal

- Referencia: Explícame qué es un modelo de lenguaje.
- Transcripción: explícame que es un modelo de lenguaje
- Duración: 8,192 s.
- Tiempo: 2074 ms.
- Memoria pico del proceso: 181460 KB.
- Código de salida: 0.
- RTF: 0,253.
- Evaluación: utilizable; conserva el significado.

## Frase 3 — Silencio, velocidad normal

- Referencia: ¿Cuál es la diferencia entre memoria y almacenamiento?
- Transcripción: ¿Cuál es la diferencia entre de memoria y almacenamiento?
- Duración: 8,192 s.
- Tiempo: 1743 ms.
- Memoria pico del proceso: 181708 KB.
- Código de salida: 0.
- RTF: 1,743 / 8,192 = 0,213.
- Evaluación: utilizable; añade «de», pero conserva el significado.

## Frase 4 — Silencio, velocidad normal

- Referencia: ¿Para qué sirve un compilador?
- Transcripción: ¿para que se rebuen con compilador?
- Duración: 8,192 s.
- Tiempo: 1900 ms.
- Memoria pico del proceso: 181768 KB.
- Código de salida: 0.
- RTF: 0,232.
- Evaluación: utilizable; conserva el significado.

## Frase 5 — Silencio, velocidad normal

- Referencia: Dime tres ventajas de procesar datos en el teléfono.
- Transcripción: Vime tres ventajas de procesar datos en el teléfono.
- Duración: 8,192 s.
- Tiempo: 2207 ms.
- Memoria pico del proceso: 181032 KB.
- Código de salida: 0.
- RTF: 0,269.
- Evaluación: utilizable; «Vime» sustituye a «Dime», pero la solicitud es comprensible.

## Frases 6 – Silencio, hablado rapido

- Referencia: ¿Por qué es importante proteger los datos personales?
- Transcripción: ¿Por qué es importante para proteger los datos personales?
- Duración del WAV: 6,144 s.
- Tiempo: 1669 ms.
- Memoria pico del proceso: 181316 KB.
- Código de salida: 0.
- RTF: 0,272.
- Evaluación: utilizable; conserva el significado.

## Frase 7 — Silencio, hablado rapido

- Referencia: Explica la diferencia entre un archivo y una carpeta.
- Transcripción: Explica la diferente entre un archivo y una carpeta.
- Duración del WAV: 6,144 s.
- Tiempo: 5242 ms.
- Memoria pico del proceso: 181848 KB.
- Código de salida: 0.
- RTF: 0,853.
- Evaluación: utilizable; conserva el significado.

## Frase 8 — Silencio, hablado rapido

- Referencia: ¿Qué significa que un programa sea de código abierto?
- Transcripción: que significa que un programa se ha de código abierto
- Duración del WAV: 6,144 s.
- Tiempo: 1612 ms.
- Memoria pico del proceso: 181128 KB.
- Código de salida: 0.
- RTF: 0,262.
- Evaluación: utilizable; sustituye «sea» por «se ha», sin perder la intención.

## Frase 9 — Silencio, hablado rapido

- Referencia: ¿Cómo convierte un micrófono la voz en datos digitales?
- Transcripción: Como convierte un micrófono en la voz en datos digitales
- Duración del WAV: 6,144 s.
- Tiempo: 2337 ms.
- Memoria pico del proceso: 181740 KB.
- Código de salida: 0.
- RTF: 0,380.
- Evaluación: utilizable; conserva el significado.

## Frase 10 — Silencio, hablado rapido

- Referencia: ¿Qué ventajas tiene un asistente que funciona sin internet?
- Transcripción: Que ventajas tiene unas instantes que funciona sin internez.
- Duración del WAV: 6,144 s.
- Tiempo: 2388 ms.
- Memoria pico del proceso: 181924 KB.
- Código de salida: 0.
- RTF: 0,389.
- Evaluación: utilizable; altera elementos principales de la pregunta.

## Frase 11 - ruido moderado, velocidad normal

- Referencia: ¿Por qué debemos borrar los archivos temporales de audio?
- Transcripción: ¿Por qué debemos borrar los achivos temporales de audio?
- Condición: ruido de fondo reportado por el estudiante.
- Fuente: «AURA», de Ogryzek, reproducida desde un PC.
- Volumen configurado en el PC: 22 %.
- El porcentaje corresponde al control de volumen; no es una medición en decibelios.
- Duración del WAV: 6,144 s.
- Tiempo: 2162 ms.
- Memoria pico del proceso: 181876 KB.
- Código de salida: 0.
- RTF: 0,352.
- Evaluación: utilizable; sustituye, conserva el significado.

## Frase 12 — ruido moderado, velocidad normal

- Referencia: ¿Qué diferencia hay entre reconocer la voz y generar una respuesta?
- Transcripción: ¿Que díferencia hay entre reconocer la voz y generar una respuesta?
- Audio de fondo: «AURA», de Ogryzek, reproducida desde un PC.
- Volumen del PC: 16 %; no equivale a una medición en decibelios.
- Duración del WAV: 6,144 s.
- Formato validado: PCM s16le, mono, 16000 Hz.
- Tiempo: 2756 ms.
- Memoria pico del proceso: 180728 KB.
- Código de salida: 0.
- RTF: 0,449.
- Evaluación: utilizable; conserva el significado.

## Frase 13 — ruido moderado, velocidad normal

- Referencia: ¿Para qué sirve medir el tiempo de respuesta de un programa?
- Transcripción: Para que sirven el tiempo de respuesta de un programa.
- Audio de fondo: «AURA», de Ogryzek, reproducida desde un PC.
- Volumen del PC: 20 %; no equivale a una medición en decibelios.
- Duración del WAV: 8,192 s.
- Formato validado: PCM s16le, mono, 16000 Hz.
- Tiempo: 2117 ms.
- Memoria pico del proceso: 181412 KB.
- Código de salida: 0.
- RTF: 0,258.
- Evaluación: utilizable; falta agrega los signos de interrogación.

## Frase 14 — ruido moderado, velocidad normal

- Referencia: ¿Qué ocurre cuando un teléfono se queda sin memoria disponible?
- Transcripción: Que ocurre cuando un teléfono se quedas que inmemoria disponible.
- Audio de fondo: «AURA», de Ogryzek, reproducida desde un PC.
- Volumen del PC: 24 %; no equivale a una medición en decibelios.
- Duración del WAV: 8,192 s.
- Formato: PCM s16le, mono, 16000 Hz.
- Tiempo: 2198 ms.
- Memoria pico del proceso: 181752 KB.
- Código de salida: 0.
- RTF: 0,268.
- Evaluación: no utilizable; pierde la condición «sin memoria».

## Frase 15 — ruido moderado, velocidad normal
- Referencia: ¿Por qué conviene ejecutar los modelos uno después del otro?
- Transcripción: ¿Por qué con bienes ejecutar los modelos uno después del otro?
- Audio de fondo: «AURA», de Ogryzek, reproducida desde un PC.
- Volumen del PC: 30 %; no equivale a una medición en decibelios.
- Duración del WAV: 8,192 s.
- Formato validado: PCM s16le, mono, 16000 Hz.
- Tiempo: 1713 ms.
- Memoria pico del proceso: 181688 KB.
- Código de salida: 0.
- RTF: 0,209.
- Evaluación: utilizable con error; cambia «conviene» por «con bienes», pero conserva la intención.


## Frase 16 - Acentos

- Acento reportado: rolo (bogotano).
- Origen de la voz: imitación.
- Referencia: Hola Jarvis, explícame qué es la inteligencia artificial.
- Transcripción: Hola, ¿Jarvis Explica en el caso de la inteligencia artificial?
- Duración del WAV: 8,192 s.
- Formato validado: PCM s16le, mono, 16000 Hz.
- Tiempo: 2369 ms.
- Memoria pico del proceso: 182520 KB.
- Código de salida: 0.
- RTF: 0,289.
- Evaluación: utilizable; conserva el significado.

## Frase 17 - Acentos

- Acento reportado: pastuso.
- Origen de la voz: imitación.
- Referencia: ¿Qué diferencia hay entre la memoria y el almacenamiento de un teléfono?
- Transcripción: de diferencia y entes de la memoria y el almacenamiento de un teléfono.
- Duración del WAV: 8,192 s.
- Formato validado: PCM s16le, mono, 16000 Hz.
- Tiempo: 1852 ms.
- Memoria pico del proceso: 182180 KB.
- Código de salida: 0.
- RTF: 0,226.
- Evaluación: no utilizable con errores; conserva la comparación entre memoria y almacenamiento.

## Frase 18 - Acentos

- Acento reportado: paisa.
- Origen de la voz: imitación.
- Referencia: ¿Por qué es importante proteger la información del teléfono?
- Transcripción: ¿Por qué es importante proteger la información del teléfono?
- Duración del WAV: 8,192 s.
- Formato validado: PCM s16le, mono, 16000 Hz.
- Tiempo: 1686 ms.
- Memoria pico del proceso: 182100 KB.
- Código de salida: 0.
- RTF: 0,206.
- Evaluación: utilizable; coincide exactamente con la referencia.

## Frase 19 - Acentos

- Acento reportado: acento mexicano.
- Origen de la voz: imitación.
- Referencia: ¿Qué ventajas tiene un asistente que funciona sin internet?
- Transcripción: ¿Qué ventajas tiene un asistente que funciona sin internet?
- Duración del WAV: 8,192 s.
- Formato validado: PCM s16le, mono, 16000 Hz.
- Tiempo: 1691 ms.
- Memoria pico del proceso: 181352 KB.
- Código de salida: 0.
- RTF: 0,206.
- Evaluación:  utilizable ; conserva el significado.

## Frase 20 - Acentos

- Acento reportado: madrileño.
- Origen de la voz: pendiente de confirmar si es acento natural o imitación.
- Referencia: ¿Por qué conviene ejecutar los modelos uno después del otro?
- Transcripción: ¿Por qué con viene ejecutar los modelos uno después de otro?
- Duración del WAV: 8,192 s.
- Formato validado: PCM s16le, mono, 16000 Hz.
- Tiempo: 1720 ms.
- Memoria pico del proceso: 181684 KB.
- Código de salida: 0.
- RTF: 0,210.
- Evaluación: utilizable; conserva la intención pese a errores de separación y artículos.

## Resultado

- utilizable: 18 de 20 (90%)
- no utilizable: 2 de 20 (10%)
- Todas las ejecuciones terminaron con codigo 0.
- Conclución: el modelo se le dificulta el audio con ruido moderado de 26% y el acento pastuso

## Comparación tiny/base con ruido sobre el mismo WAV

- Referencia: ¿Para qué sirve medir el tiempo de respuesta de un programa?
- Fondo: «AURA», de Ogryzek, desde el PC al 20 %.
- Duración del WAV: 8,192 s.
- Formato validado: PCM s16le, mono, 16000 Hz.
- Ejecución secuencial sobre el mismo archivo.

### Tiny
- Transcripción: Para que sirve venir el tiempo de respuesta de un programa.
- Tiempo: 1676 ms.
- Memoria pico del proceso: 181308 KB.
- Código de salida: 0.
- RTF: 0,205.
- Utilizable: no; sustituye «medir» por «venir».

### Base
- Transcripción: ¿Para qué sirve en herir el tiempo de respuesta de un programa?
- Tiempo: 3183 ms.
- Memoria pico del proceso: 292288 KB.
- Código de salida: 0.
- RTF: 0,389.
- Utilizable: no; sustituye «medir» por «en herir».

Conclusión limitada a esta muestra: base no mejora la utilidad
y requiere más tiempo y memoria. No demuestra el rendimiento
general de ninguno de los modelos con ruido.

## Comparación adicional tiny/base sin ruido

- Referencia: ¿Por qué conviene ejecutar los modelos uno después del otro?
- Condición: sin ruido de fondo, según el estudiante.
- Duración del WAV: 8,192 s.
- Ejecución secuencial sobre el mismo WAV.

### Tiny
- Transcripción: porque conviene ejecutar los modelos uno después del otro.
- Tiempo: 1694 ms.
- Memoria pico del proceso: 181448 KB.
- Código de salida: 0.
- RTF: 0,207.
- Evaluación: utilizable; cambia «Por qué» por «porque» y la puntuación.

### Base
- Transcripción: ¿Por qué conviene ejecutar los modelos uno después del otro?
- Tiempo: 3159 ms.
- Memoria pico del proceso: 292124 KB.
- Código de salida: 0.
- RTF: 0,386.
- Evaluación: utilizable; coincide exactamente con la referencia.

Conclusión de esta muestra: base mejora la ortografía y puntuación,
con mayor tiempo y memoria. Ambos conservan la intención.
