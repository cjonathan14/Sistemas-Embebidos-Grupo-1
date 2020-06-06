/*============================================================================
 * Licencia:
 * Autor: Grupo 1
 * Fecha: 06/06/2020
 *===========================================================================*/

#ifndef _TP2_H_
#define _TP2_H_

/*==================[inclusiones]============================================*/

#include <stdint.h>
#include "sapi.h"        // <= Biblioteca sAPI
//#include "sapi_datatypes.h"
//#include "sapi_peripheral_map.h"

/*==================[c++]====================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

#define INPUT_PORT 0
#define OUTPUT_PORT 1

/*==================[tipos de datos declarados por el usuario]===============*/

typedef enum {
	MY_GPIO_INPUT, MY_GPIO_OUTPUT,
	MY_GPIO_INPUT_PULLUP, MY_GPIO_INPUT_PULLDOWN,
	MY_GPIO_INPUT_REPEATER,
	MY_GPIO_ENABLE
} my_gpioInit_t;

typedef struct {
	int8_t scu_port;
	int8_t scu_pin;
	int8_t func;
	int8_t gpio_port;
	int8_t gpio_pin;
} my_conf_t;

typedef enum {

   // Configure GPIO pins for each board

   #if (BOARD == edu_ciaa_nxp)
      MY_VCC = -2, MY_GND = -1,
      // Leds
      // 0   		1     	2     		3     	4     		5
      MY_LEDR,  MY_LEDG,  MY_LEDB,  MY_LED1,  MY_LED2,  MY_LED3,
	  // 6			7		8		9		10			11
	  MY_TEC1, MY_TEC2, MY_TEC3, MY_TEC4, MY_GPIO0, MY_GPIO2
   #else
      #error BOARD not supported yet!
   #endif
} my_gpioMap_t;

/*==================[declaraciones de datos externos]========================*/

/*==================[declaraciones de funciones externas]====================*/

bool_t my_gpioInit( my_gpioMap_t pin, my_gpioInit_t conf );
bool_t my_gpioWrite( my_gpioMap_t pin, bool_t value );
bool_t my_gpioRead( my_gpioMap_t pin );

/*==================[c++]====================================================*/
#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* _TP2_H_ */
