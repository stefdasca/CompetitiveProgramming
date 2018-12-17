/// be happy!

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 998244353
using namespace std;
long long n, m, k, dp[2002][2002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    dp[1][0] = m;
    for(int i = 1; i < n; ++i)
        for(int j = 0; j < i; ++j)
        {
            dp[i+1][j+1] = (dp[i+1][j+1] + (m-1) * dp[i][j]) % mod;
            dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
        }
    cout << dp[n][k];
    return 0;
}

