/*
 Un juego de un parque de diversiones, debe realizar los siguientes controles antes de comenzar a funcionar:

    Sólo pueden participar quienes tengan una altura entre 1.60 m y 1.90 m

    El peso total de los participantes no debe superar las 1.5 toneladas

    La capacidad máxima de participantes es de 20

Debemos programar una simulación de estos controles, para ello nuestro programa debe solicitar a medida que va a ingresar al juego un nuevo participante, su peso y su altura.

En caso de detectar que la altura del participante no cumple con lo requerido, se debe enviar el siguiente mensaje: “Altura del participante fuera de rango permitido”; y se debe continuar con el siguiente participante.

A medida que se procesan los ingresos de participantes, se debe controlar que el peso acumulado de los participantes no exceda el total permitido. Si lo excediera, debe enviar el mensaje: “Peso total excedido, el participante no puede subir”, el juego puede comenzar con los participantes ya aceptados.

También a medida que se procesan los ingresos de participantes, se debe controlar que la cantidad de participantes no exceda el máximo establecido, por ello, si se alcanza el máximo, se debe informar: “Cantidad máxima de participantes alcanzada” y el juego podrá comenzar si cumple con el resto.

Por último, podría ser que suban menos personas que la capacidad máxima, entonces, utilizar el último ingreso de los pesos como corte de ingreso de participantes, considerando que si se ingresa 0 como peso, indica, que no hay más participantes.
   
*/

#include <stdio.h>

int main(){

	int peso = 0, altura = 0, contador = 0 ,peso_acumulado = 0;
	printf("para ingresar un participante, ingrese su peso(en kg): ");
	scanf("%d", &peso);

	while(peso != 0){

		printf("ingrese la altura(en cm): ");
		scanf("%d", &altura);
		if(altura >= 160 && altura <= 190){
			if (peso_acumulado+peso <=1500){
				peso_acumulado+=peso;
				contador+=1;
			}else{
				printf("el participante no puede subir \n");
				peso = 0;
			}
		}else {
			printf("altura del participante fuera del rango permitido \n");
		}

		if (contador == 20){
			printf("cantidad maxima de participantes alcanzada \n");
			peso = 0;
		}else if(peso_acumulado==1500 || peso ==0 ){
			printf("peso total excedido \n");
			peso = 0;
		}else{
			printf("ingrese el peso del participante(em kg): ");
			scanf("%d",&peso);
		}

	}
	printf("el juego comenzo con los participantes ya aceptados \n");

	printf("el peso total de los participantes: %d\n",peso_acumulado);
	printf("la cantidad de participantes es: %d\n",contador);
	return 0;
}
