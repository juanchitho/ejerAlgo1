/* Escribir un programa que solicite el ingreso de una serie de números.
Por cada número ingresado se deberá informar si el mismo es ó no, un número
capicúa.
Se debe evaluar que lo ingresado, sea un número entero positivo; de lo contrario,
se debe enviar el mensaje “Número Inválido”, y solicitar el siguiente.
El ingreso de números, termina cuando en lugar de un número, el usuario ingresa
“FIN”.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void esCapicua()
{
    int entrada;
    bool continuar = true;

    while (continuar)
    {
        int invertido = 0;
        printf("Ingrese un numero entero positivo: \n");
        scanf("%d", &entrada);

        if (entrada == 0)
        {
            continuar = false;
        }

        if (entrada < 0)
        {
            printf("Numero invalido \n");
        }
        else
        {
            int original = entrada;
            while (entrada > 0)
            {
                invertido = invertido * 10 + entrada % 10;
                entrada /= 10;
            }

            if (invertido == original)
            {
                printf("Es capicua\n");
            }
            else
            {
                printf("No es capicua\n");
            }
        }
    }
}

int main()
{

    esCapicua();

    return 0;
}