/*
                                            Infoarena drumuri5
                                (https://www.infoarena.ro/problema/drumuri5)

    "Given a directed graph with n vertexes and m edges, find the popular vertexes in the graph. A popular vertex i is a vertex such that
for each other node, one can either get from i to that node or one can get from that node to i"

    We can use a DP-like approach to find the good vertexes. We will do 2 topological sorts: first one of graph of strong connected components, then
of transpose of this graph. Since a normal DP approach where we find size of subtree + number of parents for each node will overcount stuff, at a given
node, we will only add those values to the closest "son" in topological sort order


*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("drumuri5.in");
ofstream g("drumuri5.out");
int n, m;
vector<int>v[150002], tr[150002], v2[150002], tr2[150002];
map<pair<int, int>, int>mrp;
int gr[200002], gr2[200002], gr3[200002];
int subtreesize[200002], tt[200002];
int poz[150002];
bool viz[150002];
deque<int>order;
int cat, nrctc[150002];
void dfs(int nod)
{
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
        if(!viz[v[nod][i]])
            dfs(v[nod][i]);
    order.push_back(nod);
}
void dfs2(int nod, int care)
{
    nrctc[nod] = care;
    for(int i = 0; i < tr[nod].size(); ++i)
        if(!nrctc[tr[nod][i]])
            dfs2(tr[nod][i], care);
}
void cantoposort()
{
    deque<int>vv;
    int ct = 0;
    for(int i = 1; i <= cat; ++i)
        if(gr[i] == 0)
            vv.push_back(i), ++ct;
    int pz = 0;
    while(!vv.empty())
    {
        int nod = vv[0];
        ++pz;
        poz[nod] = pz;
        vv.pop_front();
        for(int j = 0; j < v2[nod].size(); ++j)
        {
            int vecin = v2[nod][j];
            --gr[vecin];
            if(gr[vecin] == 0)
            {
                ++ct;
                vv.push_back(vecin);
            }
        }
    }
}
void tps()
{
    deque<int>vv;
    for(int i = 1; i <= cat; ++i)
        if(gr2[i] == 0)
            vv.push_back(i);
    for(int i = 1; i <= cat; ++i)
        subtreesize[i] = 1;
    while(!vv.empty())
    {
        int nod = vv[0];
        vv.pop_front();
        int tba = subtreesize[nod];
        bool add = 0;
        int mp = 0;
        int wh = 0;
        for(int j = 0; j < tr2[nod].size(); ++j)
        {
            int vecin = tr2[nod][j];
            --gr2[vecin];
            if(gr2[vecin] == 0)
                vv.push_back(vecin);
            if(poz[vecin] > mp)
                mp = poz[vecin], wh = vecin;
        }
        subtreesize[wh] += tba;
    }
}
void tps2()
{
    deque<int>vv;
    for(int i = 1; i <= cat; ++i)
        if(gr3[i] == 0)
            vv.push_back(i);
    while(!vv.empty())
    {
        int nod = vv[0];
        vv.pop_front();
        int tba = tt[nod] + 1;
        bool add = 0;
        int mp = 200002;
        int wh = 0;
        for(int j = 0; j < v2[nod].size(); ++j)
        {
            int vecin = v2[nod][j];
            --gr3[vecin];
            if(gr3[vecin] == 0)
                vv.push_back(vecin);
            if(poz[vecin] < mp)
                mp = poz[vecin], wh = vecin;
        }
        tt[wh] += tba;
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
        tr[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            dfs(i);
    while(!order.empty())
    {
        int node = order.back();
        order.pop_back();
        if(!nrctc[node])
        {
            ++cat;
            dfs2(node, cat);
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        int a = nrctc[i];
        for(int j = 0; j < v[i].size(); ++j)
        {
            int b = nrctc[v[i][j]];
            if(a == b)
                continue;
            if(!mrp[{a, b}])
            {
                v2[a].push_back(b);
                tr2[b].push_back(a);
                gr[b]++;
                gr2[a]++;
                gr3[b]++;
                mrp[{a, b}] = 1;
            }
        }
    }
    cantoposort();
    tps();
    tps2();
    vector<int>ans;
    for(int j = 1; j <= n; ++j)
        if(subtreesize[nrctc[j]] + tt[nrctc[j]] == cat)
            ans.push_back(j);
    g << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i)
        g << ans[i] << " ";
    return 0;
}
