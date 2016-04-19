/*exceptions.cpp*/
#include <iostream>
using namespace std;

int main(){
  try{
    throw 20;
  }catch(int e){
    cout<<"An exception occurred. Exception Nr. "<<e<<endl;
  }
  try{
     throw 'A';
  }catch(int param){
    cout<<"int exception"<<endl;
  }catch(char param){
    cout<<"char exception"<<endl;
  }catch(...){
    cout<<"default exception"<<endl;
  }
  try{
    try{
      throw 100;
    }catch(int n){
      throw;
    }
  }catch(...){
    cout<<"Exception occured"<<endl;
  }
  return 0;
}
