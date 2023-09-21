/*inclusion de archivos*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int x;
	do
	{
	printf("ingrese x menor de 100:");
	scanf("%d",&x);
	}while(x>100);
	printf("x es %d\n",x);

	return 0;
}
