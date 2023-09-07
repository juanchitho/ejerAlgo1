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
maximo_comun_divisor()    