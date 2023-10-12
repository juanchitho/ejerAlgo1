/*
Dadas las siguientes declaraciones de constantes y tipos

#define MAX 1000
typedef int Tvector[MAX]

Desarrollar una función en lenguaje C que reciba como parámetros un vector de tipo Tvector
ya cargado con números positivos y su máximo lógico, que devuelva:
un valor entero igual a 1 que informe si el vector esta ordenado ascendentemente, 0 en
el caso que no lo esté
la menor diferencia entre elementos contiguos.

En el caso que no esté ordenado la diferencia a retornar es cero.
Ejemplo: - Dado el siguiente vector (cuyo máximo lógico es 7) 
La función debería devolver 1 ya que está ordenado y 1 (diferencia entre 27 y 28)
0  |1     |2  |3  |4  |5  |6  |7  |…
15 |18 |20 |27 |28 |46 |70 |-  |-


Se solicita resolver lo solicitado recorriendo una sola vez al vector
*/
#include <stdio.h>

#define MAX 1000
typedef int Tvector[MAX];

void ordenado(Tvector vector, int max, int *orden, int *diferencia){
    int i;
    *orden=1;
    *diferencia=0;
    for(i=0; i<max-1; i++){
        if(vector[i]>vector[i+1]){
            *orden=0;
        }
        if(vector[i+1]-vector[i]<*diferencia){
            *diferencia=vector[i+1]-vector[i];
        }
    }
}