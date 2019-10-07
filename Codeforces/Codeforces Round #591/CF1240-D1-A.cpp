#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int t;

ll n, v[200002], x, y, k, a, b;

ll cmmdc(ll a, ll b)
{
    ll c;
    while(b)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}
bool can(ll poz)
{
    ll cateamandoua = poz / (a / cmmdc(a, b) * b);
    ll cateuna = poz / a - cateamandoua;
    ll catedoua = poz / b - cateamandoua;
    int pz = n;
    ll rms = k;
    while(cateamandoua)
    {
        rms = rms - 1LL * (x + y) * v[pz];
        if(rms <= 0)
            return 1;
        --pz;
        --cateamandoua;
    }
    if(x >= y)
    {
        while(cateuna)
        {
            rms = rms - 1LL * x * v[pz];
            if(rms <= 0)
                return 1;
            --pz;
            --cateuna;
        }
        while(catedoua)
        {
            rms = rms - 1LL * y * v[pz];
            if(rms <= 0)
                return 1;
            --pz;
            --catedoua;
        }
    }
    else
    {
        while(catedoua)
        {
            rms = rms - 1LL * y * v[pz];
            if(rms <= 0)
                return 1;
            --pz;
            --catedoua;
        }
        while(cateuna)
        {
            rms = rms - 1LL * x * v[pz];
            if(rms <= 0)
                return 1;
            --pz;
            --cateuna;
        }
    }
    if(rms <= 0)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> v[i], v[i] /= 100;
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;
        sort(v+1, v+n+1);
        int st = 1;
        int dr = n;
        int ans = -1;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(can(mid))
                ans = mid, dr = mid - 1;
            else
                st = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
