#include "sapi.h"

uint8_t  dutyCycle1 = 0; /* 0 a 255 */

void onRx(void *noUsado){

   char c = uartRxRead( UART_USB );

   switch(c){
            case '1':

				  dutyCycle1+=5;
				  if(dutyCycle1 > 255){
					  dutyCycle1 = 255;
				  }
				  pwmWrite( PWM7, dutyCycle1 );
                  break;
            case '2':

				if(dutyCycle1 <= 0){
					  dutyCycle1 = 0;
				}
				else{
					dutyCycle1-=5;
				}
				pwmWrite( PWM7, dutyCycle1 );
                  break;
            default:
                  break;
     }
}

int main( void )
{

   boardConfig();
   uartConfig(UART_USB, 115200);
   uint8_t dato;

   bool_t valor = 0;
   uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL);
   uartInterrupt(UART_USB, true);


   uint8_t pwmVal = 0; /* 0 a 255 */

   /* Configurar PWM */
   valor = pwmConfig( 0, PWM_ENABLE );
   valor = pwmConfig( PWM7, PWM_ENABLE_OUTPUT );

   valor = pwmWrite( PWM7, dutyCycle1 );
   pwmVal = pwmRead( PWM7 );
   pwmWrite( PWM7, pwmVal );

   while( 1 ){

   }


   return 0;
}
