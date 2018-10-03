#include<bits/stdc++.h>
using namespace std;
short n;
bool z[4002];
short gr[4002];
struct q1
{
    short st,sf,pb;
};
q1 v[4002];
q1 p[4002];
struct si
{
    short t,nr;
};
si v1[4002];
bool test(q1 a, q1 b)
{
    if(a.st==b.st)
        return a.sf<b.sf;
    return a.st<b.st;
}
bool test1(si a, si b)
{
    return a.t<b.t;
}
int main()
{
    ifstream f("motel.in");
    ofstream g("motel.out");
    f>>n;
    for(short i=1;i<=n;++i)
        f>>v[i].st>>v[i].sf,v[i].pb=i;
    for(short i=1;i<=n;++i)
        f>>v1[i].t,v1[i].nr=i;
    sort(v+1,v+n+1,test);
    sort(v1+1,v1+n+1,test1);
    for(short i=1;i<=n;++i)
    {
        short extm=31000;
        short poz=0;
        short l=0;
        for(short j=1;j<=n && v[j].st<=v1[i].t;++j)
            if(z[j]==0)
                if(v1[i].t<=v[j].sf && v[j].sf<extm)
                    extm=v[j].sf,poz=j;
        if(poz==0){
            g<<0<<" "<<0<<'\n';
            return 0;
        }
        else
            gr[v[poz].pb]=v1[i].nr,z[poz]=1;
    }
    for(short i=1;i<=n;++i)
        g<<i<<" "<<gr[i]<<'\n';
    return 0;
}
