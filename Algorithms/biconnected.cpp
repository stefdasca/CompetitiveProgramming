// https://www.infoarena.ro/problema/biconex

#include<bits/stdc++.h>
using namespace std;
ifstream f("biconex.in");
ofstream g("biconex.out");
int n, m, nr;
vector<int>v[100002], sol[100002];
bool viz[100002];
int niv[100002], low[100002];
deque<int>d;
void dfs(int dad, int nod)
{
    viz[nod] = 1;
    low[nod] = niv[nod];
    d.push_back(nod);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        if(viz[vecin])
        {
            low[nod] = min(low[nod], niv[vecin]);
            continue;
        }
        niv[vecin] = niv[nod] + 1;
        dfs(nod, vecin);
        low[nod] = min(low[nod], low[vecin]);
        if(low[vecin] >= niv[nod])
        {
            nr++;
            int lst;
            do
            {
                sol[nr].push_back(d.back());
                lst = d.back();
                d.pop_back();
            }while(!d.empty() && lst != vecin);
            sol[nr].push_back(nod);
        }
    }
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, 1);
    g << nr << '\n';
    for(int i = 1; i <= nr; g << '\n', ++i)
        for(int j = 0; j < sol[i].size(); ++j)
            g << sol[i][j] << " ";
    return 0;
}
