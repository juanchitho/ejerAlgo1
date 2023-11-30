/* Escritura de un archivo caracter a caracter usando fputc */
#include <stdio.h>

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
        char caracter;

        printf("Texto a agregar a archivo: ");

        caracter = getchar();
        while (caracter != '\n')
        {
            fputc(caracter, archivo);
            caracter = getchar();
        }

        fclose(archivo);
    }

    return 0;
}