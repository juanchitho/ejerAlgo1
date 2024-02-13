#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MF 20
#define NO_ENCONTRADO -1

typedef int tvector[MF];

int BusqSec(tvector valores, int tamanio, int buscado)
{
  int i=0, posicion=NO_ENCONTRADO;
  bool encontrado=false;
 
  // mientras no se encontro y restan elementos por comparar
  while (!encontrado && i<tamanio) { //! (not) ==> mientas esto (encontrado) no sea true y...
    if (valores[i] == buscado)
    {
        encontrado=true;
        posicion=i;
    }
    i++;
  }

  return posicion;
}

int BusqBinaria(tvector valores, int tamanio, int buscado)
{
  int inf, sup, mit;
  bool terminado;
  int posicion;
 
  // inicializaciones
  inf=0;
  sup=tamanio-1;
  terminado=false;

  while (!terminado) //while(terminado == false)
  {
      if ((buscado > valores[sup]) || (buscado < valores[inf]))
      {
          terminado = true; // NO ESTA => FIN DE LA BUSQUEDA
          posicion = NO_ENCONTRADO;
      }
      else
      {
          mit=(inf+sup)/2;
          if (valores[mit] == buscado)
          {
            terminado = true; // ENCONTRADO => FIN DE LA BUSQUEDA
            posicion = mit;
          }                
          else
            if(buscado > valores[mit])
                inf= mit + 1;
            else
                sup= mit - 1;
      }        
  }

  return posicion;
}

void mostrar_resultado(char *tipo, int dato, int pos) {
  if (pos == NO_ENCONTRADO) {
    printf("Valor %d buscado x BUSQUEDA %s no encontrado \n", dato, tipo);
  } else {
    printf("Valor %d buscado x BUSQUEDA %s encontrado en posicion %d \n", dato, tipo ,pos);
  }
}

int main()
{
  tvector vector = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190};
  int dato, n=MF;
  int pos;

  printf("Ingrese dato a buscar:");
  scanf("%d", &dato);

  /* BUSQUEDA SECUENCIAL */
  pos = BusqSec(vector, n, dato);
  mostrar_resultado("SECUENCIAL", dato, pos);

  /* BUSQUEDA BINARIA */
  pos = BusqBinaria(vector, n, dato);
  mostrar_resultado("BINARIA", dato, pos);

  system("PAUSE");
  return 0;
}