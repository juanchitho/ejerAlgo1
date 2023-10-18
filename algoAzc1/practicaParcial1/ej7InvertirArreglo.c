/*
 Completar en el siguiente programa para que el arreglo vec quede invertido, es decir {15.00,204.00,42.00,30.00,23.00,107.00}.
 evitar el uso de estructuras de datos y ciclos innecesarios.
*/

#include <stdio.h>
#define MAX 6

int main(){
	float vec[MAX] = {107.00,23.00,30.00,42.00,204.00,15.00};
	float vecInvertido[MAX] = {};
	int ultima_pos = MAX - 1;
	for (int i = ultima_pos;i >= 0;i--){
		vecInvertido[ultima_pos - i] = vec[i];
	}
	for(int i=0; i<MAX;i++){
		printf("%.2f ",vecInvertido[i]);
	}

	return 0;

}

