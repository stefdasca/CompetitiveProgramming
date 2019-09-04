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

ll n, b, g;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>b>>g>>n;
    if (b>n)
        b=n;
    if (g>n)
        g=n;
    ll pb=0,pf=n;
    pb=b+1;
    pf=n-g+1;
    cout<<abs(pb-pf+1);
    return 0;
}
