#4) Decisiones
#4.1)a)
def es_par(n):
    if n % 2 == 0:
        return True 
    return False

#print(es_par(200))
#b)
def es_primo(n):
    if n<=1:
        return False
    for i in range(2,n):#para hacer al programa mas eficiente conviene hacer (n**0.5)+1
        if n % i == 0:
            return False
    return True

#print(es_primo(29))

#4.2)
def funcion_abs(value):
    if value <= 0:
        return value * -1
    return value * 1
    """
    #mejor solucion
    return (value**2)**(0.5)
    """
#print(funcion_abs(-6))

#4.3)
def matriz_identidad(dimen):
    for i in range(dimen):
        for j in range(dimen):
            if i == j:
                print("1", end=" ")
            else:
                print("0",end=" ")
        print()

matriz_identidad(4)
