/* Se tienen los siguientes datos de un empleado: numero de legajo,
categoría a la que pertenece, fecha de ingreso a la empresa, cantidad
de horas trabajadas en el mes y cantidad de horas extras trabajadas.
• La categoría puede ser: administrativo, técnico, profesional u
operario.
• El valor de la hora trabajada por categoría es: $5, $7, $12 y $3
respectivamente.
• Las horas extras tienen un valor superior en un 50%.
• El sueldo a cobrar se compone de: sueldo base (cantidad de
horas * valor hora) + monto por horas extras + porcentaje por años de antigüedad -un descuento del 3% por obra social -un
descuento del 10% por jubilación.
• Los porcentajes se calculan sobre el sueldo base.
• La antigüedad se calcula según: 5% entre 1 y 3 años, 10% entre 4
y 6 años, 20% entre 7 y 10 años, 50% entre 11 y 15 años, 100%
más de 16 años (años cumplidos). La fecha de procesamiento se
ingresa una única vez.
i. Informar el legajo, el sueldo base, el monto por horas
extras si existe, el monto por antigüedad, el monto de cada
descuento y el sueldo a cobrar.  */

#include <stdio.h>

int main()
{
    int numeroLegajo;
    char categoria;
    int horasTrabajadas;
    int horasExtras;
    int aniosAntiguedad;
    double valorHora, valorHoraExtra, sueldoBase, montoHorasExtras, montoAntiguedad, sueldo, descuentoObraSocial, descuentoJubilacion;

    printf("Ingrese el número de legajo del empleado: ");
    scanf("%d", &numeroLegajo);

    printf("Ingrese la categoría del empleado (A: Administrativo, T: Técnico, P: Profesional, O: Operario): ");
    scanf(" %c", &categoria);

    if (categoria == 'A')
    {
        valorHora = 5.0;
    }
    else if (categoria == 'T')
    {
        valorHora = 7.0;
    }
    else if (categoria == 'P')
    {
        valorHora = 12.0;
    }
    else if (categoria == 'O')
    {
        valorHora = 3.0;
    }
    else
    {
        printf("Categoría no válida.\n");
        return 1;
    }

    printf("Ingrese la cantidad de horas trabajadas en el mes: ");
    scanf("%d", &horasTrabajadas);

    printf("Ingrese la cantidad de horas extras trabajadas: ");
    scanf("%d", &horasExtras);

    valorHoraExtra = valorHora * 1.5;

    printf("Ingrese la cantidad de años de antigüedad del empleado: ");
    scanf("%d", &aniosAntiguedad);

    sueldoBase = horasTrabajadas * valorHora;
    montoHorasExtras = horasExtras * valorHoraExtra;

    if (aniosAntiguedad >= 1 && aniosAntiguedad <= 3)
    {
        montoAntiguedad = sueldoBase * 0.05;
    }
    else if (aniosAntiguedad >= 4 && aniosAntiguedad <= 6)
    {
        montoAntiguedad = sueldoBase * 0.10;
    }
    else if (aniosAntiguedad >= 7 && aniosAntiguedad <= 10)
    {
        montoAntiguedad = sueldoBase * 0.20;
    }
    else if (aniosAntiguedad >= 11 && aniosAntiguedad <= 15)
    {
        montoAntiguedad = sueldoBase * 0.50;
    }
    else
    {
        montoAntiguedad = sueldoBase;
    }

    descuentoObraSocial = sueldoBase * 0.03;
    descuentoJubilacion = sueldoBase * 0.10;

    sueldo = sueldoBase + montoHorasExtras + montoAntiguedad - descuentoObraSocial - descuentoJubilacion;

    printf("Legajo: %d\n", numeroLegajo);
    printf("Sueldo Base: %.2lf\n", sueldoBase);
    if (montoHorasExtras > 0)
    {
        printf("Monto por Horas Extras: %.2lf\n", montoHorasExtras);
    }
    printf("Monto por Antigüedad: %.2lf\n", montoAntiguedad);
    printf("Descuento por Obra Social: %.2lf\n", descuentoObraSocial);
    printf("Descuento por Jubilación: %.2lf\n", descuentoJubilacion);
    printf("Sueldo a Cobrar: %.2lf\n", sueldo);

    return 0;
}
