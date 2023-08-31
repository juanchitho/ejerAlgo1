"""Lógica del juego Unruly"""

from typing import List, Tuple, Any

Grilla = Any


def crear_grilla(desc: List[str]) -> Grilla:
    """Crea una grilla a partir de la descripción del estado inicial.

    La descripción es una lista de cadenas, cada cadena representa una
    fila y cada caracter una celda. Se puede asumir que la cantidad de las
    filas y columnas son múltiplo de dos. **No** se puede asumir que la
    cantidad de filas y columnas son las mismas.
    Los caracteres pueden ser los siguientes:

    Caracter  Contenido de la celda
    --------  ---------------------
         ' '  Vacío
         '1'  Casillero ocupado por un 1
         '0'  Casillero ocupado por un 0

    Ejemplo:

    >>> crear_grilla([
        '  1 1 ',
        '  1   ',
        ' 1  1 ',
        '  1  0',
    ])
    """
    grilla = []
    for fila in range(len(desc)):
        nueva_fila = []
        for columna in range(len(desc[fila])):
            if desc[fila][columna] == ' ':
                nueva_fila.append(' ')
            elif desc[fila][columna] == '1':
                nueva_fila.append(1)
            elif desc[fila][columna] == '0':
                nueva_fila.append(0)
        grilla.append(nueva_fila)
    return grilla


def dimensiones(grilla: Grilla) -> Tuple[int, int]:
    """Devuelve la cantidad de columnas y la cantidad de filas de la grilla
    respectivamente (ancho, alto)"""
    ancho = len(grilla[0]) #columnas
    alto = len(grilla) #filas
    tupla = (ancho, alto)
        
    return tupla
    


def posicion_es_vacia(grilla: Grilla, col: int, fil: int) -> bool:
    """Devuelve un booleano indicando si la posición de la grilla dada por las
    coordenadas `col` y `fil` está vacía"""
    
    if grilla[fil][col] == ' ':
        return True
    else:
        return False

def posicion_hay_uno(grilla: Grilla, col: int, fil: int) -> bool:
    """Devuelve un booleano indicando si la posición de la grilla dada por las
    coordenadas `col` y `fil` está el valor 1"""
    if grilla[fil][col] == 1:
        return True
    else:
        return False



def posicion_hay_cero(grilla: Grilla, col: int, fil: int) -> bool:
    """Devuelve un booleano indicando si la posición de la grilla dada por las
    coordenadas `col` y `fil` está el valor 0"""
    if grilla[fil][col] == 0:
        return True
    else:
        return False
    



def cambiar_a_uno(grilla: Grilla, col: int, fil: int):
    """Modifica la grilla, colocando el valor 1 en la posición de la grilla
    dada por las coordenadas `col` y `fil`"""
    grilla[fil][col] = 1
    #print(grilla)


def cambiar_a_cero(grilla: Grilla, col: int, fil: int):
    """Modifica la grilla, colocando el valor 0 en la posición de la grilla
    dada por las coordenadas `col` y `fil`"""
    grilla[fil][col] = 0
    #print(grilla)


def cambiar_a_vacio(grilla: Grilla, col: int, fil: int):
    """Modifica la grilla, eliminando el valor de la posición de la grilla
    dada por las coordenadas `col` y `fil`"""
    grilla[fil][col] = ' '
    #print(grilla)

def fila_es_valida(grilla: Grilla, fil: int) -> bool:
    """Devuelve un booleano indicando si la fila de la grilla denotada por el
    índice `fil` es considerada válida.

    Una fila válida cuando se cumplen todas estas condiciones:
        - La fila no tiene vacíos
        - La fila tiene la misma cantidad de unos y ceros
        - La fila no contiene tres casilleros consecutivos del mismo valor
    """
    fila = grilla[fil-1]
    if ' ' in fila:
        return False
    else:
        if fila.count(1) == fila.count(0):
            for i in range(len(fila)-2):
                if fila[i] == fila[i+1] == fila[i+2]:
                    return False
            return True
        else:
            return False


def columna_es_valida(grilla: Grilla, col: int) -> bool:
    """Devuelve un booleano indicando si la columna de la grilla denotada por
    el índice `col` es considerada válida.

    Las condiciones para que una columna sea válida son las mismas que las
    condiciones de las filas."""
    columna = []
    for i in range(len(grilla)):
        columna.append(grilla[i][col-1])
    if ' ' in columna:
        return False
    else:
        if columna.count(1) == columna.count(0):
            for i in range(len(columna)-2):
                if columna[i] == columna[i+1] == columna[i+2]:
                    return False
            return True
        else:
            return False


def grilla_terminada(grilla: Grilla) -> bool:
    """Devuelve un booleano indicando si la grilla se encuentra terminada.

    Una grilla se considera terminada si todas sus filas y columnas son
    válidas."""
    for i in range(len(grilla)):
        if fila_es_valida(grilla, i+1) == False:
            return False
    for i in range(len(grilla[0])):
        if columna_es_valida(grilla, i+1) == False:
            return False
    return True

"""print(crear_grilla([
        '  1 1 ',
        '  1   ',
        ' 1  1 ',
        '  1  0',
    ]))
print(dimensiones(crear_grilla([
        '  1 1 ',
        '  1   ',
        ' 1  1 ',
        '  1  0',
    ])))
print(posicion_hay_uno([[' ', ' ', 1, ' ', 1, ' '], [' ', ' ', 1, ' ', ' ', ' '], [' ', 1, ' ', ' ', 1, ' '], [' ', ' ', 1, ' ', ' ', 0]],6,4))
cambiar_a_uno([[' ', ' ', 1, ' ', 1, ' '], [' ', ' ', 1, ' ', ' ', ' '], [' ', 1, ' ', ' ', 1, ' '], [' ', ' ', 1, ' ', ' ', 0]],1,1)
cambiar_a_vacio([[' ', ' ', 1, ' ', 1, ' '], [' ', ' ', 1, ' ', ' ', ' '], [' ', 1, ' ', ' ', 1, ' '], [' ', ' ', 1, ' ', ' ', 0]],6,4)
print(fila_es_valida([[' ', ' ', 1, ' ', 1, ' '], [' ', ' ', 1, ' ', ' ', ' '], [' ', 1, ' ', ' ', 1, ' '], [0, 1, 0, 1, 1, 0]],4))
print(columna_es_valida([['1', ' ', 1, ' ', 1, 1], [' ', ' ', 1, ' ', ' ', 0], [' ', 1, ' ', ' ', 1, 1], [0, 1, 0, 1, 1, 0]],6))
print(grilla_terminada([[0, 0, 1, 0, 1, 1], [0, 1, 0, 1, 0, 1], [1, 0, 1, 0, 1, 0], [1, 1, 0, 1, 0, 0]]))"""