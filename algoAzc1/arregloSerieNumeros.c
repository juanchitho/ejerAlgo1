/*Ingresar una serie de numeros, validar que esten entre 0 y 99,  finalizada con un numero negativo y mostrar la cantidad de veces que aparece cada numero en la serie*/

#include <stdio.h>

#define MF 100

typedef int tm_vector[MF];

void ingreso_numero(tm_vector VECserie){
	int numero;
	printf("ingrese una serie de numeros entre 0 y 99, y -1 para salir: \n");
	scanf("%d",&numero);
	while (numero >= 0){
		if (numero >= 0 && numero <= MF){
			VECserie[numero]++;
		}else{
			printf("el numero %d se encuentra fuera de rango (rango 0-99) \n ",numero);
		}
		printf("ingrese el siguiente numero (negativo para finalizar): \n");
		scanf("%d", &numero);
	}
	printf("aca esta el VECserie[]: %d \n",VECserie);
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
	

	ingreso_numero(VECserie);

	mostrar_repeticiones(VECserie);

	return 0;
}
