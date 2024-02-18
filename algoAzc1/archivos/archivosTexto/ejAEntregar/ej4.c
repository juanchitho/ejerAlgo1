/*Escribir un programa modular en C , que lea un archivo txt, e informe la cantidad de palabras  que hay en en el texto.
Considerar que una palablra esta separada por otra por uno o mas blancos.
*/
#include <stdio.h>
#define MAX 30

typedef char cadena[MAX];

int contador_de_palabras(FILE *archivo){
    int cantidad = 0;
    cadena aux;
    fscanf(archivo,"%s",aux);
    while (!feof (archivo))
    {
        cantidad++;
        //printf("%s \n",aux);
        fscanf(archivo,"%s",aux);
    }
    
    return cantidad;
}

int main(){
    FILE *archivo;

    archivo = fopen("texto1.txt","r");

    if( archivo == NULL){
        printf("Error de apertura del archivo \n ");
    }else{
        printf("La cantidad de palabras que hay en el archivo es : %d \n",contador_de_palabras(archivo));

    }
    fclose(archivo);


    return 0;
}
