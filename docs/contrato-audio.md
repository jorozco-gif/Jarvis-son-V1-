# Contrato de audio · Jarvis-son V1

- Ruta de entrada al STT: ../jarvis-tmp/entrada.wav
- Formato: WAV PCM s16le.
- Canales: mono.
- Frecuencia: 16.000 Hz.
- Captura iniciada por el usuario: entre 5 y 8 segundos.
- Límites propuestos por la guía: mínimo 1 segundo y máximo
  8 segundos más 0,5 segundos de tolerancia.
- El original se elimina después de convertirlo.
- El WAV se elimina al terminar el STT.
- Los temporales del turno se eliminan al finalizar, incluso si falla.
- No se suben grabaciones a Git.

## Evidencia de la prueba en el teléfono

El validador jarvis-wav informó:

    formato=1 (1=PCM) canales=1 frecuencia=16000 Hz bits=16 duracion=8.192 s
    OK: WAV PCM s16le, mono, 16 kHz

Los archivos de audio de esta prueba fueron eliminados.
