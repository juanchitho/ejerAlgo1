#unidad 2
#1)
def encuestasXY():
    enc_prod_x=0
    enc_prod_y=0
    total_ambos_prod=0
    enc_prod_solamente_x=0
    enc_prod_solamente_y=0
    enc_total_ninguno = 0
    cantidad_enc=0
    continuar=True
    while continuar:
        encuestar = input("quiere cargar a un encuestado(s para continuar): ")
        if encuestar != 's':
            continuar = False
        else:
            opcion_x=input("consume el producto x?(s) ")
            opcion_y=input("consume el producto y?(s) ")
            
            cantidad_enc+=1
            if opcion_x == 's' and opcion_y == 's':
                enc_prod_x+=1
                enc_prod_y+=1
                total_ambos_prod+=1
            elif opcion_x == 's':
                enc_prod_solamente_x+=1
                enc_prod_x+=1
            elif opcion_y == 's':
                enc_prod_solamente_y+=1
                enc_prod_y+=1
            else:
                enc_total_ninguno+=1
    if cantidad_enc > 0:
        print("total de encuestados",cantidad_enc)
        print("Porcentaje de consumidores del producto x",((100*enc_prod_x)/cantidad_enc),"%")
        print("Porcentaje de consumidores del producto y",((100*enc_prod_y)/cantidad_enc),"%")
        print("Porcentaje de consumidores solo del producto x",((100*enc_prod_solamente_x)/cantidad_enc),"%")
        print("Porcentaje de consumidores solo del producto y",((100*enc_prod_solamente_y)/cantidad_enc),"%")
        
        print("Porcentaje de consumidores de ambos productos",((100*total_ambos_prod)/cantidad_enc),"%")
        
        print("Porcentaje de los que no consumieron ninguno de los productos",((100*enc_total_ninguno)/cantidad_enc),"%")

    else:
        print("no hubo encuestados")
            

encuestasXY()
