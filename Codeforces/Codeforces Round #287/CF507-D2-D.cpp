#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;

int p10[1002], n, k, mod, dp[1002][102][2];

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> mod;
    p10[0] = 1;
    for(int i = 1; i <= n; ++i)
        p10[i] = (p10[i-1] * 10) % k;
    for(int i = 0; i <= 9; ++i)
        dp[0][i%k][(i%k == 0 && i != 0)] = add(dp[0][i%k][(i%k == 0 && i != 0)], 1);
    for(int i = 0; i < n - 1; ++i)
        for(int rest = 0; rest < k; ++rest)
            for(int ok = 0; ok <= 1; ++ok)
            {
                if(ok == 0)
                {
                    for(int nextcif = 0; nextcif <= 9; nextcif++)
                    {
                        if(nextcif == 0)
                        {
                            if(i != n - 2)
                                dp[i + 1][rest][ok] = add(dp[i + 1][rest][ok], dp[i][rest][ok]);
                        }
                        else
                            dp[i + 1][(rest + p10[i+1] * nextcif) % k][((rest + p10[i+1] * nextcif) % k == 0)] = add(dp[i + 1][(rest + p10[i+1] * nextcif) % k][((rest + p10[i+1] * nextcif) % k == 0)], dp[i][rest][ok]);
                    }
                }
                else
                {
                    for(int nextcif = 0; nextcif <= 9; nextcif++)
                    {
                        if(nextcif == 0)
                        {
                            if(i != n - 2)
                                dp[i + 1][rest][ok] = add(dp[i + 1][rest][ok], dp[i][rest][ok]);
                        }
                        else
                            dp[i + 1][(rest + p10[i+1] * nextcif) % k][ok] = add(dp[i + 1][(rest + p10[i+1] * nextcif) % k][ok], dp[i][rest][ok]);
                    }
                }
            }
    ll ans = 0;
    for(int rest = 0; rest < k; ++rest)
        ans = add(ans, dp[n - 1][rest][1]);
    cout << ans%mod;
    return 0;
}
