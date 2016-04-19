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


