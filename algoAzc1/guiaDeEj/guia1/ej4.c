/* Ingresar tres números y hallar el mayor.  */

#include <stdio.h>

void ingresoDatos(int *num1, int *num2, int *num3)
{
    printf("Ingrese un numero: \n");
    scanf("%d", num1);

    printf("Ingrese un numero: \n");
    scanf("%d", num2);

    printf("Ingrese un numero: \n");
    scanf("%d", num3);
}

int numeroMayor(int num1, int num2, int num3)
{
    int max = 0;

    if (num1 > num2 && num1 > num3)
    {
        max = num1;
    }
    else if (num2 > num1 && num2 > num3)
    {
        max = num2;
    }
    else
    {
        max = num3;
    }

    return max;
}

int main()
{
    int num1, num2, num3;

    ingresoDatos(&num1, &num2, &num3);

    int max = numeroMayor(num1, num2, num3);

    printf("El numero maximo es %d", max);
}