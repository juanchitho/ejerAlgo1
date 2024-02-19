/*
 Una libreria posee un archivo denominado Stock.dat, cuyos registros contienen el codigo de libro(entero),ek codigo de la editorial(entero),el stock actual de dicho libro(entero) y el stock minimo de dicho libro(entero). Dicho archivo no esta ordenado y no "entra" en memoria en su totalidad.

 Se pide desarrollar un programa en lenguaje C que procese este archivo y que permita:
 1)Generar una tabla llamada Pedidos que contenga toda la informacion de aquellos libros cuyo stock_actual esta por debajo del stock minimo. Asumir que esta tabla tendra como MAXIMO 100 registros, razon porla cual "ENTRA" EN MEMORIA.
 2) Ordenar la tabla Pedidos ascendentemente.
 3)Realizar consultas: para ello , debe solicitar al usuario el ingreso de un codigo de libro y buscar de modo eficiente en la tabla Pedidos el codigo ingresado. De encontrar el registro correspondiente a dicho codigo, mostrar por pantalla todos los cmapos del mismo. En caso de no encontrarlo, mostrar por pantalla el mensaje "CODIGO NO ENCONTRADO". Las consultas terminan cuando el usuario ingresa un codigo de libro negativo. 
 
*/
