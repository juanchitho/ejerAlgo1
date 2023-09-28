/*Inclusion de archivos*/

#include <stdio.h>

void mensaje()
{
	//mensaje inicial
	printf("programa que permite al usuario ingresar los montos de las compras \n");
	printf("para luego informar por pantalla el importe total a pagar \n");
	printf("teniendo que cuenta que si este supera los $1000 corresponde aplicar un 10%% de descuento\n");
	printf("------------------------------------------------------------------------------------\n\n");
}

float ingreso(){
	//ingreso de datos
	float tot=0; //LOCAL A FUNCION INGRESO
	float monto; //LOCAL A FUNCION INGRESO
	printf("ingrese el monto de la venta (o 0 para terminar): $");
	scanf("%f",&monto);
	while (monto!=0){
		if (monto<0){
			printf("monto no valido.\n");
		}lose{
			tot=tot+monto;
		}
		printf("ingrese el monto de la venta (o 0 para terminar): $");
		scanf("%f",&monto);
	}
	printf("(FUNCION INGRESO)--> El total ingreso ( $ %6.2f ) \n",tot);

	return tot;
}
void resultado(float total_local)
{

	//Procesamiento
	if (total_local>1000){
		printf("el total a pagar ( $ %6.2f) supera los $1000, se aplica el descuento 10%%\n",total_local);
		total_local = total_local-(total_local*0.1);
	}
	//presentacion de resultado
	printf("(FUNCION RESULTADO)--> total a pagar: $ %6.2f \n",total_local);//%6.2f => tamaño total de 6 digitos, con dos decimales
}

int main()
{
	float total=0;

	mensaje();
	
	total = ingreso();

		
	resultado(total);

	return 0;

}
