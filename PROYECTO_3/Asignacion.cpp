//Asignacion.cpp
#include <ostream>
#include <vector>
using std::endl;
using std::ostream;
using std::string;
using std::vector;
#include "Asignacion.h"
#include "Actividad.h"
#include "Alumno.h"
int Asignacion::NDA=0;
/*Tabla catalogo de Tecnicas de Ensenianza y Actividades de Aprendizaje*/
extern string TecDEnsYActDApr[][2];

ostream& operator<<(ostream& out,Asignacion& a){
  out<<"\t"<<a.TA<<"h\t[Tema "<<a.Act->nombre<<"]"<<endl;
  for(int i=0;i<a.AR.size();i++){
  	out<<"\t\t"<<*(a.AR[i])<<endl;
  }
  out<<"TEC. de ENS.: "<<TecDEnsYActDApr[a.indexTecDEYADApr][0]<<" || "
     <<"ACTIV. de APR.: "<<TecDEnsYActDApr[a.indexTecDEYADApr][1]<<endl;
  return out;
}
