#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

struct mch
{
    int a, b, c, pi;
};
mch v[500002];

bool cmp(mch a, mch b)
{
    return a.c < b.c;
}
bool cmp2(mch a, mch b)
{
    return a.pi < b.pi;
}

bool rau[500002];

int tt[500002], sz[500002], viz[500002];

pair<int, int> color[500002];

vector<int> vv[500002];

int Find(int nod)
{
    if(tt[nod] == nod)
        return nod;
    return tt[nod] = Find(tt[nod]);
}

void Union(int a, int b)
{
    if(a == b)
        return;
    if(sz[a] >= sz[b])
        sz[a] += sz[b], tt[b] = a;
    else
        sz[b] += sz[a], tt[a] = b;
}

bool ok;
int cr;

void dfs(int nod, int tt)
{
    if(viz[nod] == cr)
    {
        ok = 0;
        return;
    }
    viz[nod] = cr;
    for(int i = 0; i < vv[nod].size(); ++i)
    {
        int vecin = vv[nod][i];
        if(vecin != tt)
            dfs(vecin, nod);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        cin >> v[i].a >> v[i].b >> v[i].c;
        v[i].pi = i;
    }
    sort(v + 1, v + m + 1, cmp);
    for(int i = 1; i <= n; ++i)
        tt[i] = i, sz[i] = 1;
    for(int i = 1; i <= m; )
    {
        vector<int> pz;
        int j = i;
        while(j <= m && v[j].c == v[i].c)
            pz.pb(j++);
        for(int j = 0; j < pz.size(); ++j)
        {
            int vx = pz[j];
            if(Find(v[vx].a) == Find(v[vx].b))
                rau[v[vx].pi] = 1;
            else
                color[v[vx].pi] = {min(Find(v[vx].a), Find(v[vx].b)), max(Find(v[vx].b), Find(v[vx].a))};
        }
        for(int j = 0; j < pz.size(); ++j)
        {
            int vx = pz[j];
            if(Find(v[vx].a) != Find(v[vx].b))
                Union(Find(v[vx].a), Find(v[vx].b));
        }
        i = j;
    }
    sort(v + 1, v + m + 1, cmp2);
    int q;
    cin >> q;
    for(; q; --q)
    {
        int szz;
        cin >> szz;
        ok = 1;
        vector<int> mx;
        vector<pair<int, int> >bd;
        for(int i = 1; i <= szz; ++i)
        {
            int nr;
            cin >> nr;
            if(rau[nr])
                ok = 0;
            else
            {
                bd.pb({v[nr].c, color[nr].fi});
                bd.pb({v[nr].c, color[nr].se});
                vv[color[nr].fi].pb(color[nr].se);
                vv[color[nr].se].pb(color[nr].fi);
            }
        }
        sort(bd.begin(), bd.end());
        cr = q;
        for(int x = 0; x < bd.size(); ++x)
        {
            if(viz[bd[x].se] == q)
                continue;
            dfs(bd[x].se, 0);
        }
        for(int i = 0; i < bd.size(); ++i)
            vv[bd[i].se].clear();
        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
