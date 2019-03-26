/*
            Infoarena pitici(https://www.infoarena.ro/problema/pitici)
    
    "Given a directed acyclic graph, where 1 is the highest node and n is the lowest node, find the shortest k different paths starting
from 1 and ending to n"

    We can use dp on DAG to solve this problem, where dp[i][j] = the jth shortest path starting from i to n. In order to speed up the  
transitions, we will use priority queues to get the best k paths for each node.


*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("pitici.in");
ofstream g("pitici.out");
int n, m, k;
int cost[1022][1022];
vector<int>v[1002];
int shp[1022][1022], ct[1022];
int cr, pz, toposort[1022], gr[1022];
int qq;
struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        int aa = shp[a.first][a.second] + cost[qq][a.first];
        int bb = shp[b.first][b.second] + cost[qq][b.first];
        return aa > bb;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
void process(int nod)
{
    qq = nod;
    while(!q.empty())
        q.pop();
    if(nod == n)
    {
        ct[nod] = 1;
        return;
    }
    for(int i = 0; i < v[nod].size(); ++i)
        if(ct[v[nod][i]] >= 1)
            q.push({v[nod][i], 1});
    for(int i = 1; i <= k && !q.empty(); ++i)
    {
        ++ct[nod];
        pair<int, int>x = q.top();
        q.pop();
        shp[nod][i] = shp[x.first][x.second] + cost[nod][x.first];
        ++x.second;
        if(x.second <= ct[x.first])
            q.push(x);
    }
}
int main()
{
    f >> n >> m >> k;
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        f >> a >> b >> c;
        cost[a][b] = c;
        v[a].push_back(b);
        ++gr[b];
    }
    for(int i = 1; i <= n; ++i)
        if(!gr[i])
            toposort[++pz] = i;
    cr = 1;
    while(cr <= n)
    {
        int nod = toposort[cr];
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i];
            --gr[vecin];
            if(gr[vecin] == 0)
                toposort[++pz] = vecin;
        }
        ++cr;
    }
    for(int i = n; i >= 1; --i)
        process(toposort[i]);
    for(int i = 1; i <= k; ++i)
        g << shp[1][i] << " ";
    return 0;
}
