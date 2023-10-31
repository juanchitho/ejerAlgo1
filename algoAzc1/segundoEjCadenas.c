/*
Escribir una función en C, que reciba una cadena de no más de 50 caracteres.
La función debe devolver la cantidad de vocales minúsculas, no acentuadas, que hay en la cadena recibida.
Escribe un programa que haga uso de la función y que la pruebe al menos con 5 casos, por ejemplo:
contar_vocales("El sol es una estrella")
mostrar por cada invocación el valor que devuelve. 
Definir un tipo adecuado para la cadena a utilizar.

*/
#include <stdio.h>
#define MAX 50
typedef char cadena[MAX];

int contar_vocales(char *cadena){
    int i = 0;
    int contador = 0;
    while (cadena[i] != '\0'){
        if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u'){
            contador++;
        }
        i++;
    }
    return contador;

}
int main(){
    cadena cadena = "El sol es una estrella";
   
    printf("La cantidad de vocales minúsculas, no acentuadas, que hay en la cadena recibida es: %d", contar_vocales(cadena));
    return 0;
}