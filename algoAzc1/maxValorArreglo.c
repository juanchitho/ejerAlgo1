/*
 Escribir una función, que reciba como primer parámetro un arreglo unidimensional (vector) de valores enteros y como segundo parámetro, la cantidad de valores a recorrer (ML) ó la última posición en el arreglo; y devuelva el valor más alto que hay en el arreglo.

Suponga que el arreglo como máximo podrá almacenar hasta 10 valores.

Declare un tipo y máximo físico adecuado.

Para probar su función, incluya los siguientes casos de prueba, con la correspondiente invocación, e imprima lo que devuelve la función.

vec_1 = {8, -4, 7, 8, 0}
vec_2 = { -4, -7, -10}
vec_3 = { 425, -70, 500, 2, 43, 12, -1}
 */

# include <stdio.h>

# define MF 10

typedef int max_valor_arreglo[MF];

int maximo_valor_arreglo(max_valor_arreglo v, int ultima_pos){
    int i;
    int max = v[0];
    for (i=1; i<=ultima_pos; i++)
        if (v[i] > max)
            max = v[i];
    return max;
}

int main (){
    max_valor_arreglo vec_1 = {8, -4, 7, 8, 0};
    max_valor_arreglo vec_2 = { -4, -7, -10};
    max_valor_arreglo vec_3 = { 425, -70, 500, 2, 43, 12, -1};
    printf("El maximo valor del arreglo vec_1 es: %i \n", maximo_valor_arreglo(vec_1, 4));
    printf("El maximo valor del arreglo vec_2 es: %i \n", maximo_valor_arreglo(vec_2, 2));
    printf("El maximo valor del arreglo vec_3 es: %i \n", maximo_valor_arreglo(vec_3, 6));
    return 0;
}


