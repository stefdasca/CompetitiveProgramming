#include<bits/stdc++.h>
using namespace std;
ifstream f("poligoane.in");
ofstream g("poligoane.out");
long long t,n,mod,v[2002];
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n>>mod;
        memset(v,0,sizeof(v));
        for(int i=3;i<=n;++i)
        {
            v[i]++;
            for(int j=3;j<=n-i;++j){
                v[i+j]+=v[j];
                if(v[i+j]>=mod)
                    v[i+j]-=mod;
            }
            v[i]%=mod;
        }
        g<<v[n]%mod<<'\n';
    }
    return 0;
}
