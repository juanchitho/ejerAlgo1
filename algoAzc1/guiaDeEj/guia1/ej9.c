/* Dada una fecha año, mes y día, informar si es correcta o no */

#include <stdio.h>
#include <stdbool.h>

bool esBisiesto(int anio)
{
    bool check = false;

    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
    {
        check = true;
    }

    return check;
}

bool fechaValida(int anio, int mes, int dia)
{
    bool check = true;

    if (anio < 1 || mes < 1 || mes > 12 || dia < 1)
    {
        check = false;
    }

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dia > 30)
        {
            check = false;
        }
    }
    else if (mes == 2)
    {
        if (esBisiesto(anio))
        {
            if (dia > 29)
            {
                check = false;
            }
        }
        else if (dia > 28)
        {
            check = false;
        }
    }
    else
    {
        if (dia > 31)
        {
            check = false;
        }
    }

    return check;
}

int main()
{
    int anio, mes, dia;

    printf("Ingrese el anio: \n");
    scanf("%d", &anio);

    printf("Ingrese el mes: \n");
    scanf("%d", &mes);

    printf("Ingrese el dia: \n");
    scanf("%d", &dia);

    if (fechaValida(anio, mes, dia))
    {
        printf("La fecha es correcta");
    }
    else
    {
        printf("La fecha es incorrecta");
    }
    return 0;
}