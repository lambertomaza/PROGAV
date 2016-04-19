#ifndef CALENDARIO_H
#define CALENDARIO_H
using std::string;

class Calendario{
public:
  void mostrar_fechas(string dia,string mes);
  Calendario(int year):numdanio(year){ }
  //...
  int numdanio;  //numero de anio
};//end class Calendario
#endif
