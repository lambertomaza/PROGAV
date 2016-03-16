#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
class Actividad{
public:
  string nombre;         /*nombre de la actividad*/
  float duracion;        /*tiempo en hrs que debe durar la actividad*/
  vector<Dia*> intervalo;/*Dias durante los cuales se realizara la Actividad*/
};//end class Actividad
#endif /*ACTIVIDAD_H*/
