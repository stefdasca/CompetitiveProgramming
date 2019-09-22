/*
        POI 04-Tournament

    * Let's start from the simplest case: the graph is a strongly connected component. It can easily be observed that everyone in that strongly
component can win.

    * So, we will find the strongly connected components of the graph and do a topological sort in the DAG which results if we draw edges between
every pair of SCCs connected by an edge. In this topological sort, we are going to add to the answer the following nodes:

        - the nodes which are part of SCCs which are at the beginning of the topological sort(no other SCC which is the "boss" of node's SCC).
These nodes will be called the "winner" nodes.

        - all the nodes which are either not connected to all the "winner" nodes or to not all the nodes which cancel the winner nodes. If
this happens for a certain node, we are going to add it to the list of nodes which cancel the winners.

    * Even though this algorithm is linear, one has to be careful at the memory used, because 32MB is a small limit given the constraints.

*/
#include<bits/stdc++.h>
using namespace std;
int n, m, cc;
vector<int>v[100002], tr[100002], losers, top;
bool viz[100002], winner[100002], possiblewinners[100002], cancel[100002];
deque<int>d, toposort;
int zona[100002], fi[100002], nxt[100002], prv, countwinners[100002], gr[100002], nre = 0;
pair<int, int> pe[1000002];
void dfs(int nod)
{
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(!viz[vecin])
            dfs(vecin);
    }
    d.push_back(nod);
}
void dfs2(int nod)
{
    viz[nod] = 1;
    zona[nod] = cc;
    if(!fi[cc])
        fi[cc] = nod;
    nxt[prv] = nod;
    prv = nod;
    for(int i = 0; i < tr[nod].size(); ++i)
    {
        int vecin = tr[nod][i];
        if(!viz[vecin])
            dfs2(vecin);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int m;
        cin >> m;
        for(int j = 0; j < m; ++j)
        {
            int vecin;
            cin >> vecin;
            v[i].push_back(vecin);
            tr[vecin].push_back(i);
        }
    }
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            dfs(i);
    memset(viz, 0, sizeof(viz));
    while(!d.empty())
    {
        int nod = d.back();
        d.pop_back();
        if(!viz[nod])
        {
            prv = 0;
            ++cc;
            dfs2(nod);
        }
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < v[i].size(); ++j)
            if(zona[i] != zona[v[i][j]])
            {
                ++nre;
                pe[nre] = {zona[i], zona[v[i][j]]};
                gr[zona[v[i][j]]]++;
            }
    for(int i = 1; i <= n; ++i)
        v[i].clear();
    for(int i = 1; i <= nre; ++i)
        v[pe[i].first].push_back(pe[i].second);
    int nrwinners = 0;
    for(int i = 1; i <= cc; ++i)
        if(!gr[i])
        {
            toposort.push_back(i);
            int nod = fi[i];
            while(nod)
            {
                possiblewinners[nod] = 1;
                ++nrwinners;
                winner[nod] = 1;
                nod = nxt[nod];
            }
        }
    int countcancel = 0;
    while(!toposort.empty())
    {
        int nod = toposort[0];
        toposort.pop_front();
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i];
            --gr[vecin];
            if(gr[vecin] == 0)
                toposort.push_back(vecin);
        }
        int nn = fi[nod];
        while(nn)
        {
            int ot = 0;
            int cac = 0;
            for(int k = 0; k < tr[nn].size(); ++k)
            {
                cac += cancel[tr[nn][k]];
                ot += winner[tr[nn][k]];
            }
            if(ot != nrwinners || cac != countcancel)
            {
                cancel[nn] = 1;
                for(int i = 0; i < losers.size(); ++i)
                    possiblewinners[losers[i]] = 1;
                losers.clear();
                possiblewinners[nn] = 1;
                ++countcancel;
            }
            else
                losers.push_back(nn);
            nn = nxt[nn];
        }
    }
    for(int i = 1; i <= n; ++i)
        if(possiblewinners[i])
            top.push_back(i);
    cout << top.size() << " ";
    for(int i = 0; i < top.size(); ++i)
        cout << top[i] << " ";
    return 0;
}
