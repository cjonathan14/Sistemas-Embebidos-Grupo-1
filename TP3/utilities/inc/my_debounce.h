#ifndef _MYDEBOUNCE_H_
#define _MYDEBOUNCE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "sapi_datatypes.h"
#include "sapi_gpio.h"

typedef enum{
   STATE_BUTTON_UP,
   STATE_BUTTON_DOWN,
   STATE_BUTTON_FALLING,
   STATE_BUTTON_RISING
} ButtonState_t;


void ButtonUpdate(gpioMap_t,ButtonState_t *,bool_t *);
ButtonState_t ButtonError( void );
ButtonState_t ButtonInit( void );


#ifdef __cplusplus
}
#endif

#endif
