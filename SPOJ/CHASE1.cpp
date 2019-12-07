/*
            SPOJ CHASE1

    Let's find using a DFS tree the biconnected components of the graph. We will also mark the cycles which will be formed,
since the player A can't lose if he can get to a cycle with at least one turn worth of advantage, since we don't have triangles.

    We will also run BFS from a and b to find the distances, and for each node such that a is closer to it than b, we will find the maximal distance required
for b to get there, and check if that node is part of a cycle(in case of this statement being true, we will print No).


*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

int t, n, m, a, b, E;
int discover_time;
int low[3002];
int dfsnum[3002];
bool in_cycle[3002];
int distA[3002];
int distB[3002];
int head[3002];
struct edge
{
    int v, nxt;
};
edge edges[30002];
stack<int>S;

void dfs(int nod, int dad)
{
    dfsnum[nod] = low[nod] = ++discover_time;
    S.push(nod);
    for(int e = head[nod]; e != -1; e = edges[e].nxt)
    {
        int vecin = edges[e].v;
        if(vecin == dad)
            continue;
        if(!dfsnum[vecin])
        {
            dfs(vecin, nod);
            low[nod] = min(low[nod], low[vecin]);
        }
        else
            low[nod] = min(low[nod], dfsnum[vecin]);
    }
    if(dfsnum[nod] == low[nod])
        if(S.top() != nod)
            for(; ;)
            {
                int x = S.top();
                in_cycle[x] = 1;
                S.pop();
                if(x == nod)
                    break;
            }
        else
            S.pop();
}

void bfs(int src, int dist[])
{
    fill(dist, dist + n + 1, -1);
    dist[src] = 0;
    queue<int> Q;
    Q.push(src);
    while(!Q.empty())
    {
        int nod = Q.front();
        Q.pop();
        for(int e = head[nod]; e != -1; e = edges[e].nxt)
        {
            int vecin = edges[e].v;
            if(dist[vecin] == -1)
            {
                dist[vecin] = dist[nod] + 1;
                Q.push(vecin);
            }
        }
    }
}

int main()
{

    cin >> t;
    for(; t--; )
    {
        E = 0;
        discover_time = 0;
        memset(head, -1, sizeof(head));
        memset(dfsnum, 0, sizeof(dfsnum));
        memset(in_cycle, 0, sizeof(in_cycle));

        cin >> n >> m >> a >> b;
        for(int i = 1; i <= m; ++i)
        {
            int u, v;
            cin >> u >> v;
            edges[E++] = {v, head[u]};
            head[u] = E - 1;
            edges[E++] = {u, head[v]};
            head[v] = E - 1;
        }

        dfs(1, -1);
        bfs(a, distA);
        bfs(b, distB);

        int sol = 0;
        for(int i = 1; i <= n; ++i)
            if(distA[i] < distB[i])
            {
                sol = max(sol, distB[i]);
                if(in_cycle[i])
                {
                    sol = -1;
                    break;
                }
            }

        if(sol == -1)
            cout << "No" << '\n';
        else
            cout << sol << '\n';
    }

    return 0;
}
