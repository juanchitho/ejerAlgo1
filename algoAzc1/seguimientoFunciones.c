/*
Programa seguimiento
Indicar cual será la salida por pantalla de este programa
luego de realizar un analisis del código.
*/

#include <stdio.h>

int func_suma(int A, int B)
{
    return A + B; // {10}
}

void proc_02(int A, int *B, int C)
{
    A = func_suma(A, *B) * C;       // {11}
    printf("%d %d %d\n", A, *B, C); // {12}
}
void proc_01(int *A, int B, int D)
{
    int C;

    C = *A;                         // {13}
    *A = B;                         // {14} es el valor que termina cambiado en el main()
    B = C;                          // {15}
    printf("%d %d %d\n", *A, B, C); // {16}
    proc_02(B, &C, D);              // {17}
    printf("%d %d %d\n", *A, B, C); // {18}
}

int main()
{
    int A, B, C;

    A = 1;                         // {1}
    B = 2;                         // {2}
    C = 3;                         // {3}
    printf("%d %d %d\n", A, B, C); // {4}
    proc_01(&A, B, C);             // {5}
    printf("%d %d %d\n", A, B, C); // {6}
    proc_02(A, &B, C);             // {7}
    printf("%d %d %d\n", A, B, C); // {8}

    return 0;
}