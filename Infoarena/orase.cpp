#include<bits/stdc++.h>
using namespace std;
ifstream f("orase.in");
ofstream g("orase.out");
int n,m,maxd;
int max1;
struct streets
{
    int plc, nr;
};
streets v[50002];
bool test(streets a, streets b)
{
    return a.plc<b.plc;
}
int main()
{
    f>>m>>n;
    for(int i=1;i<=n;++i)
        f>>v[i].plc>>v[i].nr;
    sort(v+1,v+n+1,test);
    max1=v[n].nr;
    for(int i=n-1;i>=1;--i)
    {
        max1+=v[i+1].plc-v[i].plc;
        maxd=max(maxd,max1+v[i].nr);
        max1=max(max1,v[i].nr);
    }
    g<<maxd;
}
