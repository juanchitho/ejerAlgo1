#include <stdio.h>
#include <string.h>

//definimos una estructura alumno
typedef struct {
    char nombre[30];
    int padron;
    char email[50];
    int notas[2];
    float promedio;
} alumno;

int main (){
    alumno Alumnos[3];

    //al primer elemento lo cargo como antes
    strcpy(Alumnos[0].nombre, "Nombres alumno[0]");
    Alumnos[0].padron = 12345;
    strcpy(Alumnos[0].email, "Alumno2@yahoo.com");
    Alumnos[0].notas[0] = 6;
    Alumnos[0].notas[1] = 9;
    Alumnos[0].promedio = (float)(Alumnos[0].notas[0] + Alumnos[0].notas[1])/2;

    // a los otros elementos los ingresa el usuario
    printf("Ingrese el nombre: \n");
    fgets(Alumnos[1].nombre,30,stdin);
    fflush(stdin);

    printf("Ingrese el padron : \n");
    scanf("%d",&Alumnos[1].padron);
    fflush(stdin);

    printf("Ingrese el email: \n");
    fgets(Alumnos[1].email,50,stdin);
    fflush(stdin);

    printf("Ingrese la nota del Parcial 1 : \n");
    scanf("%d",&Alumnos[1].notas[0]);

    printf("Ingrese la nota del Parcial 2 : \n");
    scanf("%d",&Alumnos[1].notas[1]);

    Alumnos[1].promedio = (float)(Alumnos[1].notas[0] + Alumnos[1].notas[1])/2;

    //Muestro datos del primer elemento de la tabla
    printf("\n Alumno[0]");
    printf("\n nombre: %s", Alumnos[0].nombre);
    printf("\n padron: %d", Alumnos[0].padron);
    printf("\n email: %s", Alumnos[0].email);
    printf("\n nota Parcial 1: %d", Alumnos[0].notas[0]);
    printf("\n nota Parcial 2: %d", Alumnos[0].notas[1]);
    printf("\n el promedio es: %.2f", Alumnos[0].promedio);

    printf("\n \n");
    //Muestro datos del segundo elemento de la tabla
    printf("\n Alumno[1]");
    printf("\n nombre: %s", Alumnos[1].nombre);
    printf("\n padron: %d", Alumnos[1].padron);
    printf("\n email: %s", Alumnos[1].email);
    printf("\n nota Parcial 1: %d", Alumnos[1].notas[0]);
    printf("\n nota Parcial 2: %d", Alumnos[1].notas[1]);
    printf("\n el promedio es: %.2f \n", Alumnos[1].promedio);

    return 0;
}
