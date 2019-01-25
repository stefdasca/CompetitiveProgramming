/*
                    Infoarena hacker2
        (https://infoarena.ro/problema/hacker2)

    "Given a tree with n nodes, where each edge has a cost, and M queries of type (a, b), find for each of the given queries
a position from an edge from the tree, which is at distance b from node a"

    We can use binary lifting and several DFS in order to solve each of the queries. In order to answer to a query, we will consider
three distinct cases
    1. we have a node in subtree of a given node which is at least b distance away from the given node
    2. the node is at least b distance away from root
    3. we will find the farthest node away from the current node

*/

#include<bits/stdc++.h>
using namespace std;
ifstream f("hacker2.in");
ofstream g("hacker2.out");
int n, m;
vector<pair<int, int> >queries[100002];
vector<pair<int, int> >v[100002];
struct answers
{
    int a, b, k;
};
answers va[100002];
int dad[100002], dist[100002];
int distmax[2][100002], wh[2][100002];
int binlift[100002][19];
void dfs(int dad, int nod)
{
    int q = dad, pos = 0;
    while(q)
    {
        binlift[nod][pos] = q;
        q = binlift[q][pos];
        ++pos;
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        dist[vecin] = dist[nod] + v[nod][i].second;
        dfs(nod, vecin);
    }
}
void dfs2(int dad, int nod)
{
    distmax[0][nod] = dist[nod], wh[0][nod] = nod;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        dfs2(nod, vecin);
        if(wh[0][vecin])
            if(distmax[0][nod] < distmax[0][vecin])
            {
                distmax[1][nod] = distmax[0][nod];
                wh[1][nod] = wh[0][nod];
                distmax[0][nod] = distmax[0][vecin];
                wh[0][nod] = wh[0][vecin];
            }
            else
                if(distmax[1][nod] < distmax[0][vecin])
                {
                    distmax[1][nod] = distmax[0][vecin];
                    wh[1][nod] = wh[0][vecin];
                }
    }
}
void cauta(int pstart, int cat, int wtp)
{
    for(int i = 18; i >= 0; --i)
    {
        int anc = binlift[pstart][i];
        if(anc == 0)
            continue;
        if(dist[anc] <= cat)
            continue;
        pstart = anc;
    }
    va[wtp] = {binlift[pstart][0], pstart, cat - dist[binlift[pstart][0]]};
}
void dfs3(int dad, int nod, int mx, int unde, int root)
{
    for(int j = 0; j < queries[nod].size(); ++j)
    {
        int d = queries[nod][j].first;
        int Pans = queries[nod][j].second;
        if(distmax[0][nod] - d >= dist[nod])
            cauta(wh[0][nod], dist[nod] + d, Pans);
        else
            if(dist[nod] >= d)
                cauta(nod, dist[nod] - d, Pans);
            else
                cauta(unde, dist[root] + (d - (dist[nod] - dist[root])), Pans);
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        int z = -1;
        if(wh[0][vecin] == wh[0][nod])
            z = 1;
        else
            z = 0;
        if(root == 0)
        {
            if(wh[z][nod])
                dfs3(nod, vecin, dist[wh[z][nod]] - dist[nod] + (dist[vecin] - dist[nod]), wh[z][nod], nod);
            else
                dfs3(nod, vecin, 0, 0, 0);
        }
        else
        {
            if(wh[z][nod])
            {
                if(dist[wh[z][nod]] - dist[nod] > mx)
                    dfs3(nod, vecin, dist[wh[z][nod]] - dist[nod] + (dist[vecin] - dist[nod]), wh[z][nod], nod);
                else
                    dfs3(nod, vecin, mx + (dist[vecin] - dist[nod]), unde, root);
            }
            else
                dfs3(nod, vecin, mx + (dist[vecin] - dist[nod]), unde, root);
        }
    }
}
int main()
{
    f >> n >> m;
    for(int i = 1; i < n; ++i)
    {
        int a, b, c;
        f >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for(int i = 1; i <= m; ++i)
    {
        int x, p;
        f >> x >> p;
        queries[x].push_back({p, i});
    }
    dfs(0, 1);
    dfs2(0, 1);
    dfs3(0, 1, 0, 0, 0);
    for(int i = 1; i <= m; ++i)
        g << va[i].a << " " << va[i].b << " " << va[i].k << '\n';
    return 0;
}
