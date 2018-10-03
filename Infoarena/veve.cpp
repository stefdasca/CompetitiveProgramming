/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("veve.in");
ofstream g("veve.out");
int k;
int r,m,n,smax,ss;
struct posloc
{
    int x,y,nr;
};
posloc sedii[22];
posloc trees[102];
int v[12];
int d[22][102];
int dist(int i, int j)
{
    return (trees[i].x-sedii[j].x)*(trees[i].x-sedii[j].x)+(trees[i].y-sedii[j].y)*(trees[i].y-sedii[j].y);
}
void comb(int q)
{
    if(smax==ss)
        return;
    if(k==q)
    {
        int s=0;
        for(int i=1;i<=n;++i)
        {
            bool gut=0;
            for(int j=1;!gut && j<=k;++j)
                if(d[v[j]][i]<=r*r)
                    gut=1;
            if(gut)
                s+=trees[i].nr;
        }
        smax=max(smax,s);
        return;
    }
    else
        for(int i=v[q]+1;i<=m;++i)
        {
            v[q+1]=i;
            comb(q+1);
        }
}
int main()
{
    f>>k>>r;
    f>>m;
    for(int i=1;i<=m;++i)
        f>>sedii[i].x>>sedii[i].y;
    f>>n;
    for(int i=1;i<=n;++i)
        f>>trees[i].x>>trees[i].y>>trees[i].nr,ss+=trees[i].nr;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            d[i][j]=dist(j,i);
    comb(0);
    g<<smax;
    return 0;
}
