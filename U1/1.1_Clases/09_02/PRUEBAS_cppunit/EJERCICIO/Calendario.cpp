#include <iostream>
#include "Calendario.h"
using std::string;
using std::cout;
using std::endl;

void Calendario::mostrar_fechas(string d,string m){
  SetDIntType* sdi=obtener_nums_ddia(d,m);
  print_SetDIntYFecha(d,m,sdi);
}

void Calendario::print_SetDIntYFecha(string d,string m,SetDIntType* SDI){
  for(int i=0;i<SDI->n;i++){
    cout<<SDI->intPt[i]<<" de "<<m<<" de 2016"<<endl;
  }
}

SetDIntType* Calendario::obtener_nums_ddia(string d,string m){
  SetDIntType* r=(SetDIntType*)malloc(sizeof(SetDIntType));
  int i,j;  /* i: index del mes en el arreglo ARREGLO*/
  i=index_delmes(m);
  if(i>=0 && i<12){
    j=primera_fecha_delmes(d,i);
  }
  fill_SDIT(i,j,r);
  return r;
}
