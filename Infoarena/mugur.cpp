#include<bits/stdc++.h>
#define mod 123457
using namespace std;
ifstream f("mugur.in");
ofstream g("mugur.out");
int n,k;
int dp[502][502];
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        dp[i][i]=1;
    dp[2][1]=1;
    for(int i=3;i<=n;++i)
        for(int j=i-1;j>=1;--j)
            dp[i][j]=(dp[i][j+1]+dp[i-1][j-1])%mod;
    g<<dp[n][k]<<" ";
    return 0;
}
