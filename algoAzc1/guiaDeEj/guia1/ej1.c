/* 1) Ingresar un número entero y decir si:
a) es par o impar.
b) es mayor, menor o igual a cero. */

#include <stdio.h>

/* parte a */

void esPar(int numero)
{
    if (numero % 2 == 0)
    {
        printf("Es par\n");
    }
    else
    {
        printf("Es impar\n");
    }
}

/* parte b */

void mayoria(int numero)
{
    if (numero > 0)
    {
        printf("Es mayor a cero\n");
    }
    else if (numero == 0)
    {
        printf("Es igual a cero\n");
    }
    else
    {
        printf("Es menor a cero\n");
    }
}

int main()
{
    int numero = 0;

    esPar(numero);
    mayoria(numero);

    return 0;
}