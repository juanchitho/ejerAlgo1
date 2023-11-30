/*
Dado el archivo binario adjunto, y que posee la siguiente estructura:

	int codigo;
        char descripcion[30];
        float stock;

Escribir un programa modular en C, que deje en un archivo .txt, la descripción de aquellos artículos cuyo stock, sea nulo. 
Los productos con stock, deben ser mostrados por pantalla todos sus datos.
El archivo sólo puede ser recorrido una vez en su totalidad.

*/
#include <stdio.h>
#define MAX 30

typedef struct {
    int codigo;
    char descripcion[30];
    float stock;
} TRegistro;

// Función para procesar el archivo binario
void mostrar () {
    TRegistro registro;
    FILE *archivo, *archivoTxt;
    archivo = fopen("productos.dat", "rb");
    archivoTxt = fopen("productos.txt", "w");

    fread(&registro, sizeof(TRegistro), 1, archivo);
    printf("Productos con stock:\n");
    while (!feof(archivo)) {
        if (registro.stock == 0) {
            fprintf(archivoTxt, "%s \n", registro.descripcion);
        } else {
            printf("\n%d  \t%s  \t%f\n", registro.codigo , registro.descripcion , registro.stock);
        }
        fread(&registro, sizeof(TRegistro), 1, archivo);
    }
    fclose(archivo);
    fclose(archivoTxt);
}

int main() {
    
    mostrar();
    return 0;
}