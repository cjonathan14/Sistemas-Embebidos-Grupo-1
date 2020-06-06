Chip_GPIO_Init(LPC_GPIO_PORT); --> Configuracion inicial de GPIO

Chip_SCU_PinMux(
         pinNamePort,
         pinNamePin,
         SCU_MODE_INACT/PULLUP/... | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS,  // El unico argumento que cambia es el primero
         func
      ); --> Configura el SCU. Tambien hace pullup y pulldown

Chip_GPIO_SetDir( 
	LPC_GPIO_PORT, 
	gpioPort, 
	( 1 << gpioPin ), 
	GPIO_INPUT/OUTPUT ); --> Configura el GPIO

Chip_GPIO_SetPinState( LPC_GPIO_PORT, gpioPort, gpioPin, value); --> Escribe en GPIO


(bool_t) Chip_GPIO_ReadPortBit( LPC_GPIO_PORT, gpioPort, gpioPin ); --> Lee de GPIO
