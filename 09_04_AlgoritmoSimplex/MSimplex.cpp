#include "TablaS.h"
void
do_mostrartablaorig(TablaS& tsorig)
{
  cout<<tsorig;
}

void
do_mostrartabla(TablaS& ts)
{
  cout<<ts;
}

void
do_setcolumnapivote(TablaS& ts)
{
  int j;
  cout<<"Inserte el numero (1,2,3,...) de la columna pivote: ";
  cin>>j;
  ts.J=j-1;
}

void
do_setfilapivote(TablaS& ts)
{
  int i;
  cout<<"Inserte el numero (1,2,3,...) de la fila pivote: ";
  cin>>i;
  ts.I=i-1;
}

void
do_multfilapivoteporescalar(TablaS& ts)
{
  float esc;
  cout<<"Ingrese el escalar: ";
  cin>>esc;
  for(int j=0;j<ts.m;j++)
  {
    ts.ts[ts.I][j]*=esc;
  }
}

void
do_gaussjordanparafilanum(TablaS& t)
{
  int fila;
  float elemdcp;
  cout<<"Ingrese el numero de la fila (1,2,3,...)) a actualizar: ";
  cin>>fila;
  fila--;
  //cout<<"t.n="<<t.n<<" t.m="<<t.m<<endl;
  //cout<<"Fila pivote t.I="<<t.I<<" Columna pivote t.J="<<t.J<<endl;
  //cout<<"fila="<<fila<<endl;
  elemdcp=t.ts[fila][t.J];
  for(int j=0;j<t.m;j++)
  {
    //cout<<"t.ts["<<fila<<"]["<<j<<"]="<<t.ts[fila][j]
    //    <<" -= "<<"t.ts["<<fila<<"]["<<t.J<<"]*t.ts["<<t.I<<"]["<<j<<"]"
    //    <<t.ts[fila][t.J]<<"*"<<t.ts[t.I][j]<<endl;
    t.ts[fila][j]-=elemdcp*t.ts[t.I][j];
  }
}
