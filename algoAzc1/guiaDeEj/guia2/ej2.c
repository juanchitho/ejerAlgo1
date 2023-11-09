/* Se tiene un listado de pares ordenados (x,y) de puntos de un plano, con -99< x <+99, -99< y <= +99. Informar por cada par, si pertenece, si es exterior o interior al rectángulo de coordenadas 3 < +x < +5, 2 < +y < +3. */

#include <stdio.h>

void chequear_punto(float x, float y)
{
    if (x > 5 || x < 3 || y > 3 || y < 2)
    {
        printf("El punto (%.2f, %.2f) esta afuera del rectangulo.\n", x, y);
    }
    else if (x == 3 || x == 5 || y == 2 || y == 3)
    {
        printf("El punto (%.2f, %.2f) esta en el borde del rectangulo.\n", x, y);
    }
    else
    {
        printf("El punto (%.2f, %.2f) esta adentro del rectangulo.\n", x, y);
    }
}

int main()
{
    float x, y;
    int continuar = 1;

    printf("Ingresar un par de coordenadas (x, y) (-99 < x < 99, -99 < y <= 99). Ingresar -100 para ambos para frenar.\n");

    while (continuar)
    {
        printf("Ingresar x: ");
        scanf("%f", &x);
        printf("Ingresar y: ");
        scanf("%f", &y);

        if (x == -100 && y == -100)
        {
            continuar = 0;
        }

        chequear_punto(x, y);
    }

    return 0;
}