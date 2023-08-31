#Funciones
#3.1)
#a)
def duracion_en_segundos(valorH,valorM,valorS):
    seg=((valorH*3600)+(valorM*60)+valorS)
    return seg
#duracion_en_segundos(2,50,20)

#b)
def duracion_en_hms(seg):
    hora=seg//3600
    minuto=(seg-(3600*hora))//60
    segundos= seg-((3600*hora)+(60*minuto))
    print(f'{hora},{minuto},{segundos}')
#duracion_en_hms(10220)

#3.2)
def pide_al_usr_hora():
    valorH=int(input('ingrese la hora '))
    return valorH

def pide_al_usr_min():
    valorM=int(input('ingrese los min '))
    return valorM

def pide_al_usr_seg():
    valorS=int(input('ingrese los seg '))
    return valorS

def main():
    intervalo1=duracion_en_segundos(pide_al_usr_hora(),pide_al_usr_min(),pide_al_usr_seg())
    intervalo2=duracion_en_segundos(pide_al_usr_hora(),pide_al_usr_min(),pide_al_usr_seg())
    resul=intervalo1+intervalo2
    duracion_en_hms(resul)

#main()

#3.3)
def mayor_producto_4numeros(a,b,c,d):
    '''forma en python, ya que la funcion max en py admite mas de 2 parametros(en la mayorias de lenguajes la funcion max solo admite hasta 2 parametros))'''
    return max(a*b,a*c,a*d,b*c,b*d,c*d)

#print(mayor_producto_4numeros(1,5,-2,-4))

"""
def mayor_producto_4num(a,b,c,d)
    '''forma con un acumulador '''
    maximo=max(a*b,a*c)
    maximo=max(maximo,a*d)
    maximo=max(maximo,b*c)
    maximo=max(maximo,b*d)
    maximo=max(maximo,c*d)

    return maximo

print(mayor_producto_4num(1,5,-2,-4))
"""

#3.4)a)
def norma(x,y,z):
    '''recibe un vector en en R3 y devuelve su norma '''
    return (x**2 + y**2 + z**2)**0.5
#print(norma(3,2,-4))
#b)
def vector_diferencia(x1,y1,z1,x2,y2,z2):
    dif_x=x1 - x2
    dif_y=y1 - y2
    dif_z=z1 - z2
    return dif_x, dif_y, dif_z
#print(vector_diferencia(8,7,-3,5,3,2))
#c)
def producto_vec(x1,y1,z1,x2,y2,z2):
    prod_vect_x=y1*z2-z1*y2
    prod_vect_y=z1*x2-x1*z2
    prod_vect_z=x1*y2-y1*x2
    return prod_vect_x,prod_vect_y,prod_vect_z
#print(producto_vec(1,4,-2,3,-1,0))

#d)
def area_triangulo(x1,y1,z1,x2,y2,z2,x3,y3,z3):
    dif_AB_x,dif_AB_y,dif_AB_z = vector_diferencia(x1,y1,z1,x2,y2,z2)
    dif_AC_x,dif_AC_y,dif_AC_z = vector_diferencia(x1,y1,z1,x3,y3,z3)

    x,y,z = producto_vec(dif_AB_x,dif_AB_y,dif_AB_z,dif_AC_x,dif_AC_y,dif_AC_z)
    return (norma(x,y,z))/2

#print(area_triangulo(5,8,-1,-2,3,4,-3,3,0))
#e) 
def area_cuadrilatero(x1,y1,x2,y2,x3,y3,x4,y4):
    # Asumimos que z = 0 para todas las coordenadas
    z = 0

    # Crear vectores entre los puntos
    v1 = vector_diferencia(x1, y1, z, x2, y2, z)
    v2 = vector_diferencia(x2, y2, z, x3, y3, z)
    v3 = vector_diferencia(x3, y3, z, x4, y4, z)
    v4 = vector_diferencia(x4, y4, z, x1, y1, z)

    # Calcular el área del cuadrilátero convexo utilizando la fórmula de la Shoelace
    area = 0.5 * ((x1*y2 + x2*y3 + x3*y4 + x4*y1) - (y1*x2 + y2*x3 + y3*x4 + y4*x1))
    return area

print(area_cuadrilatero(4,3,5,10,-2,8,-3,-5))
