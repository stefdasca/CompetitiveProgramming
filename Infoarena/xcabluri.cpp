/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("xcabluri.in");
ofstream g("xcabluri.out");
int n,m,nrs;
struct segmente
{
    int xa,ya,xb,yb;
};
segmente v[5002];
int mat[102][102];
int nrgut[102];
deque<pair<int,int> >d;
int verificare(int i,int j)
{
   int ok=0,a1,a2,b1,b2,c1,c2;
   a1=v[i].yb-v[i].ya;
   b1=v[i].xb*(-1)+v[i].xa;
   c1=v[i].ya*v[i].xb-v[i].yb*v[i].xa;
   a2=v[j].yb-v[j].ya;
   b2=v[j].xb*(-1)+v[j].xa;
   c2=v[j].ya*v[j].xb-v[j].yb*v[j].xa;
   if((a1*v[j].xa+b1*v[j].ya+c1)*(a1*v[j].xb+b1*v[j].yb+c1)<=0)
      if((a2*v[i].xa+b2*v[i].ya+c2)*(a2*v[i].xb+b2*v[i].yb+c2)<=0)
         ok=1;
   return ok;
}
int conditie1(int i,int j)
{
   float n1,n2;
   n1=(float)(v[i].yb-v[i].ya)/(v[i].xb-v[i].xa);
   n2=(float)(v[j].yb-v[j].ya)/(v[j].xb-v[j].xa);
   if(n1!=n2)
      return 1;
   return 0;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>mat[i][j];
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(mat[j][i])
            {
                ++nrs;
                int col=mat[j][i];
                v[col].xa=j;
                v[col].ya=i;
                mat[j][i]=0;
                d.push_back({j,i});
                while(!d.empty())
                {
                    int X=d[0].first;
                    int Y=d[0].second;
                    d.pop_front();
                    if(mat[X-1][Y+1]==col)
                    {
                        mat[X-1][Y+1]=0;
                        d.push_back({X-1,Y+1});
                    }
                    else
                        if(mat[X][Y+1]==col)
                        {
                            mat[X][Y+1]=0;
                            d.push_back({X,Y+1});
                        }
                        else
                            if(mat[X+1][Y+1]==col)
                        {
                            mat[X+1][Y+1]=0;
                            d.push_back({X+1,Y+1});
                        }
                   if(d.empty())
                   {
                       v[col].xb=X;
                       v[col].yb=Y;
                   }
                }
            }
    for(int i=1;i<nrs;++i)
        for(int j=i+1;j<=nrs;++j)
            if(conditie1(i,j) && verificare(i,j))
                nrgut[i]++,nrgut[j]++;
    for(int i=1;i<=nrs;++i)
        g<<nrgut[i]<<" ";
    return 0;
}
