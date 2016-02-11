#include <iostream>
#include <stdlib.h>  /*malloc()*/
#include "Calendario.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using std::cout;
using std::endl;

struct SetDInt{
  int n;
  int *intPt;
};
typedef struct SetDInt SetDIntType;

SetDIntType* obtener_nums_ddia(string d,string m);
void print_SetDIntYFecha(string d,string m,SetDIntType* SDI);
int index_delmes(string month);
int primera_fecha_delmes(string day,int i);
void fill_SDIT(int i,int j,SetDIntType* r);

int main(int argc, char** argv) {
	Calendario *Cal2016=new Calendario(2016);
	cout<<"Los lunes del mes de enero son:"<<endl;
	Cal2016->mostrar_fechas("Lunes","enero");
	cout<<"Los miercoles del mes de febrero son:"<<endl;
	Cal2016->mostrar_fechas("Miercoles","febrero");
#ifdef _WIN32
	system("PAUSE");
#endif
	return 0;
}


void Calendario::mostrar_fechas(string d,string m){
  SetDIntType* sdi=obtener_nums_ddia(d,m);
  print_SetDIntYFecha(d,m,sdi);
}

void print_SetDIntYFecha(string d,string m,SetDIntType* SDI){
  for(int i=0;i<SDI->n;i++){
    cout<<SDI->intPt[i]<<" de "<<m<<" de 2016"<<endl;
  }
}
string ARREGLO[][7]={
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}, /*enero*/
  {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"}, /*febrero*/
  {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"}, /*marzo*/
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}, /*abril*/
  {"Sabado","Domingo","Lunes","Martes","Miercoles","Jueves","Viernes"}, /*mayo*/
  {"Martes","Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes"}, /*junio*/
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}, /*julio*/
  {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"}, /*agosto*/
  {"Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes","Martes"}, /*septiembre*/
  {"Viernes","Sabado","Domingo","Lunes","Martes","Miercoles","Jueves"}, /*octubre*/
  {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"}, /*noviembre*/
  {"Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes","Martes"}  /*diciembre*/
};

/**
 Obtiene los numeros de dia de las fechas de los 
 dias d en el mes m.
 */
SetDIntType* obtener_nums_ddia(string d,string m){
  SetDIntType* r=(SetDIntType*)malloc(sizeof(SetDIntType));
  int i,j;  /* i: index del mes en el arreglo ARREGLO*/
  i=index_delmes(m);
  if(i>=0 && i<12){
    j=primera_fecha_delmes(d,i);
  }
  fill_SDIT(i,j,r);
  return r;
}

string MES[]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto",
              "septiembre","noviembre","diciembre"};

/**
 Obtiene el indice correspondiente al mes month. 
 Si month="enero", debe devolver 0, 
 Si month="febrero", debe devolver 1, 
 Si month="marzo", debe devolver 2, 
 etc.
 */
int index_delmes(string month){
  for(int i=0;i<12;i++){
    if(month==MES[i])
      return i;
  }
  return -1;/*no se encontro la cadena*/
}

/**
 Devuelve el numero de dia de la primera fecha 
 del mes con indice i (devuelto por 
 index_delmes(string month)), en la que el dia 
 es el string day.
 */
int primera_fecha_delmes(string day,int i){
  if(ARREGLO[i][0]==day) return 7;
  if(ARREGLO[i][1]==day) return 1;
  if(ARREGLO[i][2]==day) return 2;
  if(ARREGLO[i][3]==day) return 3;
  if(ARREGLO[i][4]==day) return 4;
  if(ARREGLO[i][5]==day) return 5;
  if(ARREGLO[i][6]==day) return 6;
  return -1;/*nunca deberia llegarse aqui*/
}

/*Cantidades de dias de los meses del anio (valido para anios bisiestos)*/
int TamDMes[]={
  31,/*enero*/
  29,/*febrero*/
  31,/*marzo*/
  30,/*abril*/
  31,/*mayo*/
  30,/*junio*/
  31,/*julio*/
  31,/*agosto*/
  30,/*septiembre*/
  31,/*octubre*/
  30,/*noviembre*/
  31 /*diciembre*/
};

/**
  Cumplimenta el SetDIntType al que apunta el apuntador r. 
  Esto es, despues de llamar a este metodo, r->n contendra
  la cantidad de veces que se presenta el dia de la semana 
  correspondiente a la fecha j (j es un int que corresponde 
  al primer lunes, martes, miercoles etc. 
  j\in{1,2,3,4,5,6,7}), en el mes con indice i. Mientras que 
  el apuntador r->intPt apuntara a los numeros de dia en las 
  fechas tales que el dia coincide con el dia de la fecha j 
  del mes con indice i.
  @param i: index del mes; 0 enero, 1 febrero, 2 marzo, etc.
  @param j: primera fecha del mes correspondiente al dia de  
            la semana cuyas fechas que estamos buscando.
  @param r: Conjunto de enteros.
 */
void fill_SDIT(int i,int j,SetDIntType* r){
  int cnt=1,k=j;
  while((k=k+7)<=TamDMes[i])cnt++;
  r->n=cnt;
  k=j;
  r->intPt=(int*)malloc((r->n)*sizeof(int));
  for(int m=0;m<r->n;m++){
    *(r->intPt+m)=k;
    k+=7;
  }
}
