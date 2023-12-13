
#include <stdio.h>
#define CANT 4

typedef int Tmatriz[CANT][CANT];

void trianguloSupSegundaDiagonal(int numero , int *sumatoria , Tmatriz matriz){
    int i, j;
    (*sumatoria) = 0;
    for(i=0; i < CANT-1; i++){
        for(j=0; j < CANT-1-i; j++){
            printf("\nj vale %d \n", j);
            printf("%d  ",matriz[i][j]);
            if(matriz[i][j]%numero==0){
                (*sumatoria)+= matriz[i][j];
            }
            
        }
    }
}

void trianguloInfSegundaDiagonal(int numero , int *sumatoria , Tmatriz matriz){
    int i, j;
    (*sumatoria) = 0;
    for(i=1; i <= CANT-1; i++){
        for(j=CANT-1; j > CANT - 1 - i; j--){
            printf("\nj vale %d \n", j);
            printf("%d  ",matriz[i][j]);
            if(matriz[i][j]%numero==0){
                (*sumatoria)+= matriz[i][j];
            }
            
        }
    }
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
    trianguloSupSegundaDiagonal(numero,&sumatoria,matriz);
    printf("\nla suma es de: %d\n",sumatoria);


    trianguloInfSegundaDiagonal(numero,&sumatoria,matriz);
    printf("\nla suma es de: %d\n",sumatoria);

    return 0;
}
