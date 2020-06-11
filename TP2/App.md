# **Documentación de app.c**


## **Secuencia de funciones**


boardConfig(); : Macro definida en sapi_board.h . Se trata de una macro a función encargada de llamar a  la función boardInit.

void boardInit(void): Esta función se encuentra en el archivo sapi_board.c . Es la encargada de inicializar y setear la placa.
Esto consiste en inicializar el clock de la placa y setearlo e inicializar y configurar los pines GPIO de entrada y de salida.
 

void delay( tick_t duration_ms );

	tick_t tickRead( void )

bool_t gpioRead( gpioMap_t pin );

bool_t gpioWrite( gpioMap_t pin, bool_t value );

bool_t gpioRead( gpioMap_t pin );

int printf (const char *template, ...);

bool_t gpioToggle( gpioMap_t pin );