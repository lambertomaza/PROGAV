#include "stdafx.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
/*
using std::string;
using std::ostream;
using std::vector;
using std::endl;
*/
using namespace std;
#include "Fecha.h"
#include "Dia.h"
#include "Asignacion.h"
extern string ARREGLO[][7];
extern string MONTH[];
extern int anio;
ostream& operator<<(ostream& out,Dia& D){
  out<<ARREGLO[D.f->m][(D.f->d)%7]<<" "<<D.f->d<<" de "
     <<MONTH[D.f->m]<<" de "<<anio<<endl;
  for(unsigned int i=0;i<D.A.size();i++){
    out<<*(D.A[i])<<endl;
  }
  return out;
}

void Dia::set_TDT(float tdt){
  TD=TDT=tdt;
}
