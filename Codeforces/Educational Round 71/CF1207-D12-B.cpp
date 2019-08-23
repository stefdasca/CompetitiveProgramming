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
int n, m;
int ma[52][52], mb[52][52];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> mb[i][j];
    vector<pair<int, int> >ans;
    for(int i = 1; i + 1 <= n; ++i)
        for(int j = 1; j + 1 <= m; ++j)
            if(mb[i][j] + mb[i+1][j] + mb[i][j+1] + mb[i+1][j+1] == 4)
                ans.pb({i, j}), ma[i][j] = ma[i+1][j] = ma[i][j+1] = ma[i+1][j+1] = 1;
    int rau = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(ma[i][j] != mb[i][j])
                rau = 1;
    if(rau)
        cout << -1;
    else
    {
        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i].fi << " " << ans[i].se << '\n';
    }
    return 0;
}

