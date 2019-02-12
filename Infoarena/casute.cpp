/*
            Infoarena casute(https://www.infoarena.ro/problema/casute)

    "Given a DAG with n nodes and m edges, find the LCA for all pairs of distinct nodes"

    Since n and m are small, we will use BFS starting from each node, where we will go at each step on the current node's transpose graph to find
the LCA for all the distinct pairs

*/

#include<bits/stdc++.h>
using namespace std;
ifstream f("casute.in");
ofstream g("casute.out");
int n, m;
vector<int>v[3002], tr[3002];
short inter[3002][3002];
int poz[3002], adv[3002], val[3002];
bool viz[3002], nw[3002];
bool cmp(int a, int b)
{
    return val[a] < val[b];
}
void dfs(int st, int nod, int cn)
{
    viz[nod] = 1;
    inter[st][nod] = cn;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(!viz[vecin])
            dfs(st, vecin, cn);
    }
}
void bfs(int st)
{
    memset(viz, 0, sizeof(viz));
    viz[st] = 1;
    dfs(st, st, st);
    for(int i = 0; i < tr[st].size(); ++i)
        nw[val[tr[st][i]]] = 1;
    for(int i = 1; i <= n; ++i)
        if(nw[i])
        {
            dfs(st, adv[i], adv[i]);
            for(int j = 0; j < tr[adv[i]].size(); ++j)
                nw[val[tr[adv[i]][j]]] = 1;
            nw[i] = 0;
        }
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> val[i], poz[i] = i;
    sort(poz + 1, poz + n + 1, cmp);
    for(int i = 1; i <= n; ++i)
        val[poz[i]] = i, adv[i] = poz[i];
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        f >> a >> b;
        v[b].push_back(a);
        tr[a].push_back(b);
    }
    for(int i = 1; i <= n; ++i)
        bfs(i);
    int nr = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = i+1; j <= n; ++j)
        {
            nr = nr * (n+1) + inter[i][j];
            nr %= 666013;
        }
    g << nr << '\n';
    return 0;
}
