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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int>v;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        v.push_back(nr);
    }
    vector<int>diff;
    for(int i = 0; i + 1 < n; ++i)
        diff.push_back(v[i+1] - v[i]);
    sort(diff.begin(), diff.end());
    long long ans = 0;
    int pz = 0;
    while(k < n)
    {
        ans += diff[pz];
        ++k;
        ++pz;
    }
    cout << ans;
    return 0;
}
