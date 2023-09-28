/* Inclusión de archivos */
#include <stdio.h>
#include <stdbool.h>

#define MAXIMO 1000
#define DESCUENTO 0.1

void mensaje()
{
  //Mensaje inicial	
  printf ("Programa que permite al usuario ingresar los montos de las compras\n");
  printf ("para luego informar por pantalla el importe total a pagar\n");
  printf ("teniendo que cuenta que si éste supera los $1000 corresponde aplicar un 10%% de descuento\n");
  printf ("-----------------------------------------------------------------------------------------\n\n");
}

float solicitar_monto() {
  float monto;
  printf ("Ingrese el monto de la venta (o 0 para terminar): $");  
  scanf("%f", &monto);
  return monto;
}

bool es_monto_valido(float monto) {
  return monto < 0;
}

float procesar_montos(int *cant)
{ 
  float total = 0; //LOCAL A FUNCION INGRESO
  float monto;   //LOCAL A FUNCION INGRESO
  *cant = 0;
  
  //Ingreso de datos  
  monto = solicitar_monto();

  while (monto != 0) {

    if (es_monto_valido(monto)) {
        printf("Monto no válido.\n"); 
    } else {     
        total=total+monto;
        (*cant)++;
    }

    monto = solicitar_monto();
  }
  return total;
}

bool aplica_descuento(float total) {
  return total > MAXIMO;
}

float calcular_descuento(float total) {
  if (aplica_descuento(total)){        
    total = total - (total * DESCUENTO);
  }
  return total;
}

void mostrar_resultados(float total, float total_con_descuento, int cant)
{
  //Presentacion de resultado
  if (aplica_descuento(total)) { 
    printf("El total a pagar ( $ %6.2f ) supera los $1000, se aplica descuento del 10%%\n", total);
    printf("Total a pagar por los %d items es: $ %6.2f \n", cant, total_con_descuento);    
  } else {
    printf("Total a pagar por los %d items es: $ %6.2f \n", cant, total); // %6.2f	=> tamaño total de 6 dígitos, con dos decimales
  }
}

/* Función principal */
int main ()
{
  float total, total_con_descuento;
  int cantidad;
 
  mensaje();
 
  total = procesar_montos(&cantidad);
  total_con_descuento = calcular_descuento(total);
  mostrar_resultados(total, total_con_descuento, cantidad);
  
  return 0;
}