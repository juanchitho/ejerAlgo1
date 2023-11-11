/* Escribir un programa que solicite el ingreso de dos números, y luego informe los
números primos que hay entre esos dos números.
Se debe validar que los números ingresados sean enteros y además que el primer
número sea menor o igual que el segundo.
 */

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

int numerosPrimos()
{
    int a, b;

    printf("Ingrese un numero entero: \n");
    scanf("%d", &a);

    printf("Ingrese otro numero entero: \n");
    scanf("%d", &b);

    if (a > b)
    {
        printf("El primer numero debe ser menor o igual al segundo");
    }
    else
    {
        for (int i = a; i <= b; i++)
        {
            if (esPrimo(i))
            {
                printf("\n%d \n", i);
            }
        }
    }

    return 0;
}

int main()
{
    numerosPrimos();

    return 0;
}
