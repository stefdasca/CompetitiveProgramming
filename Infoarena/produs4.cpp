#include<bits/stdc++.h>
using namespace std;
ifstream f("produs4.in");
ofstream g("produs4.out");
int t,n,v[30002];
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        for(int i=1;i<=n;++i)
            f>>v[i];
        sort(v+1,v+n+1);
        long long prodmax=1ll*v[n]*v[n-1]*v[n-2];
        prodmax=max(prodmax,1ll*v[n]*v[1]*v[2]);
        g<<prodmax<<'\n';
    }
}
