#include <iostream>
#include <vector>
#include "TablaS.h"
#define PROBANDO
//#define USANDO
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float ARRTS[][3]={
  {1,1,1},
  {2,3,4}
};
vector<string> elemdmenu;

void initTS(int,int,float**);
void initTS1(int,int,float**,float arrts[2][3]);
void printTS(int n,int m,float **ts);
void initelemsdmenu(void);
int mostrarmenu(void);
void do_mostrartablaorig(TablaS&);
void do_mostrartabla(TablaS&);
void do_setcolumnapivote(TablaS&);
void do_setfilapivote(TablaS&);
void processcommands(TablaS&);

int main(int argc, char** argv) {
  int n,m;     //n filas de la tabla simplex,m columnas de la tabla simplex
  float **TS;  //Tabla Simplex
#ifdef  USANDO
  cout<<"Algoritmo Simplex"<<endl;
  cout<<"Ingrese numero de filas de la tabla:";
  cin>>n;
  cout<<"Ingrese numero de columnas de la tabla:";
  cin>>m;
#endif /*USANDO*/
#ifdef PROBANDO
  n=2;m=3;
#endif /*PROBANDO*/
  TS=new float*[n];
  for(int i=0;i<n;i++)
  {
    TS[i]=new float[m];
  }
  //initTS(n,m,TS);
  //printTS(n,m,TS);
#ifdef PROBANDO
  initTS1(n,m,TS,ARRTS);
#endif /*PROBANDO*/
  TablaS TabS(n,m,TS);
  cout<<"Tabla inicial simplex"<<endl;
  cout<<TabS;
  initelemsdmenu();   /*Modificar esta funcion para agregar elemento(s) de menu*/
  processcommands(TabS);
  return 0;
}//end main()

void
initTS(int n,int m,float **ts)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cout<<"TS["<<i<<"]["<<j<<"]= ";
      cin>>ts[i][j];
    }
  }
}

void printTS(int n,int m,float **ts)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cout<<ts[i][j]<<" ";
    }
    cout<<endl;
  }
}

void
initTS1(int N,int M,float **A,float arrts[2][3])
{
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
    {
      A[i][j]=arrts[i][j];
    }
  }
}

/*Modificar esta funcion para agregar elemento de menu*/
void
initelemsdmenu(void)
{
  elemdmenu.push_back("Mostrar tabla inicial simplex");
  elemdmenu.push_back("Mostrar tabla simplex");
  elemdmenu.push_back("Settear columna pivote");
  elemdmenu.push_back("Settear fila pivote");
}

void
processcommands(TablaS& t)
{
  int ch;    /*choice*/
  TablaS torig=t;
  do{
    ch=mostrarmenu();
    if((ch>=0)&&(ch<elemdmenu.size())){
      cout<<"La opcion elegida fue "<<ch<<" "<<elemdmenu[ch]<<endl;
    }
    
    switch(ch){
      /*Mostrar tabla inicial*/
      case 0:{do_mostrartablaorig(torig);break;}
      case 1:{do_mostrartabla(t);break;}
      case 2:{do_setcolumnapivote(t);break;}
      case 3:{do_setfilapivote(t);break;}
      default:{break;}
    }
  }while(ch!=elemdmenu.size());
}



int
mostrarmenu(void)
{
  int r;
  for(int i=0;i<elemdmenu.size();i++)
  {
    cout<<i<<" "<<elemdmenu[i]<<endl;
  }
  cout<<elemdmenu.size()<<" Salir"<<endl;
  cout<<"Seleccione una opcion: ";
  cin>>r;
  return r;
}
