/*
        infoarena pm2(https://www.infoarena.ro/problema/pm2)
        
    "Given a directed acyclic graph with n vertexes and m edges, where each vertex is a project with a time ti necessary to be completed,
 find the shortest time to complete all the projects, given the fact that for each edge (a, b), project a has to be finished before we can
 start project b. We also have to find the earliest and the latest time we can start each project, so that the total time is not influenced."

    This problem can be easily solved with a topological sort and 2 traversals of the graph and of the reverse graph, where we find the 
 required data. 

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("pm2.in");
ofstream g("pm2.out");
int n, t[102], ar[102], gr[102], trg[102], t2[102];
int st[102], sf[102];
vector<int>v[102], tr[102];
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> t[i];
    deque<int>d;
    for(int i = 1; i <= n; ++i)
    {
        f >> gr[i];
        for(int j = 1; j <= gr[i]; ++j)
        {
            int a;
            f >> a;
            v[a].push_back(i);
            tr[i].push_back(a);
            ++trg[a];
        }
    }
    for(int i = 1; i <= n; ++i)
        if(!gr[i])
            v[0].push_back(i), tr[i].push_back(0), ++gr[i], ++trg[0];
    d.push_back(0);
    int ans = 0;
    while(!d.empty())
    {
        int nod = d[0];
        st[nod] = ar[nod] - t[nod];
        d.pop_front();
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i];
            ar[vecin] = max(ar[vecin], ar[nod] + t[vecin]);
            ans = max(ans, ar[vecin]);
            --gr[vecin];
            if(gr[vecin] == 0)
                d.push_back(vecin);
        }
    }
    g << ans << '\n';
    for(int i = 0; i <= n; ++i)
        if(!trg[i])
        {
            sf[i] = ans - t[i];
            d.push_back(i), t2[i] = ans;
        }
        else
            sf[i] = -1;
    while(!d.empty())
    {
        int nod = d[0];
        d.pop_front();
        for(int i = 0; i < tr[nod].size(); ++i)
        {
            int vecin = tr[nod][i];
            if(sf[vecin] == -1)
                sf[vecin] = sf[nod] - t[vecin];
            else
                sf[vecin] = min(sf[vecin], sf[nod] - t[vecin]);
            --trg[vecin];
            if(trg[vecin] == 0)
                d.push_back(vecin);
        }
    }
    for(int i = 1; i <= n; ++i)
        g << st[i] << " " << sf[i] << '\n';
    return 0;
}
