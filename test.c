/* Dadas las siguientes declaraciones de constantes y tipos

#define MAX 1000
typedef int Tvector[MAX]

Desarrollar una funcion en lenguaje C que reciba como parametros un vector de tipo Tvector
ya cargado y su maximo logico, que devuelva:
- un valor de verdad que informe si el vector esta ordenado ascendentemente
- la menor diferencia entre elementos contiguos
- en el caso que no este ordenado la diferencia a retornar es cero.

Ejemplo: Dado el siguiente vector (cuyo maximo logico es 7)
La funcion deberia devolver TRUE y 1 (diferencia entre 27 y 28)
0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 15 | 18 | 20 | 27 | 28 | 46 | 70

Se solicita resolver lo solicitado recorriendo una sola vez al vector */

#include <stdio.h>
#include <stdbool.h>

#define MAX 1000
typedef int Tvector[MAX];

void verificarOrdenado(Tvector vector, int maxLogico, bool *ordenado, int *menor_diferencia)
{
    *ordenado = true;
    *menor_diferencia = vector[maxLogico - 1] - vector[0];

    for (int i = 1; i < maxLogico; i++)
    {
        int diferencia = vector[i] - vector[i - 1];
        if (diferencia < 0)
        {
            *ordenado = false;
            *menor_diferencia = 0;
        }
        else
        {
            if (diferencia < *menor_diferencia)
            {
                *menor_diferencia = diferencia;
            }
            else
            {
                *menor_diferencia = *menor_diferencia;
            }

            // *menor_diferencia = diferencia < *menor_diferencia ? diferencia : *menor_diferencia;
        }
    }
}

int main()
{
    Tvector vector = {0, 1, 2, 3, 4, 5, 6, 7, 15, 18, 20, 27, 28, 46, 70};
    int maxLogico = 15;
    bool ordenado;
    int menor_diferencia;

    verificarOrdenado(vector, maxLogico, &ordenado, &menor_diferencia);

    if (ordenado)
    {
        printf("El vector está ordenado ascendentemente.\n");
        printf("La menor diferencia entre elementos contiguos es: %d\n", menor_diferencia);
    }
    else
    {
        printf("El vector no está ordenado ascendentemente. La menor diferencia es: %d\n", menor_diferencia);
    }

    return 0;
}