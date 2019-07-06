#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;

typedef long long ll;

ll lgput(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
ll fact[210002], inv[210002];
set<int>sL, sC;
int h, w, n;
ll dp[2002];
ll comb(ll n, ll k)
{
    ll ans = fact[n] * inv[k];
    ans %= mod;
    ans *= inv[n-k];
    ans %= mod;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w >> n;
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= 210000; ++i)
    {
        fact[i] = (fact[i-1] * i) % mod;
        inv[i] = lgput(fact[i], mod - 2);
    }
    pair<int, int> v[5002];
    for(int i = 1; i <= n; ++i)
        cin >> v[i].first >> v[i].second;
    ++n;
    v[n].first = h, v[n].second = w;
    sort(v+1, v+n+1);
    set<int> ::iterator it;
    for(int i = 1; i <= n; ++i)
    {
        dp[i] = comb(v[i].first + v[i].second - 2, v[i].second - 1);
        for(int j = 1; j < i; ++j)
            if(v[i].first >= v[j].first && v[i].second >= v[j].second)
                dp[i] = (dp[i] + mod - (dp[j] * comb(v[i].first - v[j].first + v[i].second - v[j].second, v[i].first - v[j].first) % mod)) % mod;
    }
    cout << dp[n] << '\n';
    return 0;
}
