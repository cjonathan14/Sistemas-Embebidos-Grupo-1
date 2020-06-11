# TP2: Entradas y salidas (digitales) de propósito general (GPIO)

## System Control Unit (SCU)

La unidad de control del sistema determina la función y el modo eléctrico de la mayoría de los pines digitales. Algunos pines también soportan funciones analógicas y son manejados por la misma unidad.

El esquema general de un pin sontrolado por la SCU se muestra en la figura siguiente

![](https://user-images.githubusercontent.com/38143566/84207295-6a5ce080-aa87-11ea-8fff-72878b23c3c6.png)

### Configuración

Las partes configurables más importantes de la SCU son las siguientes:

#### Función

Cada pin soporta hasta 8 funciones digitales, y en algunos casos 1 extra analógica. Salvo en el caso de las GPIO, la función decide si el pin funciona como entrada y salida.

#### Modo

Cada pin cuenta con un resistor pull-up y uno pull-down. El pin tiene 4 opciones: con resistor de cull-up, de pull-down, sin ninguno de los 2 y en modo repetidor. En este último modo ambos resistores están activos, provocando que se conserve el último estado conocido del pin y no quede "flotando" cuando no está siendo controlado.

#### Buffer de entrada

Se utiliza para almacenar el valor digital leído. Debe estar activado si el pin se utiliza para entrada digital, y desactivado si se utiliza para funciones analógicas.

Existen otras configuraciones, pero no son fundamentales en esta aplicación.


### Registros

La SCU cuenta con un registro de 4 bytes por cada pin, llamado SFSP. En los pines normales (normal-drive pins), tiene el siguiente contenido

![](https://user-images.githubusercontent.com/38143566/84207333-8c566300-aa87-11ea-967d-15828a184604.png)

MODE: Permite seleccionar la función del pin.

EPD: Activar y desactivar el resistor de pull-down.

EPUN: Activar y desactivar el resistor de pull-up.

EZI: Activar y desactivar el buffer de entrada.


### Funciones 

El fabricante del microcontrolador ofrece una biblioteca para el manejo de la SCU: scu_18xx_43xx. Esta bibliteca cuenta con varias funciones, de las cuales solo se usa una en este proyecto:

```
Chip_SCU_PinMux(uint8_t **port**, uint8_t **pin**, uint16_t **mode**, uint8_t **func**)
```

Esta función escribe **mode | func** en el registro SFSP correspondiente al pin **port | pin**.

Existen MACROS definidas en la biblioteca para simplificar el uso de la función. Por ejemplo, para inicializar el pin con la función **func**, sin resistores de pull-up / pull-down, con el buffer de entrada activo y el glitch filter deshabilitado:

```
Chip_SCU_PinMux ( pinNamePort, 
pinNamePin, 
SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS,
func );
```



## GPIO

El microcontrolador cuenta con un bloque de entradas y salidas de propósito general (GPIO) que cuenta con sus propios registros. A partir de los registros de GPIO puede configurarse un pin como entrada y salida, leer y escribir valores, y habilitar y configurar interrupciones. La conexión de los pines de GPIO a los pines físicos está controlada por la SCU.

La unidad de GPIO cuenta con 7 puertos, con una cantidad variable de pines de hasta 31 cada uno. Por cada pin existe un bit de salida, que configurado correctamente se escribirá sobre un pin físico del microcontrolador.


### Registros

El registro que se utiliza para configurar un pin como entrada o salida dentro del bloque de GPIO es **DIR**. El microcontrolador cuenta con un registro DIR por cada puerto, cuyo bit **m** configura el pin **m** correspondiente.

![](https://user-images.githubusercontent.com/38143566/84331192-f4787800-ab5f-11ea-827c-acb9f8382d09.png)

Existen numerosos registros para leer y escribir: puede realizarse lectura/escritura de un pin, de un puerto con o sin máscara, entre otras opciones. En este proyecto solo se utiliza el registro **B**. Existe un registro **B** por cada pin de GPIO y puede utilizarse tanto para leer como para escribir.

![](https://user-images.githubusercontent.com/38143566/84331220-065a1b00-ab60-11ea-8e5d-dc8a434db3a6.png)

Como se menciona en la tabla, al leer el registro se obtiene el estado del pin correspondiente; mientras que al escribirlo se carga el valor en el bit de salida.


### Leer y escribir

Cada pin cuenta con un bit de salida en el bloque de GPIO, que es escrito por ejemplo al actualizar el registro **B**. Para llevar este bit de salida hasta el pin físico es necesario realizar 2 pasos:

* Configurar en la SCU el pin como GPIO.
* Seleccionar el pin como salida en el registro DIR de su puerto correspondiente.

Para leer un bit de entrada solo es necesario que se configure el pin como entrada en **DIR** y esté activado el buffer de entrada en el SCU. No es necesario que se seleccione la función GPIO. La lectura de un valor puede hacerse por medio del registro **B**.


### Funciones

El fabricante del microcontrolador ofrece una biblioteca para el manejo del módulo de GPIO: **gpio_18xx_43xx**. Esta biblioteca cuenta con varias funciones, de las cuales se utilizan solamente 4:

```
void Chip_GPIO_Init(LPC_GPIO_T *pGPIO)
```

Inicializa las GPIO. En un principio no hace nada, pero puede modificarse para establecer una configuración inicial.

```
STATIC INLINE void Chip_GPIO_SetDir(LPC_GPIO_T *pGPIO, uint8_t portNum, uint32_t bitValue, uint8_t out)
```

Configura un pin como entrada o salida, es decir, escribe el registro DIR. 

pGPIO es la dirección en la que comienzan los registros de GPIO (0x400F4000). 

El valor de bitValue es una máscara con un 1 en el bit que se desea configurar. Es decir **bitValue = ( 1 << gpio_pin )**.

El valor **out = 1** configura el pin como salida, mientras que **out = 0** corresponde a entrada.

```
STATIC INLINE void Chip_GPIO_SetPinState(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin, bool setting)
```

Escribe en el bit de salida el valor de **setting** utilizando el registro **B**.

```
STATIC INLINE bool Chip_GPIO_GetPinState(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin)
```

Lee el valor de **pin** a través del registro **B**.


## Documentacion del código

Se define un tipo enumerativo que contiene todos los posibles GPIOs.
```
typedef enum {
	MY_GPIO_INPUT, MY_GPIO_OUTPUT,
	MY_GPIO_INPUT_PULLUP, MY_GPIO_INPUT_PULLDOWN,
	MY_GPIO_INPUT_REPEATER,
	MY_GPIO_ENABLE
} my_gpioInit_t;
```

La siguiente estructura contiene el pin y el puerto del SCU y GPIO que se va a configurar.

```
typedef struct {
	int8_t scu_port;
	int8_t scu_pin;
	int8_t func;
	int8_t gpio_port;
	int8_t gpio_pin;
} my_conf_t;
```
Es un vector que contiene la información de los pines y funciones del SCU y GPIO que se usan para manejar los leds de la placa. Se utiliza una compilación condicional para las distintas placas. En este casi se utiliza la placa edu_ciaa_nxp.

```
const my_conf_t my_gpio_pinsInit[] = {

   //{ SCUPortN ,SCUNamePinN, PinFUNC, gpioPortN, gpioPinN }

   #if BOARD==edu_ciaa_nxp

      { 2, 0, FUNC4, 5, 0 },   // LEDR    LED0_R
      { 2, 1, FUNC4, 5, 1 },   // LEDG    LED0_G
      { 2, 2, FUNC4, 5, 2 },   // LEDB    LED0_B
      { 2,10, FUNC0, 0,14 },   // LED1    LED1
      { 2,11, FUNC0, 1,11 },   // LED2    LED2
      { 2,12, FUNC0, 1,12 },   // LED3    LED3
	   { 1, 0, FUNC0, 0, 4 },   // TEC1    TEC_1
      { 1, 1, FUNC0, 0, 8 },   // TEC2    TEC_2
      { 1, 2, FUNC0, 0, 9 },   // TEC3    TEC_3
      { 1, 6, FUNC0, 1, 9 },   // TEC4    TEC_4
	   { 6, 1, FUNC0, 3, 0 },   // CON2_29   GPIO0
	   { 6, 5, FUNC0, 3, 4 },   // CON2_31   GPIO2

	#elif BOARD==ciaa_nxp
	   #error CIAA-NXP

    #elif BOARD==ciaa_z3r0
       #error CIAA-Z3R0

    #elif BOARD==pico_ciaa
       #error PicoCIAA

   #else
      #error BOARD compile variable must be defined

   #endif

};
```
Mediante esta función se obtienen todos los datos necesarios del pin que se va a configurar. 
```
static void my_gpioObtainPinInit( my_gpioMap_t pin,
                               int8_t *scu_port, int8_t *scu_pin,
                               int8_t *func, int8_t *gpio_port,
                               int8_t *gpio_pin )
```

Esta función recibe como parametros el pin a configurar y su configuración. Si la configuración es invalida retorna FALSE. 
```
bool_t my_gpioInit( my_gpioMap_t pin, my_gpioInit_t config )
```

Esta función se encarga de la configuración del pin SCU recibiendo como parametros el puerto, el pin, su modo de configuración y la función del pin. 
```
Chip_SCU_PinMux(
		 scu_port,
		 scu_pin,
		 SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS,
		 func
	  );
```

Aquí se configura el pin del GPIO como salida o entrada. En este caso esta configurado como entrada. Recibe como parametros el registro GPIO , el puerto y el valor del bit.
```
Chip_GPIO_SetDir( LPC_GPIO_PORT, gpio_port, ( 1 << gpio_pin ), INPUT_PORT )
```
Luego se setea el estado del pin, esta función recibe como parametros el registro GPIO, el puerto, el pin y el nivel lógico.
```
Chip_GPIO_SetPinState( LPC_GPIO_PORT, gpio_port, gpio_pin, 0);
```

# Notas y cosas por hacer

Chip_GPIO_Init(LPC_GPIO_PORT); --> Configuracion inicial de GPIO


Chip_GPIO_SetDir( LPC_GPIO_PORT, gpioPort, ( 1 << gpioPin ), GPIO_INPUT/OUTPUT ); --> Configura el GPIO

Chip_GPIO_SetPinState( LPC_GPIO_PORT, gpioPort, gpioPin, value); --> Escribe en GPIO // Primer argumento: dirección física del puerto. Se usa siempre esa macro

(bool_t) Chip_GPIO_GetPinState( LPC_GPIO_PORT, gpioPort, gpioPin ); --> Lee de GPIO



Por hacer:

Sacar los #if, si es necesario

Nota:

La funcion ObtainPin es static, o sea que tiene alcance limitado: solo puede verse en el .c al que pertenece. Eso es para tener como mas "privacidad" para la estructura, ObtainPin es la unica funcion que accede a ella. Ademas, como la funcion es local al .c, no se define en el .h, para que no se vea desde afuera.
