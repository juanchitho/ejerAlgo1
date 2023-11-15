/* Ejercicio 3:
Escribe una función en C que tome como parámetro un número entero y devuelva al módulo invocante:
El menor dígito que compone al número entero recibido.
La cantidad de veces que dicho dígito mínimo se encuentra en el número entero recibido. 
Ejemplo: Si el número entero con el que se invoca la función es 4692141, la función deberá devolver 1 y 2, ya que 1 es el dígito mínimo y aparece dos veces en el número.

*/

#include <stdio.h>

void menorDigito(long int numero , int *ocurrencias , int *menor){

    int digito = numero % 10; //1
    int min = digito; //min=1
    *ocurrencias=1;
    numero = numero/10;

    while (numero>0)
    {
        digito = numero % 10;
        if(digito<min){
            min = digito;
            *ocurrencias =1;
        }else if(digito == min){
            (*ocurrencias)++;
        }
        numero = numero/10;
    }
    *menor = min;

   
}

int main(){
    long int numero = 1838197291;
    int menor , ocurrencias;

    menorDigito(numero,&ocurrencias,&menor);
    printf("menor numero: %d y apariciones: %d ",menor,ocurrencias);

    return 0;
}
