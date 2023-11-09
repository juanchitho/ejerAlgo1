/*
Utilizando las declaraciones dadas debajo, implementar la función eiercicio_3 que reciba una
matriz cargada con números enteros, que representan las cantidades de mililitros de lluvia por
hora de cada dia del mes de noviembre.
La función debe mostrar por pantalla el dia y el acumulado de ese dia, de aquellos dias que
superen el promedio diario mensual.

Considerar que solo se puede recorrer una vez la matriz. Está permitido utilizar un vector
auxiliar.

Por ejemplo:

hora -> 0 1 2 ... 22 23   acumulado x dia
-------------------------------------------------
Dia 1 | 0 7 5 ... 4 3   -> 51
    2 | 2 6 3 ... 3 2   -> 40
    3 | 0 1 3 ... 2 3   -> 52
   ...| . . . ... . .
    30| 1 2 6 ... 3 5   -> 45

Promedio diario mensual = 44.2
El resultado a mostrar sería:
En el dia 1 han caido 51 ml.
En el dia 3 han caido 52 ml.
-.(si hay día entre el 2 y el 30 que superen el promedio se mostrarían aquí)
En el dia 30 han caido 45 ml. 

 
 */
#include <stdio.h>

#define cantfilas 30
#define cantcols 24

typedef int TvecCols[cantcols];
typedef TvecCols TvecFilas[cantfilas];

void acumulacion_de_lluvia(TvecFilas milimetrosLluvia, int *vec_resultado){
	int dias , horas;
	int acum = 0 , promedio = 0;
	for (dias=0;dias<cantfilas;dias++){
		vec_resultado[dias]=0;

		for (horas=0;horas<cantcols;horas++){
			
			vec_resultado[dias]+=milimetrosLluvia[dias][horas];
		}

		acum+=vec_resultado[dias];
	}
	
	promedio=acum/cantfilas;
	printf("El promedio es de %d ml. \n",promedio);
	
	//imprimo en pantalla los dias que superan el promedio mensual
    	for (dias=0;dias<cantfilas;dias++){
		
		if(vec_resultado[dias] > promedio){
			printf("En el dia %d han caido %d ml. \n",dias+1,vec_resultado[dias]);
		}
	}
}

int main(){
	TvecFilas milimetrosLluvia = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45},
    {46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75},
    {76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
    {91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105},
    {106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
    {121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135},
    {136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150},
    {151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165},
    {166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180},
    {181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195},
    {196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210},
    {211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225},
    {226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240},
    {241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255},
    {256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270},
    {271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285},
    {286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300},
    {301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315},
    {316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330},
    {331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345},
    {346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360},
    {361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375},
    {376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390},
    {391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405},
    {406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420},
    {391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405},
    {406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420},
	};
	
	int vec_resultado[cantfilas];
	acumulacion_de_lluvia(milimetrosLluvia , vec_resultado);

	return 0;
}
