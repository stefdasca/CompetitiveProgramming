#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

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

int bts[(1<<18)];

bool viz[20][(1<<18)];
long double dp[20][(1<<18)], ans[20][102], x;
long double solve(int sz, int msk)
{
    if(bts[msk] >= sz)
        return 0;
    if(viz[sz][msk])
        return dp[sz][msk];
    dp[sz][msk] = 0;
    viz[sz][msk] = 1;
    int new_mask = msk + 1;
    dp[sz][msk] = (1.00000 - x) * (solve(sz, new_mask) + 2 * ((msk ^ new_mask)-1));
    if(msk & 1)
        dp[sz][msk] += x * (solve(sz - bts[msk], 2));
    else
    {
        new_mask = msk + 2;
        dp[sz][msk] += x * (solve(sz, new_mask) + 2 * ((msk ^ new_mask) - 2));
    }
    return dp[sz][msk];
}
void run()
{
    for(int i = 0; i <= 100; ++i)
    {
        x = 0.01 * i;
        memset(viz, 0, sizeof(viz));
        for(int n = 1; n <= 16; ++n)
        {
            for(int j = (1<<(n+1)) - 1; j; j--)
                solve(n, j);
            ans[n][i] = solve(n, 0);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < (1<<18); ++i)
        bts[i] = __builtin_popcount(i);
    run();
    int t;
    cin >> t;
    for(; t; --t)
    {
        int n, p;
        cin >> n >> p;
        cout << fixed << setprecision(10) << ans[n][p] << '\n';
    }
    return 0;
}
