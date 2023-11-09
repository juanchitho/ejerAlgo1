/* Dado un número n, informar los n primeros términos de la sucesión
geométrica de razón 3 (1, 3, 9, 27, etc.).  */

#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, termino;

    printf("Ingrese un valor de n: \n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        termino = 1 * pow(3, i - 1);
        printf("%d ", termino);
    }

    return 0;
}