#include <iostream>
#include <ostream>
using std::string;
using std::ostream;
#include "Fecha.h"
#include "Dia.h"
extern string ARREGLO[][7];
extern string MONTH[];
extern int anio;
ostream& operator<<(ostream& out,Dia& D){
  out<<ARREGLO[D.f->m][(D.f->d)%7]<<" "<<D.f->d<<" de "
     <<MONTH[D.f->m]<<" de "<<anio<<endl;
  return out;
}
