/*
Escribir un programa que solicite el ingreso de valores, que representarán una
cantidad de segundos. El programa deberá informar al usuario, el equivalente en
días, horas, minutos y segundos.
Se debe validar que el valor ingresado sea entero y positivo, de lo contrario,
deberá mostrarse el mensaje: “Valor ingresado inválido”.
El ingreso de valores finaliza cuando el usuario ingrese como valor, 0.

Ejemplo: 
Valor ingresado: 1234567

Resultado:
Dias: 14
Horas: 6
Minutos: 56
Segundos 7

verificacion:
https://www.satsig.net/training/seconds-days-hours-minutes-calculator.htm
*/
#include <stdio.h>


int main(){
	int diaSeg=86400;
	int horaSeg=3600;
	int minutosSeg=60;
	int segundos;
	int dia , hora ,minutos , seg;

	printf("Ingrese segundos(0 para terminar)\n");
	scanf("%d",&segundos);
	while(segundos!=0){
		if (segundos<0){
			printf("Valor ingresado invalido \n");
		}
		else{
			dia = segundos/diaSeg;
			hora = (segundos-(dia*diaSeg))/horaSeg;
			minutos = (segundos-(dia*diaSeg)-(hora*horaSeg))/minutosSeg;
			seg = (segundos-(dia*diaSeg)-(hora*horaSeg)-(minutos*minutosSeg));
			printf("Resultado:\n Dias: %d \n Horas:%d \n Minutos: %d \n Segundos: %d \n",dia,hora,minutos,seg);
		}
		printf("Vuelve a ingresar segundos(0 para terminar)\n");
		scanf("%d",&segundos);
	}
	return 0;
}
