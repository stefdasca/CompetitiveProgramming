/*
        IOI 07-flood

    * Let's build a graph, where each wall is an edge and each point is a vertex. For each vertex we will keep
four lists, each of them containing the edge bordering the given vertex, coming from its respective direction.

    * Then, we will sort the coordinates, then for each unvisited coordinate, run DFS, prioritizing going to right,
then straight forward, then left and then backward(spiral shape). If we found a loop, then all the outer walls in the loop will be collapsed.

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

int n, m;
vector<pair<pair<int, int>, int> >v;
vector<pair<int, int> >mch[100005][5];
bool viz[100005];
vector<int> ans;
pair<int, int> p[100005];
int direction(pair<int, int> a, pair<int, int> b)
{
    if(b.fi == a.fi)
    {
        if(b.se > a.se)
            return 0;
        return 2;
    }
    if(b.fi > a.fi)
        return 1;
    return 3;
}
int go(int nod, int dir)
{
    if (viz[nod])
        return nod;
    viz[nod] = 1;
    for(int i = 0; i < 4; ++i)
    {
        int nxt = ((dir + 1) - i + 4) % 4;
        if(mch[nod][nxt].empty())
            continue;
        auto ed = mch[nod][nxt].front();
        mch[nod][nxt].clear();
        int vecin = ed.se;
        mch[vecin][(nxt + 2) % 4].clear();
        int loop = go(vecin, nxt);
        if(!loop)
        {
            ans.pb(ed.fi);
            continue;
        }
        if (loop != nod)
        {
            viz[nod] = 0;
            return loop;
        }
    }
    viz[nod] = 0;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> p[i].fi >> p[i].se;
        v.pb({p[i], i});
    }
    cin >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        mch[a][direction(p[a], p[b])].pb({i, b});
        mch[b][direction(p[b], p[a])].pb({i, a});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); ++i)
        go(v[i].se, 0);
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << '\n';
    return 0;
}
