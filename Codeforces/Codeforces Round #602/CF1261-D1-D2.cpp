#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pi 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;

const int mod = 998244353;

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

int n, k, v[200002];

int nxt(int poz)
{
    if(poz == n)
        return 1;
    return poz + 1;
}

ll fact[200002], inv[200002];
ll C(ll n, ll k)
{
    ll ans = (fact[n] * inv[k]) % mod;
    ans = (ans * inv[n-k]) % mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        fact[i] = (fact[i-1] * i) % mod;
        inv[i] = pw(fact[i], mod - 2);
    }
    int eq = 0;
    for(int i = 1; i <= n; ++i)
        if(v[i] == v[nxt(i)])
            ++eq;
    ll ans = 1;
    for(int i = 1; i <= eq; ++i)
        ans = (ans * k) % mod;
    n -= eq;
    ll ans2 = 0;
    for(int i = 1; i <= n; ++i)
    {
        ll total = (pw(k-2, n - i) * C(n, n - i)) % mod;
        ll totalcomb = pw(2, i);
        ll comb2 = 0;
        if(i % 2 == 0)
            comb2 = C(i, i/2);
        totalcomb = totalcomb - comb2 + mod;
        totalcomb %= mod;
        totalcomb = (totalcomb * pw(2, mod - 2)) % mod;
        total *= totalcomb;
        total %= mod;
        ans2 = (ans2 + total) % mod;
    }
    cout << (ans * ans2) % mod;
    return 0;
}
