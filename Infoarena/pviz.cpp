#include<bits/stdc++.h>
#define mod 10007
using namespace std;
ifstream fi("pviz.in");
ofstream fo("pviz.out");
int n, m, v[2002];
short dp[2002][2002];
int main()
{
    ios_base::sync_with_stdio(false);
    fi>>n>>m;
    for(int i=1; i<=m; ++i)
        fi>>v[i];
    dp[0][0]=1;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            dp[i][j]=(dp[i-1][j-1] + (v[j]-i+1)*dp[i-1][j])%mod;
    fo<<dp[n][m]<<'\n';
    return 0;
}
