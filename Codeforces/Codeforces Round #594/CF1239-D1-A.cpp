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
int n, m, fib[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 2;
    for(int i = 3; i <= 100000; ++i)
        fib[i] = (fib[i - 1] + fib[i-2]) % mod;
    int ans = fib[n];
    for(int i = 2; i <= m; ++i)
        ans = (ans + fib[i-2]) % mod;
    cout << (2 * ans) % mod;
    return 0;
}
