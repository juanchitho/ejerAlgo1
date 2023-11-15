/* Cargar un conjunto de números de documento en un vector. No se conoce la
cantidad de datos válidos. Informar el número de documento más alto del
conjunto y la posición que ocupa. Puede haber repetición, en este caso
informar todas las posiciones que ocupa.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

typedef int Tvector[MAX];

int main()
{
    bool continuar = true;
    int dni;
    int max_logico = 0;
    int dni_maximo = 0;
    int contador_posicion = 0;
    Tvector posiciones = {0};
    Tvector vector = {0};

    while (continuar)
    {
        printf("Ingrese un numero de documento: \n");
        scanf("%d", &dni);

        if (dni == 0)
        {
            continuar = false;
        }
        else
        {
            vector[max_logico] = dni;
            max_logico++;
        }

        if (max_logico == MAX)
        {
            continuar = false;
        }
    }

    for (int i = 0; i <= max_logico; i++)
    {
        if (vector[i] > dni_maximo)
        {
            dni_maximo = vector[i];
            posiciones[0] = i;
            contador_posicion = 1;
        }
        else if (vector[i] == dni_maximo)
        {
            posiciones[contador_posicion] = i;
            contador_posicion++;
        }
    }

    printf("El valor maximo es: %d\n", dni_maximo);
    printf("Se encuentra en la(s) posicion(es): ");

    for (int i = 0; i < contador_posicion; i++)
    {
        printf("%d ", posiciones[i]);
    }
    printf("\n");

    return 0;
}