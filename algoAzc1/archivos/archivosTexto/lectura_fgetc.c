/* Lectura de un archivo caracter a caracter usando fgetc */
#include <stdio.h>

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
        char caracter;

        caracter = fgetc(archivo);
        while (caracter != EOF)
        {
            printf("%c", caracter);
            caracter = fgetc(archivo);
        }

        fclose(archivo);
    }

    return 0;
}