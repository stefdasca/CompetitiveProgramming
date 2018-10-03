#include<bits/stdc++.h>
using namespace std;
ifstream f("zoro.in");
ofstream g("zoro.out");
int n,m,mat[1002][1002];
int maxl[1002],maxc[1002];
struct poz
{
    int L,C;
};
poz v[1000002];
int main()
{
    f>>n>>m;
    if(n*m==1)
    {
        g<<1;
        return 0;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>mat[i][j],v[mat[i][j]]={i,j};
    int poz=n*m;
    while(v[poz].L!=1 || v[poz].C!=1)
        --poz;
    --poz;
    maxl[1]=maxc[1]=1;
    while(poz>=1)
    {
        if(maxl[v[poz].L] || maxc[v[poz].C]){
            int maxx=max(maxl[v[poz].L],maxc[v[poz].C])+1;
            maxl[v[poz].L]=maxx;
            maxc[v[poz].C]=maxx;
            if(v[poz].L==n && v[poz].C==m)
            {
                g<<maxx;
                return 0;
            }
        }
        --poz;
    }
    return 0;
}
