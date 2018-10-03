#include<bits/stdc++.h>
using namespace std;
ifstream f("teamwork.in");
ofstream g("teamwork.out");
int n;
long long v[1000002],prefix[1000002],sumi[1000002],suma[1000002],st[1000002],sz;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i],prefix[i]=prefix[i-1]+v[i];
    v[n+1]=998244353;
    long long sol=-(1LL<<60);
    for(int i=1;i<=n+1;++i)
    {
        sumi[i]=prefix[i-1];
        suma[i]=prefix[i-1];
        for (;sz && v[i]>=v[st[sz]];)
        {
            if(v[st[sz]]>=0)
                sol=max(sol,v[st[sz]]*(suma[i] - sumi[st[sz]]));
            else
                sol=max(sol,v[st[sz]]*(sumi[i] - suma[st[sz]]));
            sumi[i]=min(sumi[st[sz]],sumi[i]);
            suma[i]=max(suma[st[sz]],suma[i]);
            --sz;
        }
        if(i<=n)
            st[++sz]=i;
    }
    g<<sol<<'\n';
    return 0;
}
