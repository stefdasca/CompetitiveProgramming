/*

        CF101666-gym-D

    Find with Dijkstra the node towards which each node will point out. These will be the forbidden edges

    Then, using a BFS, we are going to find whether we have a path from 0 to 1 which doesn't use a forbidden edge.

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

typedef long long ll;

int n, m;
vector<pair<int, int> >v[100002];
ll dist[100002];
struct cmp
{
    bool operator()(pair<ll, int> a, pair<ll, int> b)
    {
        return a.fi > b.fi;
    }
};
priority_queue<pair<ll, int>, vector<pair<ll, int> >, cmp> q;
int fw[100002], was[100002];
void djk(int nod)
{
    for(int i = 1; i <= n; ++i)
        dist[i] = (1LL<<60);
    dist[nod] = 0;
    q.push({0, nod});
    while(!q.empty())
    {
        pair<ll, int> nod = q.top();
        q.pop();
        if(was[nod.se])
            continue;
        was[nod.se] = 1;
        for(int i = 0; i < v[nod.se].size(); ++i)
        {
            int vc = v[nod.se][i].fi;
            int d = v[nod.se][i].se;
            if(dist[nod.se] + d < dist[vc])
            {
                dist[vc] = dist[nod.se] + d;
                fw[vc] = nod.se;
                q.push({dist[vc], vc});
            }
        }
    }
}
int viz[100002];
int un[100002];
void bfs(int nod)
{
    deque<int> d;
    d.pb(nod);
    viz[nod] = 1;
    while(!d.empty())
    {
        int nod = d[0];
        d.pop_front();
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i].fi;
            if(vecin != fw[nod] && !viz[vecin])
            {
                viz[vecin] = 1;
                un[vecin] = nod;
                d.pb(vecin);
            }
        }
    }
    if(viz[2])
    {
        vector<int> P;
        P.pb(2);
        int zz = 2;
        while(zz != 1)
        {
            zz = un[zz];
            P.pb(zz);
        }
        cout << P.size() << " ";
        for(int i = P.size() - 1; i >= 0; --i)
            cout << P[i] - 1 << " ";
    }
    else
        cout << "impossible";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ++a, ++b;
        v[a].pb({b, c});
        v[b].pb({a, c});
    }
    djk(2);
    bfs(1);
    return 0;
}
