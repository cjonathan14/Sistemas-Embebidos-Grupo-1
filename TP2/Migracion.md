# **Documentación del archivo app**


## **Migración**
A continuación se detallan las pasos a seguir para poder migrar el proyecto **examples/c/app** a **examples/c/project/tp2**.


### **Paso 1**

Generamos una nueva carpeta en el directorio **examples/c** titulada **project**.

![Paso1](https://user-images.githubusercontent.com/65372063/84198875-97ef5d00-aa7a-11ea-8e99-9e8621a6c666.png)


### **Paso 2**

Copiamos la carpeta **app** a **project** y cambiamos su nombre a **tp2**.

![Paso2](https://user-images.githubusercontent.com/65372063/84199417-82c6fe00-aa7b-11ea-8ef4-9320ecd67559.png)

### **Paso 3**

Cambiamos el nombre de *app.c* a *tp2.c*.

![Paso3](https://user-images.githubusercontent.com/65372063/84203789-6bd6da80-aa80-11ea-89f7-81a2f5cfb77d.png)

### **Paso 4**

Para poder compilar el programa modificamos los parametros de *program.mk* a los descriptos en la siguiente figura.

![Paso4](https://user-images.githubusercontent.com/65372063/84203839-7beeba00-aa80-11ea-933b-075de02390cf.png)

### **Paso 5**

Renombramos el archivo *app.h* a *tp2.h* y modificamos el archivo *tp2.c* para incluir a *tp2.h*.

![Paso5_1](https://user-images.githubusercontent.com/65372063/84203857-83ae5e80-aa80-11ea-9b93-3f6bcada153c.png)
![Paso5_2](https://user-images.githubusercontent.com/65372063/84203860-8446f500-aa80-11ea-898b-c8ee1b237c9e.png)

### **Paso 6**

Creamos el nuevo proyecto *tp2* con el comando *Build Project*.

![Paso6](https://user-images.githubusercontent.com/65372063/84203862-84df8b80-aa80-11ea-8693-8fb72b029ce4.png)

### **Paso 7**

Una vez creado el proyecto nos dirigimos a *Debug as* -> *Debug configurations* donde se nos desplegara el menu para modificar los parametros para debuggear.

![Paso7](https://user-images.githubusercontent.com/65372063/84203864-84df8b80-aa80-11ea-9f92-58724f5d9a88.png)

### **Paso 8**

Dentro de este menu nos dirigimos a *Search project*, elegimos *tp2.elf*, seleccionamos *OK*, luego *Apply* y finalmente *Debug*.

![Paso8_1](https://user-images.githubusercontent.com/65372063/84203865-85782200-aa80-11ea-85ab-c8cdd67dc978.png)
![Paso8_2](https://user-images.githubusercontent.com/65372063/84203867-8610b880-aa80-11ea-91ef-70212c67c8d8.png)

