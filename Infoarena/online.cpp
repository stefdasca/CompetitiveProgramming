#include<bits/stdc++.h>
using namespace std;
ifstream f("online.in");
ofstream g("online.out");
short n,dad[202],m,k;
struct muchii
{
    short a,b,c;
};
muchii v[10202];
muchii gut[202];
inline bool cmp(muchii a, muchii b)
{
    return a.c<b.c;
}
inline int arb(int nod)
{
    if(dad[nod]==nod)
        return nod;
    return dad[nod]=arb(dad[nod]);
}
inline void kruskal(int m)
{
    int j=0;
    int qq=0;
    if(m!=n)
        sort(v+1,v+m+1,cmp);
    for(int i=1;i<=n;++i)
        dad[i]=i;
    int cost=0;
    for(int i=1;i<=m && qq<n-1;++i)
    {
        int x=arb(v[i].a);
        int y=arb(v[i].b);
        if(x!=y)
        {
            dad[x]=y;
            ++qq;
            gut[qq]={v[i].a,v[i].b,v[i].c};
            j=i;
            cost+=v[i].c;
        }
    }
    g<<cost<<'\n';
    for(int i=1;i<n;++i)
        v[i]=gut[i];
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;++i)
        f>>v[i].a>>v[i].b>>v[i].c;
    f>>k;
    kruskal(m);
    for(int i=1;i<=k;++i)
    {
        f>>v[n].a>>v[n].b>>v[n].c;
        int z=n;
        while(v[z].c<v[z-1].c && z>=2)
            swap(v[z],v[z-1]),--z;
        kruskal(n);
    }
    return 0;
}
