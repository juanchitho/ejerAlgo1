/* Se tiene un listado de alumnos que consiste en número de padrón y 4
notas por alumno. Informar el mayor y el menor promedio registrado
junto con el numero de padrón del alumno, suponiendo que ambos son
únicos.  */

#include <stdio.h>

int main()
{
    int padron, max_padron, min_padron;
    float promedio = 0, nota1 = 0, nota2 = 0, nota3 = 0, nota4 = 0;
    float max_promedio = 0, min_promedio = 10;

    printf("Ingrese el numero de padron (0 para salir): \n");
    scanf("%d", &padron);

    while (padron != 0)
    {
        printf("Ingrese las 4 notas del alumno: \n");
        scanf("%f %f %f %f", &nota1, &nota2, &nota3, &nota4);

        promedio = (nota1 + nota2 + nota3 + nota4) / 4;

        if (promedio > max_promedio)
        {
            max_promedio = promedio;
            max_padron = padron;
        }

        if (promedio < min_promedio)
        {
            min_promedio = promedio;
            min_padron = padron;
        }

        printf("Ingrese el numero de padron (0 para salir): \n");
        scanf("%d", &padron);
    }

    printf("El alumnno con mayor promedio es %d con promedio %.2f \n", max_padron, max_promedio);
    printf("El alumnno con mayor promedio es %d con promedio %.2f \n", min_padron, min_promedio);

    return 0;
}