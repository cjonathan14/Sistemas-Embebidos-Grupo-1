## Punto 1

# uartConfig(UART_USB,115200);

La función inicializa el UART_USB a 115200 baudios.
UART_USB: es el hardware UART2 en UBS DEBUG PORT.
115200: representa el baud rate.

Los módulos correspondientes de la biblioteca sAPI que contienen las funciones para el manejo de UART son sapi_uart.c/.h  y a su vez utilizan los modulos uart_18xx_43xx.c y .h de la biblioteca LPCOpen.

En esta función se invocan las siguientes funciones:

* Chip_UART_Init. Inicializa la UART.

* Chip_UART_SetBaud. Se setea el baud rate.

* Chip_UART_SetupFIFOS. Configura el UART FIFO.

* Chip_UART_ReadByte. Lee un byte del periferico UART.

* Chip_UART_TXEnable. Habilita la transmisión UART.

* Chip_SCU_PinMux. Configura el SCU UARTn_TXD pin y el SCU UARTn_RXD pind

* Chip_UART_SetRS485Flags.

# adcConfig(ADC_ENABLE);

Esta función configura el ADC, con los siguientes valores de configuración: ADC_ENABLE, ADC_DISABLE, habilita/deshabilita el periférico ADC.
Cuenta con tres entradas analógicas CH1 a CH3.

El módulo correspondiente de la biblioteca sAPI que contiene las funciones para el manejo del ADC es sapi_adc.c/.h. A su vez utiliza el  módulo adc_18xx_43xx.c/.h de la biblioteca LPCOpen

Esta función invoca a las siguientes funciones:

* Chip_ADC_Init. Inicializa el periferico ADC.

* Chip_ADC_SetBurstCmd. Deshabilita o habilita la conversion en modo rafaga. 

*  Chip_ADC_SetSampleRate. Setea la frecuencia de muestreo del ADC.

* Chip_ADC_EnableChannel. Habilita o deshabilita el canal ADC en el periférico ADC.

* Chip_ADC_Int_SetChannelCmd. Activa o desactiva interrupción para el canal ADC.

# dacConfig(DAC_ENABLE)
Esta función configura el DAC, con los siguientes valores de configuración: DAC_ENABLE, DAC_DISABLE, habilita/deshabilita el periférico DAC.
Cuenta con una salida analógica nombrada DAC..

El módulo correspondiente de la biblioteca sAPI que contiene las funciones para el manejo del DAC es sapi_dac.c/.h. A su vez utiliza el módulo dac_18xx_43xx.c/.h de la biblioteca LPCOpen.

Esta función invoca a las siguientes funciones:

* Chip_Clock_EnableOpts. Habilita un clock periférico y establece los estados del clock.

* Chip_DAC_SetBias. Establece la tasa de actualización máxima para DAC.

* Chip_DAC_ConfigDAConverterControl. Permite la operación DMA y controla el timer DMA.

* Chip_DAC_UpdateValue. Actualiza valor en buffer DAC.

* Chip_DAC_DeInit. Apaga el periférico DAC.

# delayConfig(&delay,500)

Esta función configura un delay no bloqueante. Esto permite que el microcontrolador realice otras tareas mientras se espera a que se cumpla el tiempo fijado.

El módulo correspondiente de la biblioteca sAPI que contiene las funciones para el manejo del delay es sapi_delay.c/.h

# muestra = adcRead(CH1)

Esta función hace una lectura de una entrada analógica. Se le pasa como parametro el pin a leer y devuelve el valor actual de la entrada analógica. 

Esta función invoca las siguientes funciones:

* Chip_ADC_EnableChannel.

* Chip_ADC_SetStartMode. Selecciona el modo de conversión AD.

* Chip_ADC_ReadStatus. Lee el status del canal ADC.

* Chip_ADC_ReadValue. Lee el valor ADC del canal.

# uartReadByte(UART_USB,&dato)

Esta función lee un byte del RX de UART. Se le pasa como parametro el UART a configurar y la dirección de momemoria donde se va a escribir el dato recibido en caso de que exista un dato para recibir. Devuelve TRUE si recibió un dato y FALSE en caso contrario.

Las funciones que invoca son las siguientes:

* uartRxReady. Devuelve TRUE si tiene datos no leídos en RX del UART.

* uartRxRead. Lee del RX del UART.

# uartWriteByte(UART_USB, dato)

Esta función escribe un byte en el TX de la UART. Se le pasa como parametro el UART a configurar y el byte a enviar.

Las funciones que invoca son las siguientes:

* uartTxReady. Devuelve TRUE si tiene espacio en TX del UART.

* uartTxWrite. Escribe el dato en TX del UART.

# uartWriteString(UART_USB,"ADC CH1 value:")

Esta función envia un string por la UART. Recibe como parametros el UART a configurar y el string a enviar. 

Esta función invoca a las siguiente función:

* uartwriteByte.

# dacWrite(DAC,muestra)

Es una función de escritura analógica. Recibe como parametro el pin a escribir y el valor del pin a escribir.

Esta función invoca a la siguiente función:

* Chip_DAC_UpdateValue.

# uartCallbackSet(UART_USB,UART_RECEIVE,onRx,NULL)

Setea un callback al evento de recepción y habilita su interrupción. 

LLama a la función Chip_UART_IntEnable.

# uartInterrupt(UART_UBS,true)

Habilita o deshabilita todas las interrupciones de UART_USB.

Invoca a las siguientes funciones:

* NVIC_SetPriority. 
* NVIC_EnableIRQ.
* NVIC_DisableIRQ.
