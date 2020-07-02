#include "sapi.h"
#include <string.h>

#define VALUE_ASCII_INT 48
#define MAX_VALUE_SCALE 1023.0
#define DIVISOR 9.0

void reverse(char s[]);
void itoa(int n, char s[]);
void onRx( void *noUsado );


int main(void){

   
  boardConfig();

  uartConfig( UART_USB, 115200 );
  uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL);
  uartInterrupt(UART_USB, true);

  adcConfig( ADC_ENABLE ); 
  dacConfig( DAC_ENABLE ); 

  static char uartBuff[10];
  uint16_t muestra = 0;

  delay_t delay1;

  delayConfig( &delay1, 500 );

   
  while(1) {

    if ( delayRead( &delay1 ) ){
      muestra = adcRead( CH1 );
      uartWriteString( UART_USB, "ADC CH1 value: " );
      itoa( muestra, uartBuff); /*Hace la conversion en base 10*/
      uartWriteString( UART_USB, uartBuff );
      uartWriteString( UART_USB, ";\r\n" );
    }

  }

   
   return 0 ;
}

void onRx( void *noUsado ){
   char c = uartRxRead( UART_USB );
   double muestra = (double)(c-VALUE_ASCII_INT);

   muestra = (muestra*MAX_VALUE_SCALE)/DIVISOR;

   dacWrite( DAC, (uint16_t)muestra );
}


void reverse(char s[]){
   int i, j;
   char c;

   for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
       c = s[i];
       s[i] = s[j];
       s[j] = c;
   }
 }

void itoa(int n, char s[]){
   int i, sign;

   if ((sign = n) < 0)  
       n = -n;          
   i = 0;
   do{       
      s[i++] = n % 10 + '0';   
   } while ((n /= 10) > 0);     
   if (sign < 0)
       s[i++] = '-';
   s[i] = '\0';
   reverse(s);
}
