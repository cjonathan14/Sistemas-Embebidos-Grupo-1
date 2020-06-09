# TP2: Entradas y salidas (digitales) de propósito general (GPIO)

## Migracion

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

Chip_SCU_PinMux(uint8_t **port**, uint8_t **pin**, uint16_t **mode**, uint8_t **func**)

Esta función escribe **mode | func** en el registro SFSP correspondiente al pin **port | pin**.

Existen MACROS definidas en la biblioteca para simplificar el uso de la función. Por ejemplo, para inicializar el pin con la función **func**, sin resistores de pull-up / pull-down, con el buffer de entrada activo y el glitch filter deshabilitado:

```
Chip_SCU_PinMux ( pinNamePort, 
pinNamePin, 
SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS,
func );
```



## GPIO


## Documentacion de nuestro codigo (renombrar titulo)



# Notas y cosas por hacer

Chip_GPIO_Init(LPC_GPIO_PORT); --> Configuracion inicial de GPIO


Chip_GPIO_SetDir( LPC_GPIO_PORT, gpioPort, ( 1 << gpioPin ), GPIO_INPUT/OUTPUT ); --> Configura el GPIO

Chip_GPIO_SetPinState( LPC_GPIO_PORT, gpioPort, gpioPin, value); --> Escribe en GPIO // Primer argumento: dirección física del puerto. Se usa siempre esa macro

(bool_t) Chip_GPIO_GetPinState( LPC_GPIO_PORT, gpioPort, gpioPin ); --> Lee de GPIO



Por hacer:

Sacar los #if, si es necesario

Nota:

La funcion ObtainPin es static, o sea que tiene alcance limitado: solo puede verse en el .c al que pertenece. Eso es para tener como mas "privacidad" para la estructura, ObtainPin es la unica funcion que accede a ella. Ademas, como la funcion es local al .c, no se define en el .h, para que no se vea desde afuera.
