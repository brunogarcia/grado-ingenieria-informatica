# Actividad Evaluativa #4

## Instrucciones

El siguiente programa escrito en lenguaje ensamblador permite imprimir en pantalla
caracteres independientes o símbolos, cambios de líneas, y cadenas de caracteres
haciendo uso del servicio INT 21H de MS-DOS.

```asm
DOSSEG
.MODEL SMALL
.STACK 100H
.DATA
FRASE DB "HOLA MUNDO$"
; BUFFER FOR ASCII STRING
NLINEA DB 10D,13D,'$'
; NUEVA LINEA
.CODE
MOV AX,@DATA
; LEER LA DIRECCION DEL SEGEMENTO DE DATOS
MOV DS,AX
; Y GUARDARLA EN EL REGISTRO DE DATOS
MOV DL,'A'
; IMPRIME 'A'
MOV AH,2
INT 21H
MOV DL,' '
; IMPRIME ' '
MOV AH,2
INT 21H
MOV DL,'5'
; IMPRIME '5'
MOV AH,2
INT 21H
MOV DX,OFFSET NLINEA
; ESCRIBIR LA CADENA EN LA SALIDA
ESTANDAR
MOV AH,9
; INDICA QUE LA CADENA TERMINA CON '$'
INT 21H
MOV DX,OFFSET FRASE
MOV AH,9
INT 21H
MOV AH,76
; 76=4CH
VOLVER A DOS
INT 21H
END
```

Complete el siguiente programa en ensamblador, en el cual se desea imprimir en pantalla lo siguiente:

* Posición y número total de caracteres que difieren entre las dos frases
* Total y frecuencia de los números pares en CADENA_C1
* Contar e imprimir cuantas veces aparece cada vocal minúscula en CADENA_C2