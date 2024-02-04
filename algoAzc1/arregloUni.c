/*Tomando como base el código que está debajo, modificalo para que:
- los valores del arreglo sean cada uno de los dígitos de tu padrón/legajo 110164
- declará un tipo de dato para el arreglo y una constante para su máximo físico.
- mostrá del último elemento al primer elemento.*/

# include <stdio.h>

# define MF 6

typedef int tamanio_vector_nros[MF];

void mostrar_datos(tamanio_vector_nros v, int ultima_pos){
	int i;
	for (i=ultima_pos - 1; i>=0; i--)
		printf("%i \n", v[i]);
}

int main(){
	tamanio_vector_nros padron = {1,1,0,1,6,4};
	mostrar_datos(padron , MF);

	return 0;
}
