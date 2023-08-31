import gamelib
import png

BLACK = "#000000"
WHITE = "#FFFFFF"
RED = "#FF0000"
LIME = "#00FF00"
BLUE = "#0000FF"
YELLOW = "#FFFF00"
CYAN = "#00FFFF"
SILVER = "#C0C0C0"
GRAY = "#808080"
DICC_COLORES = {1: WHITE, 2: BLACK, 3: RED, 4: LIME, 5: BLUE, 6: YELLOW, 7: CYAN}
VALORES_HEX_VALIDOS = (
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "#",
)


def paint_nuevo():
    """Inicializa el estado del programa con un diccionario vacio"""
    return {}


def paint_mostrar(paint, tecla, pixeles, seleccion_color):
    """Dibuja la interfaz de la aplicación en la ventana"""

    gamelib.draw_begin()
    # Grilla
    gamelib.draw_rectangle(5, 5, 345, 345)
    for fila in range(5, 350, 350 // pixeles):
        gamelib.draw_line(5, fila, 345, fila, fill=BLACK)
    for columna in range(5, 350, 350 // pixeles):
        gamelib.draw_line(columna, 5, columna, 345, fill=BLACK)

    # Coloressss
    gamelib.draw_rectangle(20, 375, 50, 405, fill=WHITE, outline=GRAY)
    gamelib.draw_rectangle(60, 375, 90, 405, fill=BLACK, outline=GRAY)
    gamelib.draw_rectangle(100, 375, 130, 405, fill=RED, outline=GRAY)
    gamelib.draw_rectangle(140, 375, 170, 405, fill=LIME, outline=GRAY)
    gamelib.draw_rectangle(180, 375, 210, 405, fill=BLUE, outline=GRAY)
    gamelib.draw_rectangle(220, 375, 250, 405, fill=YELLOW, outline=GRAY)
    gamelib.draw_rectangle(260, 375, 290, 405, fill=CYAN, outline=GRAY)

    if seleccion_color is None:
        gamelib.draw_rectangle(300, 375, 330, 405, fill=SILVER, outline=GRAY)
    else:
        gamelib.draw_rectangle(300, 375, 330, 405, fill=seleccion_color, outline=GRAY)

    # Indicaciones
    gamelib.draw_text("1", 35, 360, bold=True)
    gamelib.draw_text("2", 75, 360, bold=True)
    gamelib.draw_text("3", 115, 360, bold=True)
    gamelib.draw_text("4", 155, 360, bold=True)
    gamelib.draw_text("5", 195, 360, bold=True)
    gamelib.draw_text("6", 235, 360, bold=True)
    gamelib.draw_text("7", 275, 360, bold=True)
    gamelib.draw_text("N", 315, 360, bold=True)

    # Guardado
    gamelib.draw_rectangle(10, 420, 110, 460, fill=WHITE, outline=WHITE)
    gamelib.draw_text("Guardar .ppm", 60, 430, fill=BLACK)
    gamelib.draw_text("S", 60, 450, fill=BLACK, bold=True)

    gamelib.draw_rectangle(125, 420, 225, 460, fill=WHITE, outline=WHITE)
    gamelib.draw_text("Abrir .ppm", 175, 430, fill=BLACK)
    gamelib.draw_text("A", 175, 450, fill=BLACK, bold=True)

    gamelib.draw_rectangle(240, 420, 340, 460, fill=WHITE, outline=WHITE)
    gamelib.draw_text("Guardar .png", 290, 430, fill=BLACK)
    gamelib.draw_text("G", 290, 450, fill=BLACK, bold=True)

    # Seleccion de color
    if tecla in (DICC_COLORES.keys()):
        gamelib.draw_rectangle(
            25 + (tecla - 1) * 40,
            350,
            45 + (tecla - 1) * 40,
            370,
            outline=WHITE,
            fill=None,
        )
    elif str(tecla).lower() == "n":
        gamelib.draw_rectangle(305, 350, 325, 370, outline=WHITE, fill=None)

    # Imagennn
    for (fil, col), color in paint.items():
        x1 = col * (350 // pixeles) + 5
        y1 = fil * (350 // pixeles) + 5

        x2 = x1 + (350 // pixeles)
        y2 = y1 + (350 // pixeles)

        gamelib.draw_rectangle(x1, y1, x2, y2, fill=color)

    # Instrucciones
    gamelib.draw_text(
        "Aprete la letra I en su teclado para\nabrir las instrucciones ",
        180,
        500,
        size=10,
        fill=SILVER,
        bold=True,
    )

    gamelib.draw_end()


def instrucciones():
    gamelib.say(
        "La seleccion de colores se realiza vía teclado, apretando los\nnúmeros de 1 a 7 podrá seleccionar los predeterminados.\nApretando la letra N le abrira un caja de dialogo donde usted\npodrá ingresar un color personalizado.\nCon la letra S podrá guardar la imagen en formato .ppm, con la letra A podrá abrir un archivo en formato .ppm y con la letra G podrá guardar la imagen en formato .png"
    )


def seleccionar_color(tecla):
    """Devuelve el color elegido por el usuario"""
    for numero, color in DICC_COLORES.items():
        if numero == tecla:
            return color
    return None


def color_personalizado():
    """Crea un nuevo color mediante un código hexadecimal ingresado por el usuario"""

    seleccion_color = gamelib.input(
        "Escriba el color que desea en código hexadecimal:\n(Recuerde colocar el # adelante)"
    )

    if not seleccion_color:
        if seleccion_color is None:
            return
        gamelib.say("Código inválido")
        return

    # Verifica que sea válido
    if len(seleccion_color) != 7:
        gamelib.say("Código inválido (Recuerde poner el # adelante)")
        return None

    for caracter in seleccion_color:
        if caracter.lower() not in VALORES_HEX_VALIDOS:
            gamelib.say(
                f"Código inválido, recuerde que los valores hex válidos son: {VALORES_HEX_VALIDOS}"
            )
            return None

    return seleccion_color


def pintar_pixeles(paint, x, y, pixeles, color):
    """Dado un color, pinta los pixeles correspondientes según los valores de x e y indicados"""
    fila = y // (350 // pixeles)
    columna = x // (350 // pixeles)
    paint[(fila, columna)] = color


def hex_a_dec(hex):
    """Convierte un color dado en codigo hexadecimal a código decimal"""
    return (int(hex[1:3], 16), int(hex[3:5], 16), int(hex[5:7], 16))


def dec_a_hex(r, g, b):
    """Convierte un color dado en codigo decimal a código hexadecimal"""
    return f"#{r:02x}{g:02x}{b:02x}"


def abrir_ppm():
    """Abre un archivo de formato .ppm"""

    ruta_archivo = gamelib.input("Escriba la ruta del archivo:")

    if ruta_archivo is None:
        return None, None
    if ruta_archivo == " " or ruta_archivo == "":
        gamelib.say("Ruta inválida")
        return

    paint_nuevo = {}

    try:
        with open(ruta_archivo) as archivo:
            lineas = ""
            for linea in archivo:
                lineas += linea
            imagen = lineas.split()
            ancho, alto = int(imagen[1]), int(imagen[2])
            n = 4

            for fil in range(ancho):
                for col in range(alto):
                    color = imagen[n : n + 3]
                    if color == ["255", "255", "255"]:
                        n += 3
                        continue
                    r, g, b = int(color[0]), int(color[1]), int(color[2])
                    color_hex = dec_a_hex(r, g, b)
                    paint_nuevo[(fil, col)] = color_hex
                    n += 3

        return paint_nuevo, ancho

    except FileNotFoundError:
        gamelib.say("El archivo no existe")
        return


def guardar_ppm(paint, pixeles):
    """Guarda el dibujo realizado por el usuario en un archivo de formato .ppm"""

    ruta_archivo = gamelib.input("Escriba la ruta donde guardar el archivo:")

    if ruta_archivo is None:
        return
    if ruta_archivo == " " or ruta_archivo == "":
        gamelib.say("Ruta inválida")
        return

    with open(ruta_archivo, "w") as archivo:
        archivo.write("P3\n")
        archivo.write(f"{pixeles} {pixeles}\n")
        archivo.write("255\n")

        for fil in range(pixeles):
            for col in range(pixeles):
                paint[(fil, col)] = paint.get((fil, col), WHITE)
                color = hex_a_dec(paint[(fil, col)])

                for n in range(len(color)):
                    if n == 2:
                        archivo.write(f"{color[n]}\n")
                    else:
                        archivo.write(f"{color[n]} ")


def guardar_png(paint, pixeles):
    """Guarda el dibujo realizado por el usuario en un archivo de formato .png"""

    ruta_archivo = gamelib.input("Escriba la ruta donde guardar el archivo:")

    if ruta_archivo is None:
        return
    if ruta_archivo == " " or ruta_archivo == "":
        gamelib.say("Ruta inválida")
        return

    colores = []
    imagen = []
    for fil in range(pixeles):
        lista_indices = []
        for col in range(pixeles):
            paint[(fil, col)] = paint.get((fil, col), WHITE)
            color_decimal = hex_a_dec(paint[(fil, col)])
            if color_decimal not in colores:
                colores.append(color_decimal)
            lista_indices.append(colores.index(color_decimal))
        imagen.append(lista_indices)

    png.escribir(ruta_archivo + ".png", colores, imagen)


def main():
    gamelib.title("AlgoPaint - TP2")
    gamelib.resize(347, 527)
    pixeles = 20
    tecla = 1
    color = WHITE
    seleccion_color = None
    paint = paint_nuevo()

    while gamelib.loop(fps=15):
        paint_mostrar(paint, tecla, pixeles, seleccion_color)

        for ev in gamelib.get_events():
            if ev.type == gamelib.EventType.ButtonPress and ev.mouse_button == 1:
                if 5 < ev.x < 340 and 5 < ev.y < 340:
                    if seleccion_color:
                        color = seleccion_color
                    else:
                        color = seleccionar_color(tecla)

                if color:
                    pintar_pixeles(paint, ev.x, ev.y, pixeles, color)

            elif ev.type == gamelib.EventType.Motion:
                if 5 < ev.x < 340 and 5 < ev.y < 340:
                    if color:
                        pintar_pixeles(paint, ev.x, ev.y, pixeles, color)

            elif ev.type == gamelib.EventType.ButtonRelease and ev.mouse_button == 1:
                color = None

            elif ev.type == gamelib.EventType.KeyPress:
                if ev.key.isdigit():
                    if ev.key in ("1", "2", "3", "4", "5", "6", "7"):
                        tecla = int(ev.key)
                        seleccion_color = None

                elif ev.key.lower() == "n":
                    nuevo_color = color_personalizado()
                    if nuevo_color is not None:
                        seleccion_color = nuevo_color
                        tecla = ev.key

                elif ev.key.lower() == "s":
                    guardar_ppm(paint, pixeles)

                elif ev.key.lower() == "a":
                    nuevo, dimension = abrir_ppm()
                    if nuevo is not None:
                        pixeles = int(dimension)
                        paint = nuevo

                elif ev.key.lower() == "g":
                    guardar_png(paint, pixeles)

                elif ev.key.lower() == "i":
                    instrucciones()


gamelib.init(main)
