/*
        USACO 18mar-disrupt-plat

    We are going to use DSU to solve the problem. Basically, we will keep for each node the lowest ancestor such that
the cost for the edge between that node and its father wasn't fixed yet, using path compression. In order for this algorithm to be correct, we need
to sort the extra edges by their value and process both nodes in the query until we reached their LCA.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("disrupt.in");
ofstream g("disrupt.out");
int n, m, L[50002], R[50002], poz, anc[17][50002], tt[50002], cn[50002], lvl[50002];
vector<pair<int, int> > v[50002];

struct extra
{
    int a, b, c;
};
extra ve[50002];

bool cmp(extra a, extra b)
{
    return a.c < b.c;
}

void dfs(int dad, int nod)
{
    ++poz;
    L[nod] = poz;
    tt[nod] = dad;
    anc[0][nod] = dad;
    for(int i = 1; i <= 16; ++i)
        anc[i][nod] = anc[i-1][anc[i-1][nod]];
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        lvl[vecin] = lvl[nod] + 1;
        cn[vecin] = v[nod][i].second;
        dfs(nod, vecin);
    }
    R[nod] = poz;
}

int sol[50002];

int LCA(int a, int b)
{
    if(lvl[a] > lvl[b])
        swap(a, b);
    for(int i = 16; i >= 0; --i)
        if(lvl[b] - (1<<i) >= lvl[a])
            b = anc[i][b];
    if(a == b)
        return a;
    for(int i = 16; i >= 0; --i)
        if(anc[i][a] != anc[i][b])
        {
            a = anc[i][a];
            b = anc[i][b];
        }
    return anc[0][a];
}

void proc(int a, int b, int c)
{
    int x = LCA(a, b);
    vector<int> tbc;
    if(cn[a] != 0);
    else
        a = tt[a];
    while(lvl[a] > lvl[x])
    {
        sol[cn[a]] = c;
        cn[a] = 0;
        tbc.push_back(a);
        a = tt[a];
    }
    if(cn[b] != 0);
    else
        b = tt[b];
    while(lvl[b] > lvl[x])
    {
        sol[cn[b]] = c;
        cn[b] = 0;
        tbc.push_back(b);
        b = tt[b];
    }
    for(int i = 0; i < tbc.size(); ++i)
        tt[tbc[i]] = x;
}
int main()
{
    f >> n >> m;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back({b, i});
        v[b].push_back({a, i});
        sol[i] = (1<<30);
    }
    dfs(0, 1);
    for(int i = 1; i <= m; ++i)
        f >> ve[i].a >> ve[i].b >> ve[i].c;
    sort(ve + 1, ve + m + 1, cmp);
    for(int i = 1; i <= m; ++i)
        proc(ve[i].a, ve[i].b, ve[i].c);
    for(int i = 1; i < n; ++i)
        g << (sol[i] == (1<<30) ? -1 : sol[i]) << '\n';
    return 0;
}
