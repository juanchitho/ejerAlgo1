/*
 escribir una funcion en C que reciba como parametro un numero entero y devuelva al modulo invocante los siguientes valores:
 -el resultado de multiplicar sus digitos pares y 
 -la cantidad de digitos que cumplieron la condicion y fueron procesados

 ejemplo 25831
 los digitos pares son 2 y 8
 la funcion debe devolver los valores 16 y 2
 */

#include <stdio.h>

void devuelve_numeros_pares(int numero,int *contador ,int *producto){
	*contador=0;
	*producto=1;
	int ultDigito;
	while (numero>0){
		ultDigito=numero%10;
		if (ultDigito%2==0){
			(*contador)++;
			(*producto) = (*producto)*ultDigito;
			
		}
		numero=numero/10;
	}
	if (*contador == 0){
		*producto=0;
	}


}	





int main(){
	int numero = 25831;
	int contador , producto;

	devuelve_numeros_pares(numero ,&contador , &producto );
	printf("el producto de los numeros pares es %d y la cantidad de digitos pares %d \n",producto,contador);
	return 0;

}

