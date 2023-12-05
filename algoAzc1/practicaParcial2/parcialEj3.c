#include <stdio.h>
#define CANT 4
typedef int Tmatriz[CANT][CANT];

// void ele_triangulo_superior(int numero, int *sumatoria, Tmatriz matriz){
//     int i,j;
//     *sumatoria = 0;
//     int contador = 0;
//     for (i=0 ; i<CANT-1 ; i++){
//         printf("\n");
//         for (j=CANT-1 ; j>i; j--){   //j=i diagonal primaria ,j>i diagonal superior , j<i diagonal inferior
//             printf("\nj vale %d \n", j);
//             printf("%d  ",matriz[i][j]);
//             if (matriz[i][j]%numero == 0){
//                 (*sumatoria) += matriz[i][j];
//                 contador++;
//             }
//         }
//     }
//     printf("\n cantidad de numero divisibles(solo para testear) %d \n" , contador);    

// }
void ele_triangulo_superior(int numero, int *sumatoria, Tmatriz matriz){
    int i,j;
    *sumatoria = 0;
    int contador = 0;
    for (i=0 ; i<CANT-1 ; i++){
        printf("\n");
        for (j=CANT-1 ; j>i; j--){
            printf("\nj vale %d \n", j);
            printf("%d  ",matriz[i][j]);
            if (matriz[i][j]%numero == 0){
                (*sumatoria) += matriz[i][j];
                contador++;
            }
        }
    }
    printf("\n cantidad de numero divisibles(solo para testear) %d \n" , contador);    

}

int main()
{
    int numero = 2;
    int sumatoria;
    Tmatriz matriz = {
        {4,39,66,8},
        {9,10,20,5},
        {42,2,12,23},
        {9,34,76,16}
    };
    ele_triangulo_superior(numero,&sumatoria,matriz);
    printf("la suma es de: %d\n",sumatoria);
    return 0;
}
