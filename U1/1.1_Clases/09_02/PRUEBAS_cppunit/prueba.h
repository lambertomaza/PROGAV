#ifndef TEST_CALENDARIO
#define TEST_CALENDARIO
//#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>
#include <fstream>

#include "Calendario.h"

using namespace std;
//string archivo="1 Resultados_secciones.csv";

class TestCalendario : public CppUnit::TestFixture {
private:
  Calendario* testCalendario;
public:
  TestCalendario():testCalendario(NULL){}
  virtual ~TestCalendario(){
    delete testCalendario;
  }
  static CppUnit::Test *suite();
   
  void setUp() {}//Setup method
  void tearDown() {}//Teardown method
protected:
  void testCreacionDeUnCalendario();
//  void testDiscriminaCasillaConsideradaComoNoReportada();
};//end class TestCalendario

#endif /*TEST_CALENDARIO*/
