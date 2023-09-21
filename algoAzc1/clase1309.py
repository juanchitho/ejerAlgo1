"""Dada una serie de números ingresados de a uno.
Indicar mayor, menor y promedio de la serie.
El ingreso de números finaliza cuando el usuario ingresa 0."""

def sumatoria_de_numeros_promedio(): 
    numero=int(input("ingres de un numero  (0 para finalizar) "))
    sumaTotal=0
    mayorNumero=numero
    menorNumero=numero
    contador=0
    while (numero != 0):
        contador+=1
        sumaTotal+=numero
        if numero > mayorNumero:
                mayorNumero=numero
        elif numero < menorNumero:
                menorNumero=numero
        numero=int(input("ingres de un numero  (0 para finalizar) "))
    if contador == 0:
            print("no se ingreso ningun pais")
    else:
            print("el promedio es ",sumaTotal/contador )
        
            print("el menor numeros es ",menorNumero)
            print("el mayor numeros es ",mayorNumero)
#sumatoria_de_numeros_promedio()

"""
Un juego de un parque de diversiones, debe realizar los siguientes controles antes de comenzar a funcionar:

    Sólo pueden participar quienes tengan una altura entre 1.60 m y 1.90 m

    El peso total de los participantes no debe superar las 1.5 toneladas

    La capacidad máxima de participantes es de 20

Debemos programar una simulación de estos controles, para ello nuestro programa debe solicitar a medida que va a ingresar al juego un nuevo participante, su peso y su altura.

En caso de detectar que la altura del participante no cumple con lo requerido, se debe enviar el siguiente mensaje: “Altura del participante fuera de rango permitido”; y se debe continuar con el siguiente participante.

A medida que se procesan los ingresos de participantes, se debe controlar que el peso acumulado de los participantes no exceda el total permitido. Si lo excediera, debe enviar el mensaje: “Peso total excedido, el participante no puede subir”, el juego puede comenzar con los participantes ya aceptados.

También a medida que se procesan los ingresos de participantes, se debe controlar que la cantidad de participantes no exceda el máximo establecido, por ello, si se alcanza el máximo, se debe informar: “Cantidad máxima de participantes alcanzada” y el juego podrá comenzar si cumple con el resto.

Por último, podría ser que suban menos personas que la capacidad máxima, entonces, utilizar el último ingreso de los pesos como corte de ingreso de participantes, considerando que si se ingresa 0 como peso, indica, que no hay más participantes."""

def juego_parque_diversiones():
    pesoTotal=0
    altura=0
    peso=1
    contador=0
    continuar=True

    while continuar and peso != 0:
            peso=int(input("ingrese el peso del participante (0 para finalizar) "))
        
            altura=float(input("ingrese la altura del participante "))
            if altura >= 1.60 and altura <= 1.90:
                if pesoTotal+peso <= 1500:
                    pesoTotal+=peso
                    contador+=1
                else:
                    print("Peso total excedido, el participante no puede subir")
            else:
                print("Altura del participante fuera de rango permitido")

            if contador == 20:
                print("Cantidad máxima de participantes alcanzada")
                continuar=False
                
            
            

    print("el juego puede comenzar con los participantes ya aceptados")
    print("el peso total de los participantes es de ",pesoTotal)
    print("la cantidad de participantes es de ",contador)
#juego_parque_diversiones()



def juego_parque_diversiones2():
    pesoTotal=0
    contador=0
    continuar=True

    while continuar:
            peso=int(input("ingrese el peso del participante (0 para finalizar) "))
            
            if peso == 0:
                continuar=False
                print("termino el ingreso de participantes")
            else:
                if pesoTotal+peso > 1500:
                    print("Peso total excedido, el participante no puede subir")
                    continuar=False
                else:
                    altura=float(input("ingrese la altura del participante "))
                    if altura < 1.60 or altura > 1.90:
                        print("Altura del participante fuera de rango permitido")
                    else:
                        pesoTotal+=peso
                        contador+=1
                        

            if contador == 2:
                print("Cantidad máxima de participantes alcanzada")
                continuar=False
                
            
            

    print("el juego puede comenzar con los participantes ya aceptados")
    print("el peso total de los participantes es de ",pesoTotal)
    print("la cantidad de participantes es de ",contador)
#juego_parque_diversiones2()

""" 
def juego_parque_diversiones_profe():
    MAX_ALTURA=1.90
    MIN_ALTURA=1.60
    MAX_PESO = 1500
    MAX_PERSONAS = 20


    altura = float(input('ingrese altura (en mts): '))

    if altura < MIN_ALTURA or altura > MAX_ALTURA:
        mostrar fuera de rango
    elif(peso_acumulado + peso_participante > MAX_PESO):
         mostrar peso excedido
    else:
         ingresa participante 

          
 """