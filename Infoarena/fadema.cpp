/// Sigur e problema de OJI a IX-a?
#include<bits/stdc++.h>
using namespace std;
ifstream f("fadema.in");
ofstream g("fadema.out");
int n,m,a[1002][1002];
int Lcur;
int Lc[1002][1002];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>a[i][j];
    for(int j=1;j<=m;++j)
        for(int i=1;i<=n;++i)
            if(i==1)
                Lc[i][j]=1;
            else
                if(a[i][j]!=a[i-1][j])
                    Lc[i][j]=Lc[i-1][j]+1;
                else
                    Lc[i][j]=1;
    int sol=0;
    for(int i=n;i>=1 && i*m>sol;--i)
    {
        for(int j=1;j<=m;++j)
        {
            int minx=Lc[i][j];
            for(int k=j;minx*(m-j+1)>sol && k<=m;++k)
            {
                minx=min(minx,Lc[i][k]);
                sol=max(sol,(k-j+1)*minx);
                if(a[i][k+1]==a[i][k])
                    break;
            }
        }
    }
    g<<sol;
    return 0;
}
