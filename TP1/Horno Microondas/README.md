# TP1: Horno Microondas

## Enunciado

Las especificaciones se muestran en el enunciado:

![](https://user-images.githubusercontent.com/38143566/82250233-72f74680-9921-11ea-913d-947f2c95f483.jpg)

## Solución

### Eventos y operaciones

* Eventos

in event evModo // Pulsador de cambio de modo

in event evStartStop // Pulsador de encendido/apagado

in event evPuertaAbierta // Se activa cuando se abre la puerta

in event evPuertaCerrada // Se activa cuando se cierra la puerta

* Operaciones

operation aEncerderLuz():void // Enciende la luz interior del horno

operation aApagarLuz():void // Apaga la luz interior del horno

operation aLed(modo:integer):void // Enciende y apaga el LED que indica el modo de funcionamiento

operation aEnciendeHorno(modo:integer):void // Enciende y apaga horno y grill


### Estados

Se utilizó una solución con 2 regiones:

* Main: Controla el encendido del horno. Tiene 3 estados: FUNCIONAMIENTO, RESPOSO y PUERTA ABIERTO.

* Modo: Controla el modo de funcionamiento. Tiene 3 estados: HORNO, GRILL, HORNO+GRILL.

La región "Modo" no hace más que settear una variable que indica el modo en que el microondas debe funcionar. El modo de funcionamiento no puede cambiar si el horno está funcionando.

La región main utiliza la variable de modo para decidir cómo debe funcionar el microondas. El evento de puerta abierta lleva al estado correspondiente, y el evento de puerta cerrada devuelve al último estado. Para recordar el último estado se utiliza una variable. Puede utilizarse alternativamente un estado con historia, pero esto dificulta limitar el cambio de modo durante el funcionamiento, pues la variable utilizada tiene también ese fin.


### Statechart

#### Región main

![](https://user-images.githubusercontent.com/38143566/82251554-c7032a80-9923-11ea-9add-b634271035f7.png)

#### Región modo

![](https://user-images.githubusercontent.com/38143566/82251557-c8345780-9923-11ea-882f-178487a5d5d4.png)
