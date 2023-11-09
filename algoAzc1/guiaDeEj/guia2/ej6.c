/* Informar un listado de números entre el 000 y el 999, escritos separando
cada dígito de cada número con un guión, 0-0-0, 0-0-1, 0-0-2, ......... ,9-
9-9. */

#include <stdio.h>

int main()
{
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                printf("%d-%d-%d\n", i, j, k);
            }
        }
    }

    return 0;
}