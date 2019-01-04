/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
long long n, k;
long long modpow(long long b, long long e)
{
    long long ans = 1;
    while(e)
    {
        if(e & 1)
            ans = (ans * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
    }
    return ans;
}
long long dp[60], dp2[60];
long long mp[62];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    long long ans = 1;
    for(int j = 1; j <= 60; ++j)
        mp[j] = modpow(j, mod - 2);
    bool fi = 0;
    for(long long i = 2; i * i <= n; ++i)
        if(n % i == 0)
        {
            int qq = 0;
            while(n % i == 0)
                n /= i, ++qq;
            long long ans2 = 0;
            memset(dp, 0, sizeof(dp));
            memset(dp2, 0, sizeof(dp2));
            dp[qq] = 1;
            for(int j = 1; j <= k; ++j)
            {
                for(int a = 0; a <= qq; ++a)
                {
                    long long nr = (dp[a] * mp[a+1]) % mod;
                    for(int q = a; q >= 0; --q)
                    {
                        dp2[q] = (dp2[q] + nr);
                        if(dp2[q] >= mod)
                            dp2[q] -= mod;
                    }
                }
                for(int a = 0; a <= qq; ++a)
                    dp[a] = dp2[a], dp2[a] = 0;
            }
            long long pp = 1;
            for(int a = 0; a <= qq; ++a)
                ans2 += dp[a] * pp, ans2 %= mod, pp = (pp * i) % mod;
            ans = (ans * ans2) % mod;
        }
    if(n > 1)
    {
        memset(dp, 0, sizeof(dp));
        memset(dp2, 0, sizeof(dp2));
        dp[1] = 1;
        long long ans2 = 0;
        for(int j = 1; j <= k; ++j)
        {
            for(int a = 0; a <= 1; ++a)
            {
                if(!dp[a])
                    continue;
                long long nr = mp[a+1];
                nr = (dp[a] * nr) % mod;
                for(int q = a; q >= 0; --q)
                {
                    dp2[q] = (dp2[q] + nr);
                    if(dp2[q] >= mod)
                        dp2[q] -= mod;
                }
            }
            for(int a = 0; a <= 1; ++a)
                dp[a] = dp2[a], dp2[a] = 0;
        }
        long long pp = 1;
        for(int a = 0; a <= 1; ++a)
            ans2 += dp[a] * pp, ans2 %= mod, pp = (pp * n) % mod;
        ans = (ans * ans2) % mod;
    }
    cout << ans;
    return 0;
}

