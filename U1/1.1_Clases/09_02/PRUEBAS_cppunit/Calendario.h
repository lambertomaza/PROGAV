//Calendario.h
#ifndef CALENDARIO_H
#define CALENDARIO_H

typedef
struct SetDIntType{
  int n;
  int *intPt;
  SetDIntType():n(0),intPt(NULL){ }
  bool operator==(SetDIntType &sdit)const{
    bool tmp0=true;
    //bool tmp1=(n==sdit.n)?true:false;
    bool tmp1=(n==sdit.n);
    for(int i=0;i<n;i++){
      if(*(intPt+i)!=*(sdit.intPt+i)){
        tmp0=false;
        break;
      }
    }
    return (tmp0 && tmp1);
  }
}SetDIntType;
//typedef struct SetDInt SetDIntType;


class Calendario{
public:
  void mostrar_fechas(string dia,string mes);
  Calendario(int year):numdanio(year){ }
  int get_anio(){
    return numdanio;
  }
  //...
  /**
   Obtiene los numeros de dia de las fechas de los 
   dias d en el mes m.
   */
  SetDIntType* obtener_nums_ddia(string d,string m);
  void print_SetDIntYFecha(string d,string m,SetDIntType* SDI);

  /**
   Obtiene el indice correspondiente al mes month. 
   Si month="enero", debe devolver 0, 
   Si month="febrero", debe devolver 1, 
   Si month="marzo", debe devolver 2, 
   etc.
   */
  int index_delmes(string month);

  /**
   Devuelve el numero de dia de la primera fecha 
   del mes con indice i (devuelto por 
   index_delmes(string month)), en la que el dia 
   es el string day.
   */
  int primera_fecha_delmes(string day,int i);

  /**
    Cumplimenta el SetDIntType al que apunta el apuntador r. 
    Esto es, despues de llamar a este metodo, r->n contendra
    la cantidad de veces que se presenta el dia de la semana 
    correspondiente a la fecha j (j es un int que corresponde 
    al primer lunes, martes, miercoles etc. 
    j\in{1,2,3,4,5,6,7}), en el mes con indice i. Mientras que 
    el apuntador r->intPt apuntara a los numeros de dia en las 
    fechas tales que el dia coincide con el dia de la fecha j 
    del mes con indice i.
    @param i: index del mes; 0 enero, 1 febrero, 2 marzo, etc.
    @param j: primera fecha del mes correspondiente al dia de  
              la semana cuyas fechas que estamos buscando.
    @param r: Conjunto de enteros.
 */
  void fill_SDIT(int i,int j,SetDIntType* r);

  int numdanio;  //numero de anio
};//end class Calendario
#endif
