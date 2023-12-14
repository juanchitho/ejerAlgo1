#include<stdio.h>
#define MAX 12

typedef int Tvector[MAX];

void valoresRepetido(Tvector vector,int ml , int *cantRepeticiones){
    *cantRepeticiones = 0;
    int i;
    for(i=0; i<ml-1 ; i++){
        if(vector[i]==vector[i+1] && vector[i]!=vector[i+2]){
            (*cantRepeticiones)++;
        }
    }
}

int main(){
    Tvector vector ={1,2,3,3,3,4,5,5,6,12,12,15};
    int ml = MAX;
    int cantRepeticiones;
    valoresRepetido(vector,ml,&cantRepeticiones);
    printf("repeticiones %d \n",cantRepeticiones);

    return 0;
}