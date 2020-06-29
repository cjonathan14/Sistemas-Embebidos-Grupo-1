#include "sapi_debounce.h"
#include "sapi.h"

void myPrintChar(gpioMap_t, ButtonState_t);
void ErrorPrintChar(void);
void onRx( void *noUsado );


int main(void)
{

	boardConfig();

	uartConfig(UART_USB,115200);

	ButtonState_t ButtonStateTEC1;
	ButtonState_t ButtonStateTEC2;
	ButtonState_t ButtonStateTEC3;
	ButtonState_t ButtonStateTEC4;
	
	bool_t TransitionButton = FALSE;
	
	delay_t updateButton;
	
	delayInit( &updateButton, 40 );

	ButtonStateTEC1 = ButtonInit();
	ButtonStateTEC2 = ButtonInit();
	ButtonStateTEC3 = ButtonInit();
	ButtonStateTEC4 = ButtonInit();

	 uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL);
	 
	 uartInterrupt(UART_USB, true);


	while(TRUE){

	    if( delayRead(&updateButton) ){
		         ButtonUpdate(TEC1,&ButtonStateTEC1,&TransitionButton);
		         if(TransitionButton == TRUE){
		        	 myPrintChar(TEC1,ButtonStateTEC1);
		         }

		         ButtonUpdate(TEC2,&ButtonStateTEC2,&TransitionButton);
		         if(TransitionButton == TRUE){
		         	myPrintChar(TEC2,ButtonStateTEC2);
		         }

		         ButtonUpdate(TEC3,&ButtonStateTEC3,&TransitionButton);
		         if(TransitionButton == TRUE){
		         	 myPrintChar(TEC3,ButtonStateTEC3);
		         }

		         ButtonUpdate(TEC4,&ButtonStateTEC4,&TransitionButton);
				if(TransitionButton == TRUE){
					myPrintChar(TEC4,ButtonStateTEC4);
				}


		}

	}
	   return 0;

}


void ErrorPrintChar(void){
	char textoError[] = "Error";

	uartWriteString( UART_USB, textoError );
}
void myPrintChar(gpioMap_t tecla, ButtonState_t ButtonState){
	
	switch (tecla){

		case TEC1:
				if(ButtonState == STATE_BUTTON_DOWN)
					uartWriteByte( UART_USB, 'H' );
				 
				break;
		case TEC2:
				if(ButtonState == STATE_BUTTON_DOWN)
					uartWriteByte( UART_USB, 'O' );
						 
				break;
		case TEC3:
				if(ButtonState == STATE_BUTTON_DOWN)
					uartWriteByte( UART_USB, 'L' );
						 
				break;
		case TEC4:
				if(ButtonState == STATE_BUTTON_DOWN)
					uartWriteByte( UART_USB, 'A' );
						 
				break;

		default:
				break;
	}
	uartWriteByte( UART_USB, '\r' ); // Envia '\r', retorno de carro
	uartWriteByte( UART_USB, '\n' ); // Envia '\n', nueva linea


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
