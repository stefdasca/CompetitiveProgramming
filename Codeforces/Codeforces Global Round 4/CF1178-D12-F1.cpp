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

int n, m, v[502];
int dp[502][502];
int calc(int st, int dr)
{
    if(st > dr)
        return 1;
    if(dp[st][dr] != -1)
        return dp[st][dr];
    ll sum = 0;
    int mn = (1<<30), pz = 0;
    for(int i = st; i <= dr; ++i)
        if(v[i] < mn)
            mn = v[i], pz = i;
    sum = calc(pz+1, dr);
    for(int i = pz+1; i <= dr; ++i)
        sum = add(sum, mul(calc(pz+1, i-1), calc(i, dr)));
    dp[st][dr] = mul(sum, calc(st, pz-1));
    for(int i = st; i < pz; ++i)
        dp[st][dr] = add(dp[st][dr], mul(sum, mul(calc(st, i), calc(i+1, pz-1))));
    return dp[st][dr];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
        cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << calc(1, n);
    return 0;
}

