#include "sapi.h"

uint8_t  dutyCycle1 = 0; /* 0 a 255 */

void onRx(void *noUsado){

   char c = uartRxRead( UART_USB );

   switch(c){
            case '1':

				  if(dutyCycle1 == 255){
					  dutyCycle1 = 255;
				  } else {
					  dutyCycle1+=1;
				  }
				  pwmWrite( PWM7, dutyCycle1 );
                  break;
            case '2':

				if(dutyCycle1 == 0){
					  dutyCycle1 = 0;
				}
				else{
					dutyCycle1-=1;
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

   bool_t valor = 0;
   uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL);
   uartInterrupt(UART_USB, true);

   /* Configurar PWM */
   valor = pwmConfig( 0, PWM_ENABLE );
   valor = pwmConfig( PWM7, PWM_ENABLE_OUTPUT );

   valor = pwmWrite( PWM7, dutyCycle1 );

   while( 1 ){

   }


   return 0;
}
