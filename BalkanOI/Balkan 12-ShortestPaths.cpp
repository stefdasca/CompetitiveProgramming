/*
        Balkan 12-ShortestPaths

    My implementation is inspired from this comment: https://codeforces.com/blog/entry/17630?#comment-225408

    Firstly, we run dijkstra from both a and b and we create a shortest path tree from a, which has to contain
nodes on the path from a to b.

    Then, we observe that in this tree, LCA(i, b) will always be on the given path, so we will precompute LCA for
every node i.

    Let's note iz[i] = position where i is on the shortest path from a to b(or 0 if we dont have i from a to b)

    For every edge (x, y) not in path, if iz[LCA(x, b)] < iz[LCA(y, b)], we will update positions in range [iz[LCA(x, b)], iz[LCA(y, b)] - 1]
with value edgecost(x, y) + shortest_path(a, x) + shortest_path(y, b).

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

int n, m, a, b, cost[2002][2002];

bool edg[2002][2002];
vector<pair<int, int> >v[2002];

int shp[2002], sz, iz[2002], tt[2002], lvl[2002];
ll bstpath[2][2002], opt[2002];

set<pair<ll, int> >s;
void djk(int start, int wh)
{
    for(int i = 1; i <= n; ++i)
        bstpath[wh][i] = (1LL<<60);
    bstpath[wh][start] = 0;
    if(wh == 0)
    {
        ll tot = 0;
        for(int i = 1; i <= sz; ++i)
        {
            tt[shp[i]] = shp[i-1];
            bstpath[wh][shp[i]] = tot;
            if(i >= 2)
                lvl[shp[i]] = lvl[shp[i-1]] + 1;
            s.insert({bstpath[wh][shp[i]], shp[i]});
            tot += cost[shp[i]][shp[i+1]];
        }
    }
    else
        s.insert({bstpath[wh][start], start});
    while(!s.empty())
    {
        pair<ll, int> x = *s.begin();
        s.erase(x);
        for(int i = 0; i < v[x.se].size(); ++i)
        {
            int vec = v[x.se][i].fi;
            int cs = v[x.se][i].se;
            if(x.fi + cs < bstpath[wh][vec])
            {
                if(bstpath[wh][vec] != (1LL<<60))
                    s.erase({bstpath[wh][vec], vec});
                bstpath[wh][vec] = x.fi + cs;
                if(wh == 0)
                {
                    lvl[vec] = lvl[x.se] + 1;
                    tt[vec] = x.se;
                }
                s.insert({bstpath[wh][vec], vec});
            }
        }
    }
}
int lca[2002];
void findLCA(int a, int b)
{
    int pz = a;
    if(lvl[a] < lvl[b])
        swap(a, b);
   // cout << a << " " << b << '\n';
   // cout << lvl[a] << " " << lvl[b] << '\n';
    while(lvl[a] > lvl[b])
        a = tt[a];
    while(a != b)
    {
        a = tt[a];
        b = tt[b];
    }
  //  cout << pz << " " << a << '\n';
    lca[pz] = a;
}
void proc(int a, int b, int c)
{
    ll totval = bstpath[0][a] + c + bstpath[1][b];
   // cout << a << " " << b << " " << c << " " << totval << '\n';
    a = lca[a];
    b = lca[b];
    for(int i = iz[a]; i < iz[b]; ++i)
        opt[i] = min(opt[i], totval);
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> a >> b;
    for(int i = 1; i <= m; ++i)
    {
        int x, y, c;
        cin >> x >> y >> c;
        cost[x][y] = cost[y][x] = c;
        v[x].pb({y, c});
        v[y].pb({x, c});
    }
    cin >> sz;
    for(int i = 1; i <= sz; ++i)
    {
        cin >> shp[i];
        opt[i] = (1LL<<60);
        iz[shp[i]] = i;
        edg[shp[i]][shp[i-1]] = edg[shp[i-1]][shp[i]] = 1;
    }
    djk(a, 0);
    djk(b, 1);
    for(int i = 1; i <= n; ++i)
        findLCA(i, b);
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < v[i].size(); ++j)
        {
            int vec = v[i][j].fi;
            if(!edg[i][vec])
                proc(i, vec, v[i][j].se);
        }
    for(int i = 1; i < sz; ++i)
        cout << (opt[i] == (1LL<<60) ? -1 : opt[i]) << '\n';
    return 0;
}
