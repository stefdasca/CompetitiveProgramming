#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll l, h;
    cin >> h >> l;
    ll x = l * l - h * h;
    double ans = x / (0.0000 + h);
    ans = ans * 0.50000000;
    cout << fixed << setprecision(12) << ans << '\n';
    return 0;
}

