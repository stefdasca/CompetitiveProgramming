/*
                Infoarena paintball

    To determine the minimum number of deaths, proceed as follows:

    * select a node with inner degree 0 and remove from the graph the chosen node and its adjacent node
    * after all the nodes with inner degree 0 have been eliminated, only cycles can remain (because each node in the graph has the outer degree 1);
for each cycle of length L the minimum number of deaths is L / 2

    To determine the maximum number of deaths, proceed as follows:

    * a scan is made from each node with inner degree 0 and all accessible nodes are marked; every accessible node is considered dead except the
starting one
    * the remaining unmarked nodes form only cycles; for each cycle of length L the maximum number of deaths is L-1

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("paintball.in");
ofstream g("paintball.out");
int n, nxt[1000002], dd, trr[1000002], trr2[1000002], mn, mx;
bool viz[1000002];
void dfs(int nod)
{
    ++dd;
    viz[nod] = 1;
    if(!viz[nxt[nod]])
        dfs(nxt[nod]);
}
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        int ve;
        f >> ve;
        trr[ve]++;
        trr2[ve]++;
        nxt[i] = ve;
    }
    for(int i = 1; i <= n; ++i)
        if(!trr2[i])
        {
            dd = 0, dfs(i);
            mx += dd - 1;
        }
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
        {
            dd = 0;
            dfs(i);
            mx += dd - 1 + (dd == 1);
        }
    memset(viz, 0, sizeof(viz));
    queue<int>q;
    for(int i = 1; i <= n; ++i)
        if(!trr[i])
            q.push(i);
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        viz[nod] = 1;
        if(!viz[nxt[nod]])
        {
            ++mn;
            viz[nxt[nod]] = 1;
            if (!viz[nxt[nxt[nod]]] && --trr[nxt[nxt[nod]]] == 0)
                q.push(nxt[nxt[nod]]);
        }
    }
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
        {
            dd = 0;
            dfs(i);
            mn = mn + dd - dd / 2;
        }
    g << mn << " " << mx << '\n';
    return 0;
}
