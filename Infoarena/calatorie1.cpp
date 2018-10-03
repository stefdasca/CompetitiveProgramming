#include<bits/stdc++.h>
#define mod 997
using namespace std;
ifstream f("calatorie1.in");
ofstream g("calatorie1.out");
int x,k;
bool bad[50002];
int dp[50002];
int cat[50002];
int m;
int main()
{
    f>>x>>k;
    f>>m;
    k-=k&1;
    for(int i=1;i<=m;++i)
    {
        int nr;
        f>>nr;
        bad[nr]=1;
    }
    cat[0]=1;
    for(int i=1;i<=k;++i)
        for(int j=0;j<i;++j)
            cat[i]=(cat[i]+cat[j]*cat[i-j-1])%mod;
    dp[0]=1;
    for(int i=1;i<=x;++i)
        if(!bad[i])
            for(int j=i-1;j>=i-k/2 && j>=0;--j)
                if(!bad[j])
                    dp[i]=(dp[i]+2*dp[j]*cat[i-j-1])%mod;
    g<<dp[x]<<'\n';
    return 0;
}
