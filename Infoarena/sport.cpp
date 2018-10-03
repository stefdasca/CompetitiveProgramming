#include<bits/stdc++.h>
using namespace std;
ifstream f("sport.in");
ofstream g("sport.out");
int sol,n;
struct vct
{
    int nr,poz;
};
vct v[1002];
bool test(vct a, vct b)
{
    if(a.nr==b.nr)
        return a.poz<b.poz;
    return a.nr<b.nr;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i].nr,v[i].poz=i;
    sort(v+1,v+n+1,test);
    int l=1,maxl=0;
    for(int i=2;i<=n;++i)
    {
        if(v[i].poz>v[i-1].poz)
            ++l;
        else
            l=1;
        maxl=max(maxl,l);
    }
    g<<n-maxl;
    return 0;
}
