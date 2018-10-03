#include<bits/stdc++.h>
using namespace std;
ifstream f("sir23.in");
ofstream g("sir23.out");
int n;
const int mod = 1000000;
int dp[1002][1002], x[1002][1002];
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        dp[1][i] = i, dp[2][i] = (1LL*i*i)%mod;
    for(int i = 3; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(j >= 2)
                x[i][j] = (x[i][j - 1] + dp[i - 2][j - 2])%mod;
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1] + dp[i - 2][j - 1] + x[i][j])%mod;
        }
    g << dp[n][n] << '\n';
    return 0;
}
