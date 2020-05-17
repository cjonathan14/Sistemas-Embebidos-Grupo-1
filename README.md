# Sistemas embebidos - Grupo 1

### Integrantes:

Christian Guantay (98538)

Jonathan Cárdenas (99195)

Solana Caul (xxxxx)

## Instalación y uso de Yakindu

Se presenta un tutorial para la instalación desde 0 del software Yakindu, utilizado sobre el MCU Eclipse

### Instalación del MCU Eclipse

El primer paso es la instalación del entorno de desarrollo sobre el cual se ejecutará Yakindu, en este caso es el MCU Eclipse. Este programa es parte de un conjunto más grande de aplicaciones necesarias para programar sobre la placa CIAA. Puede descargarse, junto con las otras herramientas, del [Git del proyecto CIAA](https://github.com/epernia/software/releases/tag/r1.1.0). La instalación es simple, por lo cual no se especifica en este documento.

### Instalación del MCUXpresso

Dado que a ningún integrante del grupo le funcionó correctamente Eclipse, utilizamos una alternativa al mismo: MCUXpresso. El mismo puede descargarse del [sitio oficial de nxp](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE?tab=Design_Tools_Tab). Antes es necesario registrarse.

![](https://user-images.githubusercontent.com/38143566/82156304-c9e11b00-9850-11ea-9be5-d2730024a0e0.png)

### Instalación del plug-in Yakindu

El programa Yakindu se utiliza como un plug-in dentro de los entornos de desarrollo. Para instalarlo, debe accederse a "Eclipse Marketplace", dentro del menú "help"

![](https://user-images.githubusercontent.com/38143566/82157653-32cc9100-9859-11ea-9f5d-5ed0402a0862.png)

Allí, debe buscarse "Yakindu" e instalar la opción que se muestra en la figura siguiente

![](https://user-images.githubusercontent.com/38143566/82157286-dcf6e980-9856-11ea-999a-357bc59cd7ae.png)

### Descarga de Firmware v3

En este punto el entorno de desarrollo está instalado y listo para utilizar Yakindu. Firmware v3 consiste en programas desarrollados por el equipo de CIAA para facilitar el desarrollo de proyectos, así como el aprendizaje de los usuarios. Puede descargarse desde el [Git del proyecto CIAA](https://github.com/ciaa/firmware_v3). Una guía completa de como abrir el proyecto por primera vez puede encontrarse en https://github.com/epernia/firmware_v3/blob/master/documentation/firmware/eclipse/usage-es.md, por lo cual no se profundiza en esta documentación.
