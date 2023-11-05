/*
desarrollar una funcion que reciba como parametro un numero entero y devuelva al modulo invocante los siguientes valores:
- el mayor digito que compone al numero entero recibido, y
- la cantidad de veces que dicho digito maximo se encuentra en el numero entero recibido.

ejemplo ~ el numero entero con el que se invoca la funcion es 58381
        ~ la funcion debe devolver los valores 8 y 2 . dado que 8 es el digito maximo y se encuentra 2 veces en el numero 58381

escribir un programa que invoque dicha funcion.

*/

#include <stdio.h>

void mayor_digito(long int numero, int *mayor , int *contador){
    *mayor=0;
    *contador=0;
    int ultiDigito;
    while(numero>0){
        ultiDigito=numero%10;
        
        if(ultiDigito >= *mayor){
            (*mayor)=ultiDigito;
            if(ultiDigito == *mayor){
                (*contador)++;
            }
        }
        numero=numero/10;
    }
}

int main(){
    long int numero = 9838197929;
    int mayor , contador;

    mayor_digito(numero,&mayor,&contador);
    printf("mayor numero: %d y apariciones: %d ",mayor,contador);

    return 0;
}