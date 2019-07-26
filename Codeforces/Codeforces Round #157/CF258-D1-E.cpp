#include<bits/stdc++.h>
#pragma GCC optimize("O3")
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
vector<int>qu[100002], v[100002];
pair<int, int> p[100002];
int ans[100002];

int st[100002], dr[100002], pz, sz[100002];

set<int>s;
int nnd[100002];

void dfs(int dad, int nod)
{
    ++pz;
    st[nod] = pz;
    nnd[st[nod]] = nod;
    sz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        sz[nod] += sz[vecin];
    }
    dr[nod] = pz;
}
int aint[400002], aint2[800002];
void upd(int nod, int st, int dr, int L, int R, int val)
{
    if(L <= st && dr <= R)
        aint[nod] += val;
    else
    {
        int mid = (st + dr) / 2;
        if(L <= mid)
            upd(nod << 1, st, mid, L, R, val);
        if(mid < R)
            upd(nod << 1|1, mid+1, dr, L, R, val);
    }
    if(aint[nod])
        aint2[nod] = dr - st + 1;
    else
        aint2[nod] = aint2[nod << 1] + aint2[nod << 1|1];
}
void dfs2(int dad, int nod)
{
    if(!qu[nod].empty())
        upd(1, 1, n, st[nod], dr[nod], 1);
    for(int i = 0; i < qu[nod].size(); ++i)
        upd(1, 1, n, st[qu[nod][i]], dr[qu[nod][i]], 1);
    ans[nod] = max(0, aint2[1] - 1);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs2(nod, vecin);
    }
    for(int i = 0; i < qu[nod].size(); ++i)
        upd(1, 1, n, st[qu[nod][i]], dr[qu[nod][i]], -1);
    if(!qu[nod].empty())
        upd(1, 1, n, st[nod], dr[nod], -1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0, 1);
    for(int i = 1; i <= m; ++i)
    {
        cin >> p[i].fi >> p[i].se;
        qu[p[i].fi].pb(p[i].se);
        qu[p[i].se].pb(p[i].fi);
    }
    dfs2(0, 1);
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    return 0;
}
