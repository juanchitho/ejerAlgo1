/* El producto de Wallis es una expresión matemática, utilizada para representar el
valor del número Pi, que fue descubierta por John Wallis en 1655 y que
establece que:
Escribir una función, que reciba por parámetro, el valor más alto a utilizar en el
cálculo (n). La función debe calcular el valor de Pi utilizando la fórmula de Wallis
y devolver el valor de Pi obtenido.
Proba la función, utilizando al menos, como valor de n, 100, 1000 y 10000.  */

#include <stdio.h>

double calcularPi(int n)
{
    double pi = 2.0; // Inicializar con el primer término (2/1)

    for (int i = 1; i <= n; i++)
    {
        double numerador = 2.0 * i;
        double denominador1 = numerador - 1;
        double denominador2 = numerador + 1;
        pi *= (numerador / denominador1) * (numerador / denominador2);
    }

    return pi;
}

int main()
{
    int n;

    printf("Ingrese el valor de n para calcular Pi: ");
    scanf("%d", &n);

    double pi = calcularPi(n);

    printf("El valor de Pi calculado con n = %d es: %.15lf\n", n, pi);

    return 0;
}
