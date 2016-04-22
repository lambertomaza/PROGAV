#ifndef TABLAS_H
#define TABLAS_H
#include <iostream>
#include <ostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
/**
 Tabla Simplex
*/
class TablaS
{
	public:
		int n;   //numero de filas de la tabla simplex
		int m;   //numero de columnas de la tabla simplex
		float **ts;//arreglo bidimensional que contiene la tabla simplex
        int I;    //fila pivote
        int J;    //columna pivote
		TablaS(int N,int M,float **TS);
		friend ostream& operator<<(ostream&,TablaS&);
	protected:
};

#endif
