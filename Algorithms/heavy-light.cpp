// https://www.infoarena.ro/problema/heavypath
#include<bits/stdc++.h>
using namespace std;
ifstream f("heavypath.in");
ofstream g("heavypath.out");
// for HLD
int n, m, v[100002], aint[500002], nrp = 1, path[100002], pos[100002], tt[100002], subtree[100002], lft[100002], pz;
vector<int>tree[100002], paths[100002];
/// LCA w/ Euler Tour + segtree
int p, euler[200002], aint2[800002], niv[100002], lst[100002];
void dfs1(int dad, int nod)
{
    euler[++p] = nod;
    subtree[nod] = 1;
    for(int i = 0; i < tree[nod].size(); ++i)
    {
        int vecin = tree[nod][i];
        if(vecin == dad)
            continue;
        niv[vecin] = niv[nod] + 1;
        dfs1(nod, vecin);
        subtree[nod] += subtree[vecin];
        euler[++p] = nod;
    }
    lst[nod] = p;
}
void buildlca(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint2[nod] = st;
        return;
    }
    int mid = (st + dr) / 2;
    buildlca(nod << 1, st, mid);
    buildlca(nod << 1|1, mid + 1, dr);
    if(niv[euler[aint2[nod << 1]]] <= niv[euler[aint2[nod << 1|1]]])
        aint2[nod] = aint2[nod << 1];
    else
        aint2[nod] = aint2[nod << 1|1];
}
int ana = -1;
void querylca(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        if(ana == -1)
            ana = aint2[nod];
        else
            if(niv[euler[ana]] > niv[euler[aint2[nod]]])
                ana = aint2[nod];
        return;
    }
    int mid = (st + dr) / 2;
    querylca(nod << 1, st, mid, L, R);
    querylca(nod << 1|1, mid + 1, dr, L, R);
}
/// HLD
void dfs(int dad, int nod, int cr)
{
    path[nod] = cr;
    tt[nod] = dad;
    paths[cr].push_back(nod);
    pos[nod] = paths[cr].size() - 1;
    int mx = -1;
    for(int i = 0; i < tree[nod].size(); ++i)
    {
        int vecin = tree[nod][i];
        if(vecin == dad)
            continue;
        if(mx == -1)
            mx = vecin;
        else
            if(subtree[vecin] > subtree[mx])
                mx = vecin;
    }
    for(int i = 0; i < tree[nod].size(); ++i)
    {
        int vecin = tree[nod][i];
        if(vecin == dad)
            continue;
        if(mx == vecin)
            dfs(nod, vecin, cr);
        else
            dfs(nod, vecin, ++nrp);
    }
}
int pc;
void buildhld(int stp, int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod + stp] = v[paths[pc][st - 1]];
        return;
    }
    int mid = (st + dr) / 2;
    buildhld(stp, nod * 2, st, mid);
    buildhld(stp, nod * 2 + 1, mid + 1, dr);
    aint[nod + stp] = max(aint[nod * 2 + stp], aint[nod * 2 + 1 + stp]);
}
int ans;
void queryhld(int stp, int nod, int st, int dr, int L, int R)
{
    if(L <= st && dr <= R)
    {
        ans = max(ans, aint[nod + stp]);
        return;
    }
    if(dr < L || st > R)
        return;
    int mid = (st + dr) / 2;
    queryhld(stp, nod * 2, st, mid, L, R);
    queryhld(stp, nod * 2 + 1, mid + 1, dr, L, R);
}
void updatehld(int stp, int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        aint[nod + stp] = val;
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        updatehld(stp, nod * 2, st, mid, poz, val);
    else
        updatehld(stp, nod * 2 + 1, mid + 1, dr, poz, val);
    aint[nod + stp] = max(aint[nod * 2 + stp], aint[nod * 2 + 1 + stp]);
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        f >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs1(0, 1);
    dfs(0, 1, 1);
    pz = 1;
    for(int i = 1; i <= nrp; ++i)
    {
        lft[i] = pz;
        pc = i;
        pz = pz + 4 * paths[i].size() + 1;
        buildhld(lft[i] - 1, 1, 1, paths[i].size());
    }
    buildlca(1, 1, p);
    for(int i = 1; i <= m; ++i)
    {
        int tip, a, b;
        f >> tip >> a >> b;
        if(tip == 0)
        {
            updatehld(lft[path[a]] - 1, 1, 1, paths[path[a]].size(), pos[a] + 1, b);
            continue;
        }
        ana = -1;
        querylca(1, 1, p, min(lst[a], lst[b]), max(lst[a], lst[b]));
        int LCA = euler[ana];
        ans = -2000000001;
        while(path[a] != path[LCA])
            queryhld(lft[path[a]] - 1, 1, 1, paths[path[a]].size(), 1, pos[a] + 1), a = tt[paths[path[a]][0]];
        while(path[b] != path[LCA])
            queryhld(lft[path[b]] - 1, 1, 1, paths[path[b]].size(), 1, pos[b] + 1), b = tt[paths[path[b]][0]];
        queryhld(lft[path[a]] - 1, 1, 1, paths[path[a]].size(), pos[LCA] + 1, max(pos[a], pos[b]) + 1);
        g << ans << '\n';
    }
    return 0;
}
