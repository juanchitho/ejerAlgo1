/* Lectura de un archivo caracter a caracter usando fgets */
#include <stdio.h>
#define MAX 80

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
        char caracteres[MAX];

        while (feof(archivo) == 0)
        {
            fgets(caracteres, MAX, archivo);// bastante parecido al fgetc pero corta la oracion cuando llega a los 80 caracteres
            printf("%s\n", caracteres);
        }

        fclose(archivo);
    }

    return 0;
}