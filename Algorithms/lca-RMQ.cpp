// https://www.infoarena.ro/problema/lca

#include<bits/stdc++.h>
using namespace std;
ifstream f("lca.in");
ofstream g("lca.out");
int n, q;
vector<int>v[100002];
int rmq[20][200002], lg[200002];
int lvl[100002];
int m;
int euler[200002];
int nivel[200002];
int lst[100002];
void dfs(int nod)
{
    ++m;
    euler[m] = nod;
    nivel[m] = lvl[nod];
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        lvl[vecin] = lvl[nod] + 1;
        dfs(vecin);
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
    for(int i = 1; i <= lg[m]; ++i)
        for(int j = 1; j + (1<<i) - 1 <= m; ++j)
            if(nivel[rmq[i-1][j]] < nivel[rmq[i-1][j + (1<<(i - 1))]])
                rmq[i][j] = rmq[i-1][j];
            else
                rmq[i][j] = rmq[i-1][j + (1<<(i-1))];
}
int LCA(int x, int y)
{
    int a = min(lst[x], lst[y]);
    int b = max(lst[x], lst[y]);
    int ln = lg[b - a + 1];
    int ans = rmq[ln][a];
    if(nivel[rmq[ln][b - (1<<ln) + 1]] < nivel[ans])
        ans = rmq[ln][b - (1<<ln) + 1];
    return euler[ans];
}
int main()
{
    f >> n >> q;
    for(int i = 2; i <= n; ++i)
    {
        int x;
        f >> x;
        v[x].push_back(i);
    }
    dfs(1);
    build();
    int x, y;
    for(int i = 1; i <= q; ++i)
    {
        int a, b;
        f >> x >> y;
        g << LCA(x, y) << '\n';
    }
    return 0;
}
