/* Escribir una función que reciba un número y devuelva un valor booleano
indicando si el número recibido es ó no primo. Si desconoce como devolver un
valor booleano, puede devolver 0, en caso de No ser primo; y 1, si lo es.  */

#include <stdio.h>
#include <stdbool.h>

bool esPrimo(int numero)
{
    bool resp = true;

    if (numero <= 1)
    {
        resp = false;
    }

    for (int i = 2; i * i <= numero; i++)
    {
        if (numero % i == 0)
        {
            resp = false;
        }
    }

    return resp;
}

int main()
{
    int numero;
    bool respuesta;

    printf("Ingrese un valor: ");
    scanf("%d", &numero);

    respuesta = esPrimo(numero);

    printf("%d", respuesta);
}