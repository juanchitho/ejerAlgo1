/* Dados 2 vectores a y b de longitudes n y m, el primero ordenado ascendente
y el segundo ordenado descendente, crear un nuevo vector c de n + m
elementos intercalando los elementos de a y b de modo que c quede ordenado
ascendente.  */

#include <stdio.h>

void intercalarVectores(int a[], int n, int b[], int m, int c[])
{
    int i = 0, j = m - 1, k = 0;

    while (i < n && j >= 0)
    {
        if (a[i] <= b[j]) // a[0] <= b[9]
        {
            c[k] = a[i]; // c[0] = a[0]
            k++;
            i++;
        }
        else // a[0] > b[9]
        {
            c[k] = b[j]; // c[0] = b[9]
            k++;
            j--;
        }
    }

    while (i < n)
    {
        c[k] = a[i];
        k++;
        i++;
    }

    while (j >= 0)
    {
        c[k] = b[j];
        k++;
        j--;
    }
}

int main()
{
    int n, m;

    printf("Ingrese el tamaño del vector a: ");
    scanf("%d", &n);

    printf("Ingrese el tamaño del vector b: ");
    scanf("%d", &m);

    int a[n], b[m], c[n + m];

    printf("Ingrese los elementos del vector a en orden ascendente:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Ingrese los elementos del vector b en orden descendente:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    intercalarVectores(a, n, b, m, c);

    printf("Vector c en orden ascendente:\n");
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}
