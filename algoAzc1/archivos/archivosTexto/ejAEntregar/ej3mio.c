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

typedef struct{
   int codigo;
   char descripcion[MAX];
   float stock;
}Tregistro;

void lectura_y_escritura(FILE *archivo, FILE *archivoTxt){
    Tregistro registro;
    
    fread(&registro, sizeof(registro),1,archivo);
    printf("\nCodigo \tDescripcion \t\t\tCantidad");

    while (!feof(archivo))
    {
        if(registro.stock>0){
            printf("\n %d \t %-30s %8.2f",registro.codigo,registro.descripcion,registro.stock);
            
        }else{
            fprintf(archivoTxt,"%s\n",registro.descripcion);
        }
        fread(&registro, sizeof(registro),1,archivo);
    }
    
}

int main(){
    FILE *archivo , *archivoTxt;
    archivo = fopen("productos.dat","rb");
    archivoTxt = fopen("sinStock.txt","w");
    
    if (archivo == NULL)
    {
        printf("Error de apertura del archivo \n");
    }else{
        lectura_y_escritura(archivo, archivoTxt);
    }
    fclose(archivo);
    fclose(archivoTxt);
    
    return 0;
}
