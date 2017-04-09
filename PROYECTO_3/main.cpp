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
extern string NombresDA[][2];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int anio=2017;
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
string ARREGLO_2017[][7]={
  {"Sabado","Domingo","Lunes","Martes","Miercoles","Jueves","Viernes"}, /*enero*/
  {"Martes","Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes"}, /*febrero*/
  {"Martes","Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes"}, /*marzo*/
  {"Viernes","Sabado","Domingo","Lunes","Martes","Miercoles","Jueves"}, /*abril*/
  {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"}, /*mayo*/
  {"Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes","Martes"}, /*junio*/
  {"Viernes","Sabado","Domingo","Lunes","Martes","Miercoles","Jueves"}, /*julio*/
  {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"}, /*agosto*/
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}, /*septiembre*/
  {"Sabado","Domingo","Lunes","Martes","Miercoles","Jueves","Viernes"}, /*octubre*/
  {"Martes","Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes"}, /*noviembre*/
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}  /*diciembre*/
};

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
//  print_alumnos(Alum);
  
  Calendario *Cal2017=new Calendario(anio);
  //Fecha f1(1,2); /*Miercoles 1 de marzo de 2017*/
  Fecha f1(11,3); /*Martes 11 de abril de 2017*/
  Fecha f2(9,5); /*Jueves 9 de junio*/

  vector<string> vdd;         /*vector de dias*/
  vdd.push_back("Martes");    /*los dias que hay clase*/
  vdd.push_back("Jueves");
  vector<Fecha*> VDF=Cal2017->get_Fechas(&f1,&f2,vdd); /*vector con las Fechas 
                                                         entre f1 y f2 
                                                         correspondientes a 
                                                         los dias en el vector
                                                         vdd */
  /*construir un vector de apuntadores a Dias no laborables*/
  vector<Dia*> vdnl;
  vdnl.push_back(new Dia(new Fecha(20,2)));      /*Lunes 20 de marzo de 2017*/
  vdnl.push_back(new Dia(new Fecha(3,3)));      /*Lunes 3 de abril de 2017*/
  vdnl.push_back(new Dia(new Fecha(13,3)));      /*Jueves 13 de abril de 2017*/
  vdnl.push_back(new Dia(new Fecha(14,3)));       /*Viernes 14 de abril de 2017*/
  vdnl.push_back(new Dia(new Fecha(15,3)));       /*Sabado 15 de abril de 2017*/
  vdnl.push_back(new Dia(new Fecha(1,4)));       /*Lunes 1 de mayo de 2017*/
  vdnl.push_back(new Dia(new Fecha(5,4)));       /*Viernes 1 de mayo de 2017*/
  /*Ahora usando el vector de Fechas VDF y el vector de Dias no laborables vdnl,
    construir un vector de Dias laborables (los dias de clase para los que se 
    planificaran actividades) este vector de Dias laborables se obtendra 
    pasando un mensaje al objeto de clase Calendario*/
  vector<Dia*> VDDC=Cal2017->get_Dias_DC(VDF,vdnl);  /*obtener Vector De Dias de Clase*/
                                                     /*de clase en el salon de clase*/
  /*Se asigna Tiempo Disponible Total segun el dia de que se trate*/
  for(int i=0;i<VDDC.size();i++){
    if(ARREGLO_2017[VDDC[i]->f->m][VDDC[i]->f->d%7]=="Martes")
      VDDC[i]->set_TDT(2.0);
    if(ARREGLO_2017[VDDC[i]->f->m][VDDC[i]->f->d%7]=="Jueves")
      VDDC[i]->set_TDT(2.0);
  } 
  /*Se necesita crear las actividades/temas a asignar en los 
    dias de clase disponibles. Se usa usa constructor de Actividad 
    pasando el nombre del Tema y la duracion del Tema/Actividad en horas.*/
  vector<Actividad*> VDA;
  //VDA.push_back(new Actividad("I.	TEORIA DE PROBABILIDAD",0.0));
  //VDA.push_back(new Actividad("I.A CONCEPTO BASICO DE PROBABILIDAD",1.0));
  //VDA.push_back(new Actividad("I.B CONCEPTO DE EVENTO",1.0));/*Alcantar Rocha Antonio de Jesus*/
  //VDA.push_back(new Actividad("I.C COMBINACIONES DE EVENTOS",1.0));/*Bautista Contreras Jose Raul*/
  //VDA.push_back(new Actividad("I.D PROBABILIDAD CONDICIONAL",1.0));/*Cristobal Rojo Juan Ivan*/
  
  //VDA.push_back(new Actividad("PRIMER EXAMEN PARCIAL",2.0));
  //VDA.push_back(new Actividad("REVISION DE LA EVALUACION",0.0));
  
  VDA.push_back(new Actividad("I.E TEOREMA DE BAYES",1.0));/*Liy Delgado Maria Fernanda*/
  VDA.push_back(new Actividad("I.F TECNICAS DE CONTEO",1.0));
  VDA.push_back(new Actividad("II.VARIABLES ALEATORIAS",0.0));
  VDA.push_back(new Actividad("II.A.	VARIABLES ALEATORIAS DISCRETAS",2.5));
  VDA.push_back(new Actividad("II.B.	VARIABLES ALEATORIAS CONTINUAS",2.5));
  VDA.push_back(new Actividad("II.C.	VALOR ESPERADO DE UNA VARIABLE ALEATORIA",2.5));
  VDA.push_back(new Actividad("II.D.	PROBLEMAS DE VALOR ESPERADO DE LA VARIABLE ALEATORIA CONTINUA",2.5));
  VDA.push_back(new Actividad("II.E.	VARIANZA DE UNA VARIABLE ALEATORIA DISCRETA.",1.0));
  VDA.push_back(new Actividad("II.F.	PROLEMAS, VARIANZA DE LA VARIABLE ALEATORIA CONTINUA",1.0));
  
  //VDA.push_back(new Actividad("PRIMER EXAMEN PARCIAL",2.0));
  //VDA.push_back(new Actividad("REVISION DE LA EVALUACION",0.0));
  
  VDA.push_back(new Actividad("III DISTRIBUCIONES DISCRETAS",0.0));
  VDA.push_back(new Actividad("III.A.	DISTRIBUCION DE PROBABILIDAD DE BERNOULLI",1.0));
  VDA.push_back(new Actividad("III.B.	DISTRIBUCION DE PROBABILIDAD BINOMIAL",1.0));
  VDA.push_back(new Actividad("III.C.	DISTRIBUCION DE PROBABILIDAD GEOMETRICA",1.0));
  VDA.push_back(new Actividad("III.D.	DISTRIBUCION DE PROBABILIDAD BINOMIAL NEGATIVA",1.0));
  VDA.push_back(new Actividad("III.E.	DISTRIBUCION HIPERGEOMETRICA",1.0));
  VDA.push_back(new Actividad("III.F.	DISTRIBUCION DE POISSON",1.0));
  VDA.push_back(new Actividad("IV.	DISTRIBUCIONES CONTINUAS",0.0));
  VDA.push_back(new Actividad("IV.A.	DISTRIBUCION UNIFORME",2.0));
  VDA.push_back(new Actividad("IV.B.	DISTRIBUCION EXPONENCIAL",2.0));
  VDA.push_back(new Actividad("V.	DISTRIBUCION NORMAL",0.0));
  VDA.push_back(new Actividad("V.A.	USO DE LA DISTRIBUCION NORMAL EN EL CALCULO DE PROBABILIDAD",3.0));
  VDA.push_back(new Actividad("V.B.	DISTRIBUCIONES RELACIONADAS CON LA DISTRIBUCION NORMAL",2.0));
  
  VDA.push_back(new Actividad("SEGUNDO EXAMEN PARCIAL",2.0));
  VDA.push_back(new Actividad("REVISION DE LA EVALUACION",0.0));
  
  VDA.push_back(new Actividad("VI. ESTADISTICA DESCRIPTIVA",1.0));
  VDA.push_back(new Actividad("VI.A.	POBLACION, MUESTRA Y MUESTRA ALEATORIA",2.0));
  VDA.push_back(new Actividad("VI.B.	PRESENTACION DE DATOS",2.0));
  VDA.push_back(new Actividad("VI.C.	ESTADISTICOS MUESTRALES",3.0));
  VDA.push_back(new Actividad("VII. ESTIMACION ESTADISTICA Y DISTRIBUCIONES DE MUESTREO",0.0));
  VDA.push_back(new Actividad("VII.A.	ESTIMADORES PUNTUALES",1.0));
  VDA.push_back(new Actividad("VII.B.	PROPIEDADES DE LOS ESTIMADORES PUNTUALES",1.0));
  VDA.push_back(new Actividad("VII.C.	DISTRIBUCIONES DE MUESTREO",1.0));
  VDA.push_back(new Actividad("VIII INFERENCIAS EN UNA POBLACION",0.0));
  VDA.push_back(new Actividad("VIII.A INTERVALOS DE CONFIANZA",1.0));
  VDA.push_back(new Actividad("VIII.B PRUEBAS DE HIPOTESIS",1.0));
  VDA.push_back(new Actividad("IX.	INFERENCIAS DE DOS POBLACIONES",0.0));
  VDA.push_back(new Actividad("IX.A INTRODUCCION",1.0));
  VDA.push_back(new Actividad("IX.B ANALISIS DE MUESTRAS INDEPENDIENTES",1.0));
  
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
  Dia *hoy=new Dia(new Fecha(9,3));/*Lunes 20 de marzo de (anio)*/
  cout<<"                                                     "<<*hoy;
  cout<<"Planeacion de actividades de unidad de aprendizaje: PROBABILIDAD Y ESTADISTICA"<<endl;
  cout<<"Los dias a planificar son:"<<endl;
  for(int i=0;i<VDDC.size();i++){
    cout<<*VDDC[i]<<endl;
  }
  suma_de_horas(VDA);
  
  Antonio_de_Jesus_Alcantar_Rocha *Antonio=new 
  Antonio_de_Jesus_Alcantar_Rocha(NombresDA[0][0],NombresDA[0][1]);
  Alumno *alum=Alum[0];
  alum->opye();
  alum=Alum[1];
  alum->opye();
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
