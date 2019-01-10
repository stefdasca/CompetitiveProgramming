/*
                                            Infoarena amici2
                                (https://www.infoarena.ro/problema/amici2)

    "Given an undirected graph with n vertexes and m edges, estimate in how many days the given graph will become complete.
During a certain day, if there is no edge between nodes a and b but there is another node c such that there are
edges between a and c, respectively b and c, there will be created an edge between a and b."

    The first approach everyone would use is to try to do BFS from each starting node, but this is O(n * (n + m)) and it's sadly too
bad for this problem.
    Since we don't have to print the exact answer(if answer is X, X - 1 and X + 1 are accepted as well), we can run BFS from just
one arbitrary node. Since the farthest edge will be at least at (true diameter / 2) distance, the answer will be acceptable, because
true answer is Log2(true diameter of graph), thing which can be found by drawing some graphs on paper


*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("amici2.in");
ofstream g("amici2.out");
int t, n, m;
vector<int>v[21002];
map<pair<int, int>, int>mp;
int gr[21002];
int dist[21002], ans;
void bfs(int stp)
{
    deque<int>d;
    d.push_back(stp);
    while(!d.empty())
    {
        int nod = d[0];
        d.pop_front();
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i];
            if(vecin != stp && dist[vecin] == 0)
            {
                dist[vecin] = dist[nod] + 1;
                d.push_back(vecin);
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        ans = max(ans, dist[i]);
}
int main()
{
    f >> t;
    for(; t; --t)
    {
        for(int i = 1; i <= n; ++i)
            v[i].clear(), gr[i] = 0, dist[i] = 0;
        mp.clear();
        f >> n >> m;
        for(int i = 1; i <= m; ++i)
        {
            int a, b;
            f >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        ans = 0;
        bfs(1);
        int sol = 0;
        while((1<<sol) < ans)
            ++sol;
        g << sol << '\n';
    }
    return 0;
}
