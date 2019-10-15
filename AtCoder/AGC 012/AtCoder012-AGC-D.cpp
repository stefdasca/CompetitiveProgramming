/*
                AtCoder012-AGC-D

    One can easily observe that we can build a graph based on the given relations, and the answer will therefore
be the product of the number of permutations which we can build from every connected component.

    Now, the challenge consists in reducing the graph to a valid graph, with as few edges as possible.
We can sort the nodes of each color and link them all to the node with the smallest value.

    For nodes with different color, we can observe that we only need to check few nodes.

    Namely, the node with the smallest value(we link it to all the valid possibilities and add in a list
the nodes with the same color, which can be added later)

    For all the subsequent nodes with the same color as the first one, we will try to link them with the smallest
node which was linked with the first one at this step.

    For the second smallest node(the smallest node which doesn't have the same color as the first one), we are going
to link it with the nodes of the same color as the smallest one. If this isn't possible for some nodes, it won't be
possible for every other node, because the nodes are sorted in the order of their value.

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


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int n, x, y;
pair<int, int> p[200002];
vector<int>cols[200002];
vector<int>v[200002];

ll fact[200002], inv[200002];

bool cmp(int a, int b)
{
    return p[a].se < p[b].se;
}

int fiedge[200002], viz[200002];
bool is[200002];
int fr[200002], nr;
vector<int>col;

void dfs(int nod)
{
    if(fr[p[nod].fi] == 0)
        col.pb(p[nod].fi);
    ++fr[p[nod].fi];
    ++nr;
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(!viz[vecin])
            dfs(vecin);
    }
}
ll sol(int start_point)
{
    ll ans = 1;
    nr = 0;
    col.clear();
    dfs(start_point);
    ans = fact[nr];
    for(int i = 0; i < col.size(); ++i)
        ans = mul(ans, inv[fr[col[i]]]), fr[col[i]] = 0;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
    for(int i = 1; i <= n; ++i)
    {
        cin >> p[i].fi >> p[i].se;
        cols[p[i].fi].pb(i);
    }
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        fact[i] = mul(fact[i-1], i);
        inv[i] = pw(fact[i], mod - 2);
    }

    // build edges from nodes with same color

    for(int i = 1; i <= n; ++i)
    {
        sort(cols[i].begin(), cols[i].end(), cmp);
        int pz = 1;
        while(pz < cols[i].size() && p[cols[i][0]].se + p[cols[i][pz]].se <= x)
        {
            v[cols[i][0]].pb(cols[i][pz]);
            v[cols[i][pz]].pb(cols[i][0]);
            ++pz;
        }
    }

    // build edges from nodes with different color

    vector<int>mv;
    for(int i = 1; i <= n; ++i)
        mv.pb(i);
    sort(mv.begin(), mv.end(), cmp);
    vector<int>ne;
    for(int i = 0; i < (int)mv.size(); ++i)
    {
        if(viz[p[mv[i]].fi])
        {
            if(fiedge[p[mv[i]].fi] && p[mv[i]].se + p[fiedge[p[mv[i]].fi]].se <= y)
            {
                v[mv[i]].pb(fiedge[p[mv[i]].fi]);
                v[fiedge[p[mv[i]].fi]].pb(mv[i]);
            }
            continue;
        }
        viz[p[mv[i]].fi] = 1;
        if(i == 0)
        {
            for(int j = i+1; j < mv.size(); ++j)
            {
                if(p[mv[i]].se + p[mv[j]].se > y)
                    break;
                if(i == 0 && p[mv[i]].fi == p[mv[j]].fi)
                {
                    ne.pb(j);
                }
                if(p[mv[i]].fi != p[mv[j]].fi && p[mv[i]].se + p[mv[j]].se <= y)
                {
                    if(!fiedge[p[mv[i]].fi])
                        fiedge[p[mv[i]].fi] = mv[j];
                    v[mv[i]].pb(mv[j]);
                    v[mv[j]].pb(mv[i]);
                }
            }
        }
        else
        {
            for(int x = 0; x < ne.size(); ++x)
            {
                if(p[mv[i]].se + p[ne[x]].se <= y)
                {
                    if(!fiedge[p[mv[i]].fi])
                        fiedge[p[mv[i]].fi] = ne[x];
                    v[mv[i]].pb(ne[x]);
                    v[ne[x]].pb(mv[i]);
                }
            }
            ne.clear();
        }
    }
    memset(viz, 0, sizeof(viz));
    ll ans = 1;
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            ans = mul(ans, sol(i));
    cout << ans;
    return 0;
}
