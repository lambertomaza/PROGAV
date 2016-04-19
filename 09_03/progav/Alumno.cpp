/*Alumno.cpp*/
#include <iostream>
#include <ostream>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
#include "Alumno.h"
int Alumno::NDL=0; /*inicializacion de variable de clase
                    en alcance de archivo*/
ostream& operator<<(ostream& out,Alumno& a){
  out<<a.ndl<<" "<<a.firstname<<" "<<a.lastname;
  return out;
}

void Mauricio_Arturo_Aguilera_Roa::opye(void){
  cout<<"Mauricio"<<endl;
}

void David_Raciel_Arteaga_Martinez::opye(void){
  cout<<"David"<<endl;
}
