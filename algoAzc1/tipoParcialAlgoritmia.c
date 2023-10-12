/*
 escribir una funcion en C que reciba como parametro un numero entero y devuelva al modulo invocante los siguientes valores:
 -el resultado de multiplicar sus digitos pares y 
 -la cantidad de digitos que cumplieron la condicion y fueron procesados

 ejemplo 25831
 los digitos pares son 2 y 8
 la funcion debe devolver los valores 16 y 2 

				
*/

#include<stdio.h>

void devuelve_pares_productos(int numero, int *cantidad , int *producto){
	*producto=1;
    *cantidad=0;
    int digito;
    
    while(numero>0){
        digito=numero%10;
        if(digito%2==0){
            *producto=(*producto)*digito;
            (*cantidad)++;
        }
        numero=numero/10;
    }
    if (*cantidad==0){
            *producto=0;
        }

}

int main(){
    int numero = 25831;
    int cantidad , producto;
    devuelve_pares_productos(numero, &cantidad , &producto);

    printf("El resultado es %d y la cantidad es %d", producto, cantidad);
    
    return 0;
}