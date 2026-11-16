# Contrato SLM · Jarvis-son V1

## Motor y modelo
- Motor: llama.cpp, build 12407.
- Commit: e574a17b062be51b98e239ccd3d3743e3d902333.
- Modelo provisional: Qwen3.5-0.8B-Q4_0.gguf.
- Ruta: ../jarvis-modelos/Qwen3.5-0.8B-Q4_0.gguf.

## Entrada y ejecución
- Entrada: texto UTF-8 validado procedente del STT.
- Instrucciones mediante --system-prompt.
- Pregunta mediante -p.
- Contexto: 1024 tokens.
- Salida máxima: 96 tokens.
- Pensamiento desactivado.
- Una petición por proceso; terminar antes de iniciar TTS.
- En el orquestador, pasar argumentos mediante argv, sin shell.

## Salida requerida
- Respuesta breve en español latino neutro.
- Capturar el texto en memoria mediante stdout.
- Excluir eco del prompt, indicadores y métricas del texto hablado.
- Diagnósticos separados mediante stderr.
- Código distinto de 0 o respuesta vacía: estado ERROR.

## Estado
- Ejecución técnica comprobada en el teléfono.
- Calidad factual y pertinencia: no aprobadas.
- Separación de roles comprobada en el diagnóstico.
- Los ajustes probados no resolvieron todos los errores.
- La extracción limpia de stdout queda pendiente de verificar
  durante la integración.
- Evidencia: docs/evaluacion-slm.md.
