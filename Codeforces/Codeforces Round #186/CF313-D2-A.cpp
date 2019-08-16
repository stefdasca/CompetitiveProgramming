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
    int n;
    cin >> n;
    if(n >= 0)
        cout << n;
    else
    {
        n = -n;
        int a = n%10;
        n /= 10;
        int b = n%10;
        n -= b;
        if(a <= b)
            n += a;
        else
            n += b;
        if(n == 0)
            cout << 0;
        else
            cout << "-" << n;
    }
    return 0;
}
