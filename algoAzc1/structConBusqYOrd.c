#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANIO 5
#define NO_ENCONTRADO -1

/* definimos una estructura alumno */
typedef struct  
{
	char nombre[30];
	int padron;
	char email[50];
	int notas[2] ;
	float promedio;
} alumno;

void cargar(alumno vec[TAMANIO])
{
	int i;
	for(i=0;i<TAMANIO;i++){
		printf("\nIngrese el Nombre:\n");
		scanf("%s",vec[i].nombre);

		printf("Ingrese el padron:\n");
		scanf("%d",&vec[i].padron);

		printf("Ingrese el email:\n");
		scanf("%s",vec[i].email);

		printf("Ingrese la nota del Parcial 1:\n");
		scanf("%d",&vec[i].notas[0]);

		printf("Ingrese la nota del Parcial 2:\n");
		scanf("%d",&vec[i].notas[1]);

		vec[i].promedio = (float)(vec[i].notas[0] + vec[i].notas[1])/2;
	}
}

void mostrar(alumno vec[TAMANIO])
{
	int i;
	for(i=0;i<TAMANIO;i++){
		printf("\n\n Alumnos[%d]",i);
		printf("\n nombre: %s ", vec[i].nombre);
		printf("\n padron: %d ", vec[i].padron);	
		printf("\n email: %s ", vec[i].email);
		printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", vec[i].notas[0],vec[i].notas[1]);
		printf("\n promedio Cd: %.2f ", vec[i].promedio);
	}
}

float alumno_mejor_promedio(alumno vec[TAMANIO],int *mejor_promedio_pos){
	int i;
	float mayor_promedio = 0;
	*mejor_promedio_pos = 0;

	for(i=0;i<TAMANIO;i++){
		if(vec[i].promedio>mayor_promedio){
			mayor_promedio = vec[i].promedio;
			*mejor_promedio_pos = i;
		}
	}
	return mayor_promedio;
}

float promedio_general_parcial1(alumno vec[TAMANIO]){
	int i;
	int acumulador = 0;
	float promedioGeneral;
	for(i=0; i<TAMANIO; i++){
		acumulador+=vec[i].notas[0];
	}
	promedioGeneral= (float)(acumulador)/TAMANIO;
	return promedioGeneral;
}
void oredenamiento_ascendente_burbujeo(alumno vec[TAMANIO]){
	int i = 0;
	int j;
	bool intercambio = true;
	alumno aux;
	
	while(i < TAMANIO - 1 && intercambio){
		intercambio = false;
		
		for(j=0; j < TAMANIO - 1 - i; j++){
			if(vec[j].padron > vec[j + 1].padron){
				aux = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = aux;
				intercambio = true;

			}
		}
		i++;
	}

}
int busqueda_binaria(alumno vec[TAMANIO],int padronABuscar){
	int inf,sup,mit,posicion;
	bool terminado;
	inf=0;
	sup=TAMANIO-1;
	terminado=false;

	while (!terminado)
	{
		if((padronABuscar > vec[sup].padron) || (padronABuscar < vec[inf].padron)){
			terminado = true;
			posicion = NO_ENCONTRADO;
		}else{
			mit=(inf+sup)/2;
			if (vec[mit].padron == padronABuscar)
			{
				terminado=true;
				posicion=mit;
			}
			else{
				if (padronABuscar>vec[mit].padron)
				{
					inf=mit+1;
				}else{
					sup=mit-1;
				}
				
			}
			
		}
	}
	return posicion;
	
}
void mostrar_por_posicion(alumno vec[TAMANIO],int pos)
{

	printf("\n\n Alumnos[%d]",pos);
	printf("\n nombre: %s ", vec[pos].nombre);
	printf("\n padron: %d ", vec[pos].padron);	
	printf("\n email: %s ", vec[pos].email);
	printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", vec[pos].notas[0],vec[pos].notas[1]);
	printf("\n promedio Cd: %.2f ", vec[pos].promedio);

}

int main()
{
	alumno Alumnos[TAMANIO];
	//1
	// cargo los elementos con funcion cargar
	cargar(Alumnos);
	
	/* Muestro datos del primer elemento de la tabla*/
	mostrar(Alumnos);
	//2
	int mejor_promedio_pos;
	float mayor_promedio = alumno_mejor_promedio(Alumnos,&mejor_promedio_pos);
	printf("\nEl alumno con mejor promedio es %s con un promedio de %.2f \n ",Alumnos[mejor_promedio_pos].nombre,mayor_promedio);

	//3
	printf("\nEl promedio general de las notas del primer parcial es : %.2f \n",promedio_general_parcial1(Alumnos));

	//4
	oredenamiento_ascendente_burbujeo(Alumnos);
	mostrar(Alumnos);

	//5
	int padronABuscar;
	printf("\n Ingrese un padron a buscar: \n");
	scanf("%d",&padronABuscar);
	int pos = busqueda_binaria(Alumnos,padronABuscar);
	if(pos==NO_ENCONTRADO){
		printf("\n Alumno no encontrado \n");
	}else{
		mostrar_por_posicion(Alumnos,pos);
	}
	

	printf("\n\n");

	return 0;
}
