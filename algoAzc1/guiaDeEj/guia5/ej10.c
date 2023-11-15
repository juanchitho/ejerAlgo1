/* Escribir un programa que cargue 2 (dos) matrices y sus dimensiones, las
multiplique en caso de ser posible o devuelva una señal si la operación no
puede realizarse.  */

#include <stdio.h>

void multiplicarMatrices(int a[][10], int b[][10], int result[][10], int filaA, int colA, int filaB, int colB, int *exito)
{

    if (colA != filaB)
    {
        printf("No se puede realizar la multiplicacion. El numero de columnas de la primera matriz debe ser igual al numero de filas de la segunda matriz.\n");
        *exito = 0;
    }

    *exito = 1;

    for (int i = 0; i < filaA; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < colA; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void cargarMatriz(int matriz[][10], int filas, int columnas)
{
    printf("Ingrese los elementos de la matriz:\n");

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("Ingrese el elemento en la posicion [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int matriz[][10], int filas, int columnas)
{
    printf("Matriz resultante:\n");

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int filaA, colA, filaB, colB, exito;

    printf("Ingrese la cantidad de filas de la primera matriz: ");
    scanf("%d", &filaA);
    printf("Ingrese la cantidad de columnas de la primera matriz: ");
    scanf("%d", &colA);

    printf("Ingrese la cantidad de filas de la segunda matriz: ");
    scanf("%d", &filaB);
    printf("Ingrese la cantidad de columnas de la segunda matriz: ");
    scanf("%d", &colB);

    int matrizA[10][10], matrizB[10][10], resultado[10][10];

    cargarMatriz(matrizA, filaA, colA);

    cargarMatriz(matrizB, filaB, colB);

    multiplicarMatrices(matrizA, matrizB, resultado, filaA, colA, filaB, colB, &exito);

    if (exito)
    {
        mostrarMatriz(resultado, filaA, colB);
    }

    return 0;
}
