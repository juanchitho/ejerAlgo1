/* Ingresar un número que representa un mes, escribir el nombre del mes
correspondiente. Puede haber error en el número dado.  */

#include <stdio.h>

int main()
{
    int mes;

    printf("Ingrese un numero de mes (de 1 a 12): \n");
    scanf("%d", &mes);

    if (mes < 1 || mes > 12)
    {
        printf("Numero incorrecto");
    }
    else
    {
        if (mes == 1)
        {
            printf("Enero1");
        }
        if (mes == 2)
        {
            printf("Enero2");
        }
        if (mes == 3)
        {
            printf("Enero3");
        }
        if (mes == 4)
        {
            printf("Enero4");
        }
        if (mes == 5)
        {
            printf("Enero5");
        }
        if (mes == 6)
        {
            printf("Enero6");
        }
        if (mes == 7)
        {
            printf("Enero7");
        }
        if (mes == 8)
        {
            printf("Enero8");
        }
        if (mes == 9)
        {
            printf("Enero9");
        }
        if (mes == 10)
        {
            printf("Enero10");
        }
        if (mes == 11)
        {
            printf("Enero11");
        }
        if (mes == 12)
        {
            printf("Enero12");
        }
    }

    return 0;
}