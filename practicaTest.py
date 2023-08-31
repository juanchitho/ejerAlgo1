#d
def vector_diferencia(x1, y1, z1, x2, y2, z2):
    dif_x = x1 - x2
    dif_y = y1 - y2
    dif_z = z1 - z2
    return dif_x, dif_y, dif_z

def producto_vec(x1, y1, z1, x2, y2, z2):
    prod_vect_x = y1 * z2 - z1 * y2
    prod_vect_y = z1 * x2 - x1 * z2
    prod_vect_z = x1 * y2 - y1 * x2
    return prod_vect_x, prod_vect_y, prod_vect_z

def calcular_area_cuadrilatero(x1, y1, x2, y2, x3, y3, x4, y4):
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
print(calcular_area_cuadrilatero(4, 3, 5, 10, -2, 8, -3, -5))