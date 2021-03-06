#include <iostream>
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

void Calendario::mostrar_fechas(string d,string m){
  SetDIntType* sdi=obtener_nums_ddia(d,m);
  print_SetDIntYFecha(d,m,sdi);
}

void Calendario::print_SetDIntYFecha(string d,string m,SetDIntType* SDI){
  for(int i=0;i<SDI->n;i++){
    cout<<SDI->intPt[i]<<" de "<<m<<" de 2016"<<endl;
  }
}
int Calendario::index_delmes(string month){ 
  if(month=="enero")       return 0;
  if(month=="febrero")     return 1;
  if(month=="marzo")       return 2;
  if(month=="abril")       return 3;    
  if(month=="mayo")        return 4;
  if(month=="junio")       return 5;
  if(month=="julio")       return 6;
  if(month=="agosto")      return 7;
  if(month=="septiembre")  return 8;
  if(month=="octubre")     return 9;
  if(month=="noviembre")   return 10;
  if(month=="diciembre")   return 11;
   
        }

int Calendario::primera_fecha_delmes(string day,int i){
if(ARREGLO[i][0]==day) return 7;
if(ARREGLO[i][1]==day) return 1;
if(ARREGLO[i][2]==day) return 2;
if(ARREGLO[i][3]==day) return 3;
if(ARREGLO[i][4]==day) return 4;
if(ARREGLO[i][5]==day) return 5;
if(ARREGLO[i][6]==day) return 6; 
}                                                 
                      
SetDIntType* Calendario::obtener_nums_ddia(string d, string m){
             SetDIntType* r=(SetDIntType*)malloc(sizeof(SetDIntType));
             int i,j; /* index de l mex es el arreglo*/
             i=index_delmes(m);
             if(i>=0 && i<12){
                     j=primera_fecha_delmes(d,i);
                     }
                     fill_SDIT(i,j,r);
                     return r; }
 void Calendario:: fill_SDIT(int i,int j,SetDIntType* r){
 int diasdmes;
 if (i==0)  diasdmes=31;
 if (i==1)  diasdmes=29;
 if (i==2)  diasdmes=31;
 if (i==3)  diasdmes=30;
 if (i==4)  diasdmes=31;
 if (i==5)  diasdmes=30;
 if (i==6)  diasdmes=31;
 if (i==7)  diasdmes=31;
 if (i==8)  diasdmes=30;
 if (i==9)  diasdmes=31;
 if (i==10) diasdmes=30;
 if (i==11) diasdmes=31;
 int cnt=0;
 for (int k=j; k<=diasdmes; k+=7)
 {
     r->intPt[cnt]=k;
     cnt++;
 }
 r->n=cnt-1;
}                                         
                                        
