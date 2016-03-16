//prueba.h
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

class TestCalendario : public CppUnit::TestFixture {
private:
  Calendario* testCalendario;
public:
  TestCalendario():testCalendario(NULL){}
  virtual ~TestCalendario(){
    delete testCalendario;
  }
  static CppUnit::Test *suite(); /*en este metodo se agregan las pruebas*/
   
  void setUp() {}//Setup method
  void tearDown() {}//Teardown method
protected: /*estas son las pruebas*/
  void testCreacionDeUnCalendario();
  void test_Calendario_index_delmes();
  void test_primera_fecha_delmes();
  void test_fill_SDIT();
};//end class TestCalendario

#endif /*TEST_CALENDARIO*/
