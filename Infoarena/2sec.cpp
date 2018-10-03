#include<bits/stdc++.h>
using namespace std;
ifstream f("2sec.in");
ofstream g("2sec.out");
int n,v[1000002];
int smin[1000002],smax[1000002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i],smin[i]=v[i],smax[i]=v[i];
    for(int i=2;i<=n;++i)
        smin[i]=min(smin[i],smin[i-1]+v[i]);
    for(int i=n-1;i>=1;--i)
        smax[i]=max(smax[i],smax[i+1]+v[i]);
    int dmax=smax[2]-smin[1];
    for(int i=2;i<n;++i)
        dmax=max(dmax,smax[i+1]-smin[i]);
    g<<dmax;
}
