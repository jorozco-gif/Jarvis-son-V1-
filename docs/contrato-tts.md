# Contrato TTS — Jarvis-son V1

## Motor y modelo
- Motor: sherpa-onnx.
- Revisión: 1a9d234ab95567eba8c2e89873a87d70b79633e2.
- Ejecutable: ../sherpa-onnx/build-piper/bin/sherpa-onnx-offline-tts
- Directorio del modelo: ../jarvis-modelos/vits-piper-es_MX-claude-high/
- Modelo: es_MX-claude-high.onnx
- Tokens: tokens.txt
- Datos de pronunciación: espeak-ng-data/
- Hilos utilizados en las pruebas: 1.

## Entrada
- Texto en español, pasado como un único argumento.
- El orquestador utilizará argumentos separados mediante execvp.
- No se utilizará interpolación de texto mediante un shell.

## Salida
- Archivo WAV indicado mediante --output-filename.
- Frecuencia declarada del modelo: 22050 Hz.
- La salida TTS no requiere la frecuencia de 16000 Hz exigida al STT.
- Código de salida esperado: 0.
- Antes de reproducir, comprobar que el WAV existe y no está vacío.

## Ejecución
- Ejecutar después de finalizar el proceso del modelo de lenguaje.
- Esperar a que termine la síntesis antes de reproducir el WAV.
- Eliminar el audio temporal después de terminar su reproducción.
- Registrar tiempo del proceso, memoria pico y código de salida.

## Validación inicial
- Síntesis y reproducción verificadas sin conexión.
- Resultados y huellas: docs/evaluacion-tts.md.
- Pendiente: completar documentación de licencias y dependencias.
