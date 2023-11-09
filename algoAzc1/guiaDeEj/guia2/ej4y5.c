/* . Dados a y b enteros, informar el producto de ambos por sumas
sucesivas. */

#include <stdio.h>

int main()
{
    int a, b, i, acumulador = 0;

    printf("Ingrese el valor de a:\n");
    scanf("%d", &a);

    printf("Ingrese el valor de b:\n");
    scanf("%d", &b);

    for (i = 0; i < b; i++)
    {
        acumulador += a;
    }

    printf("Producto %d", acumulador);

    return 0;
}

/* . Dados a y n enteros, informar la potencia enésima de a por productos
sucesivos.  */

int main()
{
    int a, n, i, potencia = 1;

    printf("Ingrese el valor de a:\n");
    scanf("%d", &a);

    printf("Ingrese el valor de n:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        potencia *= a;
    }

    printf("Potencia %d", potencia);

    return 0;
}