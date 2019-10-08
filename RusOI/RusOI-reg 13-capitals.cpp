/*

    solution = https://github.com/SpeedOfMagic/CompetitiveProgramming/blob/master/RusOI-reg/13-capitals.cpp

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

ifstream f("capitals.in");
ofstream g("capitals.out");

typedef long long ll;

int n, k, siz[100002];

vector<int> t[100002], pathsInSubtree[100002];
map<int, int> dist[100002];
map<int, int> tot;
bitset<100002> added;
int vals[100002];
int d;

int dfs(int nod, int dad)
{
    siz[nod] = 1;
    for(int i = 0; i < t[nod].size(); ++i)
        if(!added.test(t[nod][i]) && t[nod][i] != dad)
            siz[nod] += dfs(t[nod][i], nod);
    return siz[nod];
}

void setDist(int node, int p, int h, int ind)
{
    if (h > d)
        return;
    dist[ind][h]++;
    tot[h]++;
    for(int i = 0; i < t[node].size(); ++i)
    {
        int vecin = t[node][i];
        if(!added.test(vecin) && vecin != p)
            setDist(vecin, node, h + 1, ind);
    }
}

void getDist(int node, int p, int h, int ind)
{
    if (h > d)
        return;
    vals[node] += tot[d - h] - dist[ind][d - h];
    if (d == h)
        vals[node]++;
    for(int i = 0; i < t[node].size(); ++i)
    {
        int vecin = t[node][i];
        if (!added.test(vecin) && vecin != p)
            getDist(vecin, node, h + 1, ind);
    }
}
void solve(int node)
{
    tot.clear();
    int p = 0;
    for(int i = 0; i < t[node].size(); ++i)
    {
        int vecin = t[node][i];
        if(!added.test(vecin))
        {
            dist[p].clear();
            setDist(vecin, -1, 1, p++);
        }
    }
    vals[node] += tot[d];
    p = 0;
    for(int i = 0; i < t[node].size(); ++i)
    {
        int vecin = t[node][i];
        if(!added.test(vecin))
            getDist(vecin, -1, 1, p++);
    }
}
void find_centroid(int node)
{
    int limit = (dfs(node, -1) + 1) / 2;
    int pr = -1;
    bool again = 1;
    while(again)
    {
        again = 0;
        for(int i = 0; i < t[node].size(); ++i)
        {
            int vecin = t[node][i];
            if(!added.test(vecin) && vecin != pr && siz[vecin] > limit)
            {
                pr = node;
                node = vecin;
                again = 1;
                break;
            }
        }
    }
    added.set(node);
    solve(node);
    for (int i = 0; i < t[node].size(); ++i)
    {
        int vecin = t[node][i];
        if (!added.test(vecin))
            find_centroid(vecin);
    }
}
int h[100002], anc[100002][17];
int getKthAncestor(int v, int distance)
{
    for (int k = 0; distance && k < 17; k++, distance >>= 1)
        if (distance & 1)
            v = anc[v][k];
    return v;
}
inline void precalc(int node, int p)
{
    h[node] = (p != -1) ? (h[p] + 1) : 0;
    int D = p;
    for (int k = 0; D != -1; k++)
    {
        anc[node][k] = D;
        D = anc[D][k];
    }

    if (h[node] >= d)
        pathsInSubtree[getKthAncestor(node, d)].back()++;

    for (int i = 0; i < t[node].size(); ++i)
    {
        int vecin = t[node][i];
        pathsInSubtree[node].pb(0);
        if (vecin != p)
            precalc(vecin, node);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(vals, 0, sizeof vals);
    memset(pathsInSubtree, 0, sizeof pathsInSubtree);
    memset(anc, -1, sizeof(anc));
    f >> n >> d;
    if(d % 2 == 1)
    {
        g << 0;
        return 0;
    }
    d /= 2;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        f >> a >> b;
        t[a].pb(b);
        t[b].pb(a);
    }
    find_centroid(1);
    precalc(1, -1);
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        int s = 0;
        for(int j = 0; j < pathsInSubtree[i].size(); ++j)
        {
            int vecin = pathsInSubtree[i][j];
            s += vecin;
        }
        pathsInSubtree[i].pb(vals[i] - s);
        if (pathsInSubtree[i].size() < 3)
            continue;
        ll allSquares = 0;
        for(int j = 0; j < pathsInSubtree[i].size(); ++j)
        {
            ll vecin = pathsInSubtree[i][j];
            allSquares += vecin * (vals[i] - vecin);
        }
        allSquares /= 2;
        for(int j = 0; j < pathsInSubtree[i].size(); ++j)
        {
            ll vecin = pathsInSubtree[i][j];
            ans += (allSquares - (vals[i] - vecin) * vecin) * vecin;
        }
    }
    g << ans/3;
    return 0;
}

