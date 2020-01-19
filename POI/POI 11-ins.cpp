/*
        POI 11-ins

    Find the centers of the tree using DFS and you have two cases

    1) either one subtree has size (n-1)/2 + (n-1)%2 and n is even(you have to end the path somewhere in the subtree)

    2) otherwise, you can end the path wherever you want.

    Since there are few centers, you can do BFS for each of them and you end up having an O(n) algorithm.

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

// #define fisier 1

using namespace std;

typedef long long ll;

int n, sts[1000002];

vector<int> v[1000002];

vector<pair<int, int> > centri;

void dfs(int dad, int nod)
{
    sts[nod] = 1;
    int mx = 0;
    int wh = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        sts[nod] += sts[vecin];
        if(sts[vecin] > mx)
        {
            mx = sts[vecin];
            wh = vecin;
        }
    }
    if(n - sts[nod] >= mx)
        mx = n - sts[nod], wh = dad;
    if(mx <= (n-1) / 2 + (n-1) % 2)
    {
        if(n % 2 == 0 && mx == (n-1) / 2 + (n-1) % 2)
            centri.pb({nod, wh});
        else
            centri.pb({nod, 0});
    }
}

ll ans[1000002];
int dist[1000002];

bool viz[1000002];
void bfs(int src, int org)
{
    for(int i = 1; i <= n; ++i)
        viz[i] = 0, dist[i] = 0;
    deque<pair<int, int> > d;
    d.pb({src, 1});
    viz[src] = 1;
    int mx = 0;
    while(!d.empty())
    {
        int nod = d[0].fi;
        int ax = d[0].se;
        if(d[0].se)
            mx = max(mx, dist[nod]);
        d.pop_front();
        viz[nod] = 1;
        ans[src] = ans[src] + 2 * dist[nod];
        if(nod == src && org != 0)
        {
            for(int i = 0; i < v[nod].size(); ++i)
            {
                int vecin = v[nod][i];
                if(viz[vecin])
                    continue;
                dist[vecin] = dist[nod] + 1;
                d.pb({vecin, (vecin == org)});
            }
        }
        else
        {
            for(int i = 0; i < v[nod].size(); ++i)
            {
                int vecin = v[nod][i];
                if(viz[vecin])
                    continue;
                dist[vecin] = dist[nod] + 1;
                d.pb({vecin, ax});
            }
        }
    }
    ans[src] -= mx;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0, 1);
    for(int i = 1; i <= n; ++i)
        ans[i] = -1;
    for(int i = 0; i < centri.size(); ++i)
        ans[centri[i].fi] = 0, bfs(centri[i].fi, centri[i].se);
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
    return 0;
}
