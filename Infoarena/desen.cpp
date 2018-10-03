/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("desen.in");
ofstream g("desen.out");
int n;
int t[1002];
int nred=0;
struct points
{
    double a,b;
};
points Rosa[1002];
struct muchii
{
    int a,b;
    int c;
};
muchii v[1000002];
inline bool cmp(muchii a, muchii b)
{
    return a.c<b.c;
}
inline int arb(int x)
{
    if(t[x]==x)
        return x;
    else
        return t[x]=arb(t[x]);
}
inline int dist(int a, int b)
{
    return (Rosa[a].a-Rosa[b].a)*(Rosa[a].a-Rosa[b].a) + (Rosa[a].b-Rosa[b].b)*(Rosa[a].b-Rosa[b].b);
}
inline double kruskal(int nn)
{
    for(int j=1;j<=nn;++j)
        t[j]=j;
    sort(v+1,v+nred+1,cmp);
    int j=0;
    int u=0;
    double s=0.000000;
    for(int i=1;i<=nred && j<nn;++i){
        int x=arb(v[i].a);
        int y=arb(v[i].b);
        if(x!=y)
        {
            ++j;
            u=i;
            t[x]=y;
            s+=sqrt(v[i].c);
        }
        else
            v[i].c=5e6;
    }
    nred=u;
    return s;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>Rosa[i].a>>Rosa[i].b;
        for(int j=1;j<i;++j)
        {
            v[++nred].a=j;
            v[nred].b=i;
            v[nred].c=dist(i,j);
        }
        g<<fixed<<setprecision(6)<<kruskal(i)<<'\n';
    }
    return 0;
}
