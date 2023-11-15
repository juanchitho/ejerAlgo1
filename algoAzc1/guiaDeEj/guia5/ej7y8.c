/* Dado un vector a de longitud n y un elemento p del mismo tipo que los
elementos del vector, buscar p en el vector a y devolver la posición que ocupa
en caso de encontrarlo o una señal en caso contrario. Suponer que no hay
repeticiones. */

#include <stdio.h>
#include <stdbool.h>

int buscarElemento(int a[], int n, int p)
{
    int posicion = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == p)
        {
            posicion = i;
                }
    }

    return posicion;
}

int buscarElementoOrdenado(int a[], int n, int p)
{
    int inf = 0;
    int sup = n - 1;
    int posicion = -1;
    bool terminado = false;

    while (!terminado)
    {
        if ((p > a[sup]) || (p < a[inf]))
        {
            terminado = true; // NO ESTA => FIN DE LA BUSQUEDA
            posicion = -1;
        }
        else
        {
            int mit = (inf + sup) / 2;
            if (a[mit] == p)
            {
                terminado = true; // ENCONTRADO => FIN DE LA BUSQUEDA
                posicion = mit;
            }
            else if (p > a[mit])
                inf = mit + 1;
            else
                sup = mit - 1;
        }
    }

    return posicion;
}

int main()
{
    int n, p;

    printf("Ingrese el tamaño del vector a: ");
    scanf("%d", &n);

    int a[n];

    printf("Ingrese los elementos del vector a:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Ingrese el elemento a buscar: ");
    scanf("%d", &p);

    int posicion = buscarElemento(a, n, p);

    if (posicion != -1)
    {
        printf("Elemento %d encontrado en la posicion %d\n", p, posicion);
    }
    else
    {
        printf("Elemento %d no encontrado en el vector\n", p);
    }

    return 0;
}
