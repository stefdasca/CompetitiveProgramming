#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

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

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(; t; --t)
    {
        int b, f, c;
        cin >> b >> f >> c;
        int pa, pb;
        cin >> pa >> pb;
        int ans = 0;
        while(f && c && b >= 2)
        {
            if(pa >= pb)
                ans += pa, --f, b -= 2;
            else
                ans += pb, --c, b -= 2;
        }
        while(f && b >= 2)
            ans += pa, --f, b -= 2;
        while(c && b >= 2)
            ans += pb, --c, b -= 2;
        cout << ans << '\n';
    }
    return 0;
}

