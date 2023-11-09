/*
1)ingresar los datos de 5 alumnos
2)indicar el nombre del alumno con el mejor promedio
3)indicar el promedio general en el primer parcial
4)ordenar ascendentemente el listado segun el padron
5) ingresar un padron por teclado, buscarlo e imprimir toda la informacion de ese alumno

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANIO 5

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
    for(i=0;i<TAMANIO;i++)
    {
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
    for(i=0;i<TAMANIO;i++)
    {
 	printf("\n\n Alumnos[%d]",i);
	printf("\n nombre: %s ", vec[i].nombre);
	printf("\n padron: %d ", vec[i].padron);	
	printf("\n email: %s ", vec[i].email);
	printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", vec[i].notas[0],vec[i].notas[1]);
	printf("\n promedio Cd: %.2f ", vec[i].promedio);
    }
}

void alumno_con_mejor_promedio(alumno vec[TAMANIO]){
    int i;
    float mejor_promedio = 0;
    int mejor_promedio_pos = 0;
    for(i=0;i<TAMANIO;i++)
    {
        if(vec[i].promedio > mejor_promedio){
            mejor_promedio = vec[i].promedio;
            mejor_promedio_pos = i;
        }
    }
    printf("\n\n El alumno con mejor promedio es: %s", vec[mejor_promedio_pos].nombre);


}
void promedio_general_primer_parcial(alumno vec[TAMANIO]){
    int i;
    float promedio_general = 0;
    for(i=0;i<TAMANIO;i++)
    {
        promedio_general += vec[i].notas[0];
    }
    promedio_general = promedio_general / TAMANIO;
    printf("\n\n El promedio general del primer parcial es: %.2f", promedio_general);

}

void ordena_ascendentemente_por_padron(alumno vec[TAMANIO]){
    int i;
    int j;
    alumno aux;
    for(i=0;i<TAMANIO;i++)
    {
        for(j=0;j<TAMANIO;j++)
        {
            if(vec[i].padron < vec[j].padron){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
    printf("\n\n Listado ordenado ascendentemente por padron");
    mostrar(vec);
    
    
}

int main()
{
    alumno Alumnos[TAMANIO];

    // cargo los elementos con funcion cargar
    cargar(Alumnos);

 	/* Muestro datos del primer elemento de la tabla*/
    mostrar(Alumnos);

    // alumno con mejor promedio
    alumno_con_mejor_promedio(Alumnos);

    // promedio general del primer parcial
    promedio_general_primer_parcial(Alumnos);

    // ordeno ascendentemente por padron
    ordena_ascendentemente_por_padron(Alumnos);



	printf("\n\n");
	
	return 0;
}