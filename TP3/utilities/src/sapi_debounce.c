#include "sapi_debounce.h"


ButtonState_t ButtonError(void)
{
	return STATE_BUTTON_UP;
}

ButtonState_t ButtonInit(void)
{
	return STATE_BUTTON_UP;
}
// FSM Update Sate Function
void ButtonUpdate( gpioMap_t tecla, ButtonState_t *ptrButtonState,bool_t *ptrTransition )
{

   ButtonState_t ButtonState = *ptrButtonState;


   switch( ButtonState ){

      case STATE_BUTTON_UP:
         /* CHECK TRANSITION CONDITIONS */
         if( !gpioRead(tecla) ){
            ButtonState = STATE_BUTTON_FALLING;

         }
         *ptrTransition = FALSE;
      break;

      case STATE_BUTTON_DOWN:
         /* CHECK TRANSITION CONDITIONS */
         if( gpioRead(tecla) ){
            ButtonState = STATE_BUTTON_RISING;

         }
         *ptrTransition = FALSE;
      break;

      case STATE_BUTTON_FALLING:

         /* CHECK TRANSITION CONDITIONS */
         if( !gpioRead(tecla) ){
            ButtonState = STATE_BUTTON_DOWN;
            *ptrTransition = TRUE;

         } else{
            ButtonState =  STATE_BUTTON_UP;
            *ptrTransition = FALSE;
         }

         /* LEAVE */
         break;

      case STATE_BUTTON_RISING:

         /* CHECK TRANSITION CONDITIONS */
         if( gpioRead(tecla) ){
            ButtonState = STATE_BUTTON_UP;
            *ptrTransition = TRUE;

         } else{
            ButtonState = STATE_BUTTON_DOWN;
            *ptrTransition = FALSE;
         }

         break;

      default:
         ButtonState = ButtonError();
      break;
   }

   *ptrButtonState = ButtonState;

}
