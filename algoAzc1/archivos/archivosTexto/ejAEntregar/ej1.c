/*
Usando un editor de texto plano, por ejemplo el block de notas; crea un archivo TXT, llamado texto1.txt. 
Escribí un texto corto, que comience con: 
"Mi nombre es ........, y mi padrón es ...........
 Nací el .......................".

Luego escribí un programa modular en C, que lea el archivo que creaste y muestre por pantalla el texto, y luego indique la cantidad de caracteres numéricos que hay en el archivo".

El archivo sólo se puede leer una vez.

*/
#include <stdio.h>

void leerArchivo(FILE *archivo){
    char caracter;
    int caracteresNumericos = 0;
    caracter = fgetc(archivo);
    while (caracter != EOF){
        if(caracter >= '0' && caracter <= '9'){
            caracteresNumericos++;
        }
        printf("%c", caracter);
        caracter=fgetc(archivo);
    }
    printf("\nCantidad de caracteres numericos: %d\n", caracteresNumericos);
}

int main() {
    FILE *archivo= fopen("texto1.txt", "r");
    if (archivo == NULL){
        printf("Error de apertura del archivo. \n\n");
    } else {
        leerArchivo(archivo);
        fclose(archivo);
    }
    

    return 0;
}
