/*nombresdalumnos.cpp*/
#include <iostream>
#define IO  investigacion de operaciones
using std::string;
int  NUMDALUMNOS=8;

string NombresDA[][2]={
  {"Antonio de Jesus","Alcantar Rocha"},
  {"Jose Raul","Bautista Contreras"},
  {"Juan Ivan","Cristobal Rojo"},
  {"Maria Fernanda","LiY Delgado"},
  {"Zaira Alejandra","Najera Medina"},
  {"Luis Ricardo","Rivera Hernandez"},
  {"Aldo","Rodriguez Hernandez"},
  {"Antonio","Santiago Santiago"}
};

string OPYE[][12]={/*Objetivos Particulares Y Especificos*/
  {"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
""},
  {"",
"1.1 Definira por escrito que es la IO en las organizaciones utilizando sus propias palabras.",
"1.2 Ilustrara el origen de la IO mediante un cuadro sinoptico cronologicamente sin equivocacion.",
"1.3 Citara por escrito por los menos dos de las aplicaciones de la IO en las organizacones.",
"1.4 Citara por escritodos de los modelos mas importantes de la IO en las organizaciones.",
"1.5 Enumerara por escrito los seis pasos de la metodologia general a seguir por la IO",
"",
"",
"",
"",
"",
""},
  {"",
"2.1 Reproducira el modelo de programacion lineal, sin omitir ninguno de los elementos que lo integran.",
"2.2 Resolvera cuatro problemas del modelo de programacion lineal, analizando \
la situacion presente en cada uno de ellos, sin error de concepto, evidenciando \
el valor de la honradez.",
"",
"",
"",
"",
"",
"",
"",
"",
""},
  {"",
"3.1 Resolvera por lo menos tres problemas de programacion lineal con dos \
variables de decision sin error de concepto, evidenciando el valor de la honradez",
"3.2 Resolvera por lo menos dos problemas de programacion lineal con dos variables \
de decision empleando en su solucion el paquete de computo QSB, sin error de \
concepto, evidenciando el valor de la honradez.",
"3.3 Describira por escrito el algoritmo simplex, sin omitir algun paso.",
"3.4 Resolvera por lo menos dos problemas de programacion lineal, cuyo fin sea maximizar \
o minimizar, aplicando el algoritmo simplex, sin error de concepto, evidenciando el valor \
de la honradez.",
"3.5 Resolvera por lo menos dos problemas de programacion lineal que requieran de variables \
artificiales empleando el algoritmo simplex, sin error de concepto, evidenciando el valor de honradez.",
"3.6 Resolvera por lo menos dos problemas de programacion lineal utilizando el programa de \
computo QSB, sin error de concepto, evidenciando el valor de honradez.",
"",
"",
"",
"",
""},
  {"",
"4.1 Resolvera un problema de programacion lineal mediante el modelo dual y su \
relacion con el modelo primal, sin error de concepto, evidenciando el valor de la honradez.",
"4.2 Describira por escrito el algoritmo simplex para un problema dual sin omitir algun paso.",
"4.3 Resolvera por lo menos un problema de programacion lineal aplicando el algoritmo simplex \
dual, sin error de concepto, evidenciando el valor de la honradez.","4.4 Resolvera por \
lo menos un problema dual de programacion lineal indicado por el personal docente, empleando \
en su solucion el paquete de computo QSB, sin error de concepto, evidenciando el valor de \
la honradez.",
"4.5 Examinara mediante la resolucion de un ejercicio los intervalos de \
aceptacion de los valores de las variables y parametros del cuadro optimo de un problema \
de programacion lineal, sin equivocacion.",
"",
"",
"",
"",
"",
""},
  {"",
"5.1 Describira por escrito utilizando sus propias palabras el significado de redes.",
"5.2 Resolvera por lo menos un problema de redes en busca de la ruta mas corta, sin error \
de concepto, evidenciando el valor de la honradez.",
"5.3 Resolvera por lo menos un problema de redes para la determinacion del arbol de \
expansion, sin error de concepto, evidenciando el valor de la honradez.",
"5.4 Resolvera por lo menos un problema de redes para determinar el flujo maximo, sin \
error de concepto, evidenciando el valor de la honradez.",
"5.5 Resolvera por lo menos un problema de redes para determinar el flujo de \
costo minimo, sin error de concepto, evidenciando el valor de la honradez.",
"5.6 Describira el planteamiento de por lo menos un problema de trasbordo, despues \
de haberlo analizado, sin error de concepto, evidenciando el valaor de la honradez.",
"5.7 Resolvera por lo menos un problema de trasbordo, sin error de concepto, evicenciando \
el valor de honradez.",
"5.8 Describira por escrito el planteamiento de por lo menos un problema de transporte, \
sin error de concepto, evidenciando el valor de honradez.",
"5.9 Resolvera por lo menos un problema de transporte utilizando los tres metodos (esquina \
noroeste, celda de costo minimo y Voguel), sin error de concepto, evidenciando el valor de \
la honradez.",
"5.10 Describira por escrito el planteamiento de por lo menos un problema de asignacion, \
sin error de concepto, evidenciando el valor de honradez.",
"5.11 Resolvera por escrito por lo menos un problema de asignacion, usando el metodo \
hungaro, sin error de concepto, evidenciando el valor de honradez."}
};
