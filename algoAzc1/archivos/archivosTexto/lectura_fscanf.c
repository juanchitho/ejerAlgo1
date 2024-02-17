/* Lectura de un archivo caracter a caracter usando fscanf */
#include <stdio.h>
#define MAX 40

int main()
{
    FILE *archivo;

    archivo = fopen("texto1.txt", "r");

    if (archivo == NULL)
    {
        printf("Error de apertura del archivo. \n\n");
    }
    else
    {
        char cadena[MAX];

        fscanf(archivo, "%s", cadena);//toma palabra por palabra
        while (feof(archivo) == 0)
        {
            printf("%s\n", cadena);
            fscanf(archivo, "%s", cadena);
        }

        fclose(archivo);
    }

    return 0;
}