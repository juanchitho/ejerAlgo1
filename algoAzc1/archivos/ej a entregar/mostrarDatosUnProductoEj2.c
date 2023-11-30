/*
Escribir un programa modular en C, que solicite el ingreso de un código de producto, y luego muestre los datos asociados al mismo, que se encuentran en el archivo productos.dat
Si el código de producto no existe, debe mostrarse el mensaje "Código de Producto Inexistente".
El programa debe continuar solicitando el ingreso de códigos de próducto hasta que se ingrese 0.

La estructura de los registros es la siguiente:

typedef struct{
	int codigo;
	char descripcion[30];
	float cantidad;
}t_regProducto;

*/
#include <stdio.h>

typedef struct{
    int codigo;
    char descripcion[30];
    float cantidad;
}t_regProducto;

void mostrar_datos(FILE *arProductos){
    t_regProducto rProducto;
    int codigoProducto;
    int existeProducto = 0;

    printf("\nIngrese el codigo del producto: ");
    scanf("%d", &codigoProducto);

    fread(&rProducto, sizeof(rProducto), 1, arProductos);

    while (!feof(arProductos))
    {
        if (rProducto.codigo == codigoProducto)
        {
            printf("\nCodigo \tDescripcion \t\t\tCantidad");
            printf("\n %d \t %-30s %8.2f", rProducto.codigo, rProducto.descripcion, rProducto.cantidad);
            existeProducto = 1;
        }
        fread(&rProducto, sizeof(rProducto), 1, arProductos);
    }
    if (existeProducto == 0)
    {
        printf("\nCodigo de Producto Inexistente");
    }
    printf("\n");
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