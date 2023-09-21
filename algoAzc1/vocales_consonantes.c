/* Ingresar un texto terminado en . E indicar cantidad de vocales y consonantes. */

#include <stdio.h>

int main()
{
    char letra;
    int vocales = 0, consonantes = 0;

    printf("Ingrese un texto terminado en . (en minuscula):");
    scanf("%c", &letra);

    while (letra != '.')
    {
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
        {
            vocales++;
        }
        else if (letra > 'a' && letra <= 'z')
        {
            consonantes++;
        }
        scanf("%c", &letra);
    }
    printf("La cantidad de vocales es: %d\n", vocales);
    printf("La cantidad de consonantes es: %d\n", consonantes);
}