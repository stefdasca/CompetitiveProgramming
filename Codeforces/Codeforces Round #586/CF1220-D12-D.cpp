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
int n;
ll v[200002];
vector<ll>vv[102];
bool pastr[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int max_size = 0;
    for(int i = 1; i <= n; ++i)
    {
        int nr = 0;
        ll val = v[i];
        while(val % 2 == 0)
            val /= 2, ++nr;
        vv[nr].pb(v[i]);
        if(vv[nr].size() > max_size)
            max_size = vv[nr].size();
    }
    for(int i = 0; i <= 100; ++i)
        if(vv[i].size() == max_size)
        {
            cout << n - max_size << '\n';
            for(int j = 0; j <= 100; ++j)
                if(j != i)
                    for(int q = 0; q < vv[j].size(); ++q)
                        cout << vv[j][q] << " ";
            return 0;
        }
    return 0;
}

