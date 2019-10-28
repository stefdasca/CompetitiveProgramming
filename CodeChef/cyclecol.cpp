/*

                CodeChef CYCLECOL

    Let's first find a 4-Coloring of the given graph. We will first color the nodes according to bipartite coloring(we don't care
if the coloring is correct in the end), and then we will color with different colors each node in the connected components resulted
after the first coloring.

    If we find a edge such that both nodes at the ends of the edge have the same color, then we are going backwards from the first node,
until we find the second one, keeping track of the maximum length of the path we found so far.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int t, n, m, col1[100005], col2[100005], viz[100005];
vector<int>v[100005], anscic;

pair<int, int> ed[200002];

void dfs1(int nod, int c)
{
    col1[nod] = c;
    for(int j = 0; j < v[nod].size(); j++)
    {
        int vecin = v[nod][j];
        if(col1[vecin] == -1)
            dfs1(vecin, 1 - c);
    }
}

void dfs2(int nod, int c)
{
    col2[nod] = c;
    for(int j = 0; j < v[nod].size(); j++)
    {
        int vecin = v[nod][j];
        if(col1[nod] == col1[vecin] && col2[vecin] == -1)
            dfs2(vecin, 1 - c);
    }
}

int path(int nod, int sf)
{
    viz[nod] = 1;
    if(nod == sf)
    {
        anscic.pb(nod);
        return 1;
    }
    int ans = 0;
    for(int j = 0; j < v[nod].size(); j++)
    {
        int vecin = v[nod][j];
        if(viz[vecin] == -1 && col1[nod] == col1[vecin] && col2[nod] != col2[vecin])
            ans = max(ans, path(vecin, sf));
    }
    if(ans)
        anscic.pb(nod);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
        {
            v[i].clear();
            col1[i] = col2[i] = viz[i] = -1;
        }
        for(int i = 1; i <= m; ++i)
        {
            int a, b;
            cin >> a >> b;
            ed[i] = {a, b};
            v[a].pb(b);
            v[b].pb(a);
        }
        dfs1(1, 0);
        for(int i = 1; i <= n; i++)
            if(col2[i] == -1)
                dfs2(i, 0);
        for(int i = 1; i <= m; i++)
        {
            int a = ed[i].fi, b = ed[i].se;
            if(col1[a] == col1[b] && col2[a] == col2[b])
            {
                path(a, b);
                break;
            }
        }
        if (!anscic.empty())
        {
            cout << 2 << '\n';
            cout << anscic.size() << '\n';
            for (int i = 0; i < anscic.size(); i++)
                cout << anscic[i] << " ";
            cout << '\n';
            anscic.clear();
        }
        else{
            cout << 1 << '\n';
            for (int i = 1; i <= n; i++)
                cout << col1[i]*2 + col2[i] + 1 << " ";
            cout << '\n';
        }
        for(int i = 1; i <= n; ++i)
        {
            v[i].clear();
            col1[i] = col2[i] = viz[i] = -1;
        }
    }
    return 0;
}
