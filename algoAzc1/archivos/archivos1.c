//en este ejemplo veremos como crea un archivo y cargarlo con datos

#include <stdio.h>

typedef struct{
    int codigo;
    char descripcion[30];
    float cantidad;
}t_regProducto;


void cargar_datos(FILE *arProductos){
    t_regProducto rProducto;

    printf("codigo de articulo: ");
    scanf("%d", &rProducto.codigo);
    fflush(stdin);

    while (rProducto.codigo != 0)
    {
        printf("descripcion: ");
        scanf(" %30[^\n]s", rProducto.descripcion);
        fflush(stdin);

        printf("cantidad en stock: ");
        scanf(" %f", &rProducto.cantidad);
        fflush(stdin);

        fwrite(&rProducto, sizeof(rProducto), 1, arProductos);

        printf("\n codigo de articulo: ");
        scanf("%d", &rProducto.codigo);
        fflush(stdin);
    }
    return;
    
}

void main (){

    FILE *arProductos;
    arProductos = fopen("productos.dat", "wb");
    if (arProductos == NULL)
    {
        printf("error al abrir el archivo\n");
    }else {
        cargar_datos(arProductos);
        fclose(arProductos);
    }

    return;
}