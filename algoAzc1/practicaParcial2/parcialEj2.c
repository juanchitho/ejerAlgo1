/*
Te daban un vector de numeros y su maximo logico, tipo lo pasabas por parametro a la funcion, y tenias que devolverlo invertido, pero solo intercambiar de posicion los numeros que eran distintos, es decir, si vos tenias un vec = {5, 6, 8, 5}, en la primer posicion como haces 5 contra 5 no deberias hacer intercambio y pasar al proximo

recorrer el vector una sola vez
*/

#include <stdio.h>
#define MF 10
typedef int Tvector [MF];

void invertirArreglo(Tvector vector, int ml){
    int i , ultiPos;
    int cantCambios = 0;

    for(i=0 ; i<ml/2 ; i++){
        ultiPos = vector[ml-1-i];
        if( ultiPos != vector[i]){
            vector[ml-1-i] = vector[i];
            vector[i]= ultiPos;
            cantCambios++;
        }

    }
    printf("cantidad de cambios : %d \n", cantCambios);
    
}

int main(){
    Tvector vector = { 54, 4, 5, 21, 8, 66, 5, 8, 9};
    int ml = 9;
    int i;

    invertirArreglo(vector, ml);

    for(i=0 ; i<=ml-1 ; i++){
        printf("%d -  ",vector[i]);
    }
    
    return 0;
}
