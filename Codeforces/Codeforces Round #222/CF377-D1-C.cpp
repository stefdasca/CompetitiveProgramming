#include<bits/stdc++.h>
#define god dimasi5eks
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

int m, n, pwr[102], dp[(1<<20) - 1];

char ch[22];
int t[22];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> pwr[i];
    sort(pwr + 1, pwr + n + 1, greater<int>());
    cin >> m;
    for(int i = 1; i <= m; ++i)
        cin >> ch[m - i + 1] >> t[m - i + 1];
    n = m;
    for(int i = 1; i <= m; ++i)
    {
        char c;
        int te;
        c = ch[i];
        te = t[i];
        for(int j = (1<<n) - 1; j >= 0; --j)
        {
            if(te == 1)
            {
                for(int x = 0; x < n; ++x)
                {
                    if(j & (1<<x))
                        continue;
                    dp[j + (1<<x)] = max(dp[j + (1<<x)], dp[j] + (c == 'p') * pwr[x+1]);
                }
            }
            else
            {
                for(int x = 0; x < n; ++x)
                {
                    if(j & (1<<x))
                        continue;
                    dp[j + (1<<x)] = min(dp[j + (1<<x)], dp[j] - (c == 'p') * pwr[x+1]);
                }
            }
        }
    }
    cout << dp[(1<<n) - 1];
    return 0;
}
