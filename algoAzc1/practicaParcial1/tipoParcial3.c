/* 
Ejercicio 5:
Crea una función en C que reciba un número entero y devuelva al módulo invocante:
La cantidad de dígitos diferentes presentes en el número.
El promedio de los dígitos diferentes.

Ejemplo: Si el número entero es 155943, la función deberá devolver 5 (ya que hay cinco dígitos diferentes: 1, 5, 9, 4, 3) y 4.4 (promedio de 1, 5, 9, 4, 3). */

#include <stdio.h>


void digitosDiferentes(int numero, int *cantidad, int *promedio ){
    
    int ultimoDigito = numero % 10;
    int sumatoria = ultimoDigito;
    int digito;
    *cantidad=1;

    numero=numero/10;

    while (numero != 0)
    {
        digito = numero%10;

        if(digito != ultimoDigito){
            (*cantidad)++;
            sumatoria+=digito;
            ultimoDigito=digito;
        }
        numero=numero/10;
    }
    *promedio= sumatoria/(*cantidad);
    
}

int main(){
    int numero = 155943;
    int cantidad , promedio;

    digitosDiferentes(numero,&cantidad,&promedio);

    printf("cantidad de numeros no repetidos es de  %d  y el promedio total %d",cantidad , promedio);

    return 0;
}