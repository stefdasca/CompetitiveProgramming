/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define mod 666013
using namespace std;
ifstream f("nr.in");
ofstream g("nr.out");
int n,b;
int dp[3][1002];
int sumpard[1002];
int sumpars[1002];
int main()
{
    f>>n>>b;
    for(int i=0;i<b;++i)
        dp[1][i]=(i*(i+1)/2+(b-1-i)*i)%mod;
    for(int i=b-1;i>=0;--i)
        sumpard[i]=(dp[1][i]+sumpard[i+1])%mod;
    for(int i=1;i<=b-1;++i)
        sumpars[i]=(dp[1][i]*i+sumpars[i-1])%mod;
    int q=1;
    for(int i=3;i<=n;++i)
    {
        q=3-q;
        for(int j=0;j<b;++j)
            dp[q][j]=(sumpars[j-1]+j*sumpard[j])%mod;
        for(int i=b-1;i>=0;--i)
            sumpard[i]=(dp[q][i]+sumpard[i+1])%mod;
        for(int i=1;i<=b-1;++i)
            sumpars[i]=(dp[q][i]*i+sumpars[i-1])%mod;
        /// calcule
    }
    int s=0;
    for(int i=0;i<b;++i)
        s=(s+dp[q][i])%mod;
    g<<s;
    return 0;
}
