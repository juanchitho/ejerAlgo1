/*
 Dadas las siguientes declaraciones de constantes y tipos

#define MAX 1000
typedef int Tvector[MAX]

Desarrollar una función en lenguaje C que reciba como parámetros un vector de tipo Tvector
ya cargado con números positivos y su máximo lógico, que devuelva:
-un valor entero igual a 1 que informe si el vector esta ordenado ascendentemente, 0 en
el caso que no lo esté

-la menor diferencia entre elementos contiguos.

-En el caso que no esté ordenado la diferencia a retornar es cero.
	Ejemplo: - Dado el siguiente vector (cuyo máximo lógico es 7) 
-La función debería devolver 1 ya que está ordenado y 1 (diferencia entre 27 y 28)
0  |1  |2  |3  |4  |5  |6  |7  |…
15 |18 |20 |27 |28 |46 |70 |-  |-


Se solicita resolver lo solicitado recorriendo una sola vez al vector
 */
#include<stdio.h>
#include<stdbool.h>

#define MAX 1000
typedef int Tvector[MAX];

void verifica_ordenado(Tvector vector,int maxLogico,bool *ordenado, int *menor_diferencia){
	int i;
	*ordenado = true;
	*menor_diferencia = vector[maxLogico-1]-vector[0];  //inicia en 70

	for (i=0;i<maxLogico-1;i++){
		int diferencia = vector[i+1]-vector[i];
		if (vector[i]<vector[i+1]){
			*ordenado=true;
			if(diferencia < *menor_diferencia){
				*menor_diferencia=diferencia;
			}
			

		}else{
			*ordenado=false;
			*menor_diferencia=0;
		}
	}
}
int main(){
	Tvector vector = {0,1,2,3,4,5,6,7,15,18,20,27,28,46,70};
	int maxLogico = 15;
	bool ordenado;
	int menor_diferencia;
	
	verifica_ordenado(vector, maxLogico, &ordenado, &menor_diferencia);
	if (ordenado){
		printf("El vector esta ordenado ascendentemente.\n");
	}else{
		printf("El vector no esta ordenado ascendentemente.\n");
	}
	printf("La menor diferencia es: %d \n",menor_diferencia);

	return 0;
}

