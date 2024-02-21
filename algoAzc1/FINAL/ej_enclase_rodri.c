/* Una ferreteria posee un archivo denominado productos.dat, cuyos registros contienen en el codigo de producto (int), cada codigo de prod es unico, no se repite en el archivo, su descripcion (cadena de 50 caracteres), el codigo del proveedor (int), y su precio(real). El archivo se encuentra desordenado y NO ENTRA EN MEMORIA.

Se pide desarrollar un programa en lenguaje C que procese este archivo y que permita:

1- Generar una tabla llamada Tornillos que contenga toda la informacion de aquellos productos en los cuales en su descripcion este presente la palabra "tornillo". Asumir que esta tabla tendra como maximo 100 registros, razon por la cual ENTRA EN MEMORIA.

2- Ordenar la tabla Tornillos descendentemente por el codigo de producto.

3- Solicitar el ingreso de un codigo de producto y buscar de modo eficiente en la tabla Tornillos el codigo ingresado. De encontrar el registro correspondiente a dicho codigo, mostrar por pantalla todos los campos del mismo. En caso de no encontrarlo, mostrar por pantalla el mensaje "CODIGO NO ENCONTRADO". */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRODUCTOS 100

typedef struct
{
    int codigo;
    char descripcion[50];
    int codigo_proveedor;
    float precio;
} RegProductos;

typedef RegProductos TVec[MAX_PRODUCTOS];

// 1)
void generarTabla(FILE *archivo, TVec Tornillos, int *ml)
{
    RegProductos prod;
    int i = 0;

    fread(&prod, sizeof(prod), 1, archivo);
    while (!feof(archivo))
    {
        if (strstr(prod.descripcion, "tornillo") != NULL)
        {
            Tornillos[i] = prod;
            i++;
        }

        fread(&prod, sizeof(prod), 1, archivo);
    }

    (*ml) = i;
}

// 2)
void ordenDescendentePorCodigo(TVec Tornillos, int ml)
{
    int i = 0, j;
    int intercambio = true;
    RegProductos aux;

    while (i < ml - 1 && intercambio)
    {
        intercambio = false;

        for (j = 0; j < ml - 1 - i; j++)
        {
            if (Tornillos[j].codigo < Tornillos[j + 1].codigo)
            {
                aux = Tornillos[j];
                Tornillos[j] = Tornillos[j + 1];
                Tornillos[j + 1] = aux;
                intercambio = true;
            }
        }

        i++;
    }
}

// 3)
int busquedaProducto(TVec Tornillos, int ml, int codigo)
{
    int inf, sup, mit, posicion;
    bool terminado;

    inf = 0;
    sup = ml - 1;
    terminado = false;

    while (!terminado)
    {
        if (codigo < Tornillos[sup].codigo || codigo > Tornillos[inf].codigo)
        {
            terminado = true; // NO ESTA => FIN DE LA BUSQUEDA
            posicion = -1;
        }
        else
        {
            mit = (inf + sup) / 2;
            if (Tornillos[mit].codigo == codigo)
            {
                terminado = true; // ENCONTRADO => FIN DE LA BUSQUEDA
                posicion = mit;
            }
            else if (codigo > Tornillos[mit].codigo)
                sup = mit - 1;
            else
                inf = mit + 1;
        }
    }

    return posicion;
}

void busquedaCodigo(TVec Tornillos, int ml)
{
    int codigo;

    printf("Ingrese el codigo de producto a buscar: \n");
    scanf("%d", &codigo);

    int pos = busquedaProducto(Tornillos, ml, codigo);

    if (pos != -1)
    {
        printf("Codigo: %d\n", Tornillos[pos].codigo);
        printf("Descripcion: %s\n", Tornillos[pos].descripcion);
        printf("Codigo del proveedor: %d\n", Tornillos[pos].codigo_proveedor);
        printf("Codigo: %.2f\n", Tornillos[pos].precio);
    }
    else
    {
        printf("CODIGO NO ENCONTRADO\n");
    }
}

int main()
{
    FILE *archivo;
    TVec Tornillos;
    int ml;

    archivo = fopen("productos.dat", "rb");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
    }
    else
    {

        generarTabla(archivo, Tornillos, &ml);
        fclose(archivo);
    }
    ordenDescendentePorCodigo(Tornillos, ml);
    busquedaCodigo(Tornillos, ml);

    return 0;
}