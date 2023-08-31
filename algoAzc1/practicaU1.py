#1)a)
def es_par_impar():
    n = int(input('ingrese un numero entero: '))
    if n % 2 == 0:
        print(f'el numero {n} es par')
    else:
        print(f'el numero {n} es impar') 
#es_par_impar()
#b)
def es_mayor_menor_a_cero():
    n = int(input('ingrese un numero entero: '))
    if n > 0:
        print('es mayor a 0')
    elif n == 0:
        print('es igual a 0')
    else:
        print('es menor a 0')
#es_mayor_menor_a_cero()
#2)
def superficie_de_un_triangulo():
    base=int(input('ingrese la base: '))
    altura=int(input('ingrese la altura: '))
    return (base*altura)/2
#print(superficie_de_un_triangulo())

#3)
def calcular_sueldo():
    cantidadHoras=int(input('Ingrese la cantidad de horas trabajadas: '))
    valorDeHora=int(input('Ingrese el valor de la hora: '))
    return cantidadHoras*valorDeHora
#print(calcular_sueldo())

#4)
def hallarMayor(a,b,c):
    if a>b and a>c:
        return a
    elif b>a and b>c:
        return b
    else: 
        return c

#print(hallarMayor(4,10,3))
#5)
def calculaElVolumenEsfe(r):
    pi=3.14159265359 
    return (4/3)*pi*r**3

#print(calculaElVolumenEsfe(4))

#6)
def suma_de_naturales(n):
    suma=0
    for i in range(n+1):
        suma+=i
    return suma
#print(suma_de_naturales(5))
#7)
def imprime_mes(n):
    """si no se puede con listas entonces if anidados """
    meses=["Error en el numero dado","Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"]
    if n<0 or n>12:
        print(meses[0])
    else:
        print(meses[n])

#n=int(input("ingrese un numero de mes: "))
#imprime_mes(n)

#8)
def cantidadDias(mes):
    if mes=='abril' or mes=='junio' or mes=='agosto' or mes=='noviembre':
        print("30")
    elif mes=='febrero':
        print("28")
    else:
        print("31")

#mes=input("ingrese mes: ")
#cantidadDias(mes)

#9)
def fechaCorrecta():
   
    anio=int(input("ingrese el año: "))
    mes=int(input("ingrese el mes: "))
    dia=int(input("ingrese el dia: "))

    if mes>=1 and mes<=12 and dia>=1 and dia<=31:
        print("fecha correcta")
    else:
        print("fecha incorrecta")
#fechaCorrecta()
