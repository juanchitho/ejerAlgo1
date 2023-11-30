/*
Escribir un programa modular en C, que permita listar los datos de los productos que se encuentran en el archivo productos.dat.
La estructura de los registros es la siguiente:

typedef struct{
	int codigo;
	char descripcion[30];
	float cantidad;
}t_regProducto;

El archivo sólo se puede leer una vez.
Informar al final del listado, el total de Productos en Stock.

Para la construcción del programa, podés utilizar el editor del intérprete o el IDE que prefieras.
Luego copia y pega lo que hayas hecho en la caja de texto de esta actividad y efectuá la entrega de la misma.

*/
#include <stdio.h>

typedef struct{
    int codigo;
    char descripcion[30];
    float cantidad;
}t_regProducto;

void mostrar_datos(FILE *arProductos){
    t_regProducto rProducto;
    int totalProductos = 0;

    fread(&rProducto, sizeof(rProducto), 1, arProductos);

    printf("\nCodigo \tDescripcion \t\t\tCantidad");

    while (!feof(arProductos))
    {
        printf("\n %d \t %-30s %8.2f", rProducto.codigo, rProducto.descripcion, rProducto.cantidad);
        totalProductos+=rProducto.cantidad;
        fread(&rProducto, sizeof(rProducto), 1, arProductos);
    }
    printf("\nTotal de productos en stock: %d\n", totalProductos);
}

int main(){
    FILE *arProductos;

    arProductos = fopen("productos.dat", "rb");

    if (arProductos == NULL)
    {
        printf("\nNo se pudo abrir el archivo!\n");
    }
    else
    {
        mostrar_datos(arProductos);
        fclose(arProductos);
    }

    return 0;
}