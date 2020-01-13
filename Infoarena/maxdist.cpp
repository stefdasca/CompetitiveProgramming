/*
        infoarena maxdist

    "Given a tree with n nodes, there are two clans and Q days. On ith day, the second clan conquers from the first clan city Qi and we need
to print after each day, the max distance between two nodes in each of the sets(one can pass enemy nodes, but can't start or stop the trip there)"

    One can observe that the best pair for day i+1 will contain at least one node from the pair for day i, so we can try out in day i+1 all the possibilities of
new pairs. In order to compute efficiently the distances, we are going to precompute LCA and use the distance formula

    dist(a, b) = lvl[a] + lvl[b] - 2 * lvl[LCA(a, b)]

    In order to compute the distances for the second clan, we can use the order given in the input, while for the first clan we need to add the remaining nodes
and compute the distances in reverse order.

*/
#include<bits/stdc++.h>
using namespace std;

ifstream f("maxdist.in");
ofstream g("maxdist.out");
int n, q, ord[200002], x, y, is[200002], ans[200002], ans2[200002];
vector<int> v[200002];

int m, euler[400002], nivel[400002], lvl[200002], lg[400002], rmq[21][400002], lst[200002];
void dfs(int dad, int nod)
{
    ++m;
    euler[m] = nod;
    nivel[m] = lvl[nod];
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        lvl[vecin] = lvl[nod] + 1;
        dfs(nod, vecin);
        ++m;
        euler[m] = nod;
        nivel[m] = lvl[nod];
    }
    lst[nod] = m;
}
void build()
{
    for(int i = 2; i <= m; ++i)
        lg[i] = lg[i/2] + 1;
    for(int i = 1; i <= m; ++i)
        rmq[0][i] = i;
    for(int i = 1; (1<<i) <= m; ++i)
        for(int j = 1; j + (1<<i) - 1 <= m; ++j)
            if(nivel[rmq[i-1][j]] > nivel[rmq[i-1][j+(1<<(i-1))]])
                rmq[i][j] = rmq[i-1][j+(1<<(i-1))];
            else
                rmq[i][j] = rmq[i-1][j];
}
int LCA(int a, int b)
{
    int x = min(lst[a], lst[b]);
    int y = max(lst[a], lst[b]);
    int zona = lg[y - x + 1];
    int ans = rmq[zona][x];
    if(nivel[ans] > nivel[rmq[zona][y - (1<<zona) + 1]])
        ans = rmq[zona][y - (1<<zona) + 1];
    return euler[ans];
}
int main()
{
    f >> n >> q;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, 1);
    build();
    for(int i = 1; i <= q; ++i)
        f >> ord[i], is[ord[i]] = 1;
    int qq = q;
    for(int i = 1; i <= n; ++i)
        if(!is[i])
            ord[++qq] = i;
    int a = 0, b = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(i > 2)
            ans[n - i + 1] = lvl[a] + lvl[b] - 2 * lvl[LCA(a, b)];
        if(i == 1)
            a = ord[n - i + 1];
        else
            if(i == 2)
                b = ord[n - i + 1];
            else
            {
                int md = lvl[a] + lvl[b] - 2 * lvl[LCA(a, b)];
                int md2 = lvl[a] + lvl[ord[n - i + 1]] - 2 * lvl[LCA(a, ord[n - i + 1])];
                int md3 = lvl[b] + lvl[ord[n - i + 1]] - 2 * lvl[LCA(b, ord[n - i + 1])];
                if(md2 > md && md2 > md3)
                    b = ord[n - i + 1];
                if(md3 > md && md3 > md2)
                    a = ord[n - i + 1];
            }
    }
    a = 0, b = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(i == 1)
            a = ord[i];
        else
            if(i == 2)
                b = ord[i];
            else
            {
                int md = lvl[a] + lvl[b] - 2 * lvl[LCA(a, b)];
                int md2 = lvl[a] + lvl[ord[i]] - 2 * lvl[LCA(a, ord[i])];
                int md3 = lvl[b] + lvl[ord[i]] - 2 * lvl[LCA(b, ord[i])];
                if(md2 > md && md2 > md3)
                    b = ord[i];
                if(md3 > md && md3 > md2)
                    a = ord[i];
            }
        if(i >= 2)
            ans2[i] = lvl[a] + lvl[b] - 2 * lvl[LCA(a, b)];
    }
    for(int i = 1; i <= q; ++i)
        g << ans[i] << " " << ans2[i] << '\n';
    return 0;
}
