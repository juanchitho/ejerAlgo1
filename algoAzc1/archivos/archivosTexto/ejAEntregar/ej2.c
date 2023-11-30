/*Escribí un programa modular en C, que agregue al archivo de Texto que creaste en el ejercicio anterior, una nueva línea que comience con:

"Estoy estudiando la carrera ........................."*/

#include <stdio.h>
#define MAX 100

void sumarDatos(FILE *archivo){
    char texto[MAX];
    fgets(texto, MAX, stdin);

    fprintf(archivo, "\n%s", texto);

}
void agregarLinea2(FILE *archivo) // No estoy seguro de lo que pide la consigna entonces hago las dos formas.
{
    char cadena[] = "Estoy estudiando la carrera Ingenieria en Informatica.";

    fprintf(archivo, "\n%s", cadena);
}

void agregarLinea3(FILE *archivo) // No estoy seguro de lo que pide la consigna entonces hago las dos formas.
{

    char cadena[MAX];

    printf("Ingrese la carrera que cursa: ");
    fgets(cadena, MAX, stdin);

    fprintf(archivo, "\nEstoy cursando la carrera de %s", cadena);
}
int main(){
    FILE *archivo = fopen("texto1.txt", "a");
    if (archivo == NULL){
        printf("Error de apertura del archivo. \n\n");
    } else {
        printf("Ingrese texto a agregar al archivo: ");
        sumarDatos(archivo);
        fclose(archivo);
    }
    return 0;
}
