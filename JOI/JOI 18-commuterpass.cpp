/*
        JOI 18-commuterpass

    Let's run Dijkstra's algorithm from S and T and find the edges which can lay on the shortest path between S and T. Those edges are the
ones such that distance(S, ai) + distance(ai, T) = distance(S, bi) + distance(bi, T) = distance(S, T), where ai and bi are the nodes which are
connected by the edge.

    Let's run Dijkstra's once more from U and keep another parameter, namely whether we used the shortest path or not and in which way we use it.
Basically, there are 4 cases:

    case 0: we haven't passed through a shortest path edge yet => update distances like in normal dijkstra's
    case 1: we have passed a shortest path edge and the shortest path edges are closer and closer to S => we can either keep using the edge or not
    case 2: we have passed a shortest path edge and the shortest path edges are closer and closer to T => we can either keep using the edge or not
    case 3: we have passed through shortest path edges and we are heading towards V => update distances like in normal dijkstra's

    It can be proved that the complexity is similar to Dijkstra's algorithm, but with a bigger constant factor.

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

// #define fisier

using namespace std;

typedef long long ll;

int n, m;
int s, t;
int u, v;
vector<pair<int, int> >g[200002];
ll shp[2][100002];
bool viz[2][100002];
struct cmp
{
    bool operator()(pair<ll, pair<int, int> > a,pair<ll, pair<int, int> > b)
    {
        return a.fi > b.fi;
    }
};
priority_queue<pair<ll, pair<int, int> >, vector<pair<ll, pair<int, int> > >, cmp> q;

bool was[2][100002];

void djk(int wh, int st)
{
    viz[wh][st] = 1;
    q.push({0, {0, st}});
    while(!q.empty())
    {
        pair<ll, pair<int, int> > nod = q.top();
        q.pop();
        if(was[wh][nod.se.se])
            continue;
        was[wh][nod.se.se] = 1;
        for(int i = 0; i < g[nod.se.se].size(); ++i)
        {
            int vecin = g[nod.se.se][i].fi;
            int cost = g[nod.se.se][i].se;
            if(!viz[wh][vecin] || nod.fi + cost < shp[wh][vecin])
            {
                 shp[wh][vecin] = nod.fi + cost;
                 viz[wh][vecin] = 1;
                 q.push({shp[wh][vecin], {0, vecin}});
            }
        }
    }
    while(!q.empty())
        q.pop();

}

bool viz2[4][100002];
bool was2[4][100002];
ll cost[4][100002];
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> s >> t;
    cin >> u >> v;
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    djk(0, s);
    djk(1, t);

    viz2[0][u] = 1;
    q.push({0, {0, u}});
    while(!q.empty())
    {
        pair<ll, pair<int, int> > nod = q.top();
        q.pop();
        if(was2[nod.se.fi][nod.se.se])
            continue;
        was2[nod.se.fi][nod.se.se] = 1;
        for(int i = 0; i < g[nod.se.se].size(); ++i)
        {
            int vecin = g[nod.se.se][i].fi;
            int cs = g[nod.se.se][i].se;
            if(nod.se.fi == 3)
            {
                if(!viz2[3][vecin] || nod.fi + cs < cost[3][vecin])
                {
                     cost[3][vecin] = nod.fi + cs;
                     viz2[3][vecin] = 1;
                     q.push({cost[3][vecin], {3, vecin}});
                }
            }
            if(nod.se.fi == 2)
            {
                if(shp[0][t] == shp[0][vecin] + shp[1][vecin] && shp[0][t] == shp[0][nod.se.se] + shp[1][nod.se.se] && shp[0][vecin] > shp[0][nod.se.se])
                {
                    if(!viz2[2][vecin] || nod.fi < cost[2][vecin])
                    {
                         cost[2][vecin] = nod.fi;
                         viz2[2][vecin] = 1;
                         q.push({cost[2][vecin], {2, vecin}});
                    }
                }
                else
                {
                    if(!viz2[3][vecin] || nod.fi + cs < cost[3][vecin])
                    {
                         cost[3][vecin] = nod.fi + cs;
                         viz2[3][vecin] = 1;
                         q.push({cost[3][vecin], {3, vecin}});
                    }
                }
            }
            if(nod.se.fi == 1)
            {
                if(shp[0][t] == shp[0][vecin] + shp[1][vecin] && shp[0][t] == shp[0][nod.se.se] + shp[1][nod.se.se] && shp[0][vecin] < shp[0][nod.se.se])
                {
                    if(!viz2[1][vecin] || nod.fi < cost[1][vecin])
                    {
                         cost[1][vecin] = nod.fi;
                         viz2[1][vecin] = 1;
                         q.push({cost[1][vecin], {1, vecin}});
                    }
                }
                else
                {
                    if(!viz2[3][vecin] || nod.fi + cs < cost[3][vecin])
                    {
                         cost[3][vecin] = nod.fi + cs;
                         viz2[3][vecin] = 1;
                         q.push({cost[3][vecin], {3, vecin}});
                    }
                }
            }
            if(nod.se.fi == 0)
            {
                if(shp[0][t] == shp[0][vecin] + shp[1][vecin] && shp[0][t] == shp[0][nod.se.se] + shp[1][nod.se.se] && shp[0][vecin] > shp[0][nod.se.se])
                {
                    if(!viz2[2][vecin] || nod.fi < cost[2][vecin])
                    {
                         cost[2][vecin] = nod.fi;
                         viz2[2][vecin] = 1;
                         q.push({cost[2][vecin], {2, vecin}});
                    }
                }
                else
                    if(shp[0][t] == shp[0][vecin] + shp[1][vecin] && shp[0][t] == shp[0][nod.se.se] + shp[1][nod.se.se] && shp[0][vecin] < shp[0][nod.se.se])
                    {
                        if(!viz2[1][vecin] || nod.fi < cost[1][vecin])
                        {
                             cost[1][vecin] = nod.fi;
                             viz2[1][vecin] = 1;
                             q.push({cost[1][vecin], {1, vecin}});
                        }
                    }
                if(!viz2[0][vecin] || nod.fi + cs < cost[0][vecin])
                {
                     cost[0][vecin] = nod.fi + cs;
                     viz2[0][vecin] = 1;
                     q.push({cost[0][vecin], {0, vecin}});
                }
            }
        }
    }
    ll ans = (1LL<<60);
    for(int i = 0; i <= 3; ++i)
        if(viz2[i][v])
            ans = min(ans, cost[i][v]);
    cout << ans << '\n';
    return 0;
}
