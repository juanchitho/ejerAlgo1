def bb(numeros, n):
    izq = 0
    der = len(numeros) - 1
    while izq <= der:
        medio = (izq+der)//2
        if (numeros[medio] == n):
            return medio
        if (numeros[medio]>n):
            der = medio - 1
        else:
            izq = medio + 1

    numeros.insert(izq,n)
    return izq

print(bb([1,3,4,6,8,9], 2))