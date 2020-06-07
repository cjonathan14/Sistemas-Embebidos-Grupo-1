Chip_GPIO_Init(LPC_GPIO_PORT); --> Configuracion inicial de GPIO

Chip_SCU_PinMux(
         pinNamePort,
         pinNamePin,
         SCU_MODE_INACT/PULLUP/... | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS,  
		 // El unico argumento que cambia es el primero, para PULLUP, PULLDOWN
		// El segundo es el buffer de entrada, debe estar encendido para recibir informacion digital
		// El tercero es un filtro (todo esta en hoja de datos, 17.3: descripcion general)
         func
      ); --> Configura el SCU. Tambien hace pullup y pulldown

Chip_GPIO_SetDir( 
	LPC_GPIO_PORT, 
	gpioPort, 
	( 1 << gpioPin ), 
	GPIO_INPUT/OUTPUT ); --> Configura el GPIO

Chip_GPIO_SetPinState( LPC_GPIO_PORT, gpioPort, gpioPin, value); --> Escribe en GPIO
	// Primer argumento: dirección física del puerto. Se usa siempre esa macro


(bool_t) Chip_GPIO_GetPinState( LPC_GPIO_PORT, gpioPort, gpioPin ); --> Lee de GPIO


Modo repeater:

The repeater mode enables the pull-up resistor if the pin is at a logic HIGH and enables
the pull-down resistor if the pin is at a logic LOW. This causes the pin to retain its last
known state if it is configured as an input and is not driven externally. Repeater mode may
typically be used to prevent a pin from floating (and potentially using significant power if it
floats to an indeterminate state) if it is temporarily not driven.

Por hacer:

Sacar los #if, si es necesario

Nota:

La funcion ObtainPin es static, o sea que tiene alcance limitado: solo puede verse en el .c al que pertenece. Eso es para tener como mas "privacidad" para la estructura, ObtainPin es la unica funcion que accede a ella. Ademas, como la funcion es local al .c, no se define en el .h, para que no se vea desde afuera.
