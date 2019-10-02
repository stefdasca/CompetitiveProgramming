/*
        NOI(Singapore)19-RiggedRoads

    * For each edge in the list of edges, according to the input order, if the current edge
is part of the spanning tree, we are going to label it with the smallest possible number.

    * Otherwise, we are going to label the edges which belong to the spanning tree such that they lock the
current edge according to the sorted order of their labels.

    * In order to do this, we need to precompute several things in order to speed up the algorithm:
        1. LCA values for the spanning trees such that we get O(1) query with sparse table.
        2. father and label of the edge for each node(we are going to do traversals from the nodes
which border the current edge in a DSU-like manner, thus getting O(n) overall complexity.

    * Knowing the things mentioned above, the rest of the algorithm is then an implementation exercise.

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

int n, mm, ans[300002];

bool tr[300002], pus[300002];

struct muchii
{
    int x, y;
};
muchii vm[300002];

vector<pair<int, int> >v[300002];

int tt[300002], pm[300002], tpoz[300002];

set<int>vals;

int m, euler[600002], nivel[600002], rmq[22][600002], lg2[600002], lst[300002], lvl[300002];

void dfs(int dad, int nod)
{
    ++m;
    euler[m] = nod;
    nivel[m] = lvl[nod];
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        if(vecin != dad)
        {
            lvl[vecin] = lvl[nod] + 1;
            tt[vecin] = nod;
            pm[vecin] = v[nod][i].se;
            dfs(nod, vecin);
            ++m;
            euler[m] = nod;
            nivel[m] = lvl[nod];
        }
    }
    lst[nod] = m;
}
void build()
{
    for(int i = 2; i <= m; ++i)
        lg2[i] = lg2[i/2] + 1;
    for(int i = 0; i <= m; ++i)
        rmq[0][i] = i;
    for(int i = 1; i <= lg2[m]; ++i)
        for(int j = 1; j + (1<<i) - 1 <= m; ++j)
        {
            rmq[i][j] = rmq[i-1][j];
            if(nivel[rmq[i][j]] >= nivel[rmq[i-1][j + (1<<(i-1))]])
                rmq[i][j] = rmq[i-1][j + (1<<(i-1))];
        }
}
int LCA(int x, int y)
{
    int a = min(lst[x], lst[y]);
    int b = max(lst[x], lst[y]);
    int zona = lg2[b - a + 1];
    int ans = rmq[zona][a];
    if(nivel[rmq[zona][b - (1<<zona) + 1]] < nivel[ans])
        ans = rmq[zona][b - (1<<zona) + 1];
    return euler[ans];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> mm;
    for(int i = 1; i <= mm; ++i)
        vals.insert(i);
    for(int i = 1; i <= mm; ++i)
        cin >> vm[i].x >> vm[i].y;
    for(int i = 1; i <= n; ++i)
        tpoz[i] = i;
    for(int i = 1; i < n; ++i)
    {
        int x;
        cin >> x;
        v[vm[x].x].pb({vm[x].y, x});
        v[vm[x].y].pb({vm[x].x, x});
        tr[x] = 1;
    }
    dfs(0, 1);
    build();
    lvl[0] = -1;
    for(int i = 1; i <= mm; ++i)
    {
        if(pus[i])
            continue;
        int sox = LCA(vm[i].x, vm[i].y);
        int nod = tpoz[vm[i].x];
        vector<int>noduri;
        vector<int>numere;
        while(lvl[nod] > lvl[sox])
        {
            if(pm[nod] != 0)
                numere.pb(pm[nod]), pm[nod] = 0;
            noduri.pb(nod);
            nod = tpoz[tt[nod]];
        }
        for(int j = 0; j < noduri.size(); ++j)
            tpoz[noduri[j]] = nod;
        noduri.clear();
        nod = tpoz[vm[i].y];
        while(lvl[nod] > lvl[sox])
        {
            if(pm[nod] != 0)
                numere.pb(pm[nod]), pm[nod] = 0;
            noduri.pb(nod);
            nod = tpoz[tt[nod]];
        }
        for(int j = 0; j < noduri.size(); ++j)
            tpoz[noduri[j]] = nod;
        sort(numere.begin(), numere.end());
        for(int j = 0; j < numere.size(); ++j)
        {
            pus[numere[j]] = 1;
            ans[numere[j]] = *vals.begin();
            vals.erase(vals.begin());
        }
        if(!tr[i])
        {
            pus[i] = 1;
            ans[i] = *vals.begin();
            vals.erase(vals.begin());
        }
    }
    for(int i = 1; i <= mm; ++i)
        cout << ans[i] << " ";
    return 0;
}
