#include<bits/stdc++.h>
#define half_rose 45000
#define mod 10000
using namespace std;
ifstream f("diamant.in");
ofstream g("diamant.out");
int n,m,s;
int v[2*half_rose],v2[2*half_rose];
int main()
{
    f>>n>>m>>s;
    int SMAX=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            SMAX+=i*j;
    if(abs(s)>SMAX)
        g<<0;
    else{
        v[half_rose]=1;
        SMAX=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                for(int a=half_rose-SMAX;a<=half_rose+SMAX;++a){
                    v2[a+i*j]=(v2[a+i*j]+v[a])%mod;
                    v2[a-i*j]=(v2[a-i*j]+v[a])%mod;
                    v2[a]=(v2[a]+v[a])%mod;
                }
                SMAX+=i*j;
                for(int a=half_rose-SMAX;a<=half_rose+SMAX;++a)
                    v[a]=v2[a],v2[a]=0;
            }
        g<<v[s+half_rose]<<'\n';
    }
    return 0;
}
