// https://www.infoarena.ro/problema/dijkstra

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
int n, m, dist[50002];
vector<pair<int, int> >v[50002];

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp>q;
bool was[50002];
void djk(int st)
{
    for(int i = 1; i <= n; ++i)
        dist[i] = (1<<30);
    dist[st] = 0;
    q.push({0, st});
    while(!q.empty())
    {
        pair<int, int> nod = q.top();
        q.pop();
        if(was[nod.second])
            continue;
        was[nod.second] = 1;
        for(int i = 0; i < v[nod.second].size(); ++i)
        {
            pair<int, int> vecin = v[nod.second][i];
            if(nod.first + vecin.second < dist[vecin.first])
            {
                dist[vecin.first] = nod.first + vecin.second;
                q.push({dist[vecin.first], vecin.first});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        f >> a >> b >> c;
        v[a].pb({b, c});
    }
    djk(1);
    for(int i = 2; i <= n; ++i)
    {
        if(dist[i] == (1<<30))
            dist[i] = 0;
        g << dist[i] << " ";
    }
    g << '\n';
    return 0;
}
