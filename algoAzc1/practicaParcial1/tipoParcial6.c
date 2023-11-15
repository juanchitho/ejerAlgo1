/* Ejercicio 9:
Define una función en lenguaje C que reciba como parámetros un arreglo unidimensional de números reales y su tamaño, y devuelva la media de los elementos del arreglo. Los resultados deben ser devueltos a través de parámetros pasados por referencia.

Escribe un programa que invoque la función, cree un arreglo de números reales, imprima el arreglo original, invoque la función y luego imprima la media */

#include <stdio.h>
#define MAX 100

void estadistica(float arreglo[], int tamanio, float *media)
{
    int i;
    float suma;
    for (i = 0; i < tamanio; i++)
    {
        suma += arreglo[i];
    }

    *media = suma / tamanio;
}

int main()
{
    int tamanio;

    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &tamanio);

    if (tamanio <= 0 || tamanio > MAX)
    {
        printf("Tamaño del arreglo no válido.\n");
        return 1;
    }

    float arreglo[tamanio];

    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < tamanio; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &arreglo[i]);
    }

    float media;

    estadistica(arreglo, tamanio, &media);
    printf("Media: %.2f\n", media);

    return 0;
}