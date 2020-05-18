# TP1: Escalera mecánica

## Enunciado

![](https://user-images.githubusercontent.com/38143566/82247631-17c35500-991d-11ea-9891-ed4427b3cafc.jpg)

## Funcionamiento

La escalera solo se mueve en 1 sentido a la vez. Cuando se activa un sensor la escalera comienza a funcionar y deja de hacerlo cuando no hay más gente que transportar.

Para complejizar el sistema se agregaron 2 nuevas funcionalidades:

* Dos nuevos sensores: La escalera solo tiene 1 sentido, pero podría ocurrir que lleguen personas que quieran tomar el sentido opuesto. Para esto se añaden 2 nuevos sensores. Del total de 4, 2 serán utilizados por las personas que bajen y 2 por las que suben.

* Dos contadores: uno para bajada y otro para subida. Indican al sistema la cantidad de personas que están usando la escalera, o esperando para usarla en el sentido opuesto.

## Eventos

Dado que se cuenta con 4 sensores, se utilizan 4 eventos, cada uno asociado con la activación del detector.

**Sensores de bajada**:

in event evPersonaArriba // Se detecta una persona arriba que quiere bajar

in event evPersonaBajo // La persona que estaba arriba ya bajo

**Sensores de subida**:

in event evPersonaAbajo // Se detecta una persona abajo que quiere subir

in event evPersonaSubio // La persona que estaba abajo ya subio


## Operaciones

La única operación es la relacionada al motor de la cinta. Esta recibe 2 argumentos: El primero indica el sentido y el segundo el estado (on/off)

operation opMotor(Action:boolean, State:boolean):void

## Variables

Se utilizan solo 2 variables, que corresponden con los contadores antes mencionados.

var viPersonasBajando: integer // Indica la cantidad de personas bajando, o esperando para bajar

var viPersonasSubiendo: integer // Cantidad de personas subiendo, o esperando

## Constantes

const BAJAR:boolean = true

const SUBIR:boolean = false

const ON:boolean = true

const OFF:boolean = false

## Diagrama de estados

![](https://user-images.githubusercontent.com/38143566/82248977-6c67cf80-991f-11ea-992d-d7992db0c115.png)
