/* Se dan como datos de entrada las fechas de nacimiento (día, mes, año)
y los números de DNI de cada integrante de un grupo. Se indica fin de
datos de entrada cuando día = 0. Muestre por pantalla el número de DNI
del integrante más joven del grupo.  */

#include <stdio.h>

int main()
{
    int dia = 0, mes = 0, anio = 0, dni = 0;
    int dni_joven = 0;
    int anio_joven = 0, mes_joven = 0, dia_joven = 0;

    printf("Ingrese el dia de nacimiento (0 para finalizar):\n");
    scanf("%d", &dia);

    while (dia != 0)
    {
        printf("Ingrese el mes de nacimiento:\n");
        scanf("%d", &mes);
        printf("Ingrese el anio de nacimiento:\n");
        scanf("%d", &anio);
        printf("Ingrese el DNI:\n");
        scanf("%d", &dni);

        if (anio > anio_joven)
        {
            mes_joven = 0;
            anio_joven = anio;

            if (mes > mes_joven)
            {
                dia_joven = 0;
                mes_joven = mes;

                if (dia > dia_joven)
                {
                    dia_joven = dia;
                    dni_joven = dni;
                }
            }
        }

        printf("Ingrese el dia de nacimiento (0 para finalizar):\n");
        scanf("%d", &dia);
    }

    printf("Integrante mas joven del grupo %d\n", dni_joven);
    return 0;
}