/* Ingresar los padrones y las notas de los alumnos
del curso de Algoritmos y programación 1.

Como máximo se cargarán 50 alumnos.
---------------------------------------------------
Se pide:
  1) Realizar el modulo de carga de datos.
  2) Mostrar aprobados (padrón y nota) en orden de notas crecientes.
  3) Agregar un modulo que permita la busqueda, dado un padrón ingresado por el usuario
    indicar que nota obtuvo el alumno. */

#include <stdio.h>
#include <stdbool.h>

#define MAX 50

typedef int tvector[MAX];

int cargarDatos(tvector padrones, tvector notas, int n)
{
    int i = 0;
    bool continuar = true;

    printf("Ingrese los padrones y notas de los alumnos:\n");
    while (i < n && continuar)
    {
        printf("Alumno %d (padron): ", i + 1);
        if (scanf("%d", &padrones[i]) == 1)
        {
            printf("Alumno %d (nota): ", i + 1);
            if (scanf("%d", &notas[i]) == 1)
            {
                i++;
            }
            else
            {
                printf("Entrada no válida para la nota. Intente de nuevo.\n");
            }
        }
        else
        {
            printf("Entrada no válida para el padrón. Intente de nuevo.\n");
        }

        printf("¿Desea cargar un alumno? (1 para sí, 0 para no): ");
        int respuesta;
        if (scanf("%d", &respuesta) == 1 && respuesta == 0)
        {
            continuar = false;
        }
    }
    return i;
}

void mostrarAprobados(tvector padrones, tvector notas, int n)
{
    printf("Aprobados (padrón y nota) en orden de notas crecientes:\n");

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (notas[j] < notas[min_index])
            {
                min_index = j;
            }
        }

        int auxNota = notas[i];
        notas[i] = notas[min_index];
        notas[min_index] = auxNota;

        int auxPadron = padrones[i];
        padrones[i] = padrones[min_index];
        padrones[min_index] = auxPadron;
    }

    for (int i = 0; i < n; i++)
    {
        if (notas[i] >= 4.0)
        {
            printf("Padrón: %d, Nota: %d\n", padrones[i], notas[i]);
        }
    }
}

int buscarNota(tvector padrones, tvector notas, int n, int buscarPadron)
{
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (padrones[medio] == buscarPadron)
        {
            printf("Nota: %d\n", notas[medio]);
            return medio;
        }

        if (padrones[medio] < buscarPadron)
        {
            izquierda = medio + 1;
        }
        else
        {
            derecha = medio - 1;
        }
    }

    printf("Alumno no encontrado.\n");
    return -1; // No se encontró el padrón.
}

int main()
{
    tvector padrones;
    tvector notas;
    int n;

    n = cargarDatos(padrones, notas, MAX);

    mostrarAprobados(padrones, notas, n);

    int buscarPadron;
    bool continuar = true;

    while (continuar)
    {
        printf("Ingrese el padrón a buscar (o 0 para salir): ");
        if (scanf("%d", &buscarPadron) == 1)
        {
            if (buscarPadron == 0)
            {
                continuar = false;
            }
            else
            {
                buscarNota(padrones, notas, n, buscarPadron);
            }
        }
        else
        {
            printf("Entrada no válida para el padrón.\n");
        }
    }

    return 0;
}