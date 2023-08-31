""" a=int(input("ingrese numero"))
b=int(input("ingrese otro numero"))
if a>b:
    print("el numero mas grande es: ",a)
elif b>a:
    print("el numero mas grande es: ",b)
else:
    print("son iguales")
 """
# Path: ejer2.py
""" mes=int(input("ingrese numero de mes"))
if mes==1:
    print("Mes ingresado:enero")
elif mes==2:
    print("Mes ingresado:febrero")
elif mes==3:
    print("Mes ingresado:marzo")  
elif mes==4:
    print("Mes ingresado:abril")
elif mes==5:
    print("Mes ingresado:mayo")
elif mes==6:
    print("Mes ingresado:junio")
elif mes==7:
    print("Mes ingresado:julio")
elif mes==8:
    print("Mes ingresado:agosto")
elif mes==9:
    print("Mes ingresado:septiembre")
elif mes==10:
    print("Mes ingresado:octubre")
elif mes==11:
    print("Mes ingresado:noviembre")
elif mes==12:
    print("Mes ingresado:diciembre")
else:
    print("Mes Ingresado: Inválido") """
# Path: ejer3.py

""" numero=int(input("ingrese numero: "))
for i in range(numero,0,-1):
    print(i,end="\n")
print("Despegamos!") """

# Path: ejer4.py

""" suma=0
contador=0
while suma<=1000:
    numero=int(input("ingrese numero:"))
    suma=suma+numero
    contador=contador+1
    
print(suma)
print("cantidad de numeros ingresados: ",contador) """

""" 
for i in range(100,0,-1):
    if not i%2==0:
        print(i)
 """
pesoSuma=0
cantidad=0
continuar=True

while (cantidad<=6) and (pesoSuma<=400) and continuar:
    peso=int(input("ingrese peso: "))
    if peso !=0:
        pesoSuma=pesoSuma+peso
        cantidad=cantidad+1
    else:
        continuar=False

if pesoSuma>400:
    print("se ha superado el peso maximo")
elif cantidad>6:
    print("se ha superado la cantidad de personas permitida")
else:
    print("ascensor en movimiento")