// Proyecto_Calendario_Planeacion1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"


//int main()
//{
//    return 0;
//}

//#include <stdafx.h>
#include <iostream>
#include <vector>
#include <string>   /* out<<cadena, donde std::string cadena; */
#include <stdlib.h>  /*malloc()*/
#include <fstream>  /*ofstream*/
#include <windows.h> /*STARTUPINFO, PROCESS_INFORMATION*/
/*
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;
*/
using namespace std;
#define PREFIX	"Operacion_"
#define VERSION	0
//En Windows 7 de 64 bits, utilizar:
//#define PDFLATEX	"C:/Program Files (x86)/MiKTeX 2.9/miktex/bin/pdflatex.exe"
//#define ACROBAT	"C:/Program Files (x86)/Adobe/Acrobat 10.0/Acrobat/Acrobat.exe"

//En Windows 7 de 32 bits, utilizar:
//#define PDFLATEX	"C:/Program Files/MiKTeX 2.9/miktex/bin/pdflatex.exe"
//#define ACROBAT  "C:/Program Files/Adobe/Acrobat Reader DC/Reader/AcroRd32.exe"
//LPCWSTR PDFLATEX = L"C:/Program Files/MiKTeX 2.9/miktex/bin/pdflatex.exe";

//En Windows 10 de 64 bits, utilizar:
LPCWSTR PDFLATEX = L"C:/Program Files/MiKTeX 2.9/miktex/bin/x64/pdflatex.exe";
LPCWSTR ACROBAT = L"C:/Program Files (x86)/Adobe/Acrobat Reader DC/Reader/AcroRd32.exe";

//str, "pdflatex.exe ./%s%d.tex", PREFIX, VERSION
TCHAR STR[] = _T("pdflatex.exe Operacion_0.tex");
TCHAR STR1[] = _T("AcroRd32.exe Operacion_0.pdf");

#define UNIDAD_DE_APRENDIZAJE    "INTRODUCCION A LA PROGRAMACION"
#define NUM_INIC_DE_DIA_PLANEADO      1

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
#define MAIN_MODULE_PRUEBA
#include "Calendario.h"
#include "Fecha.h"
#include "Dia.h"
#include "Actividad.h"
#include "Asignacion.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int anio = 2018;

/* A\~no 2018*/
string ARREGLO[][7] = {
	{ "Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado" }, /*enero*/
{ "Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes" }, /*febrero*/
{ "Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes" }, /*marzo*/
{ "S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes" }, /*abril*/
{ "Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo" }, /*mayo*/
{ "Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles" }, /*junio*/
{ "S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes" }, /*julio*/
{ "Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo","Lunes" }, /*agosto*/
{ "Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves" }, /*septiembre*/
{ "Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado" }, /*octubre*/
{ "Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes" }, /*noviembre*/
{ "Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves" }  /*diciembre*/
};

string MONTH[] = { "enero","febrero","marzo","abril","mayo","junio","julio",
"agosto","septiembre","octubre","noviembre","diciembre" };

SetDIntType* obtener_nums_ddia(string d, string m);
void print_SetDIntYFecha(string d, string m, SetDIntType* SDI);
int index_delmes(string month);
int primera_fecha_delmes(string day, int i);
void fill_SDIT(int i, int j, SetDIntType* r);
void suma_de_horas(vector<Actividad*>);
void alumno_init(vector<Alumno*>& alumno);
void print_alumnos(vector<Alumno*>);

int main(int argc, char** argv) {
	int intPlanDDiaNum = NUM_INIC_DE_DIA_PLANEADO;

	Calendario *Cal2016 = new Calendario(2016);
	Fecha f1(14, 7); /*Martes 14 de agosto de 2018 */
	Fecha f2(31, 7); /*Viernes 31 de agosto de 2018 */

	vector<string> vdd;         /*vector de dias*/
								/*los dias que hay clase*/
	vdd.push_back("Martes");
	vdd.push_back("Mi\\'ercoles");
	vdd.push_back("Viernes");
	vector<Fecha*> VDF = Cal2016->get_Fechas(&f1, &f2, vdd); /*vector con las Fechas
															 entre f1 y f2
															 correspondientes a
															 los dias en el vector
															 vdd */
															 /*construir un vector de apuntadores a Dias no laborables*/
	vector<Dia*> vdnl;
	vdnl.push_back(new Dia(new Fecha(19, 10)));      /*Lunes 19 de noviembre de 2018*/
													 //vdnl.push_back(new Dia(new Fecha(22,2)));      /*Martes 22 de marzo de 2016*/
													 //vdnl.push_back(new Dia(new Fecha(23,2)));      /*Miercoles 23 de marzo de 2016*/
													 //vdnl.push_back(new Dia(new Fecha(24,2)));      /*Jueves 24 de marzo de 2016*/
													 //vdnl.push_back(new Dia(new Fecha(24,2)));      /*Viernes 25 de marzo de 2016*/
													 //vdnl.push_back(new Dia(new Fecha(2,4)));       /*Lunes 2 de mayo de 2016*/
													 //vdnl.push_back(new Dia(new Fecha(5,4)));       /*Jueves 5 de mayo de 2016*/

													 /*Ahora usando el vector de Fechas VDF y el vector de Dias no laborables vdnl,
													 construir un vector de Dias laborables (los dias de clase para los que se
													 planificaran actividades) este vector de Dias laborables se obtendra
													 pasando un mensaje al objeto de clase Calendario*/
	vector<Dia*> VDDC = Cal2016->get_Dias_DC(VDF, vdnl);  /*obtener Vector De Dias de Clase*/
														  /*de clase en el salon de clase*/
														  /*Se asigna Tiempo Disponible Total segun el dia de que se trate*/
	for (unsigned int i = 0; i < VDDC.size(); i++) {
		if (ARREGLO[VDDC[i]->f->m][VDDC[i]->f->d % 7] == "Martes")
			VDDC[i]->set_TDT(1.0);
		if (ARREGLO[VDDC[i]->f->m][VDDC[i]->f->d % 7] == "Jueves")
			VDDC[i]->set_TDT(2.0);
	}
	/*Se necesita crear las actividades/temas a asignar en los
	dias de clase disponibles. Se usa usa constructor de Actividad
	pasando el nombre del Tema y la duracion del Tema/Actividad en horas.*/
	vector<Actividad*> VDA;
	VDA.push_back(new Actividad("I INTRODUCCION", 0.0));
	VDA.push_back(new Actividad("I.A Definicion, Origen y Aplicacion de la \
Investigacion de Operaciones", 2.0));
	VDA.push_back(new Actividad("I.B Origen de la Investigacion de Operaciones", 0.5));/*Alcantar Rocha Antonio de Jesus*/
	VDA.push_back(new Actividad("I.C Aplicacion de la Investigacion de Operaciones", 0.5));/*Bautista Contreras Jose Raul*/
	VDA.push_back(new Actividad("I.D Modelos y Metodologia de la Investigacion de Operaciones", 0.5));/*Cristobal Rojo Juan Ivan*/
	VDA.push_back(new Actividad("I.E Metodologia general de la Investigacion de Operaciones", 0.5));/*Liy Delgado Maria Fernanda*/
	VDA.push_back(new Actividad("II PROBLEMAS DE PROGRAMACION MATEMATICA", 0.0));
	VDA.push_back(new Actividad("II.A Modelos de Programacion Lineal", 1.0));
	VDA.push_back(new Actividad("II.B Planteamiento de Problemas de Programacion Lineal", 1.0));
	VDA.push_back(new Actividad("III SOLUCION DE PROBLEMAS LINEALES", 0.0));
	VDA.push_back(new Actividad("III.A Metodo grafico para la solucion de problemas de \
programacion lineal con dos variables de decision", 1.0));
	VDA.push_back(new Actividad("III.B Empleo del paquete de computo QSB", 2.0));
	VDA.push_back(new Actividad("PRIMER EXAMEN PARCIAL", 2.0));
	VDA.push_back(new Actividad("REVISION DE LA EVALUACION", 0.0));
	VDA.push_back(new Actividad("III.C Metodo Simplex", 2.0));
	VDA.push_back(new Actividad("III.D Solucion de problemas de programacion lineal", 2.0));
	VDA.push_back(new Actividad("III.E Uso de variables artificiales en el metodo simplex", 2.0));
	VDA.push_back(new Actividad("III.F Aplicacion del programa de computo QSB", 4.0));
	VDA.push_back(new Actividad("IV SENSIBILIDAD Y DUALIDAD", 0.0));
	VDA.push_back(new Actividad("IV.A Problema dual y su relacion con el primal", 1.0));
	VDA.push_back(new Actividad("IV.B Metodo Simplex Dual", 1.0));
	VDA.push_back(new Actividad("IV.C Aplicacion del metodo simplex dual", 2.0));
	VDA.push_back(new Actividad("IV.D Problema dual de programacion", 1.0));
	VDA.push_back(new Actividad("IV.E Analisis de sensibilidad a una solucion dada", 2.0));
	VDA.push_back(new Actividad("SEGUNDO EXAMEN PARCIAL", 2.0));
	VDA.push_back(new Actividad("REVISION DE LA EVALUACION", 0.0));
	VDA.push_back(new Actividad("V.A Concepto de redes", 1.0));
	VDA.push_back(new Actividad("V.B Problemas por la ruta mas corta", 1.0));
	VDA.push_back(new Actividad("V.C Problema del arbol de expansion minima", 1.0));
	VDA.push_back(new Actividad("V.D Problemas por flujo maximo", 1.0));
	VDA.push_back(new Actividad("V.E Problemas de flujo de costo minimo", 1.0));
	VDA.push_back(new Actividad("V.F Problemas de transbordo", 1.0));
	VDA.push_back(new Actividad("V.G Solucion de problemas de transbordo", 1.0));
	VDA.push_back(new Actividad("V.H Problemas de transporte. Metodos de la esquina \
no celda de costo minimo y de Voguel", 2.0));
	VDA.push_back(new Actividad("V.I Solucion de problemas de transporte", 1.0));
	VDA.push_back(new Actividad("V.J Problemas de asignacion", 1.0));
	VDA.push_back(new Actividad("V.K Metodo Hungaro", 1.0));
	VDA.push_back(new Actividad("TERCER EXAMEN PARCIAL", 2.0));
	VDA.push_back(new Actividad("REVISION DE LA EVALUACION", 0.0));
	VDA.push_back(new Actividad("EXAMEN FINAL ORDINARIO", 2.0));
	VDA.push_back(new Actividad("REVISION DE LA EVALUCION", 0.0));

	/*Por ultimo se hace la planeacion pasando el vector de dias de clase y el
	vector de actividades*/
	Cal2016->planear(VDDC, VDA);
	//Cal2016->planear(VDDC,VDA,Alum);
	/*Finalmente se imprime en pantalla los dias a planear con las actividaes
	correspondientes por dia de clase entre las fechas f1 y f2.*/
	cout << "Los dias a planificar son:" << endl;
	for (unsigned int i = 0; i<VDDC.size(); i++) {
		cout << *VDDC[i] << endl;
	}
	suma_de_horas(VDA);

	/* Creaci\'on del archivo LaTeX */
	char str[128];//,str1[128];
	string dest_name, string_day_name;
	///** 2018.08.16
	sprintf_s(str, "%s%d.tex", PREFIX, VERSION);
	//*/
	dest_name = string(str);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ofstream out(dest_name.c_str());
	out << "\\documentclass[landscape]{article}" << endl;
	out << "\\usepackage[lmargin=1.73cm,rmargin=1.73cm,top=1.9cm,bottom=2.54cm]{geometry}" << endl;
	out << "\\pagestyle{empty}" << endl;	/*Para que \LaTeX no ponga numeros de p\'agina*/
	out << "\\begin{document}" << endl;
	out << "{\\large" << endl;
	out << "\\begin{center}" << endl;
	out << "{\\bf " << endl;
	out << UNIDAD_DE_APRENDIZAJE << endl;
	out << "}" << endl;
	out << "\\ \\\\" << endl;
	out << "\\ \\\\" << endl;
	out << "Planeaci\\'on del d\\'ia n\\'umero \\underline{"
		<< "\\hspace{0.5cm}" << intPlanDDiaNum << "\\hspace{0.5cm}}" << endl;
	out << "\\ \\\\" << endl;
	out << "\\ \\\\" << endl;
	out << "\\begin{tabular}{|p{11cm}|p{8cm}|}\\hline" << endl;
	out << "{\\bf TEMA DEL PROGRAMA}&{\\bf ACTIVIDADES DE APRENDIZAJE}\\\\\\hline" << endl;
	//out<<VDDC[0]->A[0]->Act->nombre<<"&\\\\\\hline"<<endl;
	for (unsigned int i = 0; i<VDDC[0]->A.size(); i++) {
		out << *(VDDC[0]->A[i]) << "&\\\\" << endl;
	}
	out << "\\hline" << endl;
	out << "\\end{tabular}" << endl;
	out << "\\ \\\\" << endl; out << "\\ \\\\" << endl;
	out << "\\ \\\\" << endl; out << "\\ \\\\" << endl;
	string_day_name = ARREGLO[VDDC[0]->f->m][(VDDC[0]->f->d) % 7];
	out << string_day_name
		<< " \\underline{\\hspace{0.5cm}" << VDDC[0]->f->d << "\\hspace{0.5cm}} de "
		<< " \\underline{\\hspace{0.5cm}"
		<< MONTH[VDDC[0]->f->m] << "\\hspace{0.5cm}} de " << anio << "." << endl;
	out << "\\ \\\\" << endl; out << "\\ \\\\" << endl;
	out << "\\ \\\\" << endl; out << "\\ \\\\" << endl;
	out << "Elabor\\'o:" << endl;
	out << "\\ \\\\" << endl; out << "\\ \\\\" << endl;
	out << "\\ \\\\" << endl; out << "\\ \\\\" << endl;
	out << "{\\bf ING. LAMBERTO MAZA CASAS}" << endl;
	out << "\\end{center}" << endl;
	out << "}" << endl;/*cierra la llave del {\large */
	out << "\\end{document}" << endl;

	out.close();
	///////////////////////////////////////////////////////////////
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	sprintf_s(str, "pdflatex.exe ./%s%d.tex", PREFIX, VERSION);
	string msg = string(str);
	//V\'ease cambios (remplazo de las macros PDFLATEX y la variable STR).
	//if (!CreateProcess(PDFLATEX, str, 0, 0, 0, 0, 0, 0, &si, &pi)) {
	if (!CreateProcess(PDFLATEX, STR, 0, 0, 0, 0, 0, 0, &si, &pi)) {
		//Could not start process;
		///** 2018.08.16
		cerr << "Could not start process: " << msg << endl;
		//*/
		system("PAUSE");
		return -1;
	}
	CloseHandle(pi.hThread);
	// wait for the child program to terminate
	WaitForSingleObject(pi.hProcess, INFINITE);
	///////////////////////////////////////////////////////////////
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	sprintf_s(str, "AcroRd32.exe ./%s%d.pdf", PREFIX, VERSION);
	msg = string(str);
	if (!CreateProcess(ACROBAT, STR1, 0, 0, 0, 0, 0, 0, &si, &pi)) {
		//Could not start process;
		cerr << "Could not start process: " << msg << endl;
		system("PAUSE");
		return -1;
	}
	CloseHandle(pi.hThread);
	// wait for the child program to terminate
	WaitForSingleObject(pi.hProcess, INFINITE);
	///////////////////////////////////////////////////////////////
#ifdef _WIN32
	system("PAUSE");
#endif
	return 0;
}
/** 2018.08.16
void print_SetDIntYFecha(string d, string m, SetDIntType* SDI) {
for (int i = 0; i<SDI->n; i++) {
cout << SDI->intPt[i] << " de " << m << " de " << anio << endl;
}
}
*/

/**
Obtiene los numeros de dia de las fechas de los
dias d en el mes m.
*/
SetDIntType* obtener_nums_ddia(string d, string m) {
	SetDIntType* r = (SetDIntType*)malloc(sizeof(SetDIntType));
	int i, j;  /* i: index del mes en el arreglo ARREGLO*/
	i = index_delmes(m);
	if (i >= 0 && i<12) {
		j = primera_fecha_delmes(d, i);
	}
	fill_SDIT(i, j, r);
	return r;
}


/**
Obtiene el indice correspondiente al mes month.
Si month="enero", debe devolver 0,
Si month="febrero", debe devolver 1,
Si month="marzo", debe devolver 2,
etc.
*/
int index_delmes(string month) {
	for (int i = 0; i<12; i++) {
		if (month == MONTH[i])
			return i;
	}
	return -1;/*no se encontro la cadena*/
}

/**
Devuelve el numero de dia de la primera fecha
del mes con indice i (devuelto por
index_delmes(string month)), en la que el dia
es el string day.
*/
int primera_fecha_delmes(string day, int i) {
	if (ARREGLO[i][0] == day) return 7;
	if (ARREGLO[i][1] == day) return 1;
	if (ARREGLO[i][2] == day) return 2;
	if (ARREGLO[i][3] == day) return 3;
	if (ARREGLO[i][4] == day) return 4;
	if (ARREGLO[i][5] == day) return 5;
	if (ARREGLO[i][6] == day) return 6;
	return -1;/*nunca deberia llegarse aqui*/
}

/*Cantidades de dias de los meses del anio (valido para anios bisiestos)*/
int TamDMes[] = {
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
void fill_SDIT(int i, int j, SetDIntType* r) {
	int cnt = 1, k = j;
	while ((k = k + 7) <= TamDMes[i])cnt++;
	r->n = cnt;
	k = j;
	r->intPt = (int*)malloc((r->n) * sizeof(int));
	for (int m = 0; m<r->n; m++) {
		*(r->intPt + m) = k;
		k += 7;
	}
}

void suma_de_horas(vector<Actividad*> vda) {
	float sum = 0;
	for (unsigned int i = 0; i<vda.size(); i++) {
		sum += vda[i]->TRT;
	}
	cout << "Total de horas=" << sum << endl;
}