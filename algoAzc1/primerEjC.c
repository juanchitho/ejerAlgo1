/*
Escribir un programa que permita al usuario ingresar los montos de las compras
de un cliente y que al finalizar informe por pantalla el importe total a pagar,
teniendo que cuenta que si éste supera los $1000 se le debe aplicar un 10% de descuento.

Se desconoce la cantidad de datos que se van a ingresar.
La carga de datos finaliza cuando el usuario ingresa el monto 0 (cero). 
Se debe validar que no se ingresen montos negativos.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	float monto , total = 0;
	do
	{
	printf("ingrese un monto de compra: ");
	scanf("%f",&monto);
	if(monto<0){
		printf("el monto debe ser positivo\n");
	}else{
		total = total + monto;

	}

			
	}while(monto!=0);

	if (total>1000)
		{
		total=total*0.9;
		}
	printf("monto a pagar %f\n",total);
	return 0;
}
