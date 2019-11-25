#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

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

int n, v[1002];
int ans[1005][1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int start = 0;
    for(int val = n; val >= 1; --val)
    {
        for(int i = 1; i <= n; ++i)
            if(v[i] == val)
            {
                for(int x = 1; x <= v[i]; ++x)
                    ans[(start + x) % (n+1) + 1][i] = 1;
                ++start;
            }
    }
    cout << n+1 << '\n';
    for(int i = 1; i <= n+1; cout << '\n', ++i)
        for(int j = 1; j <= n; ++j)
            cout << ans[i][j];
    return 0;
}
