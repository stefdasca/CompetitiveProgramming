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

long long v[300002], sp[300002], n, m, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;

    long long ans = 0;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int mo = 0; mo < m; ++mo)
    {
        long long mn = 0;
        for(int i = 1; i <= n; ++i)
        {
            sp[i] = v[i] + sp[i-1];
            if(i % m == mo)
            {
                sp[i] -= k;
                ans = max(ans, sp[i] - mn);
            }
            mn = min(mn, sp[i]);
        }
    }
    cout << ans;
    return 0;
}
