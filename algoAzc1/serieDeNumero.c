/*
Ingresar una serie de numeros en finalizada en 0 y mostrar el mayor y el menor de la serie.
*/
#include <stdio.h>
int main(){
int numero;
int mayor;
int menor;
printf("ingrese una serie terminada en 0 ");
printf("ingrese un numero ");
scanf("%d",&numero);
mayor=numero;
menor=numero;
while (numero != 0) {
    if (numero>mayor)
        mayor=numero;
    else
        if (numero < menor)
            menor=numero;
    scanf("%d", &numero);
    }
printf("El mayor de la serie es %d", mayor);
printf("El menosde la serie es %d", menor);
return 0;
}
