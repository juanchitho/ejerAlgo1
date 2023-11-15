/* Dado n entero positivo y un listado de n números reales, almacenar los
números en un vector en el orden de entrada. Informar el contenido del vector
indicando la posición ocupada por cada número a partir de la primera posición. */

#include <stdio.h>

int main()
{
    int n;
    int num;

    printf("Ingrese un numero positivo:\n");
    scanf("%d", &n);

    int vec[n];

    for (int i = 0; i < n; i++)
    {
        printf("Ingrese un numero:\n");
        scanf("%d", &num);

        vec[i] = num;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Posicion %d: %d\n", i, vec[i]);
    }

    return 0;
}