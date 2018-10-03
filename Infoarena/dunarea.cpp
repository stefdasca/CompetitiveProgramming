#include<bits/stdc++.h>
using namespace std;
ifstream f("dunarea.in");
ofstream g("dunarea.out");
int a,b,n;
struct roads
{
    int s,e;
};
roads v[5002];
bool test(roads a, roads b)
{
    if(a.s==b.s)
        return a.e<b.e;
    return a.s<b.s;
}
int main()
{
    f>>a>>b>>n;
    for(int i=1;i<=n;++i)
        f>>v[i].s>>v[i].e;
    sort(v+1,v+n+1,test);
    int ps=a,pmx=0,sol=0,pz=1;
    while(ps<b)
    {
        ++sol;
        while(v[pz].s<=ps)
            pmx=max(pmx,v[pz].e),++pz;
        ps=pmx;
    }
    g<<sol;
    return 0;
}
