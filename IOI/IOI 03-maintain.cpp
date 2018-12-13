/// very similar to this Romanian problem 
/// https://www.infoarena.ro/problema/online 

/*
                IOI 03-maintain

    It is obvious that for each edge added, we will do a DFS in order to see whether graph is connected
or not. If graph formed by edges added so far is connected, we will run any MST algorithm(I've used Kruskal's
algorithm). But, an optimization is necessary in order to get 100. For each of the subsequent iterations of
Kruskal's algorithm, we will just use the n-1 edges added so far and the current edge, in order to optimize the
running time from O(W^2 log W) to O(W * N log N)

*/

#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int>v[202];
struct edges
{
    int a, b;
    int cost;
};
edges arr[6002];
edges mst[205];
edges mst2[205];
bool viz[202], was;
int counter;
void dfs(int nod)
{
    ++counter;
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int x = v[nod][i];
        if(!viz[x])
            dfs(x);
    }
}
int tt[202], rg[202];
void Union(int a, int b)
{
    if(rg[a] > rg[b])
        tt[b] = a, rg[a] += rg[b];
    else
        tt[a] = b, rg[b] += rg[a];
}
int Find(int x)
{
    if(tt[x] == x)
        return x;
    return tt[x] = (Find(tt[x]));
}
int poz;
void kruskal(int tip)
{
    for(int i = 1; i <= n; ++i)
        tt[i] = i, rg[i] = 1;
    if(tip == 2)
    {
        int cost = 0;
        int tk = 0;
        for(int i = 1; i <= poz; ++i)
            if(Find(arr[i].a) != Find(arr[i].b))
            {
                cost += arr[i].cost;
                mst[++tk] = arr[i];
                Union(Find(arr[i].a), Find(arr[i].b));
            }
        cout << cost << endl;
    }
    else
    {
        int cost = 0;
        int tk = 0;
        for(int i = 1; i <= n; ++i)
            if(Find(mst[i].a) != Find(mst[i].b))
            {
                cost += mst[i].cost;
                mst2[++tk] = mst[i];
                Union(Find(mst[i].a), Find(mst[i].b));
            }
        cout << cost << endl;
        for(int i = 1; i <= tk; ++i)
            mst[i] = mst2[i];
        mst[n] = {0, 0, 0};
    }
}
bool cmp(edges a, edges b)
{
    return a.cost < b.cost;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].cost;
        v[arr[i].a].push_back(arr[i].b);
        v[arr[i].b].push_back(arr[i].a);
        counter = 0;
        memset(viz, 0, sizeof(viz));
        dfs(1);
        if(counter == n)
        {
            if(was == 1)
            {
                mst[n] = arr[i];
                sort(mst + 1, mst + n + 1, cmp);
                kruskal(1);
            }
            else
            {
                was = 1;
                sort(arr + 1, arr + i + 1, cmp);
                poz = i;
                kruskal(2);
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
