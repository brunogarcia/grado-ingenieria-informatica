# Actividad Evaluativa #2

## Circuito

[Circuito Logisim](./circuito-logisim.circ)

![Circuito Logisim](./circuito-imagen.png?raw=true)

## Instrucciones

El objetivo de la actividad consiste en implementar un sistema digital en el cual se
utilicen varios bloques combinacionales que realizarán diferentes funciones, para dar solución a un problema
determinado.

Para ello se emplearán las técnicas aprendidas relacionadas con el diseño y sı́ntesis de circuitos
combinacionales, empleando el álgebra de Boole y los Mapas de Karnaugh.

Una vez diseñado el sistema, se implementará el circuito digital con la herramienta LOGISIM para
simular su correcto funcionamiento. Se entregarán un documento (Word o PDF) con el desarrollo y
la descripción del diseño realizado (incluyendo todos los bloques diseñados), y el fichero “.circ” con la
implementación del sistema en LOGISIM.

## Ejercicio

Implementar un sistema digital que permita visualizar el resultado final de una pelea de boxeo, derivado de la decisión de 3 jueces. Cada juez emite una puntuación por cada púgil de hasta 5 puntos (0 - 5).

Por tanto, la puntuación máxima dada por los tres jueces puede ser de hasta 15 puntos
(0 15) por boxeador.

Se desea visualizar la puntuación obtenida por cada púgil mediante displays de
7-segmentos, en los cuales se mostrará un número entre 0 y 15. Cada púgil deberá contar con su propio display, diferenciándose por el color de sus segmentos (p.e. rojo y azul).

Por otro lado, se deberán proporcionar dos teclados para cada juez, mediante los cuales podrán introducir la puntuación de cada púgil. Finalmente, se debe indicar por medio de un visualizador (tipo LED) quien ha ganado el combate.

En caso de empate técnico (misma puntuación), el vencedor será determinado por consenso de los jueces, proporcionándose para ello dos pulsadores adicionales, uno para cada púgil, cuya posición determinará quien es el vencedor.