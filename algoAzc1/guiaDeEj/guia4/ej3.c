/*Escribir un programa que solicite el ingreso de valores, que representarán una
cantidad de segundos. El programa deberá informar al usuario, el equivalente en
días, horas, minutos y segundos.
Se debe validar que el valor ingresado sea entero y positivo, de lo contrario,
deberá mostrarse el mensaje: “Valor ingresado inválido”.
El ingreso de valores finaliza cuando el usuario ingrese como valor, 0.
  */

#include <stdio.h>

void tiempo()
{
    int segundos, dias, horas, minutos;

    printf("Ingrese un valor en segundos: \n");
    scanf("%d", &segundos);

    while (segundos != 0)
    {
        if (segundos < 0)
        {
            printf("Valor ingresado invalido");
        }
        else
        {
            dias = segundos / 86400;
            segundos = segundos % 86400;

            horas = segundos / 3600;
            segundos = segundos % 3600;

            minutos = segundos / 60;
            segundos = segundos % 60;

            printf("%d dias, %d horas, %d minutos, %d segundos \n", dias, horas, minutos, segundos);
        }

        printf("Ingrese un valor en segundos: \n");
        scanf("%d", &segundos);
    }
}

int main()
{
    tiempo();

    return 0;
}