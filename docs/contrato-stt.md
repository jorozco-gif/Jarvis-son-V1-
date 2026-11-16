# Contrato STT · Jarvis-son V1

- Motor: whisper.cpp.
- Modelo inicial: ../jarvis-modelos/ggml-tiny.bin, multilingüe.
- Alternativa evaluada: ../jarvis-modelos/ggml-base.bin.
- Idioma: español.
- Entrada: ../jarvis-tmp/entrada.wav.
- Formato: WAV PCM s16le, mono, 16000 Hz.
- Ejecución: terminar STT antes de iniciar el modelo de lenguaje.

## Salida requerida para la integración

- Transcripción por stdout, capturada en memoria.
- Sin marcas de tiempo en el texto que recibe el modelo de lenguaje.
- Diagnósticos por stderr.
- Código de salida 0: ejecución correcta; no garantiza exactitud.
- Código distinto de 0: pasar al estado ERROR.
- Transcripción vacía tras limpiarla: ERROR.
- Permitir al usuario corregir la transcripción antes del SLM.
- Eliminar el WAV al terminar el STT.

## Estado de evaluación

- Resultados y comparaciones en docs/evaluacion-stt.md.
- Conjunto principal mixto: 10/20 transcripciones utilizables.
- La meta de 18/20 en silencio no está verificada.
- Origen natural o imitado de los acentos: pendiente de confirmar.
- La Etapa 3 conserva pendientes de calidad; no se declara plenamente aprobada.
