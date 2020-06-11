# **Documentación de app.c**


## **Secuencia de funciones**

INSERTE IMAGEN DE SECUENCIA

## **Funciones**

**boardConfig();**: Macro definida en sapi_board.h . Se trata de una macro a función 
encargada de llamar a  la función boardInit.

**void boardInit(void)**: Esta función se encuentra en el archivo sapi_board.c . Es la 
encargada de inicializar y setear la placa.
Esto consiste en inicializar el clock de la placa y setearlo e inicializar y
 configurar los pines GPIO de entrada y de salida.
 

**void delay( tick_t duration_ms );**: Esta funcion esta definida en sapi_delay.c . Es
la encargada de producir un delay del tiempo que se le pase como parametro en
milisegundos. Dentro de esta funcion se llama a tickRead().

**tick_t tickRead( void );**: Esta funcion esta definida en sapi_tick.c . Se encarga de
devolver el tiempo de clock de la placa en forma de ticks.

**bool_t gpioRead( gpioMap_t pin );**: Esta funcion esta definida en sapi_gpio.c . 
Se encarga de leer el pin deseado. Para esto utiliza la funcion gpioObtainPinInit() y
Chip_GPIO_ReadPortBit() para leer el estado GPIO del pin.


**static void gpioObtainPinInit( gpioMap_t pin,
                               int8_t *pinNamePort, int8_t *pinNamePin,
                               int8_t *func, int8_t *gpioPort,
                               int8_t *gpioPin )**
							   
Esta funcion esta definida en sapi_gpio.c . Es la que se dedica a cargar los 
parametros deseados a partir del dato pin. Usa la biblioteca gpioPinsInit[] para
realizar esta tarea. 


**bool_t gpioWrite( gpioMap_t pin, bool_t value );** : Esta funcion esta definida en sapi_gpio.c . 
Se encarga de escribir el pin deseado. Para esto utiliza la funcion gpioObtainPinInit() y
Chip_GPIO_SetPinState() para setear el estado GPIO del pin.

**bool_t gpioToggle( gpioMap_t pin )**; : Esta funcion esta definida en sapi_gpio.c . 
Esta funcion utiliza gpioWrite() para alternar el estado del pin deseado.


**bool_t gpioInit( gpioMap_t pin, gpioInit_t config );** : Esta funcion esta 
definida en sapi_gpio.c . Es la encargada de inicializar el pin deseado con la configuracion indicada.
Utiliza la funcion Chip_GPIO_Init() para incializar el pin, Chip_SCU_PinMux() para configurar el funcionamiento
del pin, Chip_GPIO_SetDir() para setear la direccion a un puerto GPIO y Chip_GPIO_SetPinState()
para setear el estado GPIO del pin.

## **Datos**

### **app.c**

**bool_t buttonValue** : Constante booleana encargada de almacenar el valor del boton.

**bool_t ledValue**   : Constante booleana encargada de almacenar el valor de LED.

**tick_t timeCount**  : Constante usada para contar el tiempo.

### **sapi_gpio.c**

**const pinInitGpioLpc4337_t gpioPinsInit[]**: Diccionario donde se guardan las configuraciones para cada uno
de los pines GPIO.


### **sapi_gpio.h**
```
typedef enum {
   GPIO_INPUT, GPIO_OUTPUT,
   GPIO_INPUT_PULLUP, GPIO_INPUT_PULLDOWN,
   GPIO_INPUT_PULLUP_PULLDOWN,
   GPIO_ENABLE
} gpioInit_t;
```
Tipo enumerativo donde se describen los distintos modos de configuracion de los GPIO.

```
typedef struct {
   pinInitLpc4337_t pinName;
   int8_t func;
   gpioInitLpc4337_t gpio;
} pinInitGpioLpc4337_t;
```
Tipo enumerativo donde se describen

```
typedef struct {
   int8_t port;
   int8_t pin;
} gpioInitLpc4337_t;
```
Tipo enumerativo donde se describen

### **sapi_peripheral_map.h**

```
typedef enum {

   // Configure GPIO pins for each board

   #if (BOARD == ciaa_nxp)
      VCC = -2, GND = -1,
      // Born
      DI0,   DI1,   DI2,   DI3,   DI4,   DI5,   DI6,   DI7,
      DO0,   DO1,   DO2,   DO3,   DO4,   DO5,   DO6,   DO7,
      // P12 header
      GPIO0, GPIO1, GPIO2, GPIO3, GPIO7, GPIO8, 
      // P14 header
      SPI_MISO, SPI_MOSI, SPI_CS,
      //#error CIAA-NXP

   #elif (BOARD == edu_ciaa_nxp)
      VCC = -2, GND = -1,
      // P1 header
      T_FIL1,    T_COL2,    T_COL0,    T_FIL2,      T_FIL3,  T_FIL0,     T_COL1,
      CAN_TD,    CAN_RD,    RS232_TXD, RS232_RXD,
      // P2 header
      GPIO8,     GPIO7,     GPIO5,     GPIO3,       GPIO1,
      LCD1,      LCD2,      LCD3,      LCDRS,       LCD4,
      SPI_MISO,
      ENET_TXD1, ENET_TXD0, ENET_MDIO, ENET_CRS_DV, ENET_MDC, ENET_TXEN, ENET_RXD1,
      GPIO6,     GPIO4,     GPIO2,     GPIO0,
      LCDEN,
      SPI_MOSI,
      ENET_RXD0,
      // Switches
      // 36   37     38     39
      TEC1,  TEC2,  TEC3,  TEC4,
      // Leds
      // 40   41     42     43     44     45
      LEDR,  LEDG,  LEDB,  LED1,  LED2,  LED3,
      //#error EDU-CIAA-NXP
   #else
      #error BOARD not supported yet!
   #endif
} gpioMap_t;
```

```
typedef struct {
   int8_t port;
   int8_t pin;
} pinInitLpc4337_t;
```





















