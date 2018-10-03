#include<bits/stdc++.h>
using namespace std;
ifstream f("reteta.in");
ofstream g("reteta.out");
int n,m,t,nr,pr[25],a,cb[25],ist[25];
double pmin,p;
struct retete
{
    int v[25],t;
    double p;
};
retete v[25];
int main()
{
    f>>n>>m;
    pmin=30000000.0;
    for(int i=1;i<=m;++i)
    {
        f>>v[i].t>>nr;
        for(int j=1;j<=nr;++j)
        {
            f>>a;
            v[i].v[a]=1;
        }
    }
    for(int i=1;i<=n;++i)
        f>>pr[i];
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j)
            if(v[i].v[j]==1)
                v[i].p=v[i].p+(pr[j]+0.0)/v[i].t;
    }
    int sol=(1<<m)-1;
    while(sol)
    {
        cb[m]++;
        int fr=m;
        while(cb[fr]==2)
        {
            cb[fr-1]++;
            cb[fr]=0;
            --fr;
        }
        for(int i=1;i<=m;++i)
            if(cb[i]==1)
            {
                p+=v[i].p;
                for(int j=1;j<=n;++j)
                    ist[j]+=v[i].v[j];
            }
        int ok=1;
        for(int i=1;i<=n;++i)
            if(ist[i]!=1)
                ok=0;
        if(ok)
            pmin=min(pmin,p);
        p=0;
        for(int i=1;i<=n;++i)
            ist[i]=0;
        --sol;
    }
    g<<fixed<<setprecision(1)<<pmin;
    return 0;
}
