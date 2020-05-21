**Cancelador activo de ruido acústico** 


**Descripción**

El presente proyecto consiste en la implementacion de un cancelador activo de ruido acustico
\(tambien conocido como ANC por sus siglas en ingles)\ .

**Estados**

INICIO; Estado en el que el dispositivo se inicializa

MODO FEEDBACK; Estado en el que el sistema inicializa los perifericos correspondientes al modo Feedback

MODO FEEDFORWARD; Estado en el que el sistema inicializa los perifericos correspondientes al modo Feedforward


ANALISIS CAMINO SECUNDARIO; Estado en el que se identifica la respuesta impulsiva del sistema mediante generación de ruido blanco

CONTROL; Estado en el que se emite la señal de control de ruido

**Estados LED**

ENCENDIDO; El LED se encuentra encendido 

REPOSO; El LED se encuentra en reposo

TITILA; El LED esta titilando

APAGADO; El LED se encuentra apagado

**Eventos**

in event evModoFeedback; Evento en el que se selecciona el modo Feedback

in event evModoFeedForward; Evento en el que se selecciona el modo Feedforward

in event evOffsetOK; Evento en el que el offset de la señal es nulo

in event evBiasMeasureFAIL; Evento en el que el offset de la señal es distinto de cero

in event evStop; Evento en el que se envia una señal de stop para dejar de emitir la señal de control

in event evConvergenceOK; Evento en el que el algoritmo LMS converge de manera exitosa

in event evConvergenceFAIL; Evento en el que el algoritmo LMS no converge de manera exitosa

**Operaciones**

operation opManejarMicrofono(Action:boolean, Status:boolean):void;

operation opLED(LEDNumber:integer,State:boolean): void;

operation opManejarParlante(Action:boolean, Status:boolean):void;

**Constantes**

const LED_ON: boolean = true;

const LED_OFF: boolean = false;

const LED_VERDE: integer = 0;

const LED_AMARILLO: integer = 1;

const LED_ROJO: integer = 2;

const ON: boolean = true;

const OFF: boolean = true;

const MICRO_SENAL: boolean = true;

const MICRO_RUIDO: boolean = true;

const PARLANTE: boolean = true;

**Señales**

event titilarLEDAmarillo;

event noTitilarLEDAmarillo;

event prenderLEDVerde;

event apagarLEDVerde;

event prenderLEDRojo;

event apagarLEDRojo;

**Implentación en el MCU Express**

