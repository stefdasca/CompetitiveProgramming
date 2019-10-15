/*
        AtCoder103-ARC-F

    * It is obvious that we need to sort the nodes by their distance sum, thus the nodes with the biggest distances are more likely
to be a leaf or somewhere close to a leaf.

    * We will process the nodes from right to left and we will try to find its parent. If we know the size of the subtree of node p[i],
its parent will have the sum of distances equal to sum of p[i] - n + 2 * subtreesize of p[i](this can be observed after doing some math).
If we don't have such a node, then we will print -1.

    * After we built the tree, we need to check whether the given distances actually match the real distances. If this doesn't happen,
then we will print -1. Otherwise, we will print the tree.

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

ll n, realdist[100002], dist[100002], sts[100002];
vector<int>v[100002];

bool cmp(int a, int b)
{
    return realdist[a] < realdist[b];
}

void dfs(int dad, int nod)
{
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        dist[nod] = dist[nod] + dist[vecin] + sts[vecin];
    }
}
vector<int>p;
void dfs2(int dad, int nod, ll nodes, ll dst)
{
    if(nod == p[0])
    {
        if(dist[nod] != realdist[nod])
        {
            cout << -1;
            exit(0);
        }
    }
    else
    {
        if(dist[nod] + dst != realdist[nod])
        {
            cout << -1;
            exit(0);
        }
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        int new_amount = nodes + sts[nod] - sts[vecin];
        ll new_dist = dst + new_amount + dist[nod] - dist[vecin] - sts[vecin];
        dfs2(nod, vecin, new_amount, new_dist);
    }
}
set<pair<ll, int> >s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> realdist[i];
        s.insert({realdist[i], i});
        p.pb(i);
    }
    sort(p.begin(), p.end(), cmp);
    int z = 0;
    pair<int, int> edg[100002];
    for(int i = n-1; i > 0; --i)
    {
        ++sts[p[i]];
        pair<ll, int> q = *s.lower_bound({realdist[p[i]] - n + 2 * sts[p[i]], 0});
        if(q.first != realdist[p[i]] - n + 2 * sts[p[i]])
        {
            cout << -1;
            return 0;
        }
        sts[q.se] += sts[p[i]];
        v[q.se].pb(p[i]);
        v[p[i]].pb(q.se);
        edg[++z] = {q.se, p[i]};
        if(edg[z].fi > edg[z].se)
            swap(edg[z].fi, edg[z].se);
    }
    sts[p[0]]++;
    dfs(0, p[0]);
    dfs2(0, p[0], 0, 0);
    sort(edg + 1, edg + n);
    for(int i = 1; i < n; ++i)
        cout << edg[i].fi << " " << edg[i].se << '\n';
    return 0;
}
