#include<stdio.h>

void promedio_y_repeticiones(int numero, float *promedio , int *contador){
    *promedio = 0;
    *contador = 0;
    float sumatoria = 0;
    int ultimoDigito;
    while (numero>0)
    {
        ultimoDigito=numero%10;
        sumatoria+=ultimoDigito;
        (*contador)++;
        numero=numero/10;
    }
    (*promedio)= sumatoria/(*contador);
     
}

int main(){
    int numero = 47;
    float promedio;
    int contador;

    promedio_y_repeticiones(numero,&promedio,&contador);
    printf("cantiDigitos %d y el promedio %.2f \n",contador,promedio);

    
    promedio_y_repeticiones(4885,&promedio,&contador);
    printf("cantiDigitos %d y el promedio %.2f \n",contador,promedio);

    return 0;
}