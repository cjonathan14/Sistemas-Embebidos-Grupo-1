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


### **Datos**

### **Datos**

### **Datos**

### **Datos**























