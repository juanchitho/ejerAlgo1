/* Escribir una función que reciba un valor n, entero, y devuelva la suma de los
valores entre 0 y n.
 */

#include <stdio.h>

int sumaN(int n)
{
    int acumulador = 0;
    for (int i = 0; i <= n; i++)
    {
        acumulador += i;
    }

    return acumulador;
}

int main()
{
    int valor;

    printf("Ingrese un valor entero n: ");
    scanf("%d", &valor);

    int resultado = sumaN(valor);

    printf("La suma de los valores entre 0 y %d es: %d\n", valor, resultado);

    return 0;
}