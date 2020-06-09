# **Documentación del archivo app**


## **Migración**
A continuación se detallan las pasos a seguir para poder migrar el proyecto **examples/c/app** a **examples/c/project/tp2**.

### **Paso 1**

Generamos una nueva carpeta en el directorio **examples/c** titulada **project**.

### **Paso 2**

Copiamos la carpeta **app** a **project** y cambiamos su nombre a **tp2**.

### **Paso 3**

Cambiamos el nombre de *app.c* a *tp2.c*.

### **Paso 4**

Para poder compilar el programa modificamos los parametros de *program.mk* a los descriptos en la siguiente figura.

### **Paso 5**

Renombramos el archivo *app.h* a *tp2.h* y modificamos el archivo *tp2.c* para incluir a *tp2.h*.

### **Paso 6**

Creamos el nuevo proyecto *tp2* con el comando *Build Project*.

### **Paso 7**

Una vez creado el proyecto nos dirigimos a *Debug as* -> *Debug configurations* donde se nos desplegara el menu para modificar los parametros para debuggear.

### **Paso 8**

Dentro de este menu nos dirigimos a *Search project*, elegimos *tp2.elf*, seleccionamos *OK*, luego *Apply* y finalmente *Debug*.


