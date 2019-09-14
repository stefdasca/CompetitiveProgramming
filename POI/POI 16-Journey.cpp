/*
                    POI 16-Journey

    * After drawing some simple graphs on paper, we can observe that the only graph types which respect the given property are
either the simple cycle, or "onion graph". The onion graph is a graph such that there are only two vertexes with degree bigger than 2,
the degrees of those two edges are equal, and no matter what path you take from one of the vertexes to the other one, the length will be the same.

    * In order to find these graphs, we will split the graph into biconnected components, and for each biconnected component we will test
whether the resulted graph respects one of the two conditions necessary.

    1) if the graph is a simple cycle, we will add to the answer 2 * length of the cycle
    2) if the graph is an onion graph, we will add to the answer 2 * length of the cycle * (k choose 2), where k is the number of paths of the onion graph.

    https://www.youtube.com/watch?v=PRmAUzgbOBI (Errichto has a detailed editorial for this problem, alongside the other POI problems from that contest day)

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

const int MAXN = 500000;

int n, m;
vector<int> v[MAXN + 3], biconn[MAXN + 3];
vector<pair<int, int> >edges;
int preorder[MAXN + 3], low[MAXN + 3], grad[MAXN + 3], dist[MAXN + 3];
ll cycles, length, T;
stack<pair<int, int> >S;
queue<int> Q;
bool vis[MAXN + 3];

bool Bfs(int s, int t)
{
    vis[s] = 1;
    Q.push(s);
    int d = 0;

    while(!Q.empty())
    {
        int nod = Q.front();
        Q.pop();

        for(int i = 0; i < biconn[nod].size(); i++)
        {
            int u = biconn[nod][i];
            if(!vis[u])
            {
                vis[u] = 1;
                dist[u] = dist[nod] + 1;
                Q.push(u);
                if(u != t)
                    d = max(d, dist[u]);
            }
        }
    }

    if(dist[t] <= d)
        return 0;
    return 1;
}

bool Check()
{
    if(edges.size() == 1)
        return 1;
    vector<int> fine;
    for(int i = 0; i < edges.size(); i++)
    {
        int a = edges[i].fi, b = edges[i].se;
        biconn[a].pb(b);
        biconn[b].pb(a);
        grad[a]++;
        grad[b]++;
        if(grad[a] == 3)
            fine.pb(a);
        if(grad[b] == 3)
            fine.pb(b);
        if(fine.size() > 2)
            return 0;
    }

    if(fine.size() == 0)
    {
        if(length == 0)
            length = edges.size();
        if(length != edges.size())
            return 0;
        cycles = (cycles+1) % mod;

        return 1;
    }

    if(fine.size() != 2)
        return 0;

    int x = fine[0], y = fine[1];
    if(grad[x] != grad[y])
        return 0;

    bool esc = Bfs(x, y);
    if(esc == 0)
        return 0;

    if(length == 0)
        length = 2 * dist[y];
    if(2 * dist[y] != length)
        return 0;

    cycles = (1LL * cycles + ((1LL * grad[y] * (grad[y] - 1)) / 2LL) % mod);

    return 1;
}

void Clean()
{
    for(int i = 0; i < edges.size(); i++)
    {
        int a = edges[i].fi, b = edges[i].se;
        biconn[a].clear();
        biconn[b].clear();
        grad[a] = grad[b] = 0;
        vis[a] = vis[b] = 0;
        dist[a] = dist[b] = 0;
    }
    edges.clear();
}

bool dfs(int nod, int dad)
{
    preorder[nod] = ++T;
    low[nod] = preorder[nod];
    bool esc;
    for(int i = 0; i < v[nod].size(); i++)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;

        if(preorder[vecin] == 0)
        {
            S.push(make_pair(nod, vecin));
            esc = dfs(vecin, nod);
            if(esc == 0)
                return 0;
            low[nod] = min(low[nod], low[vecin]);
            pair<int, int> e;
            if(low[vecin] >= preorder[nod])
            {
                do
                {
                    e = S.top();
                    S.pop();
                    edges.pb(e);
                }while(e != make_pair(vecin, nod) && e != make_pair(nod, vecin));
                esc = Check();
                if(esc == 0)
                    return 0;
                Clean();
            }
        }
        else
            if(preorder[vecin] < preorder[nod])
            {
                S.push({nod, vecin});
                low[nod] = min(low[nod], preorder[vecin]);
            }
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    if(m == n-1)
        return cout << "BRAK\n", 0;
    bool check = dfs(1, 0);
    if(check)
    {
        cout << "TAK\n";
        cycles = 2 * cycles * length;
        cycles %= mod;
        cout << length << " " << cycles << '\n';
    }
    else
        cout << "NIE\n";
    return 0;
}
