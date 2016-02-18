//Calendario.cpp
#include <iostream>
#include <stdlib.h>/*malloc()*/
using std::string;
using std::cout;
using std::endl;
#include "Calendario.h"

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

void Calendario::mostrar_fechas(string d,string m){
  SetDIntType* sdi=obtener_nums_ddia(d,m);
  print_SetDIntYFecha(d,m,sdi);
}

void print_SetDIntYFecha(string d,string m,SetDIntType* SDI){
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

string MES[]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto",
              "septiembre","octubre","noviembre","diciembre"};

int Calendario::index_delmes(string month){
  for(int i=0;i<12;i++){
    if(month==MES[i])
      return i;
  }
  return -1;/*no se encontro la cadena*/
}

void Calendario::print_SetDIntYFecha(string d,string m,SetDIntType* SDI){
  for(int i=0;i<SDI->n;i++){
    cout<<SDI->intPt[i]<<" de "<<m<<" de 2016"<<endl;
  }
}

int Calendario::primera_fecha_delmes(string day,int i){
  if(ARREGLO[i][0]==day) return 7;
  if(ARREGLO[i][1]==day) return 1;
  if(ARREGLO[i][2]==day) return 2;
  if(ARREGLO[i][3]==day) return 3;
  if(ARREGLO[i][4]==day) return 4;
  if(ARREGLO[i][5]==day) return 5;
  if(ARREGLO[i][6]==day) return 6;
  return -1;/*nunca deberia llegarse aqui*/
}

void Calendario::fill_SDIT(int i,int j,SetDIntType* r){
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
