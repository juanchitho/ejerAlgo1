/* Hallar la superficie de un triangulo conociendo la base y la altura. */

#include <stdio.h>

int superficieTriangulo(int base, int altura)
{
    int superficie;

    if (base > 0 && altura > 0)
    {
        superficie = (base * altura) / 2;
    }

    return superficie;
}

int main()
{
    int superficie = superficieTriangulo(8, 6);
    printf("%d", superficie);
    return 0;
}