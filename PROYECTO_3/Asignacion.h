//Asignacion.h
#ifndef ASIGNACION_H
#define ASIGNACION_H

/*Por cada Asignacion hay solo una Actividad (Tema del programa detallado),
  pero la misma Actividad puede aparecer en mas de una Asignacion. Hay que 
  recordar que la misma actividad solo va a aparecer en Asignaciones 
  "consecutivas cronologicamente." 
*/
class Actividad;
class Alumno;
class Asignacion{
public:
static int NDA;            /*Numero De Asignacion*/
  Actividad *Act;          /*Actividad asignada*/
  float TA;                /*Tiempo Asignado*/
  vector<Alumno*> AR;      /*vector de Alumnos responsables de la Actividad de la Asignacion*/
  int indexTecDEYADApr;/*INDEX TO TECnica De ENSenianza Y ACTividad de APRendizaje*/
  //Asignacion(Actividad* a,float ta):Act(a),TA(ta),indexTecDEYADApr(a->indexToTecDEnsYActDApr){ }
  Asignacion(Actividad* a,float ta,int itdeyada):Act(a),TA(ta),indexTecDEYADApr(itdeyada){ }
  /**@param *nda: numero de asignacion*/
  //Asignacion(Actividad* a,float ta,Alumno *al,int *nda):Act(a),TA(ta){
  Asignacion(Actividad* a,float ta,Alumno *al,int *nda,int itdeyada):Act(a),TA(ta),indexTecDEYADApr(itdeyada){  	
    NDA++;*nda=NDA;
    //if(NDA>=3)
    if(NDA>=0)
      AR.push_back(al);
  }
  friend ostream& operator<<(ostream& out,Asignacion& a);
};//end class Asignacion
#endif /*ASIGNACION_H*/
