# Evaluación de integración — Jarvis-son V1

## Condiciones
- Dispositivo: Xiaomi Redmi Note 14 5G, Android 16, aarch64.
- Diez preguntas diferentes ejecutadas sin internet.
- Ejecución por turnos: captura, conversión, STT, SLM, TTS y reproducción.
- Las pruebas se realizaron en sesiones separadas.
- Hubo una repetición adicional para revisar los asteriscos.

## Resultados funcionales
- 10 de 10 turnos completaron el flujo sin errores de ejecución.
- 9 de 10 necesitaron corrección manual de la transcripción.
- La pregunta sobre modelos de lenguaje no necesitó corrección.
- Se verificó la limpieza de temporales tras una sesión.
- Registro de métricas: mediciones/tiempos-integracion.csv.

## Calidad de las respuestas
| Pregunta | Evaluación |
|---|---|
| RAM y almacenamiento | Parcialmente adecuada |
| Transcripción y síntesis | Incorrecta |
| Archivo temporal | Imprecisa |
| Ejecución secuencial de modelos | Incorrecta |
| Código abierto | Incorrecta |
| Borrado de audios temporales | Incorrecta |
| Ventajas de procesar voz localmente | No responde al aspecto local |
| Medición del tiempo de respuesta | Adecuada |
| Falta de RAM | Incorrecta |
| Modelo de lenguaje | Imprecisa |

## Interpretación de las métricas
- turno_procesamiento suma conversión, STT, SLM y síntesis TTS.
- Excluye grabación, corrección manual y espera de reproducción.
- grabar y reproducir miden el comando de inicio, no la tarea completa.
- memoria_pico_kb corresponde a cada proceso hijo; no a toda la aplicación.
- Última prueba: 11181 ms de procesamiento, todas las etapas con salida 0.

## Conclusión
La integración funciona sin internet con intervención manual.
Completar el flujo no equivale a responder correctamente.
La calidad del reconocimiento y de las respuestas requiere mejoras.
