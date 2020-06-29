#include "sapi.h"
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);
 

int main(void){

   
  boardConfig();

  uartConfig( UART_USB, 115200 );

  adcConfig( ADC_ENABLE ); /* ADC */
   
  bool_t ledState1 = OFF;

 
  uint32_t i = 0;
  static char uartBuff[10];
  uint16_t muestra = 0;

   
   delay_t delay1;
   delay_t delay2;

   
   delayConfig( &delay1, 500 );
   delayConfig( &delay2, 200 );

   while(1) {

      
      if ( delayRead( &delay1 ) ){

        muestra = adcRead( CH1 );
        uartWriteString( UART_USB, "Valor ADC CH1: " );
        itoa( muestra, uartBuff); /*Hace la conversion en base 10*/

         
        uartWriteString( UART_USB, uartBuff );
        uartWriteString( UART_USB, ";\r\n" );
      }

      if ( delayRead( &delay2 ) ){
        ledState1 = !ledState1;
        gpioWrite( LED1, ledState1 );
        i++;
        if( i == 20 )
          delayWrite( &delay2, 1000 );
      }

   }

   return 0 ;
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


/*==================[end of file]============================================*/
