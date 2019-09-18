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
int n, a[1002][1002], val[1002];
bool tri(int nr)
{
    val[1] = nr;
    for(int i = 2; i <= n; ++i)
    {
        if(a[1][i] % nr != 0)
            return 0;
        val[i] = a[1][i] / nr;
    }
    for(int i = 2; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(i == j)
                continue;
            ll prod = 1LL * val[i] * val[j];
            if(prod != a[i][j])
                return 0;
        }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    for(int i = 1; i * i <= a[1][2]; ++i)
    {
        if(a[1][2] % i == 0)
        {
            if(tri(i))
            {
                cout << i << " ";
                for(int j = 2; j <= n; ++j)
                    cout << a[1][j] / i << " ";
                return 0;
            }
            if(tri(a[1][2] / i))
            {
                cout << a[1][2] / i << " ";
                for(int j = 2; j <= n; ++j)
                    cout << a[1][j] / (a[1][2] / i) << " ";
            }
        }
    }
    return 0;
}

