#include "sapi.h"
#include "sapi_debounce.h"



void myPrintChar(gpioMap_t, ButtonState_t);


int main()
{

	ButtonState_t ButtonStateTEC1;
	ButtonState_t ButtonStateTEC2;
	ButtonState_t ButtonStateTEC3;
	ButtonState_t ButtonStateTEC4;

	bool_t TransitionButton = FALSE;

	boardConfig();

	uartConfig(UART_232,115200);
	uartCallbackSet(UART_232, UART_RECEIVE, onRx, NULL);
	uartInterrupt(UART_232, true);

	delay_t updateButton;
	delayInit( &updateButton, 40 );

	ButtonStateTEC1 = ButtonInit();
	ButtonStateTEC2 = ButtonInit();
	ButtonStateTEC3 = ButtonInit();
	ButtonStateTEC4 = ButtonInit();


	while(TRUE){

	    if( delayRead(&updateButton) ){
	        ButtonUpdate(TEC1,&ButtonStateTEC1,&TransitionButton);
	        if(TransitionButton == TRUE)
	        	myPrintChar(TEC1,ButtonStateTEC1);
	        
			ButtonUpdate(TEC2,&ButtonStateTEC2,&TransitionButton);
		    if(TransitionButton == TRUE)
		     	myPrintChar(TEC2,ButtonStateTEC2);

		    ButtonUpdate(TEC3,&ButtonStateTEC3,&TransitionButton);
	        if(TransitionButton == TRUE)
	        	myPrintChar(TEC3,ButtonStateTEC3);
	         	         
	        ButtonUpdate(TEC4,&ButtonStateTEC4,&TransitionButton);
	        if(TransitionButton == TRUE)
	        	myPrintChar(TEC4,ButtonStateTEC4);
	    }

	}
	
	return 0;

}

void onRx( void *noUsado ){
	char c = uartRxRead( UART_232);
	switch(c){
		case '1':
		   	   gpioWrite(LED1,HIGH);
		   	   break;
		case '2':
		   	   gpioWrite(LED3,HIGH);
		   	   break;
		case '3':
		   	   gpioWrite(LED1,LOW);
		   	   break;
		case '4':
		   	   gpioWrite(LED3,LOW);
		   	   break;
	}
}



void myPrintChar(gpioMap_t tecla, ButtonState_t ButtonState){
	switch (tecla){

		case TEC1:
				if(ButtonState == STATE_BUTTON_DOWN){
					 gpioWrite(LEDB,HIGH);
					 uartWriteByte( UART_232, '1' );
				}
				break;

		case TEC2:
				if(ButtonState == STATE_BUTTON_DOWN){

					 gpioWrite(LED2,HIGH);
					 uartWriteByte( UART_232, '2' );
				}
				break;
		case TEC3:
				if(ButtonState == STATE_BUTTON_DOWN){	
					gpioWrite(LEDB,LOW);
					uartWriteByte( UART_232, '3' );
				}
				break;
		case TEC4:
				if(ButtonState == STATE_BUTTON_DOWN){
					gpioWrite( LED2, LOW);
					uartWriteByte( UART_232, '4' );

				}
				break;


		default:
				break;
	}


}
