
#include "sapi.h"
#include "sapi_debounce.h"

void myPrintChar(gpioMap_t, ButtonState_t);
void ErrorPrintChar(void);


int main()
{

	ButtonState_t ButtonStateTEC1;
	ButtonState_t ButtonStateTEC2;
	ButtonState_t ButtonStateTEC3;
	ButtonState_t ButtonStateTEC4;
	bool_t TransitionButton = FALSE;

	boardConfig();
	uartConfig(UART_USB,115200);



	delay_t updateButton;
	delayInit( &updateButton, 40 );

	ButtonStateTEC1 = ButtonInit();
	ButtonStateTEC2 = ButtonInit();
	ButtonStateTEC3 = ButtonInit();
	ButtonStateTEC4 = ButtonInit();

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
				if(ButtonState == STATE_BUTTON_UP){
					gpioWrite( LEDB, LOW);
				 }
				 else{
					gpioWrite(LEDB,HIGH);
					uartWriteByte( UART_USB, 'H' );
				}
				break;

			case TEC2:
				if(ButtonState == STATE_BUTTON_UP){
					gpioWrite( LED1, LOW);
				}
				 else{
					gpioWrite(LED1,HIGH);
					uartWriteByte( UART_USB, 'O' );
				}
				break;
			case TEC3:
				if(ButtonState == STATE_BUTTON_UP){
					gpioWrite( LED2, LOW);
				}
				else{
					gpioWrite(LED2,HIGH);
					uartWriteByte( UART_USB, 'L' );
				}
				break;

			case TEC4:
				if(ButtonState == STATE_BUTTON_UP){
					gpioWrite( LED3, LOW);
				}
				else{
					gpioWrite(LED3,HIGH);
					uartWriteByte( UART_USB, 'A' );
				}
				break;
			default:
				break;
	}
	
	uartWriteByte( UART_USB, '\r' ); 
	uartWriteByte( UART_USB, '\n' ); 

}
