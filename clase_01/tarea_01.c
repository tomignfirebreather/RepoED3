/*
 * --------------------------------------------------------------------------------
 * Archivo: tarea_01.c
 * Autor: Tomás Ignacio Corbalán
 * Fecha: 12 de agosto de 2024
 * Materia: ED3
 * Descripción: Este programa muestra la representación en código ASCII
 *              y en código binario de cada carácter de un texto
 *              ingresado por el usuario mediante la terminal.
 * --------------------------------------------------------------------------------
 */
#include <stdio.h>

void imprimirNumeroBinario (int num) {
    // Asumo que el número ingresado es de 8 bits (caracteres ASCII imprimibles)
    for (int i=7; i>=0; i--) {
        int bit = (num >> i) & 1; // Realizo el desplazamiento y aplico la operacion lógica AND bit a bit con "1"
        printf("%d", bit); // Imprimo bit a bit en formato decimal
    }
}

int main () {
    char texto[256]; // Defino un tamaño máximo para el texto para no desbordar el buffer
    printf("Ingrese un texto: ");
    scanf("%255[^\n]", texto); // Leer hasta 255 caracteres como máximo o hasta un salto de línea
    int i = 0;
    printf("\nTexto: %s\n\n", texto);
    printf("Caracter | Decimal | Binario\n");
    printf("-------------------------------------\n");
    while (texto[i] != '\0') {
        char caracter = texto[i]; // Almaceno el caracter
        int numeroDecimal = (int)caracter; // Almaceno el valor en decimal del caracter
        printf("    %c    |   %3d   | ", caracter, numeroDecimal); // Imprimo el caracter, su valor en decimal y su valor en binario
        imprimirNumeroBinario (numeroDecimal);
        printf("\n");
        i++;
    }
    return 0;
}