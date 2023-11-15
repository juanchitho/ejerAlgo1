/* Dado un vector a de longitud n ordenado ascendente y un elemento p del
mismo tipo que los elementos del vector, intercalar p en el vector a de modo
que siga ordenado. */

#include <stdio.h>

#include <stdio.h>

void insertarElementoOrdenado(int a[], int *n, int p)
{
    int i = *n - 1;

    while (i >= 0 && a[i] > p)
    {
        a[i + 1] = a[i];
        i--;
    }

    a[i + 1] = p;

    (*n)++;
}

int main()
{
    int n, p;

    printf("Ingrese el tamaño del vector a: ");
    scanf("%d", &n);

    int a[n];

    printf("Ingrese los elementos del vector a en orden ascendente:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Ingrese el elemento a insertar: ");
    scanf("%d", &p);

    insertarElementoOrdenado(a, &n, p);

    printf("Vector a despues de insertar %d:\n", p);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
