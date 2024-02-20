/*
 Una libreria posee un archivo denominado Stock.dat, cuyos registros contienen el codigo de libro(entero),el codigo de la editorial(entero),el stock actual de dicho libro(entero) y el stock minimo de dicho libro(entero). Dicho archivo no esta ordenado y no "entra" en memoria en su totalidad.

 Se pide desarrollar un programa en lenguaje C que procese este archivo y que permita:
 1)Generar una tabla llamada Pedidos que contenga toda la informacion de aquellos libros cuyo stock_actual esta por debajo del stock minimo. Asumir que esta tabla tendra como MAXIMO 100 registros, razon porla cual "ENTRA" EN MEMORIA.
 2) Ordenar la tabla Pedidos ascendentemente.
 3)Realizar consultas: para ello , debe solicitar al usuario el ingreso de un codigo de libro y buscar de modo eficiente en la tabla Pedidos el codigo ingresado. De encontrar el registro correspondiente a dicho codigo, mostrar por pantalla todos los cmapos del mismo. En caso de no encontrarlo, mostrar por pantalla el mensaje "CODIGO NO ENCONTRADO". Las consultas terminan cuando el usuario ingresa un codigo de libro negativo. 
 
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100
typedef struct 
{
    int codigo;
    int codigo_editorial;
    int stock_atual;
    int stock_minimo;
}Tregistro;
typedef Tregistro TablaVec[MAX];

//1)
void generar_tabla_pedidos(FILE *archivo,TablaVec Pedidos,int *ml){
    int i=0;
    Tregistro libro;
    fread(&libro,sizeof(libro),1,archivo);

    while (!feof(archivo))
    {
        if (libro.stock_atual<libro.stock_minimo)
        {
            Pedidos[i]=libro;
            i++;
        }
        fread(&libro,sizeof(libro),1,archivo);
        
    }
    (*ml)=i;
    
}
//2) ordenamiento de la tabla pedidos de forma ascendente
void ordenamiento_ascendente(TablaVec Pedidos,int ml){
    int i=0;
    int j;
    bool intercambio = true;
    Tregistro aux;
    while (i < ml - 1 && intercambio)
    {
        intercambio=false;
        for(j=0; j < ml - 1 - i; j++){
            if (Pedidos[j].codigo>Pedidos[j+1].codigo)
            {
                aux = Pedidos[j];
                Pedidos[j]=Pedidos[j+1];
                Pedidos[j+1]=aux;
                intercambio=true;
            }
            
        }
        i++;
    }
    
}

//3)
int busqueda_binaria(TablaVec Pedidos,int ml,int codigo){
    int inf, sup, mit,posicion;
    bool terminado;
    inf = 0;
    sup = ml -1;
    terminado = false;
    
    while (!terminado)
    {
        if ((codigo > Pedidos[sup].codigo) || (codigo < Pedidos[inf].codigo))
        {
            terminado = true;
            posicion = -1;
        }else{
            mit=(inf+sup)/2;
            if (Pedidos[mit].codigo==codigo)
            {
                terminado = true;
                posicion = mit;
            }else{
                if (codigo > Pedidos[mit].codigo)
                {
                    inf = mit + 1;
                }else{
                    sup = mit - 1;
                }
                
            }
            
        }
        
    }
    return posicion;
}

void pedido_de_codigo(TablaVec Pedidos, int ml){
    int codigo;
    printf("Ingrese un codigo a buscar en la tabla Tornillos \n");
    scanf("%d",&codigo);
    int posicion = busqueda_binaria(Pedidos,ml,codigo);

    if(posicion != -1){
        printf("Codigo: %d \n",Pedidos[posicion].codigo);
        printf("Descripcion: %d \n",Pedidos[posicion].codigo_editorial);
        printf("Codigo del proveedor: %d \n",Pedidos[posicion].stock_atual);
        printf("Precio: %d \n",Pedidos[posicion].stock_minimo);
    }else{
        printf("CODIGO NO ENCONTRADO\n");
    }
}

int main(){
    FILE *archivo;
    int ml;
    TablaVec Pedidos;
    archivo = fopen("Stock.dat","rb");

    if(archivo==NULL){
        printf("Error al abrir el archivo");
    }else{
        generar_tabla_pedidos(archivo,Pedidos,&ml);
        fclose(archivo);
        ordenamiento_ascendente(Pedidos,ml);
        pedido_de_codigo(Pedidos,ml);
    }

    return 0;
}