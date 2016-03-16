//Dia.h
#ifndef DIA_H
#define DIA_H
#include <iostream>
#include <ostream>
using std::string;
using std::ostream;
using std::endl;

struct Fecha;
class Dia{
public:
  Fecha *f;
  Dia(){ }
  Dia(Fecha* fPt):f(fPt){ }
  friend ostream& operator<<(ostream& out,Dia& D);
};
#endif /*DIA_H*/
