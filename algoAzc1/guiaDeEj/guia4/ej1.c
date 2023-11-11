/* Escribir un programa que solicite el ingreso de 2 valores enteros y luego informe
el resultado de multiplicarlos, pero mediante sumas sucesivas.
Optimizar el cálculo, realizando la menor cantidad de ciclos posibles.
Tener en cuenta que el usuario puede ingresar valores negativos. */

#include <stdio.h>
#include <stdbool.h>

int multiplicarSumasSucesivas()
{
    int a = 0, b = 0, i;
    int resultado = 0;
    bool negativo = false;

    printf("Ingrese un numero entero: \n");
    scanf("%d", &a);

    printf("Ingrese otro numero entero: \n");
    scanf("%d", &b);

    if (a < 0)
    {
        a = -a;
        negativo = true;
    }

    if (b < 0)
    {
        b = -b;
        negativo = true;
    }

    for (i = 0; i < a; i++)
    {
        resultado += b;
    }

    if (negativo)
    {
        resultado *= -1;
    }

    return resultado;
}

int main()
{
    int resultado;

    resultado = multiplicarSumasSucesivas();

    printf("%d", resultado);

    return 0;
}