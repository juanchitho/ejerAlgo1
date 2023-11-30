/* Escritura de un archivo caracter a caracter usando fprintf */
#include <stdio.h>
#define MAX 100

int main()
{
    FILE *archivo;

    archivo = fopen("texto2.txt", "a");

    if (archivo == NULL)
    {
        printf("Error de apertura del archivo. \n\n");
    }
    else
    {
        char cadena[MAX];
        int cant_caracteres = 0;

        printf("Texto a agregar a archivo: ");
        fgets(cadena, MAX, stdin);

        cant_caracteres = fprintf(archivo, "%s\n", cadena);

        printf("\nSe escribieron %i caracteres", cant_caracteres);

        fclose(archivo);
    }

    return 0;
}