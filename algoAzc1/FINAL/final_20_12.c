/*
Un banco pose un archivo denominado cuentas.dat, cuyos registros contienen el identificador de cliente (entero)- es unico y no se repite en el archivo-, su nombre (cadena de 50 caracteres) y su saldo (real). Este archivo se encuentra ordenado ascendentemente por identificador de cliente y no "entra" en memoria en su totalidad

Se pide desarrollar un programa en lenguaje C que procese este archivo al final de cada dia y que permita:
1)Generar una tabla llamada en_descubierto que contenga toda la informacion de aquellas cuentas en las cuales el saldo actual es negativo. Procesar el archivo de forma tal que dicha tabla quede ordenada ascendentemente por identificador de cliente. asumir que la misma tendra como maximo 250 resgistros, razon por la cual "ENTRA" en memoria.
2)Realizar consultas: para ello, debe solicitar al usuario el ingreso de un identificador de cliente y buscar de modo eficiente en la tabla en_descubierto el identificador ingresado . De encontrar el registro correspondiente a dicho identificador, mostrar por pantalla  todos los campos del mismo . En caso de no encontralo , mostrar por pantalla el mensaje "CLIENTE NO ENCONTRADO EN LA TABLA EN_DESCUBIERTO". Las consultas terminn cuando el usuario ingresa un identificador de cliente negativo.
3)Odenar la table en_descubierto descendentemente por el campo nombre.

*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 250

typedef struct
{
    int id_cliente;
    char nombre[50];
    float saldo;
} Tregistro;
typedef Tregistro TablaVec[MAX];

//1)
void genera_tabla(FILE *archivo,TablaVec en_descubierto,int *ml){
    int i = 0;
    Tregistro cuenta;
    fread(&cuenta,sizeof(cuenta),1,archivo);
    while (!feof(archivo))
    {
        if (cuenta.saldo<0)
        {
            en_descubierto[i]=cuenta;
            i++;
        }
        fread(&cuenta,sizeof(cuenta),1,archivo);
        
    }
    (*ml)=i;
    
}
//2)
int busqueda_por_codigo(TablaVec en_descubierto, int ml , int codigo){
    int inf,sup,mit,posicion;
    bool terminado;
    inf=0;
    sup=ml-1;
    terminado = false;
    while (!terminado)
    {
        if((codigo>en_descubierto[sup].id_cliente) || (codigo<en_descubierto[inf].id_cliente)){
            terminado = true;
            posicion = -1;
        }else{
            mit=(inf+sup)/2;
            if (en_descubierto[mit].id_cliente==codigo)
            {
                terminado=true;
                posicion=mit;
            }else{
                if (codigo>en_descubierto[mit].id_cliente)
                {
                    inf=mit + 1;
                }else{
                    sup=mit - 1;
                }
                
            }
            
        }
    }
    
    return posicion;
}

void pedido_de_codigo(TablaVec en_descubierto, int ml){
    int codigo;
    printf("Ingrese un codigo a buscar en la tabla EN_DESCUBIERTO \n");
    scanf("%d",&codigo);
    while (codigo>=0)
    {
        int posicion = busqueda_por_codigo(en_descubierto,ml,codigo);

        if(posicion != -1){
            printf("Id cliente: %d \n",en_descubierto[posicion].id_cliente);
            printf("Nombre: %s \n",en_descubierto[posicion].nombre);
            printf("Saldo: %.2f \n",en_descubierto[posicion].saldo);
        }else{
            printf("CLIENTE NO ENCONTRADO EN LA TABLA EN_DESCUBIERTO\n");
        }
        printf("\nIngrese un codigo a buscar en la tabla EN_DESCUBIERTO \n");
        scanf("%d",&codigo);
    }
}

//3)
void odenamiento_descendente_por_nombre(TablaVec en_descubierto, int ml){
    int i=0;
    int j;
    bool intercambio = true;
    Tregistro aux;
    while (i < ml - 1 && intercambio)
    {
        intercambio = false;
        for(j=0; j < ml - 1 - i; j++){
            if (strcmp(en_descubierto[j].nombre,en_descubierto[j+1].nombre)<0)
            {
                aux = en_descubierto[j];
                en_descubierto[j] = en_descubierto[j+1];
                en_descubierto[j + 1] = aux;
                intercambio = true;
            }
            
        }
        i++;
    }
    
}

int main(){
    FILE *archivo;
    int ml;
    TablaVec en_descubierto;
    archivo = fopen("cuentas.dat","rb");
    
    if (archivo==NULL)
    {
        printf("Hubo un problema al abrir el archivo");
    }else{
        genera_tabla(archivo,en_descubierto,&ml);
        fclose(archivo);
        pedido_de_codigo(en_descubierto,ml);
        odenamiento_descendente_por_nombre(en_descubierto,ml);
    }
    

    return 0;
}
