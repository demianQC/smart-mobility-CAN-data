# smart-mobility-CAN-data
programas necesarios para la lectura y análisis de datos provenientes de un BUS CAN

## Uso
Se deben compilar y obtener los ejecutables para data.cpp y request.cpp 

```bash
g++ data.cpp -o data.cpp.o
g++ request.cpp -o request.cpp.o
```

Luego se debe usar el programa data.cpp.o para obtener los datos que provienen desde los archivos de prueba, ordenados y agrupados por ID CAN

```bash
./data.cpp.o FILENAME  > out.txt
```
### IDs CAN ordenados segun aparición en el archivo 
![image](https://user-images.githubusercontent.com/49004826/137800917-ad261fcb-5357-4e66-a7a6-2bb78af55758.png)
### Datos CAN agrupados según ID CAN
![image](https://user-images.githubusercontent.com/49004826/137801009-5551ed2a-585f-4872-8260-9e85d4a94e74.png)

Con esto se puede tener una visualización de cuantos IDS se obtuvieron en el bus CAN y cuales son los IDS que se obtuvieron.

### request.cpp.o
El uso de este programa es particularmente para obtener los datos específicos de un ID de interés que se desee analizar ya sea por consola o en un archivo.
#### para mostrar en consola
```bash
./request.cpp.o FILENAME  
```

#### para guardar en un archivo

```bash
./request.cpp.o FILENAME > output.txt
```

## cantest.bin
Este archivo es un firmware especial para utilizar en el dispositivo Smart mobility V2 (ATSAM3X8E) que permite la conexión con el módulo MCP2515 en modo listen para escanear los posibles baud rates del bus CAN.
