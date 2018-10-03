#include<bits/stdc++.h>
using namespace std;
ifstream f("balanta.in");
ofstream g("balanta.out");
int n,m;
bool v[1050];
bool z[1050];
int nrf,mn,l,r;
int v1[1050];
bool fra[1050],frb[1050];
int main()
{
    f>>n>>m;
    memset(v,1,n+1);
    memset(z,1,n+1);
    for(int i=1;i<=m;++i)
    {
        f>>l;
        for(int j=1;j<=l;++j)
            f>>v1[j],fra[v1[j]]=1;
        for(int j=1;j<=l;++j)
            f>>v1[l+j],frb[v1[j+l]]=1;
        f>>r;
        if(r==0)
            for(int j=1;j<=l+l;++j)
                v[v1[j]]=0,z[v1[j]]=0;
        if(r==1)
            {
                for(int j=1;j<=n;++j)
                    if(v[j]==1 && fra[j]==1);
                    else
                        v[j]=0;
                for(int j=1;j<=n;++j)
                    if(z[j]==1 && frb[j]==1);
                    else
                        z[j]=0;
            }
        if(r==2)
            {
                for(int j=1;j<=n;++j)
                    if(v[j]==1 && frb[j]==1);
                    else
                        v[j]=0;
                for(int j=1;j<=n;++j)
                    if(z[j]==1 && fra[j]==1);
                    else
                        z[j]=0;
            }
         memset(frb,0,n+1);
         memset(fra,0,n+1);
    }
    int nr1=0,nr2=0;
    int mf1,mf2;
    for(int i=1;i<=n;++i){
        if(v[i]==1)
            ++nr1,mf1=i;
        if(z[i]==1)
            ++nr2,mf2=i;
    }
    if(nr1==1 && nr2==0)
        g<<mf1;
    else
        if(nr1==0 && nr2==1)
            g<<mf2;
        else
            g<<0;
    return 0;
}
