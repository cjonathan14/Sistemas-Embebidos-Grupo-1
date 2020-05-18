# TP1 - Porton Levadizo

## Enunciado

Implementar (editar,simular y generar el código) el modelo de Portón Levadizo automatizado (motor con movimiento en
dos sentidos,sensor de presencia y fines de carrera) 

### PASO 1
En el primer paso se deben identificar los eventos y las acciones.

#### Eventos
* Remoto
* Abrio
* Cerro

#### Acciones

* Motor
* Luz Roja
* Luz Verde


### PASO 2

En el segundo paso se deben identificar los estados

#### Estados

* Cerrado
* Cerrando
* Abriendo
* Abierto

* Apagada
* Titilar

* Apagada
* Encedida



## Implentación en el MCU Express

![portonlevadizo](https://user-images.githubusercontent.com/63314732/82165491-9ec7ed00-988b-11ea-807b-3cc37eb26b86.png)

 Se comienza en el estado CERRADO, donde la lus roja y luz verde se encuentran apagadas, al igual que el motor. Cuando se produce el evento
 Remoto, la luz roja comienza a titilar, se enciende la luz verde y pasa al estado ABRIENDO, donde el motor se encuentra en funcionamiento abriendo el porton.
 En este estado, se pueden producir dos eventos. El primero es el evento abrio, donde se produce una transicion al estado ABIERTO, en el cual el motor se apaga y el porton permanece abierto, con la luz roja titilando
 y la luz verde encedida. El otro evento es el remoto, es decir que mientras esta en estado abierto si se produce el evento remoto el porton estará en
 el estado CERRANDO, donde el motor se encuentra en funcionamiento cerrando el porton. La luz roja se encuentra titilando y la luz verde encendida.
 El estado ABIERTO tiene una transicion al estado CERRANDO, cuando se produce el evento remoto. Este estado, al igual que el estado ABRIENDO tiene dos eventos asociados. Si se produce el evento remoto tendrá una transición
 al estado ABRIENDO. Si se produce el evento CERRO, pasará al estado CERRADO, donde el motor deja de funcionar, la luz roja y verde se apagan.