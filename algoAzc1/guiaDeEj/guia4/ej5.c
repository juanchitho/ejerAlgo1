/* Escribir un programa que solicite el ingreso de un texto que será enviado
mediante un telegrama. Luego de ingresado, se deberá informar la cantidad de
palabras que lo componen y el importe a abonar por el solicitante.
El texto sólo puede contener, letras, números y los siguientes signos de
puntuación: . , ; : ()
Para el cálculo de las palabras, considerar que una palabra estará separada de
otra, por uno ó más blancos.
Para el cálculo del importe a abonar, deberá considerar que cada palabra pagará
$10 por cada 3 caracteres. Por las fracciones menores a los 3 caracteres, pagará
$8. */

#include <stdio.h>
#include <stdbool.h>

#define CARACTERES 3
#define TARIFA_MAX 10
#define TARIFA_MIN 8

int validarCaracter(char c)
{
    bool valido = false;

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '.' || c == ',' || c == ';' || c == ':' || c == '(' || c == ')')
    {
        valido = true;
    }

    return valido;
}

int main()
{
    char texto[1000];
    int caracteres = 0;
    int palabras = 0;
    int cobro = 0;

    printf("Ingrese el texto del telegrama: \n");
    fgets(texto, 1000, stdin);

    fflush(stdin);

    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (validarCaracter(texto[i]))
        {
            caracteres++;
        }

        if (!validarCaracter(texto[i]))
        {
            palabras++;

            if (caracteres >= CARACTERES)
            {
                cobro += (caracteres / CARACTERES) * TARIFA_MAX;
                caracteres %= CARACTERES;
            }
            if (caracteres < CARACTERES)
            {

                cobro += caracteres * TARIFA_MIN;
                caracteres = 0;
            }
        }
    }

    printf("Cantidad de palabras: %d\n", palabras);
    printf("Debe abonar: %d\n", cobro);

    return 0;
}
