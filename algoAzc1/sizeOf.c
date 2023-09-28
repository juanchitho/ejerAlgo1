#include <stdio.h>
#include <stdlib.h>

int main()
{
	int edad;
	int tamanio;
	int * p1;
	
	edad=12;
	tamanio=sizeof(edad);
	printf("edad = %d  y el tamanio=%d \n",edad,tamanio);
	
	p1=&edad;
	
	printf("p1 = %p\n",p1);
	
	*p1=15;
	printf("desferencear cambio de valor en memoria de edad = %d\n",edad);

	system("PAUSE");
	return 0;
}
