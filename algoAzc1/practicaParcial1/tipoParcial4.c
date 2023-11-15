/*
Ejercicio 7:
Define una función en lenguaje C que reciba como parámetros dos matrices cuadradas (de igual número de filas y columnas) representadas por arreglos bidimensionales y determine si una es la transpuesta de la otra. La función debe devolver 1 si son transpuestas y 0 en caso contrario. Ambas matrices y sus dimensiones deben pasarse como parámetros, y la función debe modificar una variable booleana (a través de un puntero) para indicar si la transposición fue exitosa o no.

Escribe un programa que invoque la función, cree dos matrices cuadradas, las llene con datos, imprima las matrices originales, invoque la función y luego imprima el resultado de la transposición.


*/

#include <stdio.h>
#include <stdbool.h>

#define CANT 4

typedef int Tmatriz[CANT][CANT];

void matricesTranspuestas(Tmatriz matriz1, Tmatriz matriz2, bool *exito)
{
    int i, j;
    *exito = true;

    for (i = 0; i < CANT; i++)
    {
        for (j = 0; j < CANT; j++)
        {
            if (matriz1[i][j] != matriz2[j][i])
            {
                *exito = false;
            }
        }
    }
}

int main()
{

    Tmatriz matriz1, matriz2;

    // Solicitar elementos para la primera matriz
    printf("Ingrese los elementos de la primera matriz:\n");
    for (int i = 0; i < CANT; i++)
    {
        for (int j = 0; j < CANT; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Construir la segunda matriz como la transpuesta de la primera
    printf("Ingrese los elementos de la segunda matriz:\n");
    for (int i = 0; i < CANT; i++)
    {
        for (int j = 0; j < CANT; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    bool exito;

    matricesTranspuestas(matriz1, matriz2, &exito);

    if (exito)
    {
        printf("Las matrices son transpuestas.\n");
    }
    else
    {
        printf("Las matrices no son transpuestas.\n");
    }

    return 0;
}

// Ejemplos:
// Matriz 1:

// 1  2  3  4
// 5  6  7  8
// 9 10 11 12
// 13 14 15 16

// Matriz 2:
// 1  5  9 13
// 2  6 10 14
// 3  7 11 15
// 4  8 12 16