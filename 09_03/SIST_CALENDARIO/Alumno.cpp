#include <iostream>
using namespace std;
#include "Alumno.h"
ostream& operator<<(ostream& out,Alumno& a){
  out<<a.firstname<<" "<<a.lastname<<endl;
}
int Alumno::NDL=0;
