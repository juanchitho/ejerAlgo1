/*
Cargar una serie de números reales en un vector. No se conoce la cantidad
exacta de datos, pero se sabe que no superan los 100. No se conocen cotas
para los datos. Informar el valor máximo, la cantidad de veces que aparece y
la/s posición/es que ocupa
*/

#include <stdio.h>
#define MAX 100

typedef int Tvector[MAX];

void valorMaximo(Tvector vector, int cantidad){
    int i;
    int maximo = vector[0];
    int repeticiones=0;

    for( i=1 ; i < cantidad ; i++){
        if(vector[i] > maximo){
            maximo = vector[i];
        }
    }
    printf("el valor maximo es: %d \n",maximo);

    for (i = 0; i < cantidad; i++)
    {
        if(vector[i] == maximo){
            printf("la posicion que ocupa es: %d \n", i);
            repeticiones++;
        }
    }
    printf("las cantidades de veces que aparece el valor maximo son: %d \n",repeticiones);
    
}

int main(){
    Tvector vector = {};
    int cantidad = 0;
    int numero;
    char continuar = 's';

    while(cantidad < MAX && continuar == 's'){
        printf("ingrese un numero real:\n");
        scanf("%d", &numero);

        vector[cantidad] = numero;
        cantidad++;

        printf("Desea ingresar otro numero? (s para si, cualquier otra tecla para no): ");
        scanf(" %c", &continuar);
    }
    if(cantidad > 0){
        valorMaximo(vector , cantidad);
    }

    return 0;
}