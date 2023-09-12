"""Escribir un programa que le solicite al usuario el ingreso de dos números (asumir que serán enteros).
Luego indicar cuál es el mayor de los dos, considerando el valor absoluto.
No se podrá utilizar la función abs( ) provista por Python."""

def mayor_absoluto():
    num1 = int(input("ingrese un numero: "))
    num2 = int(input("ingrese otro numero: "))
    if num1 < 0:
        num1 = num1 * -1
    if num2 < 0:
        num2 = num2 * -1
    if num1 > num2:
        print (num1)
    else:
        print (num2)
#mayor_absoluto()


"""Escribir un programa que le solicite al usuario el ingreso de dos números (asumir que serán enteros).
Luego indicar cuál es el máximo común divisor de ambos números.

    Se define el máximo común divisor (abreviado MCD) de dos o más números enteros al mayor número entero que los divide sin dejar resto.
    Ambos números deben ser distintos a cero.

Requisito: realizar la menor cantidad de ciclos posibles."""

def maximo_comun_divisor():
    num1 = int(input("ingrese un numero: "))
    num2 = int(input("ingrese otro numero: "))
    if num1 > num2:
        mayor = num1
        menor = num2
    else:
        mayor = num2
        menor = num1
    resto = mayor % menor
    while resto != 0:
        mayor = menor
        menor = resto
        resto = mayor % menor
    print (menor)
#maximo_comun_divisor()    


#parte practica
"""Calcular el factorial de un numero ingresado por el usuario e indicarle el resultado."""

def factorial():
    num=int(input("ingrese un numero: "))
    res=1
    for i in range(1,num+1):
        res= res*i
        print("el resultado es",res)
#factorial()

"""Dada una serie de números ingresados de a uno.
# Indicar promedio de la serie.
# El ingreso de números finaliza cuando el usuario ingresa 0"""

def promedio_de_sumatoria():
    suma=0
    contador=0
    #continuar=True
    num=int(input("ingrese un numero (0 para finalizar) "))
    while num != 0:
        suma+=num
        contador+=1
        num=int(input("ingrese otro numero (0 para finalizar) "))
    
    if (contador>0):
        print("la sumatoria total es ",suma)
        print("la cantidad de numeros ingresador es ", contador)
        print("el promedio es: ",suma/contador)
    else:
        print("no ingreso numeros para promediar")    

#promedio_de_sumatoria()

"""Se tiene una lista de casos confirmados de coronavirus por cada país se pide:
Indicar cual es el promedio mundial
Cantidad de Casos mundiales
Que cantidad de casos tiene el país con menos casos
Que cantidad de casos tiene el país con más casos"""

def promedio_mundial_covid():
    cantidadCasos=int(input("ingrese cantidad de casos confirmados (numero negativo para finalizar) "))
    sumaTotal=0
    mayorPais=cantidadCasos
    menorPais=cantidadCasos
    contador=0
    while (cantidadCasos > -1):
        contador+=1
        sumaTotal+=cantidadCasos
        if cantidadCasos > mayorPais:
            mayorPais=cantidadCasos
        elif cantidadCasos < menorPais:
            menorPais=cantidadCasos
        cantidadCasos=int(input("ingrese otro pais con casos confirmados (numero negativo para finalizar) "))
    if contador == 0:
        print("no se ingreso ningun pais")
    else:
        print("el promedio mundial de casos es ",sumaTotal/contador )
        print("la cantidad total de casos mundiales es de ", sumaTotal)
        print("la menor cantidad de casos es ",menorPais)
        print("la mayor cantidad de casos es ",mayorPais)
#promedio_mundial_covid()