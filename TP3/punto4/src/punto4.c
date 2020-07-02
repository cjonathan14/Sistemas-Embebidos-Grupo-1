#include "sapi.h"

int main( void )
{

   boardConfig();
   uartConfig(UART_USB, 115200);
   uint8_t dato;

   bool_t valor = 0;

   /* Variables de Retardos no bloqueantes */
  delay_t delayBase1;
  delay_t delayBase2;
  delay_t delayBase3;

  /* Inicializar Retardo no bloqueante con tiempo en milisegundos
	 (500ms = 0,5s) */
  delayConfig( &delayBase1, 50 );
  delayConfig( &delayBase2, 50 );
  delayConfig( &delayBase3, 50 );

   uint8_t  dutyCycle1 = 0; /* 0 a 255 */
   uint16_t dutyCycle2 = 0;
   uint16_t dutyCycle3 = 0;

   uint8_t pwmVal = 0; /* 0 a 255 */

   /* Configurar PWM */
   valor = pwmConfig( 0, PWM_ENABLE );
   valor = pwmConfig( PWM7, PWM_ENABLE_OUTPUT );
   valor = pwmConfig( PWM8, PWM_ENABLE_OUTPUT );
   valor = pwmConfig( PWM9, PWM_ENABLE_OUTPUT );

   valor = pwmWrite( PWM7, dutyCycle1 );
   pwmVal = pwmRead( PWM7 );
   pwmWrite( PWM7, pwmVal );

   valor = pwmWrite( PWM8, dutyCycle2 );
   pwmVal = pwmRead( PWM8 );
   pwmWrite( PWM8, pwmVal );

   valor = pwmWrite( PWM9, dutyCycle3 );
   pwmVal = pwmRead( PWM9 );
   pwmWrite( PWM9, pwmVal );

   while( 1 ){

	   if( delayRead(&delayBase1) )
		dutyCycle1+=1;
	   if( dutyCycle1>255 )
		dutyCycle1 = 0;

	   pwmWrite( PWM7, dutyCycle1 );

	   if( delayRead(&delayBase2) )
		dutyCycle2+=1;
	   if( dutyCycle2>255 )
		dutyCycle2 = 0;

	   pwmWrite( PWM8, dutyCycle2 );

	   if( delayRead(&delayBase3) )
		dutyCycle3+=1;
	   if( dutyCycle3>255 )
		dutyCycle3 = 0;

	   pwmWrite( PWM9, dutyCycle3 );
   }


   return 0;
}

