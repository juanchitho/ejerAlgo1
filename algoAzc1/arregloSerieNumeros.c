/*Ingresar una serie de numeros, validar que esten entre 0 y 99,  finalizada con un numero negativo y mostrar la cantidad de veces que aparece cada numero en la serie*/

#include <stdio.h>

#define MF 100

typedef int tm_vector[MF];

void ingreso_numero(tm_vector VECserie){
	int numero;
	printf("ingrese una serie de numeros entre 0 y 99, y -1 para salir: \n");
	scanf("%d",&numero);
	while (numero >= 0){
		if (numero >= 0 && numero < MF){
			VECserie[numero]++;
			printf("aca esta las repeticiones del numero ingresado: %d  \n",VECserie[numero]);//ver lo que se cargo
			//es importante entender que en este caso el MF=ml
		}else{
			printf("el numero %d se encuentra fuera de rango (rango 0-99) \n ",numero);
		}
		printf("ingrese el siguiente numero (negativo para finalizar): \n");
		scanf("%d", &numero);
	}
	
}
void mostrar_repeticiones(tm_vector VECserie){
	printf("Las repeticiones son: \n");
	for (int i=0; i < MF; i++){
		if (VECserie[i] > 0){
			printf("el numero %d aparece %d veces \n",i,VECserie[i]);
		}
	}	
}

int main(){
	
	tm_vector VECserie = {0};

	//para entender el vector , como lo creamos ,y despues ver como queda con las repeticiones
	printf("vector inicial: \n");
	int cantidadDeNumeros = 0;
	for(int i=0; i < MF; i++){
		printf(" %d , ",VECserie[i]);
		cantidadDeNumeros++;
	}
	printf("el vector tiene tantas %d posiciones \n", cantidadDeNumeros);

	ingreso_numero(VECserie);

	mostrar_repeticiones(VECserie);

	//entender las modificaciones que le hicimos ese vector
	printf("el vector final es :\n");
	for(int i=0; i < MF; i++){
		printf(" %d - ",VECserie[i]);
	}

	return 0;
}
