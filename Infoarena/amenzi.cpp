/*
        Infoarena amenzi

    "Given an undirected graph with n vertexes and m edges, and k events(if one is at node a at time b, he gets c points),
answer to p queries of type a b, where one has to find the biggest number of points one can get in b seconds, if he is at node a then
or print -1 if he can't get there at time b. The start point is node 1 at time 0"

    We can use dp and prefix max to get O(n * Tmax), where Tmax is guaranteed to be at most 3500

*/
#include<bits/stdc++.h>
#pragma gcc optimize("O3")
using namespace std;
ifstream f("amenzi.in");
ofstream g("amenzi.out");
int n, m, k, p;
int xtr[3502][152], mx[3502][152];
vector<pair<int, int> >v[152];
bool viz[3502][152];
int main()
{
    f >> n >> m >> k >> p;
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        f >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for(int i = 1; i <= k; ++i)
    {
        int a, b, c;
        f >> a >> b >> c;
        ++b;
        xtr[b][a] += c;
    }
    viz[1][1] = 1;
    for(int i = 1; i <= 3501; ++i)
        for(int j = 1; j <= n; ++j)
        {
            for(int q = 0; q < v[j].size(); ++q)
            {
                int vec = v[j][q].first;
                int timp = v[j][q].second;
                if(i-timp <= 0 || !viz[i-timp][vec])
                    continue;
                viz[i][j] = 1;
                mx[i][j] = max(mx[i][j], mx[i-timp][vec]);
            }
            viz[i][j] |= viz[i-1][j];
            if(viz[i][j])
                mx[i][j] = max(mx[i][j], mx[i-1][j]) + xtr[i][j];
        }
    for(int i = 1; i <= p; ++i)
    {
        int maax = -1;
        int a, b, c;
        f >> a >> b;
        ++b;
        if(viz[b][a])
            maax = mx[b][a];
        g << maax << '\n';
    }
    return 0;
}
