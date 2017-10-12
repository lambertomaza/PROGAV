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
#include "dummy.h"
extern int NUMDALUMNOS; /*cantidad de filas del siguiente arreglo bidimensional*/
                        /*definido en nombresdalumnos.cpp*/
extern string NombresDA[][2];

void alumno_init(vector<Alumno*>& alumno){
  for(int i=0;i<NUMDALUMNOS;i++){
    alumno.push_back(new Alumno(NombresDA[i][0],NombresDA[i][1]));	
  }
//  alumno.push_back(new Antonio_de_Jesus_Alcantar_Rocha(NombresDA[0][0],NombresDA[0][1]));
//  alumno.push_back(new Jose_Raul_Bautista_Contreras(NombresDA[1][0],NombresDA[1][1]));
//  alumno.push_back(new Juan_Ivan_Cristobal_Rojo(NombresDA[2][0],NombresDA[2][1]));
//  alumno.push_back(new Maria_Fernanda_Liy_Delgado(NombresDA[3][0],NombresDA[3][1]));
//  alumno.push_back(new Zaira_Alejandra_Najera_Medina(NombresDA[4][0],NombresDA[4][1]));
//  alumno.push_back(new Luis_Ricardo_Rivera_Hernandez(NombresDA[5][0],NombresDA[5][1]));
//  alumno.push_back(new Aldo_Rodriguez_Hernandez(NombresDA[6][0],NombresDA[6][1]));
//  alumno.push_back(new Antonio_Santiago_Santiago(NombresDA[7][0],NombresDA[7][1]));
}

void print_alumnos(vector<Alumno*> vda){
  for(int i=0;i<vda.size();i++) cout<<*vda[i]<<endl;
}

extern string TecDEnsYActDApr[][2];

int TDE::T0_TEC_ENS_sin_definir__ACT_APR_sin_definir=0;
int TDE::T1_EXPOSICION__Conocera=1;
int TDE::T2_EXPOSICION_TEMPRANA_A_PROBLEMAS_DE_INGENIERIA_BUSQUEDAS_BIBLIOGRAFICAS__CONOCERA_EL_LAS=2;
int TDE::T3_INDAGACION_BIBLIOGRAF_MODELOS_MATEMATICOS__Conocera_metodologia_para_o_modelos_matematicos=3;
int TDE::T4_PRESENTACIONES_DE_DIAPOSITIVAS_Y_RESOLUCION_PROBLEMAS__Resolvera_problemas_de=4;
int TDE::T5_EXPOSICION_ACTIVIDADES_DISCENTES_ANALISIS_CASO_PROBLEMA_DE__Resolvera_problemas_de=5;
