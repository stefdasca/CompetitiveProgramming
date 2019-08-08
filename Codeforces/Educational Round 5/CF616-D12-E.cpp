#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;


ll add(ll a, ll b)
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
    if(a >= mod)
        a %= mod;
    if(b >= mod)
        b %= mod;
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
ll n, m;
ll gauss(ll mx)
{
    return mul(mul(add(mx, 0), add(mx+1, 0)), 500000004);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    ll ans = 0;
    if(m >= n)
    {
        ans = ((m - n) % mod) * (n%mod);
        ans %= mod;
    }
    vector<ll>cat;
    for(ll i = 1; i * i <= n; ++i)
        cat.pb(i), cat.pb(n/i);
    sort(cat.begin(), cat.end());
    for(int i = cat.size() - 1; i >= 0; --i)
    {
        if(i + 1 < cat.size() && cat[i] == cat[i+1])
            continue;
        ll lst = min(m, n / cat[i]);
        ll lst2 = n / (cat[i] + 1);
        ans = add(ans, mul(lst - lst2, n));
        ans = add(ans, -mul(add(gauss(lst), -gauss(lst2)), cat[i]));
        if(lst == m)
            break;
    }
    cout << ans;
    return 0;
}

