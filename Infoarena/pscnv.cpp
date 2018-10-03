#include <bits/stdc++.h>
using namespace std;
ifstream f("pscnv.in");
ofstream g("pscnv.out");
struct pt
{
    int x,y,c;
}v[1<<19];
int i,n,m,x,y,G[1<<19];
bool cmp(pt a,pt b)
{
    return a.c<b.c;
}
int gr(int i)
{
    if(i!=G[i])
        G[i]=gr(G[i]);
    return G[i];
}
int main()
{
    f>>n>>m>>x>>y;
    for(i=1;i<=m;++i)
        f>>v[i].x>>v[i].y>>v[i].c;
    sort(v+1,v+m+1,cmp);
    for(i=1;i<=n;++i)
        G[i]=i;
    for(i=1;i<=m;++i)
    {
        if(gr(v[i].x)!=gr(v[i].y))
            G[v[i].x]=v[i].y;
        if(gr(x)==gr(y))
        {
            g<<v[i].c;
            return 0;
        }
    }
}
