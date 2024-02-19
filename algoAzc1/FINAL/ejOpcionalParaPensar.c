/*
Una institucion educativa posee los siguientes archivos binarios:
Archivo de socios (socios.dat) contiene todos los socios actuales de la institucion
Formato de registro: DNI (entero), Numero de socio (entero), Nombre y apellido (string).

Archivo de Socios Nuevos (nuevos.dat) contiene los socios nuevos
Formato de registro: DNI (entero), Numero de socio (entero), Nombre y apellido (string), Sucursal (entero)

Todos los dias se recibe el archivo de Socios nuevos con la altas realizadas el dia anterior
y se desea actualizar el archivo de socios agregando los socios nuevos.
Ambos archivos estan ordenados por DNI en forma ascendente.
En caso de que el DNI de un socio nuevo ya existiera en el archivos de socios se debe actualizar el campo Nombre y apellido
y agregar el DNI a un archivo de texto llamado actualizaciones.txt

Escribir un programa en lenguaje C que genere un tercer archivo de socios actualizado
(sociosAct.dat)
Este archivo debe quedar ordenado por DNI en forma ascendente.
*/
