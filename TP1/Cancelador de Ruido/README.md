# **Cancelador activo de ruido acústico**


## **Descripción**

El presente proyecto consiste en la implementación de un cancelador activo de ruido acústico
\(también conocido como ANC por sus siglas en inglés)\ .
Para su implementación se usara una placa EDU-CIAA, 2 micrófonos, un parlante y 2 pulsador para indicar el modo.

El dispositivo empieza en un estado de reposo en el que se elige el modo de operación deseado /( puede ser Feedback o Feedforward)/.
De acuerdo al modo elegido, se activarán los micrófonos correspondientes para la recepcion de la señal deseada.
La placa EDU-CIAA seguira recibiendo la señal mientras la tension de offset de esta no sea nula.
Una vez que la tension de offset sea nula se procedera al calculo de la respuesta impulsiva del sistema 
parlante/microfono. Luego de ser calculada se pasa a la fase de control. En esta fase se implementa un
loop infinito en el que la señal de control es continuamente actualizada y se activa el parlante para transmitir
esta señal. Este loop infinito solo puede ser detenido mediante una señal de Stop implementada con un pulsador, la cual devuelve al dispositivo a su estado
original y se cesa de transmitir la señal anti-ruido.

Este documento detalla el funcionamiento de este proyecto, acompañado por imágenes para facilitar su comprensión.

## **Estados**

REPOSO; Estado en el que el dispositivo se inicializa.

INICIALIZACION; Estado en el que el sistema inicializa los periféricos y carga los datos correspondientes a su modo.

ANALISIS CAMINO SECUNDARIO; Estado en el que se identifica la respuesta impulsiva del sistema mediante generación de ruido blanco.

CONTROL; Estado en el que se emite la señal de control de ruido.

## **Estados LED**

ENCENDIDO; El LED se encuentra encendido.

REPOSO; El LED se encuentra en reposo.

TITILA; El LED esta titilando.

APAGADO; El LED se encuentra apagado.

## **Estados Modo**

FEEDBACK; Estado en el que se se habilitan los periféricos correspondientes al modo Feedback.

FEEDFORWARD; Estado en el que se se habilitan los periféricos correspondientes al modo Feedforward.

## **Eventos**

in event evModo; Evento en el que se selecciona el modo.

in event evOffsetOK; Evento en el que el offset de la señal es nulo.

in event evOffsetERROR; Evento en el que el offset de la señal es distinto de cero.

in event evStartStop; Evento en el que se envia una señal de star o de stop para dejar de emitir la señal de control.

in event evConvergenceOK; Evento en el que el algoritmo LMS converge de manera exitosa.

in event evConvergenceFAIL; Evento en el que el algoritmo LMS no converge de manera exitosa.

## **Operaciones**

operation opManejarMicrofono(Action:boolean, Status:boolean):void; Operación utilizada para apagar o prender el micrófono.

operation opLED(LEDNumber:integer,State:boolean): void; Operación utilizada para apagar o prender un LED.

operation opManejarParlante(Action:boolean, Status:boolean):void; Operación utilizada para apagar o prender el parlante.

operation opInicVectores(modo:integer):void; Operación utilizada para inicializar los vectores de datos correspondientes al modo elegido.

## **Constantes**

const LED_ON: boolean = true; Constante que indica que el LED esta prendido.

const LED_OFF: boolean = false; Constante que indica que el LED esta apagado.

const LED_VERDE: integer = 0; Constante que indica el LED verde.

const LED_AMARILLO: integer = 1; Constante que indica el LED amarillo.

const LED_ROJO: integer = 2; Constante que indica el LED rojo.

const ON: boolean = true; Constante que indica que el periférico esta prendido.

const OFF: boolean = true; Constante que indica que el periférico esta apagado.

const MICRO_SENAL: boolean = true; Constante usada para identificar el micrófono que toma la señal contaminada con ruido.

const MICRO_RUIDO: boolean = true; Constante usada para identificar al micrófono que toma la referencia del ruido.

const PARLANTE: boolean = true; Constante usada para identificar al parlante que reproduce la señal de control.

const REPOSO:boolean = falsada; Constante usada para indicar que el dispositivo se encuentra en estado de reposo.

const PROCESANDO:boolean = true; Constante usada para indicar que el dispositivo se encuentra procesando.

const FEEDBACK:integer = 1; Constante que indica el modo Feedback.

const FEEDFORWARD:integer = 2; Constante que indica el modo Feedforward.

## **Variables**

var estado: boolean; Variable usada para indicar el estado del dispositivo.

## **Señales**

event titilarLEDAmarillo; Señal para indicar que el LED amarillo debe titilar

event noTitilarLEDAmarillo; Señal para indicar que el LED amarillo debe dejar de titilar

event prenderLEDVerde; Señal para prender el LED verde

event apagarLEDVerde; Señal para apagar el LED verde

event prenderLEDRojo; Señal para prender el LED rojo

event apagarLEDRojo; Señal para apagar el LED verde

## **Variables internas**

var viModo: integer; Variable usada para indicar el modo seleccionado.

## **Implentación en el MCU Express**


![Modo de cancelacion](https://user-images.githubusercontent.com/65372063/82596832-64f23180-9b7e-11ea-8a15-f91ee1ad3c69.png)

![LED Verde](https://user-images.githubusercontent.com/65372063/82596520-ccf44800-9b7d-11ea-9b41-f006491f03fb.png)

![LED Rojo](https://user-images.githubusercontent.com/65372063/82596711-29effe00-9b7e-11ea-997d-ef927f7510e1.png)

![LED Amarillo](https://user-images.githubusercontent.com/65372063/82596804-53108e80-9b7e-11ea-8a77-94679370dd1a.png)

