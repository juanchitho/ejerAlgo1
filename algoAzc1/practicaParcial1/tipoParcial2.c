/*
Ejercicio 4:
Desarrolla una función en C que reciba como parámetro un número entero y devuelva al módulo invocante:
La suma de los dígitos primos que componen al número.
La cantidad de dígitos primos presentes en el número.

Ejemplo: Si el número entero es 73642, la función deberá devolver 7 (porque 7 es un dígito primo) y 3 (ya que hay dos dígitos primos en total: 7 y 2).

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

void sumaDigitosPrimos(int numero, int *suma , int *cantidad){

    *suma = 0;
    *cantidad = 0;
    int digito;

    while (numero>0)
    {
        digito = numero % 10;
        if (esPrimo(digito)){
            *suma+=digito;
            (*cantidad)++;
        }
        numero= numero/10;
    }
    
}

int main()
{
    int numero;
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);

    int suma, cantidad;
    sumaDigitosPrimos(numero, &suma, &cantidad);

    printf("El valor de la suma es: %d\n", suma);
    printf("Hay %d digitos primos en el numero.\n", cantidad);

    return 0;
}