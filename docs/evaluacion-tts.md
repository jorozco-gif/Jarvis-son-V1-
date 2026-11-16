# Evaluación inicial de síntesis de voz

## Configuración
- Motor: sherpa-onnx.
- Revisión: 1a9d234ab95567eba8c2e89873a87d70b79633e2.
- Ejecutable: build-piper/bin/sherpa-onnx-offline-tts.
- Modelo: vits-piper-es_MX-claude-high.
- Idioma: español de México.
- Frecuencia de salida declarada: 22050 Hz.
- Hilos: 1.

## Resultados

| Prueba | Duración del audio | Tiempo de síntesis informado | Tiempo total del proceso | Memoria pico (KB) | Salida |
|---|---:|---:|---:|---:|---:|
| Inicial | 3.971 s | 1.427 s | 3151 ms | 152840 | 0 |
| Sin conexión | 2.914 s | 1.074 s | 2779 ms | 154528 | 0 |

## Comprobación auditiva
- Prueba inicial: reproducción correcta, sin cortes audibles.
- Prueba sin conexión: reproducción correcta, confirmada por el estudiante.
- Estas mediciones corresponden únicamente al componente TTS.

## Observaciones
- Aparece un aviso sobre copiar espeak-ng-data en Android.
- Ambas ejecuciones generaron el WAV correctamente.
- Queda pendiente completar la documentación de licencias y huellas de los archivos del modelo.

## Huellas SHA-256 de los archivos utilizados

```text
6b7a54f5fcc8c9ce3788cd308a26cfa429ad025cdff4a7a6c34d025d0d229341  es_MX-claude-high.onnx
1afc81f703c0e4cb3b4d7c0dca096b8b54a98806807f0170cf5eb5557723c12d  es_MX-claude-high.onnx.json
ef3a7e4a8d1af0c9d4dc45aaae1a6242ebe24a7ed6f3d025a49eb29682784c6d  tokens.txt
```

Huellas calculadas localmente mediante sha256sum. No se han contrastado
con un manifiesto publicado por el proveedor.
