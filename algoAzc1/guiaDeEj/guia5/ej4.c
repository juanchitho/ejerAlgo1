/* Cargar una serie de números reales en un vector. No se conoce la cantidad
exacta de datos, pero se sabe que no superan los 100. No se conocen cotas
para los datos. Informar el valor máximo, la cantidad de veces que aparece y
la/s posición/es que ocupa.  */

#include <stdio.h>
#include <stdbool.h>

#define MF 100
typedef int Tvector[MF];

int informarMaximo()
{
    bool continuar = true;
    int numero = 0;
    int max_logico = 0;
    int valor_maximo = 0;
    int contador_maximo = 0;
    int contador_posicion = 0;
    Tvector vec = {0};
    Tvector posiciones = {0};

    while (continuar)
    {
        printf("Ingrese un numero real (0 para finalizar): \n");
        scanf("%d", &numero);

        if (max_logico == MF)
        {
            continuar = false;
        }

        if (numero == 0)
        {
            continuar = false;
        }
        else
        {
            vec[max_logico] = numero;
            max_logico++;
        }
    }

    for (int i = 0; i <= max_logico; i++)
    {
        if (vec[i] > valor_maximo)
        {
            valor_maximo = vec[i];
            contador_maximo = 1;
            posiciones[0] = i;
            contador_posicion = 1;
        }
        else if (vec[i] == valor_maximo)
        {
            contador_maximo++;
            posiciones[contador_posicion] = i;
            contador_posicion++;
        }
    }

    printf("El valor maximo es: %d\n", valor_maximo);
    printf("Aparece %d veces\n", contador_maximo);
    printf("Se encuentra en la(s) posicion(es): ");

    for (int i = 0; i < contador_posicion; i++)
    {
        printf("%d ", posiciones[i]);
    }
    printf("\n");

    return 0;
}

int main()
{
    informarMaximo();

    return 0;
}