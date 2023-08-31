

import random

import niveles
from unruly import Grilla ,dimensiones,crear_grilla, cambiar_a_uno, cambiar_a_cero, grilla_terminada

def main():
    nivel = random.choice(niveles.NIVELES)
    grilla = crear_grilla(nivel)
    col_num, row_num = dimensiones(grilla)

    print("##################")
    print("## Juego UNRULY ##")
    print("##################")

    while True:
        print_grid(grilla)
        columna, fila, valor = enter_coordinates()

        if columna < col_num and fila < row_num and valor in ('1', '0'):
            if valor == '1':
                cambiar_a_uno(grilla, columna, fila)
            else:
                cambiar_a_cero(grilla, columna, fila)
        
        if grilla_terminada(grilla):
            print('FIN DEL JUEGO, Ganaste!enhorabuena!')
            quit()




def print_grid(grilla: Grilla) -> None:
    col_num, row_num = dimensiones(grilla)
    
    print('# | ', end='')

    for columna in range(0, col_num):
        print(str(columna) + ' | ', end='')

    print('|')

    for fila in range(0, row_num):
        print(str(fila) + ' | ', end='')
        for columna in range(0, col_num):
            if grilla[fila][columna] == ' ':
                print(' _ ', end='')
            else:
                print(grilla[fila][columna] ,' ', end='')
        
        print()


def enter_coordinates() -> tuple[int, int, int]:
    print("Comando: (columna fila valor)")
    print("Salir: quit")

    while True:
        entry = input('Comando: ')
        
        if(entry == 'quit'):
            quit()

        coordinates = entry.split(' ')

        if len(coordinates) == 3 and all(c.isdigit() for c in coordinates):
            return (int(coordinates[0]), int(coordinates[1]), coordinates[2])
        

main()