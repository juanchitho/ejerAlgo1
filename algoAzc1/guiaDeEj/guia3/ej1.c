/* Escribir una función que reciba un mes y un año; y devuelva la cantidad de días
del mes, considerando los años bisiestos.
Tenga en cuenta que un año bisiesto es aquel divisible por 4, salvo que sea
divisible por 100, en cuyo caso también debe ser divisible por 400.
 */

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

int cantDias(int anio, int mes)
{
    int dias;

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        dias = 30;
    }
    else if (mes == 2)
    {
        if (esBisiesto(anio))
        {
            dias = 29;
        }
        else
        {
            dias = 28;
        }
    }
    else
    {
        dias = 31;
    }

    return dias;
}

int main()
{
    int anio, mes, dias;

    printf("Ingrese el anio: \n");
    scanf("%d", &anio);

    printf("Ingrese el mes: \n");
    scanf("%d", &mes);

    dias = (cantDias(anio, mes));
    printf("\n%d dias", dias);

    return 0;
}