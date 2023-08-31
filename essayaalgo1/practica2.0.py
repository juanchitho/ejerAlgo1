#2.1)
def calculo_de_intereses(pesos:float,tasa_de_interes:int, cant_anios:int)->float:
    cn = pesos*(1+(tasa_de_interes/100))**cant_anios
    return cn
#print(calculo_de_intereses(85000,22,12))
#2.2)
def solicitar_datos():
    pesos=float(input("ingrese cantidad de pesos: "))
    tasa_de_interes=int(input("ingrese la tasa de interes: "))
    anios= int(input("ingrese el numero de años: "))
    print("el total es: ",calculo_de_intereses(pesos,tasa_de_interes,anios))

#solicitar_datos()
#2.3)
def convertidor_de_grados_CaF(celcius:int)->int:
    resultado = 9/5*(celcius)+32
    return resultado
#print(convertidor_de_grados_CaF(32))

#2.4)
def tabla_de_conversion_temp()->int:

    for f in range(0,121,10):
        print(convertidor_de_grados_CaF(f))

#tabla_de_conversion_temp()

#2.5)
#a) y b)
def es_par_impar(n:int)->int:
    if n % 2 == 0:
        return 0#b)1
    return 1#b)0
#print(es_par_impar(98))

#c)
def digito_de_las_unidades(n:int)->int:
    return n%10#el operador modulo nos permite devolver el resto de una division
 
#print(digito_de_las_unidades(153))

#d)
def devuelve_el_ultimo_multiplo_de_10(n):
    restar=n%10
    return n-restar
#print(devuelve_el_ultimo_multiplo_de_10(153))


#2.6)
def pares_entre_2num(n1,n2):
    if n1<n2:
        for n in range(n1,n2):
            if n % 2 == 0:
                print(n)
    else:
        for i in range(n1,n2,-1):
            if i % 2 == 0: 
                print(i)

#pares_entre_2num(25,2)

#2.7)
def imprime_los_num_triangulares(n):
    for i in range(1,n+1):
        s=i*(i+1)//2
        print(f'{i} - {s}')
#imprime_los_num_triangulares(5)


#2.8)
def calc_factorial(n):
    if n==0 or n==1:
        resultado=1
    elif n>1:
        resultado=n*calc_factorial(n-1)#el bucle lo hace invocar la funcion y acumular el resultado
        print(resultado)#los valores que va valiendo el contenido de resultado 5*4*3*2*1 --> el resultado en si 2,6,24,120
    return resultado
#calc_factorial(5)

def pide_numeros_fac():
    m = int(input("ingrese la cantidad de numeros a calcular "))
    for i in range(1, m + 1):
        value = int (input(f"Ingrese el valor {i}: "))
        resul = calc_factorial(value)
        print(f"Valor {i}:{resul}")
#pide_numeros_fac()

#2.9)
def imprimir_fichas_domino():
    for i in range(7):#for i in range(start=0,stop=N/A,step=1)default argument
        for j in range(i,7):
            print(i*'°','/',j*'°',end=" | ")
        print()

#imprimir_fichas_domino()

#2.10)
def imprime_fichas_domino_sin_filtro(n=6):
    for i in range(n+1):
        for j in range(i,n+1):
            print(i*'°','/',j*'°',end=' | ')
        print()

imprime_fichas_domino_sin_filtro(8)        


