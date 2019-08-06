/*
    * the intended solution: https://www.infoarena.ro/algoritmiada-2015/runda-1/solutii#disconnect

    * my solution: let's solve the queries using HLD. mark position i to be 1 if we removed edge from i to i's father, and when querying a
path, we have to make sure that there is no position marked with 1 along the path.

    However, this is O(n log^2 n), which gives TLE. in order to optimize one logarithmic factor, we have to solve the queries in O(1), by
observing that we only need the leftmost position marked in a path, except for the last query, which is solvable in O(log n).

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("disconnect.in");
ofstream g("disconnect.out");
int n, m, v[100002], nrp = 1, path[100002], pos[100002], tt[100002], subtree[100002], lft[100002], pz;
bool aint[500002];
vector<int>tree[100002], paths[100002];
int p, euler[200002], rmq[20][200002], niv[100002], lst[100002], lg[200002];
void dfs1(int dad, int nod)
{
    euler[++p] = nod;
    subtree[nod] = 1;
    tt[nod] = dad;
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
void buildlca(int m)
{
    for(int i = 2; i <= 200000; ++i)
        lg[i] = lg[i/2] + 1;
    for(int i = 1; i <= m; ++i)
        rmq[0][i] = i;
    for(int i = 1; (1<<i) <= m; ++i)
        for(int j = 1; j + (1<<i) - 1 <= m; ++j)
        {
            rmq[i][j] = rmq[i-1][j];
            if(niv[euler[rmq[i-1][j + (1<<(i-1))]]] < niv[euler[rmq[i-1][j]]])
                rmq[i][j] = rmq[i-1][j + (1<<(i-1))];
        }
}
int findLCA(int x, int y)
{
    int a = min(lst[x], lst[y]);
    int b = max(lst[x], lst[y]);
    int ln = lg[b - a + 1];
    int ans = rmq[ln][a];
    if(niv[euler[rmq[ln][b - (1<<ln) + 1]]] < niv[euler[ans]])
        ans = rmq[ln][b - (1<<ln) + 1];
    return euler[ans];
}
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
    aint[nod + stp] = aint[nod * 2 + stp] | aint[nod * 2 + 1 + stp];
}
bool ans;
void queryhld(int stp, int nod, int st, int dr, int L, int R)
{
    if(ans)
        return;
    if(L <= st && dr <= R)
    {
        ans = ans | aint[nod + stp];
        return;
    }
    int mid = (st + dr) / 2;
    if(L <= mid)
        queryhld(stp, nod * 2, st, mid, L, R);
    if(mid < R)
        queryhld(stp, nod * 2 + 1, mid + 1, dr, L, R);
}
void updatehld(int stp, int nod, int st, int dr, int poz)
{
    if(st == dr)
    {
        aint[nod + stp] = 1;
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        updatehld(stp, nod * 2, st, mid, poz);
    else
        updatehld(stp, nod * 2 + 1, mid + 1, dr, poz);
    aint[nod + stp] = aint[nod * 2 + stp] | aint[nod * 2 + 1 + stp];
}
int stg[100002];
int main()
{
    f >> n >> m;
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
    buildlca(p);
    int V = 0;
    bool up = 0;
    for(int i = 1; i <= m; ++i)
    {
        int tip, a, b;
        f >> tip >> a >> b;
        a ^= V;
        b ^= V;
        if(tip == 1)
        {
            up = 1;
            if(tt[a] == b)
            {
                if(stg[path[a]] == 0 || stg[path[a]] > pos[a] + 1)
                    stg[path[a]] = pos[a] + 1;
                updatehld(lft[path[a]] - 1, 1, 1, paths[path[a]].size(), pos[a] + 1);
            }
            else
            {
                if(stg[path[b]] == 0 || stg[path[b]] > pos[b] + 1)
                    stg[path[b]] = pos[b] + 1;
                updatehld(lft[path[b]] - 1, 1, 1, paths[path[b]].size(), pos[b] + 1);
            }
            continue;
        }
        int aa = a;
        int bb = b;
        if(up)
        {
            int LCA = findLCA(a, b);
            ans = 0;
            while(!ans && path[a] != path[LCA])
            {
                if(stg[path[a]] != 0 && stg[path[a]] <= pos[a] + 1)
                    ans = 1;
                a = tt[paths[path[a]][0]];
            }
            while(!ans && path[b] != path[LCA])
            {
                if(stg[path[b]] != 0 && stg[path[b]] <= pos[b] + 1)
                    ans = 1;
                b = tt[paths[path[b]][0]];
            }
            if(!ans && pos[LCA] + 2 <= max(pos[a], pos[b]) + 1)
                queryhld(lft[path[a]] - 1, 1, 1, paths[path[a]].size(), pos[LCA] + 2, max(pos[a], pos[b]) + 1);
        }
        if(ans == 0)
        {
            g << "YES\n";
            V = aa;
        }
        else
        {
            g << "NO\n";
            V = bb;
        }
    }
    return 0;
}
