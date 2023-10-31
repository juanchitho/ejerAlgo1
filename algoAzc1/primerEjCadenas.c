/*
Escribir un programa en C, que:
- declare una cadena y como valor le asigne tu nombre y apellido
- recorra la cadena e imprima sólo las consonantes, una debajo de la otra
- indique cuantas consonantes hay en tu nombre y apellido
*/
#include <stdio.h>

int main(void){
    char nombre[] = "Juan Runzio";
    int i = 0;
    int cantConsonantes = 0;
    while(nombre[i] != '\0'){
        if(nombre[i] != 'a' && nombre[i] != 'e' && nombre[i] != 'i' && nombre[i] != 'o' && nombre[i] != 'u' && nombre[i] != ' '){
            printf("%c\n", nombre[i]);
            cantConsonantes++;
        }
        i++;
    }
    printf("Cantidad de consonantes: %d\n", cantConsonantes);
    return 0;
}