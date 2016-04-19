/*myexception.cpp*/
#include <iostream>
#include <exception>
using std::cout;
using std::exception;

/*
  Class exception has a virtual member function
  called what that return a null-terminated 
  character sequence (of type char *).
 */
class myexception : public exception{
  virtual const char* what() const throw(){
    return "My exception happened";
  }
} myex;

int main(){
  try{
    throw myex;
  }catch(exception& e){
    cout<<e.what()<<'\n';
  }
  return 0;
}
