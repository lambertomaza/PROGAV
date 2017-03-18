/*initialize.cpp*/
#include <iostream>
#include <vector>
#include <ostream>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
#include "Alumno.h"
extern int NUMDALUMNOS; /*cantidad de filas del siguiente arreglo bidimensional*/
extern string NombresDA[][2];

void alumno_init(vector<Alumno*>& alumno){
  //for(int i=0;i<NUMDALUMNOS;i++){
  //  alumno.push_back(new Alumno(NombresDA[i][0],NombresDA[i][1]));	
  //}
  alumno.push_back(new Antonio_de_Jesus_Alcantar_Rocha(NombresDA[0][0],NombresDA[0][1]));
  alumno.push_back(new Jose_Raul_Bautista_Contreras(NombresDA[1][0],NombresDA[1][1]));
  alumno.push_back(new Juan_Ivan_Cristobal_Rojo(NombresDA[2][0],NombresDA[2][1]));
  alumno.push_back(new Maria_Fernanda_Liy_Delgado(NombresDA[3][0],NombresDA[3][1]));
  alumno.push_back(new Zaira_Alejandra_Najera_Medina(NombresDA[4][0],NombresDA[4][1]));
  alumno.push_back(new Luis_Ricardo_Rivera_Hernandez(NombresDA[5][0],NombresDA[5][1]));
  alumno.push_back(new Aldo_Rodriguez_Hernandez(NombresDA[6][0],NombresDA[6][1]));
  alumno.push_back(new Antonio_Santiago_Santiago(NombresDA[7][0],NombresDA[7][1]));
}

void print_alumnos(vector<Alumno*> vda){
  for(int i=0;i<vda.size();i++) cout<<*vda[i]<<endl;
}
