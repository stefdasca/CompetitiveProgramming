/*

    editorial = discuss.codechef.com/t/buying-editorial/957

*/
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

int t, n, m, k, v[50002], st[25], dr[25];
ll s[25][105], dp[25][105][25];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        cin >> n >> m >> k;
        for(int i = 1; i <= n; ++i)
            cin >> v[i];
        sort(v+1, v+n+1);
        ll ans = 0;
        for(int i = 1; i <= m; ++i)
            ans = ans + v[i];
        int max_size = 2 * k - 2;
        memset(s, 0, sizeof(s));
        for(int i = 0; i < k; ++i)
            st[i] = dr[i] = max_size;
        for(int i = m+1; i <= n; ++i)
        {
            int md = v[i] % k;
            if(dr[md] <= max_size + max_size)
                ++dr[md], s[md][dr[md]] = s[md][dr[md] - 1] + v[i];
        }
        for(int i = m; i >= 1; --i)
        {
            int md = v[i] % k;
            if(st[md] > 0)
                --st[md], s[md][st[md]] = s[md][st[md] + 1] - v[i];
        }
        for(int i = 0; i <= k; i++)
            for(int j = 0; j <= max_size * 2; j++)
                for (int p = 0; p < k; p++)
                    dp[i][j][p] = (1LL<<60);
        dp[0][max_size][ans % k] = 0;
        for(int i = 0; i < k; ++i)
            for(int j = 0; j <= max_size * 2; ++j)
                for(int p = 0; p < k; ++p)
                    for(int q = st[i]; q <= dr[i]; ++q)
                    {
                        int r = (p + (q - max_size) * i) % k;
                        if (r < 0)
                            r += k;
                        ll ft = dp[i][j][p] + s[i][q];
                        if (j + q - max_size >= 0 && j + q - max_size <= max_size * 2)
                            if (ft < dp[i + 1][j + q - max_size][r])
                                dp[i + 1][j + q - max_size][r] = ft;
                    }
        ans += dp[k][max_size][0];
        if(ans >= (1LL<<60))
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}
