#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
ifstream f("tort3.in");
ofstream g("tort3.out");
int n,m,lm[505][505],lgm;
char mt[505][505];
int main() {
  f>>n>>m;
  for(int i=1; i<=n; ++i)
    f>>(mt[i]+1);
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
    {
      lm[i][j]=1;
      if(mt[i][j]==mt[i-1][j] && mt[i][j]==mt[i][j-1] && mt[i][j]==mt[i-1][j-1])
        lm[i][j]=max(lm[i][j],1+min(lm[i-1][j-1],min(lm[i-1][j],lm[i][j-1])));
      lgm=max(lgm,lm[i][j]);
    }
  for(int lgc=lgm; lgc; --lgc)
    {
        int ok=0;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
          if(lm[i][j]>=lgc && mt[i-lgc+1][j-lgc+1]!='-' && mt[i-lgc+1][j]!='-' && mt[i][j-lgc+1]!='-' && mt[i][j]!='-')
          {
                g<<lgc<<' '<<i<<' '<<j<<'\n';
                for(int x=i-lgc+1; x<=i; ++x)
                    for(int y=j-lgc+1; y<=j; ++y)
                    mt[x][y]='-';
                ok=1;
          }
        lgc+=ok;
  }
  return 0;
}
