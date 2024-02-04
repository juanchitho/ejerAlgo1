/*Ingresar una serie de numeros, validar que esten entre 0 y 99,  finalizada con un numero negativo y mostrar la cantidad de veces que aparece cada numero en la serie*/

#include <stdio.h>

#define MF 100

typedef int tm_vector[MF];

void ingreso_numero(tm_vector VECserie){
	int numero;
	int ml = 0;
	printf("ingrese una serie de numeros entre 0 y 99, y -1 para salir: \n");
	scanf("%d",&numero);
	while (numero >= 0){
		if (numero >= 0 && numero <= MF){
			VECserie[numero]++;
			printf("aca esta el VEC[]: %d  \n",VECserie[numero]);
			ml++;
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
	printf("vector inicial: \n");
	int cantidadDeNumeros = 0;
	for(int i=0; i < MF; i++){
		printf(" %d , ",VECserie[i]);
		cantidadDeNumeros++;
	}
	printf("el vector tiene tantas %d posiciones \n", cantidadDeNumeros);

	ingreso_numero(VECserie);

	mostrar_repeticiones(VECserie);
	printf("el vector final es :\n");
	for(int i=0; i < MF; i++){
		printf(" %d - ",VECserie[i]);
	}

	return 0;
}
