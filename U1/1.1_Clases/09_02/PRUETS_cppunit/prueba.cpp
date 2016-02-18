#include <iostream>
using std::string;
//#include <cppunit/TestFixture.h>
//#include <cppunit/TestAssert.h>
//#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>  /*CppUnit*/
#include "prueba.h"
extern string ARREGLO[][7];

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

  /* Aqui se pueden agregar mas tests */
  return suiteOfTests;
}


void TestCalendario::testCreacionDeUnCalendario(){
  int year=2016;
  Calendario Cal2016(year);
  //CPPUNIT_ASSERT_EQUAL(CAS.get_delegacion(), delegacion);
  CPPUNIT_ASSERT_EQUAL(Cal2016.get_anio(), year);
}

//struct protoCalendario{
//};

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
//string MES[]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto",
//"septiembre","octubre","noviembre","diciembre"};
void TestCalendario::test_primera_fecha_delmes(){
  int i,j;
  Calendario *calPt=new Calendario(2016);
  //Ahora probamos 7*12=84 combinaciones posibles de dias de la semana y mes.
  //P.ej. ("Domingo",0),("Domingo",1),...,("Lunes",0),("Lunes",1),..., etc.
  for(i=0;i<7;i++){
    for(j=0;j<12;j++){
      CPPUNIT_ASSERT_EQUAL(primera_fecha_delmes(DIA[i],j),calPt->primera_fecha_delmes(DIA[i],j));
    }
  }
}


