### EJERCICIO A ###
def primeras_letras(cadena):
    palabras = cadena.split(" ")
    resultado = ""
    for p in palabras:
        resultado += p[0]
    return resultado

### 7.11 ###
def plegar(texto:str, n:int):
    inicio = 0
    fin = n-1
    resultado = []
    while fin <= len(texto):
        if texto[fin] != " " and texto[fin+1] == " ":
            fin += 1
        elif texto[fin]!= " ":
            fin = encontrar_anterior(texto, inicio, fin)
        resultado.append(texto[inicio:fin])
        inicio=fin+1
        fin=fin+n
    return resultado

def encontrar_anterior(texto, inicio, fin):
    for i in range(fin-1, inicio, -1):
        if texto[i] == " ":
            return i
        

def plegar_2(texto,n):
    palabras = texto.split()
    linea = ""
    resultado = []
    for palabra in palabras:
        if linea =="":
            linea=palabra + " "
            continue
        if len(linea) + len(palabra)+1 <= n:
            linea += palabra + " "
        else:
            resultado.append(linea)
            linea = palabra 
    resultado.append(linea)
    return resultado

print(plegar_2('El viejo Señor Gómez pedía queso, kiwi y habas, pero le ha tocado un saxofón', 20))