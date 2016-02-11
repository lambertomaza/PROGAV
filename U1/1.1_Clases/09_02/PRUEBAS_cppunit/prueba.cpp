//#include <cppunit/TestFixture.h>
//#include <cppunit/TestAssert.h>
//#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>  /*CppUnit*/
#include "prueba.h"

CppUnit::Test* TestCalendario::suite(){
  CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("Prueba de Calendario");
  suiteOfTests->addTest(new CppUnit::TestCaller<TestCalendario>
    ("Test 1 - Crear Calendario 2016.", &TestCalendario::testCreacionDeUnCalendario));

//  suiteOfTests->addTest(new CppUnit::TestCaller<TestCalendario>
//    ("Test 2 - Detectar Casilla sin votos para partido, candidato, o coalicion. \
//    Por ahora solo busca revisar si el primer partido no tiene votos.", \
//    &TestCalendario::testDiscriminaCasillaConsideradaComoNoReportada));

  /* Aqui se pueden agregar mas tests */
  return suiteOfTests;
}


void TestCalendario::testCreacionDeUnCalendario(){
  int year=2016;
  Calendario Cal2016(year);
  //CPPUNIT_ASSERT_EQUAL(CAS.get_distrito(), distrito);
  //CPPUNIT_ASSERT_EQUAL(CAS.get_seccion(), seccion);
  //CPPUNIT_ASSERT_EQUAL(CAS.get_casilla(), casilla);
  //CPPUNIT_ASSERT_EQUAL(CAS.get_delegacion(), delegacion);
  CPPUNIT_ASSERT_EQUAL(Cal2016.get_anio(), year);
}

//void TestCalendario::testDiscriminaCasillaConsideradaComoNoReportada(){
//  CasiCasilla CCasill;
//  Casilla *ap;
//  string cadvacia="";
//  vector<string> arr;
//  arr.push_back("");arr.push_back("");arr.push_back("");
//  arr.push_back("");arr.push_back("");arr.push_back("");
//  //crear una cadena de entrada para ese archivo
//  /* string archivo definido al inicio de este archivo */
//  ifstream in(archivo.c_str()); 
//  if(in){//el stream existe
//    string linea;
//    int line_num=0, tokcount=0;
//    while(getline(in, linea)){
//      line_num++;
//      String_Tokenizer tokenizer(linea, ",");
//      while(tokenizer.has_more_tokens()){
//        arr[tokcount]=tokenizer.next_token();
//        tokcount++;
//        if(tokcount==6){
//          //add(arr);
//          CCasill.distrito=arr[0];CCasill.seccion=arr[1];CCasill.casilla=arr[2];
//          CCasill.delegacion=arr[3];CCasill.tipo=arr[4];CCasill.PartCandCoal=arr[5];
//          ap=new Casilla(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
//          tokcount=0;
//          if(line_num==3){
////cout<<"ap->get_PartCandCoal()="<<ap->get_PartCandCoal()<<"  "<<"cadvacia="<<cadvacia<<"\n";
//            CPPUNIT_ASSERT_EQUAL(ap->get_PartCandCoal(),cadvacia);
//          }
//          break;
//        }
//      }
//    }
//  }
//  in.close();
//}

