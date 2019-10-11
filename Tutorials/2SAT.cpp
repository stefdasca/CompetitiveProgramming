// https://www.infoarena.ro/problema/2sat
#include<bits/stdc++.h>
using namespace std;
ifstream f("2sat.in");
ofstream g("2sat.out");
int n, m;
bool pus[200002], viz[200002];
int comp[200002];
vector<int>v[200002], tr[200002];
vector<int>ordine;
void dfs(int nod)
{
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(viz[vecin])
            continue;
        dfs(vecin);
    }
    ordine.push_back(nod);
}
int nr;
void dfs2(int nod)
{
    comp[nod] = nr;
    for(int i = 0; i < tr[nod].size(); ++i)
    {
        int vecin = tr[nod][i];
        if(comp[vecin])
            continue;
        dfs2(vecin);
    }
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        f >> a >> b;
        int nega = (a < 0);
        int negb = (b < 0);
        if(a < 0)
            a *= -1;
        if(b < 0)
            b *= -1;
        v[a * 2 + (!nega)].push_back(b * 2 + negb);
        v[b * 2 + (!negb)].push_back(a * 2 + nega);
        tr[b * 2 + negb].push_back(a * 2 + (!nega));
        tr[a * 2 + nega].push_back(b * 2 + (!negb));
    }
    for(int i = 2; i <= 2 * n + 1; ++i)
        if(!viz[i])
            dfs(i);
    reverse(ordine.begin(), ordine.end());
    for(int i = 0; i < ordine.size(); ++i)
    {
        int nod = ordine[i];
        if(!comp[nod])
            ++nr, dfs2(nod);
    }
    for(int i = 2; i <= 2 * n + 1; ++i)
        if(comp[i] == comp[i ^ 1])
        {
            g << -1;
            return 0;
        }
    for(int i = 1; i <= n; ++i)
        g << (comp[i * 2] > comp[i * 2 + 1]) << " ";
    return 0;
}
