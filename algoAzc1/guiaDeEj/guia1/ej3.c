/* Calcular el sueldo de un operario ingresando por teclado la cantidad de
horas que trabajó en el mes y el valor de la hora. */

#include <stdio.h>

void ingresarDatos(int *horas, int *precio)
{
    printf("Ingrese las horas que trabajo en el mes: \n");
    scanf("%d", horas);

    printf("Ingrese el valor de la hora: \n");
    scanf("%d", precio);
}

int calcularSueldo(int horas, int precio)
{
    int sueldo = horas * precio;
    return sueldo;
}

int main()
{
    int horas, precio;
    ingresarDatos(&horas, &precio);
    int sueldo = calcularSueldo(horas, precio);

    printf("%d", sueldo);

    return 0;
}