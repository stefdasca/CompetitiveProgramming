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

ll n, inten;
ll v[400002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> inten;
    inten = inten * 8;
    inten /= n;
    inten = min(inten, 40LL);
    inten = (1LL<<inten);
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    int st = 1;
    int dr = 1;
    int ctd = 1;
    ll anss = n-1;
    while(dr < n)
    {
        ++dr;
        if(v[dr] > v[dr-1])
            ++ctd;
        while(ctd > inten)
        {
            if(v[st+1] > v[st])
                --ctd;
            ++st;
        }
        anss = min(anss, n - (dr - st + 1));
    }
    cout << anss;
    return 0;
}

