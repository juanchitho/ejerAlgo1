/*
 dadas las siguientes declaraciones de constantes y tipos
	#define cantcols 15
	#define cantfilas 30
	typedef int TvecCols[cantcols];
	typedef TvecCols TvecFilas[cantfilas];

asuminedo que la estructura esta cargada en su totalidad , se solicita:

desarrollar una funcion en lenguaje C que reciba la estructura ya cargada y devuelva al modulo invocante un vector que contenga en cada posicion la suma de los elementos de cada fila (suma todas las columnas por cada fila). Codificar solamente la funcion solicitada.
*/

#define cantcols 15
#define cantfilas 30
typedef int TvecCols[cantcols];
typedef TvecCols TvecFilas[cantfilas];

void sumaColumnas(TvecFilas matriz, int *vector){
	int i, j;
	for(i=0; i<cantfilas; i++){
		vector[i]=0;
		for(j=0; j<cantcols; j++){
			vector[i]+=matriz[i][j];
		}
	}
}
