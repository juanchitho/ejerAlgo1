/* Ejercicio 8:
Crea una función en lenguaje C que reciba como parámetros una cadena de caracteres (string) y determine si es un palíndromo. La función debe devolver 1 si la cadena es un palíndromo y 0 en caso contrario. La cadena debe pasarse como parámetro, y la función debe ignorar espacios y ser insensible a mayúsculas y minúsculas.

Escribe un programa que invoque la función, solicite al usuario ingresar una cadena, invoque la función y luego imprima si la cadena es un palíndromo o no.

Este ejercicio te permitirá practicar la manipulación de cadenas y trabajar con funciones que realizan tareas específicas. */

#include <stdio.h>
#include <string.h>

int esPalindromo(char *cadena)
{
    int longitud = strlen(cadena);
    int i, j, resp = 1;

    char cadenaProcesada[longitud];
    int k = 0;
    for (i = 0; i < longitud; i++)
    {
        if (cadena[i] != ' ')
        {
            if (cadena[i] >= 'A' && cadena[i] <= 'Z')
            {
                cadenaProcesada[k] = cadena[i] + ('a' - 'A');
                k++;
            }
            else
            {
                cadenaProcesada[k] = cadena[i];
                k++;
            }
        }
    }
    cadenaProcesada[k] = '\0';

    // Verificar si la cadena procesada es un palíndromo
    for (i = 0, j = strlen(cadenaProcesada) - 1; i < j; i++, j--)
    {
        if (cadenaProcesada[i] != cadenaProcesada[j])
        {
            resp = 0; // No es un palíndromo
        }
    }
    return resp;
}

int main()
{
    char cadena[100];

    printf("Ingrese una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);

    cadena[strcspn(cadena, "\n")] = '\0';

    // Verificar si la cadena es un palíndromo
    if (esPalindromo(cadena))
    {
        printf("La cadena \"%s\" es un palindromo.\n", cadena);
    }
    else
    {
        printf("La cadena \"%s\" no es un palindromo.\n", cadena);
    }

    return 0;
}
