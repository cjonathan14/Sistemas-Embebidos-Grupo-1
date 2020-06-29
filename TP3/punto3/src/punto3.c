#include "sapi.h"

int main(void)
{
	boardConfig();
	uartConfig(UART_USB,115200);

	uint8_t dato  = 0;

	while(1){
			if(uartReadByte( UART_USB, &dato ) ){
					switch(dato){

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
	}

	return 0;
}
