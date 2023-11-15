/* Dado un listado de valores numéricos i y x, donde i es un entero mayor que
0 y x un real, almacenar x en la posición i de un vector. El listado no se ingresa
ordenado por posición. Informar la cantidad de números y el contenido del
vector indicando la posición ocupada por cada número a partir de la primera
posición */

#include <stdio.h>

int vec[3] = {0};
int listado[][2] = {{1, 8}, {2, 5}, {0, 1}};

int main()
{

    int filas = sizeof(listado) / sizeof(listado[0]);
    for (int i = 0; i < filas; i++)
    {
        printf("Posicion %d: %d\n", listado[i][0], listado[i][1]);
        vec[listado[i][0]] = listado[i][1];
    }

    printf("Cantidad de numeros: %d\n", filas);
    for (int i = 0; i < filas; i++)
    {
        printf("Posicion %d: %d\n", i, vec[i]);
    }
}
