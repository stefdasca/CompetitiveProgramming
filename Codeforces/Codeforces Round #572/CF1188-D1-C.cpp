#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 998244353
using namespace std;

typedef long long ll;

int n, k;
int v[1002];

int dp[1002][1002];
int ans[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    ll sol = 0;
    int sum = 0;
    for(int p = 1; p <= n; ++p)
        dp[p][1] = p;
    for(int i = 100000 / (k - 1); i >= 1; --i)
    {
        for(int j = 2; j <= k; ++j)
        {
            int lp = 1;
            for(int p = 1; p <= n; ++p)
            {
                while(v[p] - v[lp] >= i)
                    ++lp;
                dp[p][j] = dp[lp-1][j-1];
                dp[p][j] += dp[p-1][j];
                if(dp[p][j] >= mod)
                    dp[p][j] -= mod;
            }
        }
        ans[i] = (dp[n][k] - sum + mod);
        if(ans[i] >= mod)
            ans[i] -= mod;
        sol += 1LL * i * ans[i];
        sol %= mod;
        sum += ans[i];
        if(sum >= mod)
            sum -= mod;
    }
    cout << sol << '\n';
    return 0;
}
