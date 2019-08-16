#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int n, m, k;
ll dp[302][302];
ll mini[302][302];
vector<pair<int, int> >v[302];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(mini[a][b] == 0 || c < mini[a][b])
            mini[a][b] = c;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(mini[i][j] != 0)
                v[i].pb({j, mini[i][j]});
    for(int i = 0; i <= n+1; ++i)
        for(int j = 1; j <= n+1; ++j)
            dp[i][j] = (1LL<<60);
    ll ans = (1LL<<60);
    for(int i = 1; i <= n; ++i)
    {
        if(i != 1)
            for(int j = 1; j <= i; ++j)
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
        for(int j = i-1; j >= 1; --j)
            dp[i][j] = min(dp[i][j], dp[i][j+1]);
        for(int a = 0; a <= i; ++a)
        {
            if(dp[i-1][a] >= ans)
                continue;
            for(int j = 0; j < v[i].size(); ++j)
            {
                if(dp[i-1][a] + v[i][j].se >= ans)
                    continue;
                for(int sf = i; a + sf - i + 1 <= k && sf <= v[i][j].fi; ++sf)
                    dp[sf][a + sf - i + 1] = min(dp[sf][a + sf - i + 1], dp[i-1][a] + v[i][j].se);
            }
        }
        if(i >= k)
            ans = min(ans, dp[i][k]);
    }
    if(ans == (1LL<<60))
        cout << -1;
    else
        cout << ans;
    return 0;
}
