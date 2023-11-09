#include<stdio.h>
#include<stdbool.h>

/*Ingresar los padrones y las notas de los alumnos
del curso de Algoritmos y programación 1.

Como máximo se cargarán 50 alumnos.
---------------------------------------------------
Se pide:
  1) Realizar el modulo de carga de datos.
  2) Mostrar aprobados (padrón y nota) en orden de notas crecientes.
  3) Agregar un modulo que permita la busqueda, dado un padrón ingresado por el usuario
    indicar que nota obtuvo el alumno. */

#define MAX 50

typedef int tm_vector[MAX];

void ingreso_datos(tm_vector VECpadron, tm_vector VECnota, int *tope){
  int padron, nota;
  printf("ingrese el padron del alumno: \n");
  scanf("%d",&padron);
  while (padron > 0 && *tope < MAX){
    printf("ingrese la nota del alumno: \n");
    scanf("%d",&nota);
    if (nota >= 0 && nota <= 10){
      VECpadron[*tope] = padron;
      VECnota[*tope] = nota;
      *tope = *tope + 1;
    }else{
      printf("la nota %d se encuentra fuera de rango (rango 0-10) \n ",nota);
    }
    printf("ingrese el siguiente padron (negativo para finalizar): \n");
    scanf("%d", &padron);
  }
}

void mostrar_aprobados(tm_vector VECpadron, tm_vector VECnota, int tope){
  int i, j, aux;
  for (i=0; i < tope; i++){
    for (j=0; j < tope; j++){
      if (VECnota[i] < VECnota[j]){
        aux = VECnota[i];
        VECnota[i] = VECnota[j];
        VECnota[j] = aux;
        aux = VECpadron[i];
        VECpadron[i] = VECpadron[j];
        VECpadron[j] = aux;
      }
    }
  }
  printf("Los aprobados son: \n");
  for (i=0; i < tope; i++){
    if (VECnota[i] >= 4){
      printf("el alumno %d aprobo con nota %d \n",VECpadron[i],VECnota[i]);
    }
  }
}

void busqueda(tm_vector VECpadron, tm_vector VECnota, int tope){
  int padron, i;
  bool encontrado = false;
  printf("ingrese el padron del alumno a buscar: \n");
  scanf("%d",&padron);
  for (i=0; i < tope; i++){
    if (VECpadron[i] == padron){
      printf("el alumno %d obtuvo la nota %d \n",VECpadron[i],VECnota[i]);
      encontrado = true;
    }
  }
  if (encontrado == false){
    printf("el alumno %d no se encuentra en la lista \n",padron);
  }
}

int main(){

  tm_vector VECpadron = {0};
  tm_vector VECnota = {0};
  int tope = 0;

  ingreso_datos(VECpadron, VECnota, &tope);

  mostrar_aprobados(VECpadron, VECnota, tope);

  busqueda(VECpadron, VECnota, tope);

  return 0;
}