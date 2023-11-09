/* Dado un mes escribir la cantidad de días de dicho mes.  */

#include <stdio.h>

int main()
{
    int mes;

    printf("Ingrese el número de mes (1-12): ");
    scanf("%d", &mes);

    if (mes < 1 || mes > 12)
    {
        printf("Número de mes no válido. Debe estar en el rango de 1 a 12.\n");
    }
    else
    {
        int dias;

        if (mes == 2)
        {
            // Febrero tiene 28 o 29 días, dependiendo de si es un año bisiesto
            int anio;
            printf("Ingrese el año: ");
            scanf("%d", &anio);

            if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
            {
                // Es un año bisiesto, febrero tiene 29 días
                dias = 29;
            }
            else
            {
                // No es un año bisiesto, febrero tiene 28 días
                dias = 28;
            }
        }
        else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        {
            // Abril, junio, septiembre y noviembre tienen 30 días
            dias = 30;
        }
        else
        {
            // Los demás meses tienen 31 días
            dias = 31;
        }

        printf("El mes %d tiene %d días.\n", mes, dias);
    }

    return 0;
}