# TP1 - Panel de control

## Enunciado

Implementar (editar,simular y generar el código) el modelo de control de Panel de Control de un generador de señales.
* Tensión: 0 a 10V.
* Frecuencia: 20 a 20.000Hz
* Formas de señal: 3

### PASO 1
En el primer paso se deben identificar los eventos y las acciones.

#### Eventos
* Forma
* Magnitud
* Up
* Down

#### Acciones

* Elegir Forma
* Elegir Magnitud
* Incrementar Tensión
* Decrementar Tensión
* Incrementar Frecuencia
* Decrementar Frecuencia.


### PASO 2

En el segundo paso se deben identificar los estados

#### Estados

* Triagular
* Cuadrada
* Senoidal

* Tensión 
* Frecuencia

### PASO 4

En el cuarto paso se debe agrupar por concurrencia. Esto significa que posibilita la existencia de tareas independientes. 
Con lo cual se tienen dos subestados concurrentes, porque se ejecutan en paralelo, uno para seleccionar la **Forma** y el otro para 
seleccionar la **Magnitud**.

## Implentación en el MCU Express

![](panel de control.png "Diagrama de estados": Panel de Control)









