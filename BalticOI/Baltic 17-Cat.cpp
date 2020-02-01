/*
        Baltic 17-Cat

    Let's find one of the ends of the diameter of the tree, this can be done using a DFS.

    Then, we are going to find the distances from that leaf to all other nodes and add them in a set.

    At each step, we can take the farthest node which was not taken and not removed from the list of possible good nodes.

    In order to remove the bad nodes, there are multiple approaches, but the one I used involves running BFS at each step
from the next chosen node and stop running after either the distance from the "root" is too big or there was another BFS
where we reached some node earlier than we reached it now.

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

int n, d, nr = 1, dist[200002];
vector<int> tr[200002];
void dfs(int dad, int nod)
{
    if(dist[nod] > dist[nr])
        nr = nod;
    for(int i = 0; i < tr[nod].size(); ++i)
    {
        int vecin = tr[nod][i];
        if(vecin == dad)
            continue;
        dist[vecin] = dist[nod] + 1;
        dfs(nod, vecin);
    }
}
set<pair<int, int> >nods;

bool bad[200002];
int bst[200002];
void dfs2(int dad, int nod)
{
    nods.insert({dist[nod], nod});
    for(int i = 0; i < tr[nod].size(); ++i)
    {
        int vecin = tr[nod][i];
        if(vecin == dad)
            continue;
        dist[vecin] = dist[nod] + 1;
        dfs2(nod, vecin);
    }
}
void bfs(int nod)
{
    deque<pair<int, int> > dq;
    dist[nod] = 0;
    dq.pb({nod, 0});
    bst[nod] = 0;
    while(!dq.empty())
    {
        pair<int, int> state = dq[0];
        dq.pop_front();
        bad[state.fi] = 1;
        if(dist[state.fi] + 1 == d)
            continue;
        for(int i = 0; i < tr[state.fi].size(); ++i)
        {
            int vecin = tr[state.fi][i];
            if(vecin == state.se || bst[state.fi] + 1 >= bst[vecin])
                continue;
            bst[vecin] = bst[state.fi] + 1;
            dist[vecin] = dist[state.fi] + 1;
            dq.pb({vecin, nod});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d;
    for(int i = 2; i <= n; ++i)
    {
        int pi;
        cin >> pi;
        ++pi;
        tr[pi].pb(i);
        tr[i].pb(pi);
    }
    dfs(0, 1);
    dist[nr] = 0;
    dfs2(0, nr);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        bst[i] = (1<<20);
    while(!nods.empty())
    {
        pair<int, int> state = *nods.rbegin();
        nods.erase(*nods.rbegin());
        if(bad[state.se])
            continue;
        ++ans;
        bfs(state.se);
    }
    cout << ans;
    return 0;
}
