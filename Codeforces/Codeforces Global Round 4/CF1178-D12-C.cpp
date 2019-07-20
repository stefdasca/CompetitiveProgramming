#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

using namespace std;

typedef long long ll;

int n, m;
/*
ll dp[1002][1002][5];
ll s(int l, int c, int tp)
{
    if(i == 0)
}
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    /*
    dp[1][1][1] = dp[1][1][2] = dp[1][1][3] = dp[1][1][4] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(i == 1 && j == 1)
                continue;
            dp[i][j][1] = (s(i-1, j, 1) * s(i, j-1, 1)) % mod;
            dp[i][j][2] = (s(i-1, j, 2) * s(i, j-1, 2)) % mod;
            dp[i][j][3] = (s(i-1, j, 3) * s(i, j-1, 3)) % mod;
            dp[i][j][4] = (s(i-1, j, 4) * s(i, j-1, 4)) % mod;
        }
    ll ans = dp[n][m][1] + dp[n][m][2] + dp[n][m][3];
    cout << ans%mod;
    */
    ll ans = 4;
    for(int i = 2; i <= m; ++i)
        ans = (ans*2) % mod;
    for(int i = 2; i <= n; ++i)
        ans = (ans*2) % mod;
    cout << ans;
    return 0;
}

