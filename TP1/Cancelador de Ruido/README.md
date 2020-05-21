**Cancelador activo de ruido acústico** 


**Descripción**

**Estados**

INICIO;

MODO FEEDBACK;

MODO FEEDFORWARD;

ANALISIS CAMINO SECUNDARIO;

CONTROL;

**Estados LED**

ENCENDIDO;

REPOSO;

TITILA;

**Eventos**

in event evModoFeedback;

in event evModoFeedForward;

in event evOffsetOK;

in event evBiasMeasureFAIL;

in event evStop;

in event evConvergenceOK;

in event evConvergenceFAIL;

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

