#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

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

ll n, s, am[25], inv[25], fact[25];

ll C(ll n, ll k)
{
    n %= mod;
    ll ans = inv[k];
    for(int i = n - k + 1; i <= n; ++i)
        ans = mul(ans, i);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= 22; ++i)
    {
        fact[i] = mul(fact[i-1], i);
        inv[i] = pw(fact[i], mod - 2);
    }
    for(int i = 0; i < n; ++i)
        cin >> am[i];
    ll ans = 0;
    for(int i = 0; i < (1<<n); ++i)
    {
        ll x = s;
        int total = 0;
        for(int j = 0; j < n; ++j)
            if(i & (1<<j))
            {
                x -= (am[j] + 1);
                total ^= 1;
            }
        if(x < 0)
            continue;
        ll va = C(x + n - 1, n - 1);
        if(total == 0)
            ans = add(ans, va);
        else
            ans = add(ans, -va);
    }
    cout << ans;
    return 0;
}
