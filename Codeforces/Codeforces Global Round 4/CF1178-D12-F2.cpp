#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

using namespace std;

typedef long long ll;

ll add(ll a, ll b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

int n, m, v[1000002], nr, xx;
int dp[1002][1002];

vector<int> c[1002];

int calc(int st, int dr)
{
    if(st > dr)
        return 1;
    if(dp[st][dr] != -1)
        return dp[st][dr];
    int mn = (1<<30);
    for(int i = st; i <= dr; ++i)
        if(v[i] < mn)
            mn = v[i];
    vector<int> vv = c[mn];
    if(vv[0] < st || vv.back() > dr)
        return 0;
    dp[st][dr] = 1;
    for(int i = 0; i + 1 < vv.size(); ++i)
        dp[st][dr] = mul(dp[st][dr], calc(vv[i]+1, vv[i+1]-1));
    ll sum = 0;
    for(int i = vv[0]; i >= st; --i)
        sum = add(sum, mul(calc(st, i-1), calc(i, vv[0]-1)));
    dp[st][dr] = mul(sum, dp[st][dr]);
    sum = 0;
    for(int i = vv.back(); i <= dr; ++i)
        sum = add(sum, mul(calc(vv.back()+1, i), calc(i+1, dr)));
    dp[st][dr] = mul(sum, dp[st][dr]);
    return dp[st][dr];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        cin >> nr;
        if(nr != v[xx])
            v[++xx] = nr;
    }
    m = xx;
    if(m > 2 * n)
        return cout << 0, 0;
    for(int i = 1; i <= m; ++i)
        c[v[i]].pb(i);
    memset(dp, -1, sizeof(dp));
    cout << calc(1, m);
    return 0;
}

