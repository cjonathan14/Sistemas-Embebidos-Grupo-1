/*============================================================================
 * Autor: Grupo 1
 * Licencia:
 * Fecha:06/06/2020
 *===========================================================================*/

// Inclusiones

#include "../inc/tp2.h"         // <= Su propia cabecera

// Variables

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

// Funciones locales al archivo

static void my_gpioObtainPinInit( my_gpioMap_t pin,
                               int8_t *scu_port, int8_t *scu_pin,
                               int8_t *func, int8_t *gpio_port,
                               int8_t *gpio_pin )
{

   *scu_port = my_gpio_pinsInit[pin].scu_port;
   *scu_pin  = my_gpio_pinsInit[pin].scu_pin;
   *func        = my_gpio_pinsInit[pin].func;
   *gpio_port    = my_gpio_pinsInit[pin].gpio_port;
   *gpio_pin     = my_gpio_pinsInit[pin].gpio_pin;

}

// MAIN

int main( void )
{

   // ---------- CONFIGURACIONES ------------------------------

   // Inicializar y configurar la plataforma
   boardConfig();

   // Crear varias variables del tipo booleano
   bool_t buttonValue = OFF;

   // Configuro puertos de IO para pruebas
   my_gpioInit( MY_GPIO0 , MY_GPIO_INPUT );
   my_gpioInit( MY_GPIO2 , MY_GPIO_OUTPUT );

   // ----------------- LOOP --------------------------
   while( TRUE ) {

		buttonValue = my_gpioRead( MY_GPIO0 );
		buttonValue = !buttonValue;
		my_gpioWrite( MY_LEDB, buttonValue );
	    my_gpioWrite( MY_GPIO2, !my_gpioRead( MY_GPIO2 ) );

		buttonValue = my_gpioRead( MY_TEC2 );
		buttonValue = !buttonValue;
		my_gpioWrite( MY_LED1, buttonValue );

		buttonValue = my_gpioRead( MY_TEC3 );
		buttonValue = !buttonValue;
		my_gpioWrite( MY_LED2, buttonValue );

		buttonValue = my_gpioRead( MY_TEC4 );
		buttonValue = !buttonValue;
		my_gpioWrite( MY_LED3, buttonValue );

		delay( 250 );

   }

   return 0;

}



bool_t my_gpioInit( my_gpioMap_t pin, my_gpioInit_t config )
{

   if( pin == MY_VCC ){
	  return FALSE;
   }
   if( pin == MY_GND ){
	  return FALSE;
   }

   bool_t ret_val     = 1;

   int8_t scu_port = 0;
   int8_t scu_pin  = 0;

   int8_t func        = 0;

   int8_t gpio_port    = 0;
   int8_t gpio_pin     = 0;

   my_gpioObtainPinInit( pin, &scu_port, &scu_pin, &func,
					  &gpio_port, &gpio_pin );

   switch(config) {

   case MY_GPIO_ENABLE:
	  /* Initializes GPIO */
	  Chip_GPIO_Init(LPC_GPIO_PORT);
	  break;

   case MY_GPIO_INPUT:
	  Chip_SCU_PinMux(
		 scu_port,
		 scu_pin,
		 SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS,
		 func
	  );
	  Chip_GPIO_SetDir( LPC_GPIO_PORT, gpio_port, ( 1 << gpio_pin ), INPUT_PORT );
	  break;

   case MY_GPIO_INPUT_PULLUP:
	  Chip_SCU_PinMux(
		 scu_port,
		 scu_pin,
		 SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS,
		 func
	  );
	  Chip_GPIO_SetDir( LPC_GPIO_PORT, gpio_port, ( 1 << gpio_pin ), INPUT_PORT );
	  break;

   case MY_GPIO_INPUT_PULLDOWN:
	  Chip_SCU_PinMux(
		 scu_port,
		 scu_pin,
		 SCU_MODE_PULLDOWN | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS,
		 func
	  );
	  Chip_GPIO_SetDir( LPC_GPIO_PORT, gpio_port, ( 1 << gpio_pin ), INPUT_PORT );
	  break;
   case MY_GPIO_INPUT_REPEATER:
	  Chip_SCU_PinMux(
		 scu_port,
		 scu_pin,
		 SCU_MODE_REPEATER | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS,
		 func
	  );
	  Chip_GPIO_SetDir( LPC_GPIO_PORT, gpio_port, ( 1 << gpio_pin ), INPUT_PORT );
	  break;

   case MY_GPIO_OUTPUT:
	  Chip_SCU_PinMux(
		 scu_port,
		 scu_pin,
		 SCU_MODE_INACT | SCU_MODE_ZIF_DIS | SCU_MODE_INBUFF_EN,
		 func
	  );
	  Chip_GPIO_SetDir( LPC_GPIO_PORT, gpio_port, ( 1 << gpio_pin ), OUTPUT_PORT );
	  Chip_GPIO_SetPinState( LPC_GPIO_PORT, gpio_port, gpio_pin, 0);
	  break;

   default:
	  ret_val = 0;
	  break;
   }

   return ret_val;

}


bool_t my_gpioWrite( my_gpioMap_t pin, bool_t value ) {

   if( pin == MY_VCC ){
	  return FALSE;
   }
   if( pin == MY_GND ){
	  return FALSE;
   }

   bool_t ret_val     = 1;

   int8_t scu_port = 0;
   int8_t scu_pin  = 0;

   int8_t func        = 0;

   int8_t gpio_port    = 0;
   int8_t gpio_pin     = 0;

   my_gpioObtainPinInit( pin, &scu_port, &scu_pin, &func,
					  &gpio_port, &gpio_pin );

   Chip_GPIO_SetPinState( LPC_GPIO_PORT, gpio_port, gpio_pin, value);

   return ret_val;

}


bool_t my_gpioRead( my_gpioMap_t pin ) {

   if( pin == MY_VCC ){
	  return TRUE;
   }
   if( pin == MY_GND ){
	  return FALSE;
   }

   bool_t ret_val     = OFF;

   int8_t scu_port = 0;
   int8_t scu_pin  = 0;

   int8_t func        = 0;

   int8_t gpio_port    = 0;
   int8_t gpio_pin     = 0;

   my_gpioObtainPinInit( pin, &scu_port, &scu_pin, &func,
					  &gpio_port, &gpio_pin );

   ret_val = (bool_t) Chip_GPIO_GetPinState( LPC_GPIO_PORT, gpio_port, gpio_pin );

   return ret_val;

}
