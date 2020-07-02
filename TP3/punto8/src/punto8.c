#include "sapi.h"


void onRxUART_USB(void *noUsado);
void onRxUART_232( void *noUsado );

int main(void){

   boardConfig();

   uartConfig(UART_USB, 115200);
   uartCallbackSet(UART_USB, UART_RECEIVE, onRxUART_USB, NULL);
   uartInterrupt(UART_USB, true);

   uartConfig(UART_232, 115200);
   uartCallbackSet(UART_232, UART_RECEIVE, onRxUART_232, NULL);
   uartInterrupt(UART_232, true);
   
   while(TRUE) {

   }
   
   return 0;

}


void onRxUART_USB( void *noUsado ){
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

      default:
            break;
   }

   uartWriteByte( UART_232, c );
}
void onRxUART_232( void *noUsado ){
   char c = uartRxRead( UART_232);

   switch(c){

      case '1':
            gpioWrite(LED3,HIGH);
            break;
      case '2':
            gpioWrite(LED3,LOW);
            break;
      case '3':
            gpioWrite(LEDB,HIGH);
            break;
      case '4':
            gpioWrite(LEDB,LOW);
            break;

      default:
            break;
   }

   uartWriteByte( UART_USB, c );
}

