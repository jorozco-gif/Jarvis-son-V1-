## Prueba inicial — Qwen3.5-0.8B Q4_0

- Contexto: 1024 tokens.
- Salida máxima: 96 tokens.
- Pensamiento desactivado mediante enable_thinking=f>
- Modo: una sola petición.
- Solicitud: explicar qué es la inteligencia artific>
- Respuesta: La inteligencia artificial es un conjun>
- Tiempo total: 8586 ms.
- Velocidad de procesamiento del prompt: 42,7 tokens>
- Velocidad de generación: 7,0 tokens/s.
- Memoria pico del proceso: 1234928 KB.
- Código de salida: 0.
- Evaluación: respuesta breve, comprensible y en esp>
- Cumplimiento de extensión: una frase, frente a dos>

La ejecución anterior generó razonamiento en inglés >
17446 ms, código 0 y memoria pico de 1234568 KB.
Se conserva como fallo de calidad de la configuració>

## Pregunta 1 de 10

- Pregunta: ¿Qué diferencia hay entre memoria RAM y almacenamiento?
- Respuesta: La memoria RAM es el almacenamiento de datos que se utiliza por tiempo limitado y está en el CPU; mientras que el almacenamiento es el lugar físico donde se guardan las fotos y archivos, la RAM se usa principalmente para tareas en tiempo real.
- Tiempo total: 10722 ms.
- Procesamiento del prompt: 57,1 tokens/s.
- Generación: 7,3 tokens/s.
- Memoria pico del proceso: 1233536 KB.
- Código de salida: 0.
- Idioma y brevedad: cumple.
- Calidad: parcialmente correcta; contiene un error factual.
- Error: afirma que la RAM está en el CPU.
- Corrección: la RAM mantiene temporalmente datos y programas en uso; el almacenamiento conserva archivos aunque se apague el equipo.

## Pregunta 2 de 10

- Pregunta: ¿Qué significa que un programa sea de código abierto?
- Respuesta: El código abierto significa que la información de la computadora está disponible para ser compartida, usada y modificada por cualquier parte en cualquier tiempo.
- Tiempo total: 8077 ms.
- Procesamiento del prompt: 47,4 tokens/s.
- Generación: 7,7 tokens/s.
- Memoria pico del proceso: 1234492 KB.
- Código de salida: 0.
- Idioma y brevedad: cumple.
- Calidad: imprecisa; confunde código fuente con información de la computadora.
- Corrección: el código fuente está disponible para estudiarlo, modificarlo y redistribuirlo según las condiciones de una licencia de código abierto.

## Pregunta 3 de 10

- Pregunta: ¿Qué diferencia hay entre transcribir voz y sintetizar voz?
- Respuesta: El *sintetizador* convierte la voz en el sonido digital que se usa en el ordenador y la televisión, mientras que el *transcribidor* convierte la voz humana a texto escrito.
- Tiempo total: 9780 ms.
- Procesamiento del prompt: 54,2 tokens/s.
- Generación: 7,6 tokens/s.
- Memoria pico del proceso: 1233316 KB.
- Código de salida: 0.
- Idioma y brevedad: cumple.
- Calidad: parcialmente correcta; describe la transcripción, pero confunde la síntesis.
- Corrección: transcribir convierte voz en texto; sintetizar voz convierte texto en audio hablado.

## Pregunta 4 de 10

- Pregunta: ¿Qué ventaja de privacidad tiene procesar la voz localmente en vez de enviarla a un servidor?
- Respuesta: Procesar la voz localmente permite mantener la privacidad total, ya que ningún dato entra en el sistema de servidores donde se almacenaría o se procesaría.
- Tiempo total: 8857 ms.
- Procesamiento del prompt: 58,1 tokens/s.
- Generación: 7,5 tokens/s.
- Memoria pico del proceso: 1234084 KB.
- Código de salida: 0.
- Idioma y brevedad: cumple.
- Calidad: parcialmente correcta; exagera al prometer privacidad total.
- Corrección: el procesamiento local evita enviar la voz a servidores externos para la inferencia, pero la privacidad también depende de permisos, registros y limpieza de archivos.

## Pregunta 5 de 10

- Pregunta: ¿Por qué ejecutar tres modelos uno después del otro puede reducir el consumo máximo de memoria?
- Respuesta: El consumo máximo de memoria ocurre cuando la GPU ejecuta los modelos uno tras otro sin sincronización, causando un intercambio de memoria entre cada paso que genera el overhead. La solución es ejecutar los modelos uno por uno con el tiempo de espera mínimo, asegurando que la memoria sea compartida y el procesamiento se sincronice correctamente.
- Tiempo total: 13552 ms.
- Procesamiento del prompt: 49,9 tokens/s.
- Generación: 7,1 tokens/s.
- Memoria pico del proceso: 1234204 KB.
- Código de salida: 0.
- Idioma y extensión: español, dos frases.
- Calidad: incorrecta; atribuye el efecto a GPU, sincronización y memoria compartida.
- Corrección: terminar cada proceso antes de iniciar el siguiente evita mantener simultáneamente los tres modelos y sus recursos en memoria.

## Pregunta 6 de 10

- Pregunta: ¿Qué es un archivo temporal y por qué se elimina cuando deja de necesitarse?
- Respuesta: Un archivo temporal es un archivo de texto guardado en disco duro que se elimina automáticamente después de una duración predeterminada cuando la solicitud de almacenamiento termina.
- Tiempo total: 8705 ms.
- Procesamiento del prompt: 54,7 tokens/s.
- Generación: 7,5 tokens/s.
- Memoria pico del proceso: 1233868 KB.
- Código de salida: 0.
- Idioma y brevedad: cumple.
- Calidad: incorrecta; lo limita a texto y supone un borrado automático con plazo fijo.
- Corrección: un archivo temporal guarda datos necesarios durante una tarea; se elimina al dejar de necesitarse para liberar espacio y evitar conservar información innecesaria.

## Pregunta 7 de 10

- Pregunta: ¿Qué diferencia hay entre el tamaño de un modelo en disco y la memoria RAM que usa al ejecutarse?
- Respuesta: El tamaño de un disco duro es un espacio físico permanente que almacena datos físicos para lectura y escritura. Mientras que la memoria RAM es un almacenamiento externo que permite la transferencia inmediata entre la CPU y el programa en ejecución.
- Tiempo total: 9928 ms.
- Procesamiento del prompt: 59,2 tokens/s.
- Generación: 8,0 tokens/s.
- Memoria pico del proceso: 1234032 KB.
- Código de salida: 0.
- Idioma y extensión: español, dos frases.
- Calidad: incorrecta; no responde sobre el modelo y describe mal la RAM.
- Corrección: el tamaño en disco corresponde al archivo de pesos; durante la ejecución también se necesita memoria para contexto, cachés y buffers, por lo que ambos valores no son equivalentes.

## Pregunta 8 de 10

- Pregunta: Si un asistente transcribe mal una palabra, ¿por qué conviene corregir el texto antes de generar la respuesta?
- Respuesta: No puedo generar texto con errores ortográficos; mi función principal es la comprensión y generación de texto.
- Tiempo total: 7782 ms.
- Procesamiento del prompt: 47,9 tokens/s.
- Generación: 6,5 tokens/s.
- Memoria pico del proceso: 1236164 KB.
- Código de salida: 0.
- Idioma y brevedad: cumple.
- Calidad: incorrecta y no pertinente; afirma que no puede generar errores ortográficos.
- Corrección: una palabra mal transcrita puede cambiar la intención; corregirla permite generar una respuesta a la solicitud real.

## Pregunta 9 de 10

- Pregunta: ¿Por qué probar un asistente en modo avión ayuda a verificar que funciona sin conexión?
- Respuesta: El modo avión permite que un dispositivo conecte con el asistente sin una red Wi-Fi activa, permitiendo la prueba de la función "Verificar que funciona sin conexión" para validar la estabilidad de los componentes.
- Tiempo total: 9958 ms.
- Procesamiento del prompt: 59,7 tokens/s.
- Generación: 7,7 tokens/s.
- Memoria pico del proceso: 1232748 KB.
- Código de salida: 0.
- Idioma y brevedad: cumple.
- Calidad: imprecisa; inventa una función y no explica cómo se comprueba la ausencia de dependencia de red.
- Corrección: ejecutar STT, SLM y TTS con las conexiones desactivadas permite comprobar que funcionan localmente tras descargar sus recursos. Se debe verificar que el Wi-Fi siga apagado.

## Pregunta 10 de 10

- Pregunta: ¿Qué significa que un asistente de voz funcione por turnos?
- Respuesta: Para funcionar por turnos, se debe establecer tiempos y límites específicos para cada episodio, lo que garantiza que la atención sea estable y que cada usuario no pierda el hilo de conversación.
- Tiempo total: 9645 ms.
- Procesamiento del prompt: 48,2 tokens/s.
- Generación: 7,2 tokens/s.
- Memoria pico del proceso: 1233420 KB.
- Código de salida: 0.
- Idioma y brevedad: cumple.
- Calidad: no explica la alternancia entre intervención del usuario y respuesta del asistente.
- Corrección: el usuario inicia una grabación, el asistente transcribe, genera y reproduce su respuesta; luego permite iniciar otro turno, sin escucha simultánea ni interrupciones.

## Cierre de las 10 preguntas

Las 10 ejecuciones terminaron con código 0 y produjeron texto breve
en español. Sin embargo, todas presentaron errores, imprecisiones
o falta de pertinencia según la revisión realizada.

La ejecución técnica funciona, pero la calidad de las respuestas
no está validada. Se requiere revisar la configuración antes
de dar por aprobada esta etapa.

## Ajuste exploratorio — Mensaje de sistema separado

- llama.cpp: build 12407.
- Commit: e574a17b062be51b98e239ccd3d3743e3d902333.
- Compilador: Clang 21.1.8, Android aarch64.
- Cambio: instrucciones en --system-prompt y pregunta en -p.
- Contexto: 1024 tokens.
- Salida máxima: 96 tokens.
- Pensamiento: desactivado.
- Pregunta: ¿Qué diferencia hay entre transcribir voz y sintetizar voz?
- Respuesta: La transcripción de voz convierte el sonido en texto escrito para una copia digital, mientras que la síntesis convierte el texto escrito en el sonido audible para una reproducción.
- Tiempo total: 8975 ms.
- Procesamiento del prompt: 51,1 tokens/s.
- Generación: 7,4 tokens/s.
- Memoria pico del proceso: 1250560 KB.
- Código de salida: 0.
- Evaluación: correcta en la distinción principal, breve y en español.

Mejora frente a la pregunta 3 original. Una sola ejecución, sin
controlar la aleatoriedad, no permite atribuir la mejora únicamente
a la separación del mensaje de sistema.

## Ajuste exploratorio — RAM y almacenamiento

- Configuración: instrucciones en --system-prompt y pregunta en -p.
- Pregunta: ¿Qué diferencia hay entre memoria RAM y almacenamiento?
- Respuesta: La memoria RAM (memoria RAM) es temporal y se usa para el procesamiento activo de datos en tiempo real, mientras que el almacenamiento (SSD o HDD) se almacena permanentemente para guardar datos que no se están procesando.
- Tiempo total: 10560 ms.
- Procesamiento del prompt: 44,1 tokens/s.
- Generación: 7,9 tokens/s.
- Memoria pico del proceso: 1250588 KB.
- Código de salida: 0.
- Evaluación: correcta en la distinción principal, con redacción imprecisa.
- Observaciones: repite «memoria RAM»; el almacenamiento conserva datos al apagar el equipo, pero no garantiza conservación permanente y también puede contener datos en uso.
- Mejora: desaparece la afirmación anterior de que la RAM está en la CPU.

## Ajuste exploratorio — Ejecución secuencial

- Configuración: instrucciones en --system-prompt y pregunta en -p.
- Pregunta: ¿Por qué ejecutar tres modelos uno después del otro puede reducir el consumo máximo de memoria?
- Respuesta: El consumo máximo de memoria suele bajar porque las imágenes se procesan en bloques de datos pequeños (4K) que se optimizan para la velocidad y tamaño de cada paso, mientras que el GPU puede ejecutar múltiples modelos en paralelo sin que necesite almacenar todos los datos de los modelos anteriores.
- Tiempo total: 11916 ms.
- Procesamiento del prompt: 49,0 tokens/s.
- Generación: 8,0 tokens/s.
- Memoria pico del proceso: 1250572 KB.
- Código de salida: 0.
- Evaluación: incorrecta; introduce imágenes, bloques 4K y paralelismo sin fundamento.
- Corrección: terminar cada proceso antes de iniciar el siguiente evita mantener simultáneamente los tres modelos y sus recursos en memoria.

Separar el mensaje de sistema no resuelve todos los errores.
La calidad del modelo sigue pendiente de validación.

## Ajuste exploratorio — Muestreo recomendado por Qwen

- Pregunta: ¿Por qué ejecutar tres modelos uno después del otro puede reducir el consumo máximo de memoria?
- Configuración: mensaje de sistema separado; pensamiento desactivado.
- Contexto: 1024 tokens; salida máxima: 96 tokens.
- Muestreo: temp=1.0, top-p=1.0, top-k=20, min-p=0.0,
  presence-penalty=2.0, repeat-penalty=1.0.
- Respuesta: No es cierto; generalmente los programas ejecutamos en paralelo para evitar que toda la RAM se use simultáneamente cada vez.
- Tiempo total: 8342 ms.
- Procesamiento del prompt: 43,0 tokens/s.
- Generación: 7,0 tokens/s.
- Memoria pico del proceso: 1250436 KB.
- Código de salida: 0.
- Evaluación: incorrecta; atribuye al paralelismo una reducción de la memoria simultánea.
- Corrección: finalizar cada proceso antes de iniciar el siguiente evita mantener los tres modelos y sus recursos simultáneamente.

Este ajuste no corrigió la respuesta. La causa de los errores
no está determinada y la calidad del SLM sigue sin aprobarse.

## Diagnóstico del prompt efectivo

- Mensaje system: recibido con las instrucciones indicadas.
- Mensaje user: recibido con la pregunta indicada.
- Inicio assistant: presente.
- Bloque de pensamiento: vacío y cerrado antes de responder.
- Presupuesto de razonamiento: 0.
- Límite de generación del diagnóstico: 1 token.
- Salida: La.
- Finalización: length, coherente con el límite de un token.
- Código de salida: 0.
- Tiempo: 4469 ms.
- Memoria pico del proceso: 1248272 KB.

No se observa un defecto de separación de roles en esta prueba.
Este resultado no determina la causa de los errores de calidad.
Los parámetros de muestreo de este diagnóstico eran los predeterminados;
no corresponden a la prueba previa con el muestreo recomendado por Qwen.
