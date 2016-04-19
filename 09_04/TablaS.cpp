#include "TablaS.h"

TablaS::TablaS(int N,int M,float **TS):n(N),m(M),ts(TS){ }

ostream&
operator<<(ostream& out,TablaS& t)
{
  for(int i=0;i<t.n;i++)
  {
    for(int j=0;j<t.m;j++)
    {
      out<<t.ts[i][j]<<" ";
    }
    out<<endl;
  }
  out<<endl;
  return out;
}

ostream&
operator<<(ostream& out,float **m)
{
  
}
