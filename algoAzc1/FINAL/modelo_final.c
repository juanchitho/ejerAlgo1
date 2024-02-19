/*
Una ferretería posee un archivo denominado productos. dat, cuyos registros contienen el código de producto (entero) -cada código de producto es único, no se repite en el archivo-, su descripción (cadena de 50 caracteres), el código del proveedor (entero) y su precio (real). El archivo se encuentra desordenado y NO "ENTRA" EN MEMORIA.

Se pide desarrollar un programa en lenguaje C que procese este archivo y que permita:
• 1- Generar una tabla llamada Tornillos que contenga toda la información de aquellos productos en los cuales en su descripción este presente la palabra "tornillo". Asumir que esta tabla tendrá como máximo 100 registros, razón por la cual "ENTRA" EN MEMORIA.
• 2- Ordenar la tabla Tornillos descendentemente por el código de producto.
• 3- Solicitar el ingreso de un código de producto y buscar de modo eficiente en la tabla Tornillos el código ingresado. De encontrar el registro correspondiente a dicho código, mostrar por pantalla todos los campos del mismo. En caso de no encontrarlo, mostrar por pantalla el mensaje "CODIGO NO ENCONTRADO"

*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct 
{
    int codigo;
    char descripcion[50];
    int codigo_proveedor;
    float precio;
} TRegistro;
typedef TRegistro TablaVec[MAX];

//1)generar tabla tornillos
void generar_tabla(FILE *archivo,TablaVec Tornillos, int *ml){
    TRegistro regIndividual;
    int i=0;
    fread(&regIndividual,sizeof(regIndividual),1,archivo);
    while (!feof(archivo))
    {
        if(strstr(regIndividual.descripcion,"tornillo") != NULL){
                Tornillos[i] = regIndividual;
                i++;
        }
        fread(&regIndividual,sizeof(regIndividual),1,archivo);
    }
    (*ml)=i; //al crear una tabla nueva es importante saber cual es el ml para despues poder trabajar con eso
}

//2)ordeno tabla por codigo producto descendentemente 
void odenamiento_descendente(TablaVec Tornillo, int ml){
    int i = 0;
    int j;
    bool intercambio = true;
    TRegistro aux;
    
    while (i < ml - 1 && intercambio)
    {
        intercambio = false;
        for(j=0; j < ml - 1 - i; j++){
            if(Tornillo[j].codigo < Tornillo[j + 1].codigo){
                aux = Tornillo[j];
                Tornillo[j] = Tornillo[j+1];
                Tornillo[j + 1] = aux;
                intercambio = true;
            }
        }
        i++;
    }

}
//3)busqueda binaria por codigo
int busqueda_por_codigo(TablaVec Tornillos, int ml , int codigo){
    int inf,sup,mit,posicion;
    bool terminado;
    inf= 0;
    sup= ml - 1;
    terminado = false;

    while (!terminado)
    {
        if (codigo<Tornillos[sup].codigo || (codigo>Tornillos[inf].codigo))//si llega estar por fuera del arreglo, el arreglo esta ordenado descendente
        {
            terminado=true;
            posicion = -1;
        }else{
            mit=(inf+sup)/2;
            if (Tornillos[mit].codigo == codigo)//si llega a ser justo el de la mitad
            {
                terminado=true;
                posicion=mit;
            }else{
                if(codigo<Tornillos[mit].codigo){
                    inf=mit+1;
                }else{
                    sup=mit-1;
                }
            }
            
        }
        
    }

    return posicion;
}

void pedido_de_codigo(TablaVec Tornillos, int ml){
    int codigo;
    printf("Ingrese un codigo a buscar en la tabla Tornillos \n");
    scanf("%d",&codigo);
    int posicion = busqueda_por_codigo(Tornillos,ml,codigo);

    if(posicion != -1){
        printf("Codigo: %d \n",Tornillos[posicion].codigo);
        printf("Descripcion: %s \n",Tornillos[posicion].descripcion);
        printf("Codigo del proveedor: %d \n",Tornillos[posicion].codigo_proveedor);
        printf("Precio: %.2f \n",Tornillos[posicion].precio);
    }else{
        printf("CODIGO NO ENCONTRADO\n");
    }
}

int main(){
    TablaVec Tornillos;
    int ml;
    FILE *archivo;
    archivo = fopen("productos.dat","rb");
    
    if(archivo == NULL){
        printf("\n Error al abrir el archivo\n");
    }else{
        generar_tabla(archivo,Tornillos,&ml);
        odenamiento_descendente(Tornillos,ml);
        pedido_de_codigo(Tornillos,ml);
        
    }
    fclose(archivo);

    return 0;
}