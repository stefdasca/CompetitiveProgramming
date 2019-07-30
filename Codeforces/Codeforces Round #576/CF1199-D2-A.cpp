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
int n, x, y;
int v[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i <= n; ++i)
    {
        int mn = v[i];
        for(int j = i - x; j <= i + y; ++j)
            if(1 <= j && j <= n)
                mn = min(mn, v[j]);
        if(mn == v[i])
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}

