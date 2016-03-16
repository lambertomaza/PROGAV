//prueba.cpp
#include <iostream>
#include <stdlib.h>
using std::string;
//#include <cppunit/TestFixture.h>
//#include <cppunit/TestAssert.h>
//#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>  /*CppUnit*/
#include <stdlib.h>/*malloc()*/
#define MAIN_MODULE_PRUEBA	1
#include "prueba.h"


CppUnit::Test* TestCalendario::suite(){
  CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("Prueba de Calendario");
  suiteOfTests->addTest(new CppUnit::TestCaller<TestCalendario>
    ("Test 1 - Crear Calendario 2016.", &TestCalendario::testCreacionDeUnCalendario));

  suiteOfTests->addTest(new CppUnit::TestCaller<TestCalendario>
    ("Test 2 - Determinar si el metodo Calendario::index_delmes(string) \
funciona bien.",&TestCalendario::test_Calendario_index_delmes));

  suiteOfTests->addTest(new CppUnit::TestCaller<TestCalendario>("Test 3 - Determinar \
si el metodo Calendario::primera_fecha_delmes(string,int) funciona bien.",
&TestCalendario::test_primera_fecha_delmes));

  suiteOfTests->addTest(new CppUnit::TestCaller<TestCalendario>("Test 4 - Determinar \
si el metodo Calendario::fill_SDIT(int i,int j,SetDIntType* r) funciona bien.",
&TestCalendario::test_fill_SDIT));

  /* Aqui se pueden agregar mas tests */
  return suiteOfTests;
}


void TestCalendario::testCreacionDeUnCalendario(){
  int year=2016;
  Calendario Cal2016(year);
  //CPPUNIT_ASSERT_EQUAL(CAS.get_delegacion(), delegacion);
  CPPUNIT_ASSERT_EQUAL(Cal2016.get_anio(), year);
}


void TestCalendario::test_Calendario_index_delmes(){
  Calendario *calPt;
  calPt=new Calendario(2016);
  CPPUNIT_ASSERT_EQUAL(0,calPt->index_delmes("enero"));/*Lo que se espera, lo que se obtiene*/
  CPPUNIT_ASSERT_EQUAL(1,calPt->index_delmes("febrero"));
  CPPUNIT_ASSERT_EQUAL(2,calPt->index_delmes("marzo"));
  CPPUNIT_ASSERT_EQUAL(3,calPt->index_delmes("abril"));
  CPPUNIT_ASSERT_EQUAL(4,calPt->index_delmes("mayo"));
  CPPUNIT_ASSERT_EQUAL(5,calPt->index_delmes("junio"));
  CPPUNIT_ASSERT_EQUAL(6,calPt->index_delmes("julio"));
  CPPUNIT_ASSERT_EQUAL(7,calPt->index_delmes("agosto"));
  CPPUNIT_ASSERT_EQUAL(8,calPt->index_delmes("septiembre"));
  CPPUNIT_ASSERT_EQUAL(9,calPt->index_delmes("octubre"));
  CPPUNIT_ASSERT_EQUAL(10,calPt->index_delmes("noviembre"));
  CPPUNIT_ASSERT_EQUAL(11,calPt->index_delmes("diciembre"));
}

int primera_fecha_delmes(string day,int i){
  if(ARREGLO[i][0]==day) return 7;
  if(ARREGLO[i][1]==day) return 1;
  if(ARREGLO[i][2]==day) return 2;
  if(ARREGLO[i][3]==day) return 3;
  if(ARREGLO[i][4]==day) return 4;
  if(ARREGLO[i][5]==day) return 5;
  if(ARREGLO[i][6]==day) return 6;
  return -1;/*nunca deberia llegarse aqui*/
}
string DIA[]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};

void TestCalendario::test_primera_fecha_delmes(){
  int i,j;
  Calendario *calPt=new Calendario(2016);
  //Ahora probamos 7*12 combinaciones posibles de dias de la semana y mes.
  //P.ej. ("Domingo",0),("Domingo",1),...,("Lunes",0),("Lunes",1),..., etc.
  for(i=0;i<7;i++){
    for(j=0;j<12;j++){
      CPPUNIT_ASSERT_EQUAL(primera_fecha_delmes(DIA[i],j),calPt->primera_fecha_delmes(DIA[i],j));
    }
  }
}

void fill_SDIT(int i,int j,SetDIntType* r){
  int cnt=1,k=j;
dummy[0]=0;dummy[1]=1;
/*Cantidades de dias de los meses del anio (valido para anios bisiestos)*/
  TamDMes=(int*)malloc(12*sizeof(int));
  *TamDMes=31;/*enero*/
  *(TamDMes+1)=29;/*febrero*/
  *(TamDMes+2)=31;/*marzo*/
  *(TamDMes+3)=30;/*abril*/
  *(TamDMes+4)=31;/*mayo*/
  *(TamDMes+5)=30;/*junio*/
  *(TamDMes+6)=31;/*julio*/
  *(TamDMes+7)=31;/*agosto*/
  *(TamDMes+8)=30;/*septiembre*/
  *(TamDMes+9)=31;/*octubre*/
  *(TamDMes+10)=30;/*noviembre*/
  *(TamDMes+11)=31;/*diciembre*/
  while((k=k+7)<=TamDMes[i])cnt++;
  r->n=cnt;
  k=j;
  r->intPt=(int*)malloc((r->n)*sizeof(int));
  for(int m=0;m<r->n;m++){
    *(r->intPt+m)=k;
    k+=7;
  }
}

void TestCalendario::test_fill_SDIT(){
  Calendario *calPt=new Calendario(2016);
//  SetDIntType R,R1;
  SetDIntType* r=(SetDIntType*)malloc(sizeof(SetDIntType));
  SetDIntType* r1=(SetDIntType*)malloc(sizeof(SetDIntType));
//  SetDIntType* r=&R;
//  SetDIntType* r1=&R1;
  int i,j1,j2,k;
  string d;
  for(i=0;i<12;i++){
    for(k=0;k<7;k++){
      d=DIA[k];
      j1=primera_fecha_delmes(d,i);j2=calPt->primera_fecha_delmes(d,i);
      fill_SDIT(i,j1,r); calPt->fill_SDIT(i,j2,r1);
//      CPPUNIT_ASSERT(R==R1);
      CPPUNIT_ASSERT(*r==*r1);
    }
  }

}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
