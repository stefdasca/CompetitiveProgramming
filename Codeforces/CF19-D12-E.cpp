#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

using namespace std;

typedef long long ll;

ll add(ll a, ll b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

int n, m;

vector<pair<int, int> >v[10002];
int col[10002];
bool is_bipartite(int u, int p)
{
    bool ok = 1;
    for(int i = 0; i < v[u].size(); ++i)
    {
        pair<int, int> it = v[u][i];
        if(it.fi == p)
            continue;
        if(!col[it.fi])
        {
            col[it.fi] = (3 ^ col[u]);
            ok &= is_bipartite(it.fi, u);
        }
        if(col[it.fi] == col[u])
            ok = 0;
    }
    return ok;
}
int h[10002];
int bad = 0;
int edge[10002], dp[10002], dp2[10002];
vector <int> res, opt;
void dfs(int u, int p)
{
    for(int i = 0; i < v[u].size(); ++i)
    {
        pair<int, int> it = v[u][i];
        if(it.fi == p)
            continue;
        bool son = 0;
        if(h[it.fi] == 0)
        {
            son = 1;
            edge[it.fi] = it.se;
            h[it.fi] = h[u] + 1;
            dfs(it.fi, u);
            dp[u] += dp[it.fi];
            dp2[u] += dp2[it.fi];
        }
        else
            if(h[it.fi] > h[u] && col[it.fi] == col[u])
                --dp[u];
            else
            if(col[it.fi] == col[u])
            {
                dp[u]++;
                ++bad;
                opt.pb(it.se);
            }
        if(!son && h[it.fi] > h[u])
            dp2[u]--;
        else
            if(!son && h[it.fi] < h[u])
                dp2[u]++;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb({b, i});
        v[b].pb({a, i});
    }
    int rau = 0, id = 0;
    for(int i = 1; i <= n; ++i)
        if(!col[i])
        {
            col[i] = 1;
            if(!is_bipartite(i, 0))
                ++rau, id = i;
        }
    if(rau == 0)
    {
        cout << m << '\n';
        for(int i = 1; i <= m; ++i)
            cout << i << " ";
        return 0;
    }
    if(rau >= 2)
    {
        cout << 0;
        return 0;
    }
    h[id] = 1;
    dfs(id, 0);
    if(opt.size() == 1)
        res.pb(opt[0]);
    for(int i = 1; i <= n; ++i)
        if(dp[i] == bad && dp2[i] == bad)
            res.pb(edge[i]);
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    return 0;
}

