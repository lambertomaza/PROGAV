#include <iostream>
#include <vector>
#include <stdlib.h>  /*malloc()*/
using std::cout;
using std::cin;
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

string ARREGLO[][7]={
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}, /*enero*/
  {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"}, /*febrero*/
  {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"}, /*marzo*/
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}, /*abril*/
  {"Sabado","Domingo","Lunes","Martes","Miercoles","Jueves","Viernes"}, /*mayo*/
  {"Martes","Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes"}, /*junio*/
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}, /*julio*/
  {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"}, /*agosto*/
  {"Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes","Martes"}, /*septiembre*/
  {"Viernes","Sabado","Domingo","Lunes","Martes","Miercoles","Jueves"}, /*octubre*/
  {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"}, /*noviembre*/
  {"Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes","Martes"}  /*diciembre*/
};

string MONTH[]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto",
              "septiembre","octubre","noviembre","diciembre"};

SetDIntType* obtener_nums_ddia(string d,string m);
void print_SetDIntYFecha(string d,string m,SetDIntType* SDI);
int index_delmes(string month);
int primera_fecha_delmes(string day,int i);
void fill_SDIT(int i,int j,SetDIntType* r);
void suma_de_horas(vector<Actividad*>);
void alumno_init(vector<Alumno*>& alumno);
void print_alumnos(vector<Alumno*>);
void process_commands();
int show_menu(void);


int main(int argc, char** argv) {
  vector<Alumno*> Alum;
  alumno_init(Alum);
  cout<<"Listado de alumnos"<<endl;
  print_alumnos(Alum);
  
  process_commands();
  
#ifdef _WIN32
	system("PAUSE");
#endif
	return 0;
}

vector<string> optns;

void process_commands(){
  int cho;
  optns.push_back("Lista de alumnos");
  optns.push_back("Planecion global");
  cho=show_menu();
}

int show_menu(){
 int ch;
  for(int i=0;i<optns.size();i++)
    cout<<i+1<<" "<<optns[i]<<endl;
  cin>>ch;
  return ch;
}
