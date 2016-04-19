#include <iostream>
#include <ostream>
#include <vector>
using std::string;
using std::ostream;
using std::vector;
#include "Calendario.h"
#include "Fecha.h"
#include "Dia.h"
#include "Asignacion.h"
extern string ARREGLO[][7];
extern string MONTH[];
/*extern int anio;*/
int Calendario::numdanio=2016;
ostream& operator<<(ostream& out,Dia& D){
  out<<ARREGLO[D.f->m][(D.f->d)%7]<<" "<<D.f->d<<" de "
     <<MONTH[D.f->m]<<" de "<<Calendario::numdanio<<endl;
  for(int i=0;i<D.A.size();i++){
    out<<*(D.A[i])<<endl;
  }
  return out;
}

void Dia::set_TDT(float tdt){
  TD=TDT=tdt;
}
