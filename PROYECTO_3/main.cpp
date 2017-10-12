#include <iostream>
#include <vector>
#include <stdlib.h>  /*malloc()*/
using std::cout;
using std::endl;
using std::string;
using std::vector;
#define MAIN_MODULE_PRUEBA
#include "Calendario.h"
#include "Fecha.h"
#include "Dia.h"
#include "Actividad.h"
#include "Alumno.h"
#include "year.h"
#include "dummy.h"
extern string NombresDA[][2];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//int anio=2017;
/**
                               2017                               

        enero                 febrero                 marzo       
do lu ma mi ju vi sA   do lu ma mi ju vi sA   do lu ma mi ju vi sA
 1  2  3  4  5  6  7             1  2  3  4             1  2  3  4   
 8  9 10 11 12 13 14    5  6  7  8  9 10 11    5  6  7  8  9 10 11   
15 16 17 18 19 20 21   12 13 14 15 16 17 18   12 13 14 15 16 17 18   
22 23 24 25 26 27 28   19 20 21 22 23 24 25   19 20 21 22 23 24 25   
29 30 31               26 27 28               26 27 28 29 30 31   

    abril de 2017   
do lu ma mi ju vi sA
                   1 
 2  3  4  5  6  7  8 
 9 10 11 12 13 14 15 
16 17 18 19 20 21 22 
23 24 25 26 27 28 29 
30                  
*/
extern int anio;
///** Now included through #include year.h
// * string ARREGLO[][7] -- Contiene los nombres de los dias de la semana para el anio 2016.
// * Forma de uso: Para obtener el nombre del dia correspondiente a una fecha del anio 2016, 
// *               digamos dd/mm/2016, se puede usar la siguiente expresion:
// *               string day_name=ARREGLO[(mm)-(1)][(dd)%(7)];
// *               Por ejemplo, usando esta expresion se puede saber que el pasado 24 de diciembre
// *               de 2016, 24/12/2016 fue ARREGLO[(12)-(1)][(24)%(7)]=ARREGLO[11][3]="Sabado"
// */


string MONTH[]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto",
              "septiembre","octubre","noviembre","diciembre"};

SetDIntType* obtener_nums_ddia(string d,string m);
void print_SetDIntYFecha(string d,string m,SetDIntType* SDI,int);
int index_delmes(string month);
int primera_fecha_delmes(string day,int i);
void fill_SDIT(int i,int j,SetDIntType* r);
void suma_de_horas(vector<Actividad*>);
void alumno_init(vector<Alumno*>& alumno);
void print_alumnos(vector<Alumno*>);

int main(int argc, char *argv[]) {
  vector<Alumno*> Alum;
  alumno_init(Alum);
  cout<<"\t\t\t\t\t"<<ARREGLO[9][2%7]<<" 2 de octubre de 2017"<<endl;
  cout<<"Asignatura:Investigacion de Operaciones"<<endl;
  cout<<"Relacion de discentes del grupo 4/o ICE-EMI"<<endl;
//  print_alumnos(Alum);
  
  Calendario *Cal2017=new Calendario(anio);
  Fecha f1(18,8); /*Lunes 18 de septiembre de 2017*/
  Fecha f2(15,11); /*Viernes 15 de diciembre de 2017*/

  vector<string> vdd;         /*vector de dias*/
  vdd.push_back("Lunes");    /*los dias que hay clase*/
  vdd.push_back("Jueves");
  vector<Fecha*> VDF=Cal2017->get_Fechas(&f1,&f2,vdd); /*vector con las Fechas 
                                                         entre f1 y f2 
                                                         correspondientes a 
                                                         los dias en el vector
                                                         vdd */
  /*construir un vector de apuntadores a Dias no laborables*/
  vector<Dia*> vdnl;
  vdnl.push_back(new Dia(new Fecha(2,10)));      /*Jueves 2 de noviembre de 2017*/
  vdnl.push_back(new Dia(new Fecha(20,10)));      /*Lunes 20 de noviembre de 2017*/
  
  /*Ahora usando el vector de Fechas VDF y el vector de Dias no laborables vdnl,
    construir un vector de Dias laborables (los dias de clase para los que se 
    planificaran actividades) este vector de Dias laborables se obtendra 
    pasando un mensaje al objeto de clase Calendario*/
  vector<Dia*> VDDC=Cal2017->get_Dias_DC(VDF,vdnl);  /*obtener Vector De Dias de Clase*/
                                                     /*de clase en el salon de clase*/
  /*Se asigna Tiempo Disponible Total segun el dia de que se trate*/
  for(int i=0;i<VDDC.size();i++){
//    if(ARREGLO_2017[VDDC[i]->f->m][VDDC[i]->f->d%7]=="Martes")
    if(ARREGLO[VDDC[i]->f->m][VDDC[i]->f->d%7]=="Lunes")
      VDDC[i]->set_TDT(2.0);
//    if(ARREGLO_2017[VDDC[i]->f->m][VDDC[i]->f->d%7]=="Jueves")
	if(ARREGLO[VDDC[i]->f->m][VDDC[i]->f->d%7]=="Jueves")
      VDDC[i]->set_TDT(2.0);
  } 
  /*Se necesita crear las actividades/temas a asignar en los 
    dias de clase disponibles. Se usa usa constructor de Actividad 
    pasando el nombre del Tema y la duracion del Tema/Actividad en horas.*/
  vector<Actividad*> VDA;

  VDA.push_back(new Actividad("I INTRODUCCION",0.0,0));
  VDA.push_back(new Actividad("I.A Definicion, Origen y Aplicacion de la \
Investigacion de Operaciones",0.4,5));
  VDA.push_back(new Actividad("I.B Origen de la Investigacion de Operaciones",0.4,3));
  VDA.push_back(new Actividad("I.C Aplicacion de la Investigacion de Operaciones",0.4,3));
  VDA.push_back(new Actividad("I.D Modelos y Metodologia de la Investigacion de Operaciones",0.4,3));
  VDA.push_back(new Actividad("I.E Metodologia general de la Investigacion de Operaciones",0.4,3));


  VDA.push_back(new Actividad("II PROBLEMAS DE PROGRAMACION MATEMATICA",0.0,3));
  VDA.push_back(new Actividad("II.A Modelos de Programacion Lineal",2.0,3));
  VDA.push_back(new Actividad("II.B. Planteamiento de Problemas de Programacion Lineal",3.0,1));
  
////  VDA.push_back(new Actividad("FUNCION DE DISTRIBUCION Y FUNCION DE DENSIDAD DE V. A. DISCRETAS",2.0,0));
////  VDA.push_back(new Actividad("FUNCION DE DISTRIBUCION Y FUNCION DE DENSIDAD DE V. A. CONTINUAS",2.0,0));
////  
////  VDA.push_back(new Actividad("II.C. VALOR ESPERADO DE UNA VARIABLE ALEATORIA",0.5,0));
////  VDA.push_back(new Actividad("II.D. PROBLEMAS DE VALOR ESPERADO DE LA VARIABLE ALEATORIA CONTINUA",0.5,0));
////  VDA.push_back(new Actividad("II.E. VARIANZA DE UNA VARIABLE ALEATORIA DISCRETA.",0.5,0));
////  VDA.push_back(new Actividad("II.F. PROBLEMAS, VARIANZA DE LA VARIABLE ALEATORIA CONTINUA",0.5,0));
////  
////  VDA.push_back(new Actividad("SEGUNDO EXAMEN PARCIAL",2.0,0));
////  VDA.push_back(new Actividad("REVISION DE LA EVALUACION",2.0,0));
//  
  VDA.push_back(new Actividad("III SOLUCION DE PROBLEMAS LINEALES",0.0));
  VDA.push_back(new Actividad("III.A. Metodo grafico para la solucion de problemas de \
programacion lineal con dos variables de decision",5.0,1));
  VDA.push_back(new Actividad("III.B. Empleo del paquete de computo QSB",2.0,2));
  VDA.push_back(new Actividad("PRIMER EXAMEN PARCIAL",2.0));
  VDA.push_back(new Actividad("REVISION DE LA EVALUACION",0.0));
   
  VDA.push_back(new Actividad("III.C Metodo Simplex",2.0,1));
  VDA.push_back(new Actividad("III.D. Solucion de problemas de programacion lineal",2.0,2));
  VDA.push_back(new Actividad("III.E. Uso de variables artificiales en el metodo simplex",2.0,2));
  VDA.push_back(new Actividad("III.F. Aplicacion del programa de computo QSB",4.0,2));
  VDA.push_back(new Actividad("IV. SENSIBILIDAD Y DUALIDAD",0.0));
  VDA.push_back(new Actividad("IV.A. Problema dual y su relacion con el primal",1.0,TDE::T1_EXPOSICION__Conocera));
  VDA.push_back(new Actividad("IV.B. Metodo Simplex Dual",1.0,TDE::T1_EXPOSICION__Conocera));
  VDA.push_back(new Actividad("IV.C Aplicacion del metodo simplex dual",2.0,TDE::T2_EXPOSICION_TEMPRANA_A_PROBLEMAS_DE_INGENIERIA_BUSQUEDAS_BIBLIOGRAFICAS__CONOCERA_EL_LAS));
  VDA.push_back(new Actividad("IV.D Problema dual de programacion",1.0,TDE::T1_EXPOSICION__Conocera));
  VDA.push_back(new Actividad("IV.E Analisis de sensibilidad a una solucion dada",2.0,TDE::T4_PRESENTACIONES_DE_DIAPOSITIVAS_Y_RESOLUCION_PROBLEMAS__Resolvera_problemas_de));
  VDA.push_back(new Actividad("SEGUNDO EXAMEN PARCIAL",2.0));
  VDA.push_back(new Actividad("REVISION DE LA EVALUACION",0.0));
  VDA.push_back(new Actividad("V.A Concepto de redes",1.0,TDE::T1_EXPOSICION__Conocera));
  VDA.push_back(new Actividad("V.B Problemas por la ruta mas corta",1.0,TDE::T4_PRESENTACIONES_DE_DIAPOSITIVAS_Y_RESOLUCION_PROBLEMAS__Resolvera_problemas_de));
  VDA.push_back(new Actividad("V.C Problema del arbol de expansion minima",1.0,TDE::T3_INDAGACION_BIBLIOGRAF_MODELOS_MATEMATICOS__Conocera_metodologia_para_o_modelos_matematicos));
  VDA.push_back(new Actividad("V.D Problemas por flujo maximo",1.0,TDE::T1_EXPOSICION__Conocera));
  VDA.push_back(new Actividad("V.E Problemas de flujo de costo minimo",1.0,TDE::T1_EXPOSICION__Conocera));
  VDA.push_back(new Actividad("V.F Problemas de transbordo",1.0,TDE::T1_EXPOSICION__Conocera));
  VDA.push_back(new Actividad("V.G Solucion de problemas de transbordo",1.0,TDE::T1_EXPOSICION__Conocera));
  VDA.push_back(new Actividad("V.H Problemas de transporte. Metodos de la esquina \
no celda de costo minimo y de Voguel",2.0,TDE::T1_EXPOSICION__Conocera));
  VDA.push_back(new Actividad("V.I Solucion de problemas de transporte",1.0,TDE::T2_EXPOSICION_TEMPRANA_A_PROBLEMAS_DE_INGENIERIA_BUSQUEDAS_BIBLIOGRAFICAS__CONOCERA_EL_LAS));
  VDA.push_back(new Actividad("V.J Problemas de asignacion",1.0,TDE::T1_EXPOSICION__Conocera));
  VDA.push_back(new Actividad("V.K Metodo Hungaro",1.0,TDE::T1_EXPOSICION__Conocera));
  VDA.push_back(new Actividad("TERCER EXAMEN PARCIAL",2.0));
  VDA.push_back(new Actividad("REVISION DE LA EVALUACION",0.0));
  VDA.push_back(new Actividad("EXAMEN FINAL ORDINARIO",2.0));
  VDA.push_back(new Actividad("REVISION DE LA EVALUCION",0.0));

  /*Por ultimo se hace la planeacion pasando el vector de dias de clase y el 
    vector de actividades*/
  //Cal2016->planear(VDDC,VDA);
  Cal2017->planear(VDDC,VDA,Alum);
  
  /*Finalmente se imprime en pantalla los dias a planear con las actividaes 
    correspondientes por dia de clase entre las fechas f1 y f2.*/
  //Dia *hoy=new Dia(new Fecha(9,3));/*Domingo 9 de marzo de (anio)*/
  Dia *hoy=new Dia(new Fecha(12,3));/*Miercoles 12 de abril de (anio)*/
  cout<<"                                                   "<<*hoy;
  cout<<"Planeacion de actividades de unidad de aprendizaje: INVESTIGACION DE OPERACIONES"<<endl;
  cout<<"Los dias a planificar son:"<<endl;

  for(int i=0;i<VDDC.size();i++){
  	cout<<"(PLAN DE CLASE No. "<<i+1<<") ";
  	cout<<"AVANCE PROGRAMATICO: "<<100*((float)i/VDDC.size())<<"%"<<endl;
    cout<<*VDDC[i]<<endl;
    if((i%1)==0){
#ifdef _WIN32
	system("PAUSE");
#endif    	
	}
  }
  suma_de_horas(VDA);
  
  //Antonio_de_Jesus_Alcantar_Rocha *Antonio=new 
  //Antonio_de_Jesus_Alcantar_Rocha(NombresDA[0][0],NombresDA[0][1]);
  //Alumno *alum=Alum[0];
  //alum->opye();
  //alum=Alum[1];
  //alum->opye();
#ifdef _WIN32
	system("PAUSE");
#endif
	return 0;
}//end main()

/*Cantidades de dias de los meses del anio (valido para anios bisiestos)*/
/*El hecho de que el valor que debe tener la entrada TamDMes[1] dependa de si el
  anio de que se trata es bisiesto o no, significa que es mejor obtener la cantidad 
  de dias del mes a traves de una funcion en la cual se pueda identificar si se trata 
  de un anio bisiesto o  no: Vease la funcion 
  void Calendario:: fill_SDIT(int i,int j,SetDIntType* r) 
  en el archivo Calendario.cpp
*/
int TamDMes[]={
  31,/*enero*/
  29,/*febrero*/
  31,/*marzo*/
  30,/*abril*/
  31,/*mayo*/
  30,/*junio*/
  31,/*julio*/
  31,/*agosto*/
  30,/*septiembre*/
  31,/*octubre*/
  30,/*noviembre*/
  31 /*diciembre*/
};
//////void fill_SDIT(int i,int j,SetDIntType* r){
//////  int cnt=1,k=j;
//////  while((k=k+7)<=TamDMes[i])cnt++;
//////  r->n=cnt;
//////  k=j;
//////  r->intPt=(int*)malloc((r->n)*sizeof(int));
//////  for(int m=0;m<r->n;m++){
//////    *(r->intPt+m)=k;
//////    k+=7;
//////  }
//////}

void suma_de_horas(vector<Actividad*> vda){
  float sum=0;
  for(int i=0;i<vda.size();i++){
    sum+=vda[i]->TRT;
  }
  cout<<"Total de horas="<<sum<<endl;
}
