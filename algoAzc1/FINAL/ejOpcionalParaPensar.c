/*
Una institucion educativa posee los siguientes archivos binarios:
Archivo de socios (socios.dat) contiene todos los socios actuales de la institucion
Formato de registro: DNI (entero), Numero de socio (entero), Nombre y apellido (string).

Archivo de Socios Nuevos (nuevos.dat) contiene los socios nuevos
Formato de registro: DNI (entero), Numero de socio (entero), Nombre y apellido (string), Sucursal (entero)

Todos los dias se recibe el archivo de Socios nuevos con la altas realizadas el dia anterior
y se desea actualizar el archivo de socios agregando los socios nuevos.
Ambos archivos estan ordenados por DNI en forma ascendente.
En caso de que el DNI de un socio nuevo ya existiera en el archivos de socios se debe actualizar el campo Nombre y apellido
y agregar el DNI a un archivo de texto llamado actualizaciones.txt

Escribir un programa en lenguaje C que genere un tercer archivo de socios actualizado
(sociosAct.dat)
Este archivo debe quedar ordenado por DNI en forma ascendente.
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    int dni;
    int num_socio;
    char nombre_apellido[50];
} Socios;

typedef struct
{
    int dni;
    int num_socio;
    char nombre_apellido[50];
    int sucursal;
} SociosNuevos;

void actualizarSocios(FILE *archivo_socios, FILE *archivo_nuevos_socios, FILE *archivo_socios_activos, FILE *archivo_actualizaciones)
{
    Socios socio_actual;
    Socios aux;
    SociosNuevos nuevo;
    archivo_socios = fopen("socios.dat", "rb");
    archivo_nuevos_socios = fopen("nuevos.dat", "rb");
    archivo_socios_activos = fopen("sociosAct.dat", "rb");
    archivo_actualizaciones = fopen("actualizaciones.txt", "w");

    if (archivo_socios == NULL || archivo_nuevos_socios == NULL || archivo_socios_activos == NULL || archivo_actualizaciones == NULL)
    {
        printf("Error al abrir alguno de los archivos\n");
    }
    else
    {

        fread(&socio_actual, sizeof(socio_actual), 1, archivo_socios);
        fread(&nuevo, sizeof(nuevo), 1, archivo_nuevos_socios);

        while (!feof(archivo_socios) && !feof(archivo_nuevos_socios))
        {
            if (socio_actual.dni < nuevo.dni)
            {
                fwrite(&socio_actual, sizeof(socio_actual), 1, archivo_socios_activos);
                fread(&socio_actual, sizeof(socio_actual), 1, archivo_socios);
            }
            else if (socio_actual.dni == nuevo.dni)
            {
                strcpy(socio_actual.nombre_apellido, nuevo.nombre_apellido);
                fwrite(&socio_actual, sizeof(socio_actual), 1, archivo_socios_activos);

                fprintf(archivo_actualizaciones, "%d\n", socio_actual.dni);

                fread(&socio_actual, sizeof(socio_actual), 1, archivo_socios);
                fread(&nuevo, sizeof(nuevo), 1, archivo_nuevos_socios);
            }
            else
            {
                aux.dni = nuevo.dni;
                strcpy(aux.nombre_apellido, nuevo.nombre_apellido);
                aux.num_socio = nuevo.num_socio;

                fwrite(&aux, sizeof(aux), 1, archivo_socios_activos);
                fread(&nuevo, sizeof(nuevo), 1, archivo_nuevos_socios);
            }
        }

        while (!feof(archivo_socios))
        {
            fwrite(&socio_actual, sizeof(socio_actual), 1, archivo_socios_activos);
            fread(&socio_actual, sizeof(socio_actual), 1, archivo_socios);
        }

        while (!feof(archivo_nuevos_socios))
        {
            aux.dni = nuevo.dni;
            strcpy(aux.nombre_apellido, nuevo.nombre_apellido);
            aux.num_socio = nuevo.num_socio;

            fwrite(&aux, sizeof(aux), 1, archivo_socios_activos);
            fread(&nuevo, sizeof(nuevo), 1, archivo_nuevos_socios);
        }
    }

    fclose(archivo_socios);
    fclose(archivo_nuevos_socios);
    fclose(archivo_socios_activos);
    fclose(archivo_actualizaciones);
}

int main()
{
    FILE *archivo_socios, *archivo_nuevos_socios, *archivo_socios_activos, *archivo_actualizaciones;

    actualizarSocios(archivo_socios, archivo_nuevos_socios, archivo_socios_activos, archivo_actualizaciones);

    return 0;
}
