#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
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

int n, k;

pair<int, int> dist[100002];
vector<int> nd[100002];

int grad[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> dist[i].fi, dist[i].se = i;
    sort(dist + 1, dist + n + 1);
    if(dist[2].fi == 0)
    {
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= n; ++i)
        nd[dist[i].fi].pb(dist[i].se);
    vector<pair<int, int> >ans;
    for(int i = 0; i <= n; ++i)
    {
        ll sg = 0;
        for(int j = 0; j < nd[i].size(); ++j)
            sg += (k - grad[nd[i][j]]);
        if(sg < nd[i+1].size())
        {
            cout << -1;
            return 0;
        }
        int pz = 0;
        for(int j = 0; j < nd[i].size(); ++j)
        {
            while(pz < nd[i+1].size() && grad[nd[i][j]] < k)
            {
                ++grad[nd[i][j]];
                ++grad[nd[i+1][pz]];
                ans.pb({nd[i][j], nd[i+1][pz]});
                ++pz;
            }
        }
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i].fi << " " << ans[i].se << '\n';
    return 0;
}
