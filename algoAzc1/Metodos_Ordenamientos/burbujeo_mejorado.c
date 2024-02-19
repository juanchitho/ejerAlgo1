#include <stdio.h>
#include <stdbool.h>

#define MF 5

typedef int tvector[MF];

void mostrar(tvector vector, int n)
{
    int k;
    for (k = 0; k < n; k++)
        printf("%d ", vector[k]);
}

void ordenar_burbujeo(tvector vector, int n)
{
    int i = 0;
    int temp;
    bool intercambio = true; // Variable para verificar si se realizan intercambios

    while (i < n - 1 && intercambio)
    {
        intercambio = false; // Inicialmente no se ha realizado ningún intercambio

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
                intercambio = true; // Se realizó un intercambio en esta pasada
            }
            mostrar(vector, n);
            printf("   i= %d   j= %d   j+1= %d \n", i, j, j + 1);
        }
        printf("\n");
        i++;
    }
}

int main()
{
    tvector vec = {4, 3, 5, 2, 1};

    printf("VECTOR ORIGINAL\n");
    mostrar(vec, MF);

    printf("\n\nMETODO DE BURBUJEO MEJORADO\n\n");
    ordenar_burbujeo(vec, MF);

    printf("\nVECTOR FINAL\n");
    mostrar(vec, MF);
    printf("\n");

    return 0;
}
