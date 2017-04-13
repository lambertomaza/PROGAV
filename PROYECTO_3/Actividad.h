//Actividad.h
#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
class Dia;
class Actividad{
public:
  string nombre;         /*nombre de la actividad*/
  float TRT;             /*Tiempo Requerido Total:tiempo en hrs que debe durar la actividad*/
  float TR;              /*Tiempo Requerido*/
  int indexToTecDEnsYActDApr;/*INDEX TO TECnica De ENSenianza Y ACTividad de APRendizaje*/
  void set_TRT(float TRT);/*Hasta ahora no se ha resuelto este metodo, NO se ha usado 2017.04.12*/
  vector<Dia*> intervalo;/*Dias durante los cuales se realizara la Actividad*/
  Actividad(string name,float trt):nombre(name),TRT(trt),TR(trt),indexToTecDEnsYActDApr(0){ }
  Actividad(string name,float trt,int n):nombre(name),TRT(trt),TR(trt),indexToTecDEnsYActDApr(n){ }
};//end class Actividad
#endif /*ACTIVIDAD_H*/
