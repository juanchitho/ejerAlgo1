/* Ingresar el radio de una esfera y calcular el volumen.  */

#include <stdio.h>

float volumenEsfera()
{
    float radio, volumen;

    printf("Ingrese el radio de la esfera: \n");
    scanf("%f", &radio);

    if (radio > 0)
    {
        volumen = (4 * 3.1415 * (radio * radio * radio)) / 3;
    }

    return volumen;
}

int main()
{

    float volumen;

    volumen = volumenEsfera();

    printf("El volumen de la esfera es %f", volumen);

    return 0;
}