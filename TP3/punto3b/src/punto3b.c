#include "sapi.h"

void onRx( void *noUsado );



int main(void)
{
   boardConfig();

   uartConfig(UART_USB, 115200);
   
   uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL);
   uartInterrupt(UART_USB, true);

   while(TRUE) {
      
      gpioToggle(LEDB);
      delay(1000);
   }
   return 0;
}


void onRx(void *noUsado){
   
   char c = uartRxRead( UART_USB );
   
   switch(c){

            case '1':
                  gpioWrite(LED1,HIGH);
                  break;
            case '2':
                  gpioWrite(LED1,LOW);
                  break;
            case '3':
                  gpioWrite(LED2,HIGH);
                  break;
            case '4':
                  gpioWrite(LED2,LOW);
                  break;
            case '5':
                  gpioWrite(LED3,HIGH);
                  break;
            case '6':
                  gpioWrite(LED3,LOW);
                  break;
            default:
                  break;
         }
}
