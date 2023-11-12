/*
Dadas las siguientes declaraciones de constantes y tipos:

#define MAX 100
typedef  int Tvector[MAX];

Desarrollar una funcion en lenguaje C que reciba como parametros un vector de tipo Tvector ya cargado con datos que se encuentren en ORDEN ASCENDENTEMENTE, su maximo logico y un numero entero que debe ser intercalado en el vector , de modo que siga ordenado. Se espera que la funcion devuleva al modulo invocante 1 si pudo realizar lo solictado y 0 si no pudo hacerlo. Tanto el vector como el maximo logico actualizados deben devolverse sobre los parametros recibidos.

se solicita resolver lo solicitado recorriendo una sola vez al vector y sin utilizar un arreglo auxiliar.

escribir una programa que invoque dicha funcion.

*/
#include <stdio.h>
#define MAX 100

typedef int Tvector[MAX];


int intercalaVector(Tvector vector, int numero, int *ml){
    int i = *ml - 1;
    int devolver = 1;

    if(*ml >= MAX){
        devolver = 0;
    }else{
        while(i >= 0 && vector[i] > numero){
            //mueve los numeros 1 posicion, hasta que llega a la posicion correcta en la que iria el numero
            vector[i + 1]= vector[i];
            i--;
        }
        //cuando rompe
        vector[i + 1]= numero; //agrega a este numero
        (*ml)++;
        
    }
    return devolver;
}

int main()
{
    Tvector vector = {1,5,15,20,39,201};
    int numero = 7;
    int ml = 6;
    int devolver = intercalaVector(vector , numero , &ml);
    printf(" %d \n" , devolver );
     if (devolver == 1 ) {
        
        printf("Vector actualizado: ");
        
        for (int i = 0; i < ml; i++) {
            printf("%d ", vector[i]);
        }
        printf("\n");
        printf("%d",ml);
    }
    return 0;
}
