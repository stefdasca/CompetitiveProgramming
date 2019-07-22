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

int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        int n;
        cin >> n;
        vector<int>v;
        for(int i = 0; i < n; ++i)
        {
            int nr;
            cin >> nr;
            v.pb(nr);
        }
        sort(v.begin(), v.end());
        cout << min(n - 2, min(v.back(), v[v.size() - 2]) - 1) << '\n';
    }
    return 0;

}
