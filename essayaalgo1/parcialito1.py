matriz1 = [[("QATAR",1),("INGLATERRA",9),("ARGENTINA", 9)], [("ECUADOR", 5), ("IRAN",4), ("COLOMBIA",0)]]

def mayor_puntaje_por_columna(matriz):
    largo_columna = len(matriz[0])
    ganadores = [""] * largo_columna 
    for columna in range(largo_columna):
        maximo_actual = 0
        for fila in matriz:
            if fila[columna][1] > maximo_actual:
                maximo_actual = fila[columna][1]
                ganador = fila[columna][0]
        ganadores[columna] = ganador

    return ganadores

def mayor_puntaje_por_columna1(matriz):
    largo_columna = len(matriz[0])
    ganadores = [] 
    for columna in range(largo_columna):
        maximo_actual = 0
        ganador=""
        for fila in range(len(matriz)):
            if matriz[fila][columna][1] > maximo_actual: 
                maximo_actual = matriz[fila][columna][1]
                ganador = matriz[fila][columna][0]
        ganadores.append(ganador)

    return ganadores



print(mayor_puntaje_por_columna(matriz1))


"""<pais>:<pais>-<goles>:<goles"""

def pedir_resultado():
    while True:
        resultado = input("Ingrese los equipos y el resultado del partido")
        paises_goles = resultado.split("-")
        if len(paises_goles) != 2:
            print("algo")
            continue
        paises, goles = paises_goles
        paises = paises.split(":")
        goles = goles.split(":")
        if len(paises)!= 2 or len(goles)!=2:
            print("algo")
            continue
        if not goles[0].isdigit() or not goles[1].isdigit():
            print("algo")
        
        return paises[0],paises[1], int(goles[0]), int(goles[1])    
    

def censurar(texto, palabras_a_censurar):
    """palabras_censuradas = "" """
    palabras_censuradas = [] 
    palabras = texto.split()
    for palabra in palabras:
        if palabra.lower() in palabras_a_censurar:
            """palabras_censuradas += "*" * len(palabra) + " " """
            palabras_censuradas.append("*" * len(palabra))
        else:
            """palabras_censuradas += palabra + " " """
            palabras_censuradas.append(palabra)
        
    return " ".join(palabras_censuradas)
    """return palabras_censuradas[:-1]"""

print(censurar("Que Es ese Queso", "que"))