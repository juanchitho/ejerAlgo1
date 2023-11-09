/*  Se realiza una encuesta para estimar el grado de aceptación de los
productos x e y en el mercado. A cada encuestado se le pregunta si
consume el producto x y si consume el producto y. La respuesta puede
ser sí o no. Se pide calcular e informar el porcentaje de consumidores
de:
a) del producto x
b) del producto y
c) del producto x solamente
d) del producto y solamente
e) de ambos productos
f) de ninguno de los productos */

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int producto_x = 0, producto_y = 0, soloX = 0, soloY = 0, ambos = 0, ninguno = 0, personas = 0;
    char respuesta_x, respuesta_y, respuesta;
    bool continuar = true;

    while (continuar)
    {
        printf("Desea cargar una respuesta? (s o n) \n");
        scanf(" %c", &respuesta);

        if (respuesta == 'n')
        {
            continuar = false;
        }
        else
        {
            printf("Consume el producto X?: (s o n) \n");
            scanf(" %c", &respuesta_x);

            printf("Consume el producto Y?: (s o n) \n");
            scanf(" %c", &respuesta_y);

            if (respuesta_x == 's' && respuesta_y == 's')
            {
                producto_x++;
                producto_y++;
                ambos++;
            }
            else if (respuesta_x == 's')
            {
                soloX++;
                producto_x++;
            }
            else if (respuesta_y == 's')
            {
                soloY++;
                producto_y++;
            }
            else
            {
                ninguno++;
            }

            personas++;
        }
    }

    if (personas > 0)
    {
        float porcentajeX = (float)producto_x / personas * 100;
        float porcentajeY = (float)producto_y / personas * 100;
        float porcentajeSoloX = (float)soloX / personas * 100;
        float porcentajeSoloY = (float)soloY / personas * 100;
        float porcentajeAmbos = (float)ambos / personas * 100;
        float porcentajeNinguno = (float)ninguno / personas * 100;

        printf("a) Porcentaje de consumicion producto x: %.2f \n", porcentajeX);
        printf("b) Porcentaje de consumicion producto y: %.2f \n", porcentajeY);
        printf("c) Porcentaje de consumicion solo producto x: %.2f \n", porcentajeSoloX);
        printf("d) Porcentaje de consumicion solo producto y: %.2f \n", porcentajeSoloY);
        printf("e) Porcentaje de consumicion ambos producots: %.2f \n", porcentajeAmbos);
        printf("f) Porcentaje de ninguno: %f", porcentajeNinguno);
    }

    return 0;
}