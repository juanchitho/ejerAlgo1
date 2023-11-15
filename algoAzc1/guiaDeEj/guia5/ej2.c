/* Dado un listado de números reales del cual no se conoce la cantidad,
almacenar los números en un vector en el orden de entrada. Informar la
cantidad de números y el contenido del vector indicando la posición ocupada
por cada número a partir de la primera posición.  */

#include <stdio.h>
#define MAX 1000

int main() {
    int vector[MAX];
    int cantidad = 0;
    int numero;
    char continuar = 's';

    
    while (cantidad < MAX && continuar == 's') {
        printf("ingrese numero real:\n");
        scanf("%d", &numero);

        // Almacenar el número en el vector
        vector[cantidad] = numero;
        cantidad++;

       
        printf("Desea ingresar otro numero? (s para si, cualquier otra tecla para no): ");
        scanf(" %c", &continuar);
    }

  
    printf("cantidad de numeros: %d\n", cantidad);


    printf("Contenido del vector:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("Posicion %d: %d\n", i + 1, vector[i]);
    }

    return 0;
}