/*
            CF101908-GYM-L

    Classical HLD(+ lazy propagation) problem.

    For a query, we're going to update the nodes on the first path with 1 using lazy propagation, and we're going to query for the second path
to find out how many marked nodes we have on the path, and this is going to be the answer of the problem.

    At the end of each query, one should update again the nodes on the first path with 0 so that we get once again empty segment tree.

*/
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

// for HLD
int n, m, v[100002], aint[500002], nrp = 1, path[100002], pos[100002], tt[100002], subtree[100002], lft[100002], pz, lazy[500002];
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
int ans;
void lz(int stp, int nod, int st, int dr)
{
    aint[nod + stp] += (dr - st + 1) * lazy[stp + nod];
    if(st != dr)
    {
        lazy[nod * 2 + stp] += lazy[stp + nod];
        lazy[nod * 2 + 1 + stp] += lazy[stp + nod];
    }
    lazy[stp + nod] = 0;
}
int queryhld(int stp, int nod, int st, int dr, int L, int R)
{
    if(lazy[nod + stp] != 0)
        lz(stp, nod, st, dr);
    if(L <= st && dr <= R)
        return aint[nod + stp];
    if(dr < L || st > R)
        return 0;
    int mid = (st + dr) / 2;
    return queryhld(stp, nod * 2, st, mid, L, R) + queryhld(stp, nod * 2 + 1, mid + 1, dr, L, R);
}
void updatehld(int stp, int nod, int st, int dr, int L, int R, int tip)
{
    if(lazy[nod + stp] != 0)
        lz(stp, nod, st, dr);
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        if(tip == 1)
        {
            aint[nod + stp] += dr - st + 1;
            if(st != dr)
            {
                lazy[stp + (nod * 2)]++;
                lazy[stp + (nod * 2) + 1]++;
            }
        }
        else
        {
            aint[nod + stp] -= (dr - st + 1);
            if(st != dr)
            {
                lazy[stp + (nod * 2)]--;
                lazy[stp + (nod * 2) + 1]--;
            }
        }
        return;
    }
    int mid = (st + dr) / 2;
    updatehld(stp, nod * 2, st, mid, L, R, tip);
    updatehld(stp, nod * 2 + 1, mid + 1, dr, L, R, tip);
    aint[nod + stp] = aint[nod * 2 + stp] + aint[nod * 2 + 1 + stp];
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
    }
    buildlca(1, 1, p);
    for(int i = 1; i <= m; ++i)
    {
        int c, d, a, b;
        cin >> c >> d >> a >> b;
        ana = -1;
        querylca(1, 1, p, min(lst[a], lst[b]), max(lst[a], lst[b]));
        int LCA = euler[ana];
        ans = 0;
        int a2 = a;
        int b2 = b;

        // upd cu +
        while(path[a] != path[LCA])
        {
            updatehld(lft[path[a]] - 1, 1, 1, paths[path[a]].size(), 1, pos[a] + 1, 1);
            a = tt[paths[path[a]][0]];
        }
        while(path[b] != path[LCA])
        {
            updatehld(lft[path[b]] - 1, 1, 1, paths[path[b]].size(), 1, pos[b] + 1, 1);
            b = tt[paths[path[b]][0]];
        }
        updatehld(lft[path[a]] - 1, 1, 1, paths[path[a]].size(), pos[LCA] + 1, max(pos[a], pos[b]) + 1, 1);

        ana = -1;
        querylca(1, 1, p, min(lst[c], lst[d]), max(lst[c], lst[d]));
        LCA = euler[ana];

        while(path[c] != path[LCA])
        {
            ans += queryhld(lft[path[c]] - 1, 1, 1, paths[path[c]].size(), 1, pos[c] + 1);
            c = tt[paths[path[c]][0]];
        }
        while(path[d] != path[LCA])
        {
            ans += queryhld(lft[path[d]] - 1, 1, 1, paths[path[d]].size(), 1, pos[d] + 1);
            d = tt[paths[path[d]][0]];
        }
        ans += queryhld(lft[path[c]] - 1, 1, 1, paths[path[c]].size(), pos[LCA] + 1, max(pos[c], pos[d]) + 1);


        a = a2;
        b = b2;
        ana = -1;
        querylca(1, 1, p, min(lst[a], lst[b]), max(lst[a], lst[b]));
        LCA = euler[ana];
        // upd cu -
        while(path[a] != path[LCA])
        {
            updatehld(lft[path[a]] - 1, 1, 1, paths[path[a]].size(), 1, pos[a] + 1, -1);
            a = tt[paths[path[a]][0]];
        }
        while(path[b] != path[LCA])
        {
            updatehld(lft[path[b]] - 1, 1, 1, paths[path[b]].size(), 1, pos[b] + 1, -1);
            b = tt[paths[path[b]][0]];
        }
        updatehld(lft[path[a]] - 1, 1, 1, paths[path[a]].size(), pos[LCA] + 1, max(pos[a], pos[b]) + 1, -1);
        cout << ans << '\n';
    }
    return 0;
}
