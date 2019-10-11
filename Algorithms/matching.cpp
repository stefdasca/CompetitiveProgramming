// https://www.infoarena.ro/problema/cuplaj

#include<bits/stdc++.h>
using namespace std;
ifstream f("cuplaj.in");
ofstream g("cuplaj.out");
const int dim = 100005;
int dreapta[dim], stanga[dim], st, dr, m, a, b;
bool marked[dim], ok;
vector<int>v[dim];
bool dfs(int nod)
{
    if(marked[nod])
        return 0;
    marked[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++)
    {
        int vecin = v[nod][i];
        if(!dreapta[vecin] || dfs(dreapta[vecin]))
        {
            stanga[nod] = vecin;
            dreapta[vecin] = nod;
            return 1;
        }
    }
    return 0;
}
int main()
{
    f >> st >> dr >> m;
    for(int i = 1; i <= m; i++)
    {
        f >> a >> b;
        v[a].push_back(b);
    }
    bool ok = 1;
    while(ok)
    {
        memset(marked, 0, st+2);
        ok = false;
        for(int i = 1; i <= st; i++)
            if(!stanga[i]  && dfs(i))
                ok =1;
    }
    int cuplaje = 0;
    for(int i = 1; i <= st; i++)
        if(stanga[i])
            cuplaje++;
    g << cuplaje << '\n';
    for(int i = 1; i <= st; i++)
        if(stanga[i])
            g << i << " " <<  stanga[i] << '\n';
    return 0;
}
