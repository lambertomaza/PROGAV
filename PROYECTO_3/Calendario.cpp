#include <iostream>
#include <vector>
#include <stdlib.h> /*malloc()*/
using std::string;
using std::cout;
using std::endl;
using std::vector;
#include "Calendario.h"
#include "Fecha.h"
#include "Dia.h"
#include "Actividad.h"
#include "Asignacion.h"
//#include "year.h"
extern int NUMDALUMNOS;
int anio=2017;       /*20170320*/
/**
 * string ARREGLO[][7] -- Contiene los nombres de los dias de la semana para el anio 2017.
 * Forma de uso: Para obtener el nombre del dia correspondiente a una fecha del anio 2017, 
 *               digamos dd/mm/2016, se puede usar la siguiente expresion:
 *               string day_name=ARREGLO[(mm)-(1)][(dd)%(7)];
 *               Por ejemplo, usando esta expresion se puede saber que el pasado 24 de diciembre
 *               de 2016, 28/9/2017 fue ARREGLO[(9)-(1)][(28)%(7)]=ARREGLO[8][0]="Jueves"
 */
string ARREGLO[][7]={
  {"Sabado","Domingo","Lunes","Martes","Miercoles","Jueves","Viernes"}, /*enero 2017*/
  {"Martes","Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes"}, /*febrero 2017*/
  {"Martes","Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes"}, /*marzo 2017*/
  {"Viernes","Sabado","Domingo","Lunes","Martes","Miercoles","Jueves"}, /*abril 2017*/
  {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"}, /*mayo 2017*/
  {"Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes","Martes"}, /*junio 2017*/
  {"Viernes","Sabado","Domingo","Lunes","Martes","Miercoles","Jueves"}, /*julio 2017*/
  {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"}, /*agosto 2017*/
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}, /*septiembre 2017*/
  {"Sabado","Domingo","Lunes","Martes","Miercoles","Jueves","Viernes"}, /*octubre 2017*/
  {"Martes","Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes"}, /*noviembre 2017*/
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}  /*diciembre 2017*/
};

/**
Muestra las fechas del mes m en las cuales el dia es d.
*/
void Calendario::mostrar_fechas(string d,string m){
  SetDIntType* sdi=obtener_nums_ddia(d,m);
  print_SetDIntYFecha(d,m,sdi,anio);
}

//void Calendario::print_SetDIntYFecha(string d,string m,SetDIntType* SDI){
void Calendario::print_SetDIntYFecha(string d,string m,SetDIntType* SDI,int numYear){	
  for(int i=0;i<SDI->n;i++){
    cout<<SDI->intPt[i]<<" de "<<m<<" de "<<numYear<<endl;
  }
}

/**
 Obtiene el indice correspondiente al mes month. 
 Si month="enero", debe devolver 0, 
 Si month="febrero", debe devolver 1, 
 Si month="marzo", debe devolver 2, 
 etc.
 */
int Calendario::index_delmes(string month){ 
  if(month=="enero")       return 0;
  if(month=="febrero")     return 1;
  if(month=="marzo")       return 2;
  if(month=="abril")       return 3;    
  if(month=="mayo")        return 4;
  if(month=="junio")       return 5;
  if(month=="julio")       return 6;
  if(month=="agosto")      return 7;
  if(month=="septiembre")  return 8;
  if(month=="octubre")     return 9;
  if(month=="noviembre")   return 10;
  if(month=="diciembre")   return 11;
   
}

/**
 Devuelve el numero de dia de la primera fecha 
 del mes con indice i (devuelto por 
 index_delmes(string month)), en la que el dia 
 es el string day.
 */
int Calendario::primera_fecha_delmes(string day,int i){
if(ARREGLO[i][0]==day) return 7;
if(ARREGLO[i][1]==day) return 1;
if(ARREGLO[i][2]==day) return 2;
if(ARREGLO[i][3]==day) return 3;
if(ARREGLO[i][4]==day) return 4;
if(ARREGLO[i][5]==day) return 5;
if(ARREGLO[i][6]==day) return 6; 
}                                                 

/**
 Obtiene los numeros de dia de las fechas de los 
 dias d en el mes m.
 */                      
SetDIntType* Calendario::obtener_nums_ddia(string d, string m){
             SetDIntType* r=(SetDIntType*)malloc(sizeof(SetDIntType));
             int i,j; /* index de l mex es el arreglo*/
             i=index_delmes(m);
             if(i>=0 && i<12){
                     j=primera_fecha_delmes(d,i);
                     }
                     fill_SDIT(i,j,r);
                     return r;
}

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
void Calendario:: fill_SDIT(int i,int j,SetDIntType* r){
 int diasdmes=canddiasdmes(i);
// if (i==0)  diasdmes=31;
// if (i==1){
// 	if((abs(anio-2016)%4)==0){/*si es anio bisiesto*/
// 		diasdmes=29;
//	}else{/*si no es anio bisiesto*/
//		diasdmes=28;
//	}
// } 
// if (i==2)  diasdmes=31;
// if (i==3)  diasdmes=30;
// if (i==4)  diasdmes=31;
// if (i==5)  diasdmes=30;
// if (i==6)  diasdmes=31;
// if (i==7)  diasdmes=31;
// if (i==8)  diasdmes=30;
// if (i==9)  diasdmes=31;
// if (i==10) diasdmes=30;
// if (i==11) diasdmes=31;
 int cnt=0;
 for (int k=j; k<=diasdmes; k+=7)
 {
     r->intPt[cnt]=k;
     cnt++;
 }
 r->n=cnt-1;
}                                         

bool Calendario::esta_incluido(string d,vector<string> dias){
  bool ret=false;
  for(int i=0;i<dias.size();i++){
    if(d==dias[i]){
      ret=true;
      break;
    }
  }
  return ret;
}

bool Calendario::esta_incluido(Fecha* fPt,vector<Dia*> dnl){
  bool ret=false;
  for(int i=0;i<dnl.size();i++){
    if(*(dnl[i]->f)==*fPt){
      ret=true;
      break;
    }
  }
  return ret;
}

/**
 devuelve la cantidad de fechas entre fi y ff que corresponden a los 
 dias en el vector dias.
 */                                       
int Calendario::cant_dFechas(Fecha *fi,Fecha *ff,vector<string> dias){
  int im=fi->m,id=fi->d,cnt=0;
  /*cantidades de dias de los meses (2016)*/
//  int TamM[]={31,29,31,30,31,30,31,31,30,31,30,31};
inic:
  if((im!=ff->m)||(id!=ff->d)){
//    if(esta_incluido(ARREGLO_2017[im][id%7],dias)){
    if(esta_incluido(ARREGLO[im][id%7],dias)){
      cnt++;
    }
//    if((id+1)<=TamM[im]){
    if((id+1)<=canddiasdmes(im)){
      id++;
    }else{
      id=1;im++;
    }
    goto inic;
  }
//  if(esta_incluido(ARREGLO_2017[ff->m][ff->d%7],dias)){
  if(esta_incluido(ARREGLO[ff->m][ff->d%7],dias)){
    cnt++;
  }
  return cnt;
}

vector<Fecha*> Calendario::get_Fechas(Fecha *fi,Fecha *ff,vector<string> dias){
  int im=fi->m,id=fi->d,cnt=0;
  vector<Fecha*> vdf;
  /*cantidades de dias de los meses (2016)*/
//  int TamM[]={31,29,31,30,31,30,31,31,30,31,30,31};
inic:
  if((im!=ff->m)||(id!=ff->d)){
//    if(esta_incluido(ARREGLO_2017[im][id%7],dias)){
    if(esta_incluido(ARREGLO[im][id%7],dias)){
      vdf.push_back(new Fecha(id,im));
    }
//    if((id+1)<=TamM[im]){
    if((id+1)<=canddiasdmes(im)){	
      id++;
    }else{
      id=1;im++;
    }
    goto inic;
  }
//  if(esta_incluido(ARREGLO_2017[ff->m][ff->d%7],dias)){
  if(esta_incluido(ARREGLO[ff->m][ff->d%7],dias)){
    vdf.push_back(new Fecha(ff->d,ff->m));
  }
  return vdf;
}

vector<Dia*> Calendario::get_Dias_DC(vector<Fecha*> vdf,vector<Dia*> dnl){
  vector<Dia*> vddc;
  for(int i=0;i<vdf.size();i++){
    if(!esta_incluido(vdf[i],dnl)){
      vddc.push_back(new Dia(vdf[i]));
    }
  }
  return vddc;
}

void Calendario::planear(vector<Dia*> DIA,vector<Actividad*> ACT){
  int i=0,j=0;/*i para recorrer los dias y j para recorrer las actividades*/
inicio:
  if(ACT[j]->TR<=DIA[i]->TD){
  	
    DIA[i]->TD-=ACT[j]->TR;
    //DIA[i]->A.push_back(new Asignacion(ACT[j],ACT[j]->TR));
    DIA[i]->A.push_back(new Asignacion(ACT[j],ACT[j]->TR,ACT[j]->indexToTecDEnsYActDApr));
    j++;
    if(DIA[i]->TD==0)
      i++;
  }else{
    //DIA[i]->A.push_back(new Asignacion(ACT[j],DIA[i]->TD));
    DIA[i]->A.push_back(new Asignacion(ACT[j],DIA[i]->TD,ACT[j]->indexToTecDEnsYActDApr));
    ACT[j]->TR-=DIA[i]->TD;
    i++;
  }
  if( !( (i==DIA.size())||(j==ACT.size()) ) )
    goto inicio;
}

void Calendario::planear(vector<Dia*> DIA,vector<Actividad*> ACT,vector<Alumno*> Alum){
  int i=0,j=0;/*i para recorrer los dias y j para recorrer las actividades*/
  int k=0,nda;/*en nda el constructor de Asignacion colocara cuantas Asignaciones van.*/
inicio:
  if(ACT[j]->TR<=DIA[i]->TD){
  	
    DIA[i]->TD-=ACT[j]->TR;
    DIA[i]->A.push_back(new Asignacion(ACT[j],ACT[j]->TR,Alum[k],&nda,ACT[j]->indexToTecDEnsYActDApr));
    j++;
    if(DIA[i]->TD==0)
      i++;
  }else{
    DIA[i]->A.push_back(new Asignacion(ACT[j],DIA[i]->TD,Alum[k],&nda,ACT[j]->indexToTecDEnsYActDApr));
    ACT[j]->TR-=DIA[i]->TD;
    i++;
  }
  //if(nda>=3){
  if(nda>=0){
    k=(k+1)%NUMDALUMNOS;
  }
  if( !( (i==DIA.size())||(j==ACT.size()) ) )
    goto inicio;
}//end void Calendario::planear()

/**devuelve la cantidad de dias que tiene el mes 0-enero,1-febrero,2-marzo */
int Calendario::canddiasdmes(int i){
 if (i==0)  return 31;/*enero*/
 if (i==1){/*febrero*/
 	if((abs(anio-2016)%4)==0){/*si es anio bisiesto*/
 		return 29;
	}else{/*si no es anio bisiesto*/
		return 28;
	}
 } 
 if (i==2)  return 31;/*marzo*/
 if (i==3)  return 30;/*abril*/
 if (i==4)  return 31;/*mayo*/
 if (i==5)  return 30;/*junio*/
 if (i==6)  return 31;/*julio*/
 if (i==7)  return 31;/*agosto*/
 if (i==8)  return 30;/*septiembre*/
 if (i==9)  return 31;/*octubre*/
 if (i==10) return 30;/*noviembre*/
 if (i==11) return 31;/*diciembre*/
 return -1;/*ninguno de los doce meses del anio*/
}
