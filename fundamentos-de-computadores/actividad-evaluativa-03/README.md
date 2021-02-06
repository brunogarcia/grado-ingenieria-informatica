# Actividad Evaluativa #3

## Circuito

[Circuito Logisim](./circuito-logisim.circ)

![Circuito Logisim](./circuito-imagen.png?raw=true)

## Instrucciones

Implemente un sistema digital que controle el funcionamiento de un semáforo para un cruce de
peatones. Para ello, deberá diseñar dos contadores, cuya función será definir los tiempos durante el
cual las luces verde y roja permanecerán encendidas según sea el caso.

El sistema deberá mostrar junto a la luz verde, el tiempo (en segundos) que falta para que se encienda la luz roja, orientando ası́ a los peatones que van cruzando la calle en cada momento. De igual forma, cuando se active la luz roja, deberá mostrarse a los peatones el tiempo que falta hasta poder cruzar. 

Diseñe dos contadores sincrónicos descendentes: el primero que comenzando por el número 12, disminuye su valor por cada segundo transcurrido, hasta llegar a 0. Una vez en 0, se activará de forma automática el segundo contador (mientras se detiene el primero), que comenzará el descuento desde el número 24, hasta llegar a 0, entrando en un ciclo repetitivo ambos contadores.

Utilice para el diseño biestables tipo D cuya tabla de excitación se muestra debajo.

Emplee 4 displays 7-segmentos para visualizar el valor actual de cada contador, en función de la luz (verde o roja) encendida en cada momento.


Opcional: Añada una luz amarilla que se active los últimos 3 segundos asociados a la luz roja, y
se apague al activarse la luz verde. Esta luz irá en la parte del semáforo correspondiente a los coches, la cuales funcionan intercambiando las luces rojas y verdes del peatón. Puede usar/diseñar un solo contador para ambas luces, siempre y cuando el sistema funcione tal y como se pide en el enunciado.