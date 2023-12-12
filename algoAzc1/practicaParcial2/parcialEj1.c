/*
ejer1)


*/

#include <stdio.h>

void horaValida(long int numero ,int *segundos , int *minutos , int *horas ){
    
    if(numero>0){
        (*segundos) = numero%100;
        numero = numero/100;
        (*minutos) = numero%100;
        numero = numero/100;
        (*horas)= numero%100;

        if( *horas>23 || *minutos>59 || *segundos >59){
            (*horas) = 00;
            (*minutos) = 00;
            (*segundos) = 00;
        }
    }else{
        (*horas) = 00;
        (*minutos) = 00;
        (*segundos) = 00;
    }


}


int main(){
    long int numero = 213620;
    int segundos , minutos,horas;
    
    horaValida(numero, &segundos ,&minutos ,&horas);
    printf("%d - %d - %d \n", horas,minutos,segundos);

    numero = 236220;
    horaValida(numero, &segundos ,&minutos ,&horas);
    printf("%d - %d - %d \n", horas,minutos,segundos);

    numero = -236220;
    horaValida(numero, &segundos ,&minutos ,&horas);
    printf("%d - %d - %d \n", horas,minutos,segundos);


    return 0;
}