; x86 is an architecture derived from the Intel 8086 CPU.
; The x86 family includes the 32-bit IA-32 and 64-bit x86-64 architectures, as well as legacy 16-bit architectures.
;
; # Run MASM programs on Linux
; https://ksaikiranr.wordpress.com/2016/05/01/run-masm-programs-on-ubuntu
;
; # Mount the virtual disk with Dosbox (https://www.dosbox.com)
; mount c ~/dosbox
; c:
;
; # Steps for compile and debug the program
; masm practica
; link practica
; debug practica.exe
; -g (go)
; -q (quit)

; # Practica
; a) Mostrar la posición y número total de caracteres que difieren entre las dos frases
; b) Mostrar el total y frecuencia de los números pares en FRASE_1
; c) Mostrar cuantas veces aparece cada vocal minúscula en FRASE_2

DOSSEG
.MODEL SMALL
.STACK 100H
.DATA
  FRASE_1 DB "El 04-02-2021 es el examen final, 1ra convocatoria$"
  FRASE_2 DB "El 17-06-2021 es el Examen Final, 2da Convocatoria$"
  EJERCICIO_1 DB "TOTAL DE CARACTERES DISTINTOS Y POSICION : $"
  EJERCICIO_2 DB "CARACTERES NUMERICOS PARES EN FRASE_1 : $"
  EJERCICIO_3 DB "VOCALES MINUSCULAS EN FRASE_2 : $"
  NLINEA DB 10D,13D,'$'
  CONTADOR_DISTINTOS DB 30h ; definir la variable con el codigo ASCII del 0
  CONTADOR_PARES DB 30h     ; definir la variable con el codigo ASCII del 0
  CONTADOR_VOCALES DB 0
  CONTADOR_RESTO_VOCALES DB 0
.CODE
start:
  MOV AX,@DATA ; Lee la direccion del segmento de datos
  MOV DS,AX    ; Y la guarda en el registro de datos

  ; a) Posición y número total de caracteres que difieren entre las dos frases
  ; resultado final: 8
  MOV DX,OFFSET EJERCICIO_1 ; Escribir ejercicio_1 en la salida estandar
  MOV AH,9                  ; Indica que la cadena termina con '$'
  INT 21H                   ;
  xor si,si                   ; Inicializar el puntero si

  bucle_distintos:
    mov cl, FRASE_2[si]                ; Copiar el caracter de la FRASE_2
    cmp FRASE_1[si],cl                 ; Comparar el caracter de la FRASE_1 con el caracter de la FRASE_2
    jnz contar_distintos               ; Saltar si son distintos a la etiqueta contar_distintos
    cmp FRASE_1[si],'$'                ; Comprobar si es el fin de la cadena
    jz imprimir_distintos              ; Si es TRUE, finalizo el analisis de la secuencia
    inc si                             ; Si es FALSE, incremento el puntero si
    loop bucle_distintos               ; Saltar hasta bucle_distintos para comparar el siguiente caracter

  contar_distintos:
    inc si                             ; Incremento el puntero si
    inc CONTADOR_DISTINTOS             ; Incremento el contador de valores distintos
    cmp FRASE_1[si],'$'                ; Comprobar si es el fin de la cadena
    jz imprimir_distintos              ; Si es TRUE, finalizo el analisis de la secuencia
    loop bucle_distintos               ; Saltar hasta bucle_distintos para comparar el siguiente caracter

  imprimir_distintos:
    mov DL,CONTADOR_DISTINTOS      ; Escribir la cadena en la salida estandar
    mov AH,2                   ; Servicio para imprimir un caracter
    int 21h

  MOV DX,OFFSET NLINEA ; Escribir nlinea en la salida estandar
  MOV AH,9             ; Indica que la cadena termina con '$'
  INT 21H              ;

  ; b) Total de los números pares en FRASE_1
  ; resultado final: 4
  MOV DX,OFFSET EJERCICIO_2   ; Escribir ejercicio_2 en la salida estandar
  MOV AH,9                    ; Indica que la cadena termina con '$'
  INT 21H                     ;
  xor si,si                   ; Inicializar el puntero si

  bucle_pares:
    cmp FRASE_1[si],'2'        ; Comparar caracter con el numero 2
    jz contar_pares            ; Saltar si son iguales a la etiqueta contar_pares
    cmp FRASE_1[si],'4'        ; Comparar caracter con el numero 4
    jz contar_pares            ; Saltar si son iguales a la etiqueta contar_pares
    cmp FRASE_1[si],'6'        ; Comparar caracter con el numero 6
    jz contar_pares            ; Saltar si son iguales a la etiqueta contar_pares
    cmp FRASE_1[si],'8'        ; Comparar caracter con el numero 8
    jz contar_pares            ; Saltar si son iguales a la etiqueta contar_pares
    cmp FRASE_1[si],'$'        ; Comprobar si es el fin de la cadena
    jz imprimir_contador_pares ; Si es TRUE, finalizo el analisis de la secuencia
    inc si                     ; Si es FALSE, incremento el puntero
    loop bucle_pares           ; Saltar hasta bucle_pares para comparar el siguiente caracter

  contar_pares:
    inc si                     ; Incremento el puntero SI
    inc CONTADOR_PARES         ; Incremento el contador de numero pares
    cmp FRASE_1[si],'$'        ; Comprobar si es el fin de la cadena
    jz imprimir_contador_pares ; Si es TRUE, finalizo el analisis de la secuencia
    loop bucle_pares           ; Saltar hasta bucle_pares para comparar el siguiente caracter

  imprimir_contador_pares:
    mov DL,CONTADOR_PARES      ; Escribir la cadena en la salida estandar
    mov AH,2                   ; Servicio para imprimir un caracter
    int 21h

  MOV DX,OFFSET NLINEA         ; Escribir nlinea en la salida estandar
  MOV AH,9                     ; Indica que la cadena termina con '$'
  INT 21h                      ;

  ; c) Contar e imprimir cuantas veces aparece cada vocal minúscula en FRASE_2
  ; resultado final: 13
  ; resultado por vocal: a=5, e=3, i=2, o=3, u=0
  MOV DX,OFFSET EJERCICIO_3           ; Escribir ejercicio_3 en la salida estandar
  MOV AH,9                            ; Indica que la cadena termina con '$'
  INT 21H                             ;
  xor si,si                           ; Inicializar el puntero

  bucle_vocales:
    cmp FRASE_2[si],'a'               ; Comparar caracter con la vocal 'a'
    jz contar_vocales                 ; Si es TRUE: incrementar el valor del contador
    cmp FRASE_2[si],'e'               ; Comparar caracter con la vocal 'e'
    jz contar_vocales                 ; Si es TRUE: incrementar el valor del contador
    cmp FRASE_2[si],'i'               ; Comparar caracter con la vocal 'i'
    jz contar_vocales                 ; Si es TRUE: incrementar el valor del contador
    cmp FRASE_2[si],'o'               ; Comparar caracter con la vocal 'o'
    jz contar_vocales                 ; Si es TRUE: incrementar el valor del contador
    cmp FRASE_2[si],'u'               ; Comparar caracter con la vocal 'u'
    jz contar_vocales                 ; Si es TRUE: incrementar el valor del contador
    cmp FRASE_2[si],'$'               ; Comprobar si es el fin de la cadena
    jz imprimir_contador_vocales      ; Imprimir el resultado final
    inc si                            ; Incremento el puntero SI
    loop bucle_vocales                ; Analizo el caracter siguiente

  contar_vocales:
    inc si                            ; Incremento el puntero SI
    inc CONTADOR_VOCALES              ; Incremento el contador de vocales
    cmp FRASE_2[si],'$'               ; Comprobar si es el fin de la cadena
    jz imprimir_contador_vocales      ; Imprimir el resultado final
    loop bucle_vocales                ; Analizo el caracter siguiente

  ; Para imprimir correctamente el resultado:
  ; - Primero es necesario dividir por 10 el contador de vocales
  ; - Luego imprimir el cociente (primer numero)
  ; - Y finalmente el resto (segundo numero)
  imprimir_contador_vocales:
    mov ah,00                         ; Limpiar AH para poder usarlo luego en 'mov CONTADOR_RESTO_VOCALES,ah'
    mov al,CONTADOR_VOCALES           ; Copiar el valor del contador (dividendo) al segmento AL
    mov bl,10                         ; Guardar el valor 10 (divisor) en el segmento BL
    div bl                            ; Aplicar la division (AL/BL). El resto se guardara en AH
    mov CONTADOR_RESTO_VOCALES,ah     ; Copiar el resto de la operacion anterior
    mov dl,al                         ; Imprimir el 1º numero
    add dl,48                         ;
    mov ah,02h                        ;
    int 21h                           ;
    mov dl,CONTADOR_RESTO_VOCALES     ; Imprimir el 2º numero
    add dl,48                         ;
    mov ah,02h                        ;
    int 21h                           ;

  mov ax,4c00h                        ; Salir a DOS
  int 21h                             ;
end start