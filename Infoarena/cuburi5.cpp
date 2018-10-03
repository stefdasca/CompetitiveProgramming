#include<bits/stdc++.h>
using namespace std;
ifstream f("cuburi5.in");
ofstream g("cuburi5.out");
int i,j,n,k,pozi,x,sol,P[1<<17],Po[1<<17],C[1<<17];
vector <int> V[1<<16];
int main()
{
    f>>n>>k;
    for(i=1;i<=n;++i)
        for(j=1;j<=k;++j)
        {
            f>>x;
            V[i].push_back(x);
        }
    for(i=n;i;--i)
    {
        int best=0,poz=0;
        for(j=0;j<k;++j)
            if(C[V[i][j]]>best)
                best=C[V[i][j]],poz=P[V[i][j]];
            else
                if(C[V[i][j]]==best)
                    poz=min(poz,P[V[i][j]]);
        for(j=0;j<k;++j)
            C[V[i][j]]=best+1,P[V[i][j]]=i;
        Po[i]=poz;
        if(sol<=best+1)
            pozi=i,sol=best+1;
    }
    for(i=1;i<=sol;++i)
    {
        g<<pozi<<" ";
        pozi=Po[pozi];
    }
    return 0;
}
