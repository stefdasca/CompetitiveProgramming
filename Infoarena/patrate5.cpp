#include<bits/stdc++.h>
using namespace std;
#define nmax 100111
ifstream f("patrate5.in");
ofstream g("patrate5.out");
int n, A[nmax], B[nmax],C[nmax], p,a,b,c;
int test(int x)
{
  int i,j;
  for(i=1;i<10000;++i)
  {
    if(x < i*i)
        break;
    j = int(sqrt(x - i * i));
    if(j*j + i*i != x)
        continue;
    a = i;
    b = j;
    return 1;
  }
  return 0;
}
int doit(int x)
{
    for(int i=1;i<1000;++i)
        if(test(x + i * i))
        {
              c = i;
              return x + i * i;
        }
     return -1;
}
int main()
{
      int i,j,l,k;
      f>>n>>p;
      j = 2;
      A[0] = B[0] = 1;
      C[0] = 0;
      l = 1;
      for(i=3;i<=n;++i)
      {
        j = doit(j);
        A[l] = a;
        B[l] = b;
        C[l] = c;
        l++;
      }
      g<<j<<'\n';
      for(i=p;i<=n;++i)
      {
        k = n - i;
        g<<A[k]<<" "<<B[k]<<" ";
        for(j=k+1;j<l;++j)
            g<<C[j]<<" ";
        g<<'\n';
      }
  return 0;
}
