/* Calcular la suma de los n primeros números naturales. */

#include <stdio.h>

int main()
{
    int n, suma;

    printf("Ingrese un valor de n: \n");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Numero invalido");
    }
    else
    {
        suma = (n * (n + 1)) / 2;
        printf("La suma de los primeros %d numeros naturales es: %d", n, suma);
    }

    return 0;
}