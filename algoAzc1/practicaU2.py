#unidad 2
#1)
def encuestasXY():
    enc_prod_x=0
    enc_prod_y=0
    total_ambos_prod=0
    enc_prod_solamente_x=0
    enc_prod_solamente_y=0
    enc_total_ninguno = 0
    cantidad_enc=0
    continuar=True
    while continuar:
        encuestar = input("quiere cargar a un encuestado(s para continuar): ")
        if encuestar != 's':
            continuar = False
        else:
            opcion_x=input("consume el producto x?(s) ")
            opcion_y=input("consume el producto y?(s) ")
            
            cantidad_enc+=1
            if opcion_x == 's' and opcion_y == 's':
                enc_prod_x+=1
                enc_prod_y+=1
                total_ambos_prod+=1
            elif opcion_x == 's':
                enc_prod_solamente_x+=1
                enc_prod_x+=1
            elif opcion_y == 's':
                enc_prod_solamente_y+=1
                enc_prod_y+=1
            else:
                enc_total_ninguno+=1
    if cantidad_enc > 0:
        print("total de encuestados",cantidad_enc)
        print("Porcentaje de consumidores del producto x",((100*enc_prod_x)/cantidad_enc),"%")
        print("Porcentaje de consumidores del producto y",((100*enc_prod_y)/cantidad_enc),"%")
        print("Porcentaje de consumidores solo del producto x",((100*enc_prod_solamente_x)/cantidad_enc),"%")
        print("Porcentaje de consumidores solo del producto y",((100*enc_prod_solamente_y)/cantidad_enc),"%")
        
        print("Porcentaje de consumidores de ambos productos",((100*total_ambos_prod)/cantidad_enc),"%")
        
        print("Porcentaje de los que no consumieron ninguno de los productos",((100*enc_total_ninguno)/cantidad_enc),"%")

    else:
        print("no hubo encuestados")
            

#encuestasXY()

#2)
"""
En este ejercicio, tienes un rectángulo con coordenadas (3 <= x <= 5, 2 <= y <= 3) en el plano. Esto significa que el rectángulo tiene esquinas en (3, 2) (esquina inferior izquierda) y (5, 3) (esquina superior derecha).

Ahora, debes determinar la posición de un punto (x, y) con respecto a este rectángulo. Hay tres posibilidades:

    Interior: Si el punto (x, y) está dentro del rectángulo, esto significa que (3 <= x <= 5) y (2 <= y <= 3). El punto se encuentra en el interior del rectángulo.

    Exterior: Si el punto (x, y) está fuera del rectángulo, esto significa que (x < 3 or x > 5) o (y < 2 or y > 3). El punto está fuera del rectángulo.

    Pertenece: Si el punto (x, y) no está en ninguna de las dos categorías anteriores, entonces pertenece a los bordes o las esquinas del rectángulo. Esto significa que (x >= 3 and x <= 5) y (y >= 2 and y <= 3) pero no está completamente en el interior.

La función determinar_posicion(x, y) implementa esta lógica. Primero, verifica si (x, y) está dentro del rectángulo revisando las condiciones (3 <= x <= 5) y (2 <= y <= 3). Si ambas condiciones son verdaderas, el punto está en el interior.

Luego, verifica si (x, y) está fuera del rectángulo revisando las condiciones (x < 3 or x > 5) o (y < 2 or y > 3). Si alguna de estas condiciones es verdadera, el punto está fuera del rectángulo.

Finalmente, si ninguna de las condiciones anteriores es verdadera, significa que (x, y) pertenece a los bordes o las esquinas del rectángulo, por lo que se declara como "Pertenece".
"""
def determinar_posicion(x, y):
    if 3 <= x <= 5 and 2 <= y <= 3:
        return "Interior"
    else:
        if -99 < x < 3 or x > 5 or -99 < y < 2 or y > 3:
            return "Exterior"
        else:
            return "Pertenece"

def pares_ordenados():
    # Lista de pares ordenados (x, y)
    pares_ordenados = [(1, 2), (4, 2.5), (6, 3.5), (0, 0), (3.5, 2.5)]
    
    for par in pares_ordenados:
        x, y = par
        resultado = determinar_posicion(x, y)
        print(f"Para el punto ({x}, {y}): {resultado}")

pares_ordenados()

