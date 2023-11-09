/* Escribir una función que reciba un valor y calcule el factorial del mismo. Si no se
puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo
contrario deberá devolver el valor calculado.
 */

#include <stdio.h>

long long calculoFactorial(int n)
{
    long long factorial;

    if (n < 0)
    {
        factorial = 0;
    }
    else if (n == 0)
    {
        factorial = 1;
    }
    else
    {
        factorial = 1;
        for (int i = 1; i <= n; i++)
        {
            factorial *= i;
        }
    }

    return factorial;
}

int main()
{
    int valor;

    printf("Ingrese un valor para calcular su factorial: ");
    scanf("%d", &valor);

    long long resultado = calculoFactorial(valor);

    printf("Factorial de %d: %lld", valor, resultado);

    return 0;
}