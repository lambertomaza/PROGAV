/*bad_alloc.cpp*/
#include <iostream>
#include <exception>
using namespace std;

int main(){
  try{
    int* myarray=new int[10000000000];
  }catch(exception& e){
    cout<<"Standar exception: "<<e.what()<<endl;
  }
  return 0;
}
