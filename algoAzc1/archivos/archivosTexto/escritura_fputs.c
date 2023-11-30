/* Escritura de un archivo caracter a caracter usando fputs */
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

        printf("Texto a agregar a archivo: ");
        fgets(cadena, MAX, stdin);

        if (fputs(cadena, archivo) == 0)
        {
            printf("El archivo fue actualizado");
        }
        else
        {
            printf("No fue posible agregar el texto al archivo.");
        }

        fclose(archivo);
    }

    return 0;
}