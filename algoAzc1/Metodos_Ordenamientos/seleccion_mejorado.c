#include <stdio.h>

#define MF 5

typedef int tvector[MF];

void mostrar(tvector vector, int n)
{
    int k;
    for (k = 0; k < n; k++)
        printf("%d ", vector[k]);
}

void ordenar_seleccion(tvector vector, int n)
{
    int i, j, min_index, temp;

    for (i = 0; i < n - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < n; j++)
        {
            if (vector[j] < vector[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            temp = vector[i];
            vector[i] = vector[min_index];
            vector[min_index] = temp;
        }
        mostrar(vector, n);
        printf("   i= %d   j= %d   j+1= %d index= %d\n", i, j, j + 1, min_index);
    }
}

int main()
{
    tvector vec = {4, 3, 5, 2, 1};

    printf("VECTOR ORIGINAL\n");
    mostrar(vec, MF);

    printf("\n\nMETODO DE SELECCION MEJORADO\n\n");
    ordenar_seleccion(vec, MF);

    printf("\nVECTOR FINAL\n");
    mostrar(vec, MF);
    printf("\n");

    return 0;
}
