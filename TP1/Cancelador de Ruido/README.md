**Cancelador activo de ruido acústico** 


**Descripción**

El presente proyecto consiste en la implementacion de un cancelador activo de ruido acustico
\(tambien conocido como ANC por sus siglas en ingles)\ .
Para su implementacion se usara una placa EDU-CIAA, 2 microfonos, un parlante y 2 pulsador para indicar el modo.

El dispositivo empieza en un estado de reposo en el que se elige el modo de operacion deseado /( puede ser Feedback o Feedforward)/.
De acuerdo al modo elegido, se activiran los microfonos correspondientes para la recepcion de la señal deseada.
La placa EDU-CIAA seguira recibiendo la señal mientras la tension de offset de esta no sea nula.
Una vez que la tension de offset sea nula se procedera al calculo de la respuesta impulsiva del sistema 
parlante/microfono. Luego de ser calculada se pasa a la fase de control. En esta fase se implementa un
loop infinito en el que la señal de control es continuamente actualizada y se activa el parlante para transmitir
esta señal. Este loop infinito solo puede ser detenido mediante una señal de Stop implementada con un pulsador, la cual devuelve al dispositivo a su estado
original y se cesa de transmitir la señal anti-ruido.

Este documento detalla el funcionamiento de este proyecto, acompañado por imagenes para facilitar su comprension.

**Estados**

INICIO; Estado en el que el dispositivo se inicializa.

MODO FEEDBACK; Estado en el que el sistema inicializa los perifericos correspondientes al modo Feedback.

MODO FEEDFORWARD; Estado en el que el sistema inicializa los perifericos correspondientes al modo Feedforward.


ANALISIS CAMINO SECUNDARIO; Estado en el que se identifica la respuesta impulsiva del sistema mediante generación de ruido blanco.

CONTROL; Estado en el que se emite la señal de control de ruido.

**Estados LED**

ENCENDIDO; El LED se encuentra encendido.

REPOSO; El LED se encuentra en reposo.

TITILA; El LED esta titilando.

APAGADO; El LED se encuentra apagado.

**Eventos**

in event evModoFeedback; Evento en el que se selecciona el modo Feedback.

in event evModoFeedForward; Evento en el que se selecciona el modo Feedforward.

in event evOffsetOK; Evento en el que el offset de la señal es nulo.

in event evBiasMeasureFAIL; Evento en el que el offset de la señal es distinto de cero.

in event evStop; Evento en el que se envia una señal de stop para dejar de emitir la señal de control.

in event evConvergenceOK; Evento en el que el algoritmo LMS converge de manera exitosa.

in event evConvergenceFAIL; Evento en el que el algoritmo LMS no converge de manera exitosa.

**Operaciones**

operation opManejarMicrofono(Action:boolean, Status:boolean):void; Operacion utilizada para apagar o prender el microfono.

operation opLED(LEDNumber:integer,State:boolean): void; Operacion utilizada para apagar o prender un LED.

operation opManejarParlante(Action:boolean, Status:boolean):void; Operacion utilizada para apagar o prender el parlante.

**Constantes**

const LED_ON: boolean = true; Constante que indica que el LED esta prendido.

const LED_OFF: boolean = false; Constante que indica que el LED esta apagado.

const LED_VERDE: integer = 0; Constante que indica el LED verde.

const LED_AMARILLO: integer = 1; Constante que indica el LED amarillo.

const LED_ROJO: integer = 2; Constante que indica el LED rojo.

const ON: boolean = true; Constante que indica que el periferico esta prendido.

const OFF: boolean = true; Constante que indica que el periferico esta apagado.

const MICRO_SENAL: boolean = true; Constante usada para identificar el microfono que toma la señal contaminada con ruido.

const MICRO_RUIDO: boolean = true; Constante usada para identificar al microfono que toma la referencia del ruido.

const PARLANTE: boolean = true; Constante usada para identificar al parlante que reproduce la señal de control.

**Señales**

event titilarLEDAmarillo; Señal para indicar que el LED amarillo debe titilar

event noTitilarLEDAmarillo; Señal para indicar que el LED amarillo debe dejar de titilar

event prenderLEDVerde; Señal para prender el LED verde

event apagarLEDVerde; Señal para apagar el LED verde

event prenderLEDRojo; Señal para prender el LED rojo

event apagarLEDRojo; Señal para apagar el LED verde

**Implentación en el MCU Express**

IMAGEN DE PRUEBA, NO DARLE BOLA

![imagen](https://user-images.githubusercontent.com/65372063/82520354-52ceaf80-9afa-11ea-9eea-9773003a05aa.png)


