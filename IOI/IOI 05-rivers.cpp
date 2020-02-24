/*
        IOI 05-rivers

    We can solve this problem using dp on trees.

    Let dp[i][j] = the smallest cost if the subtree with root at node i has j sawmills(and node i has a sawmill too).

    In order to find dp[i][j], we need to use a knapsack-like approach, while making sure that we don't choose nodes which intersect
(their subtrees' intersections are disjoint).

    In order to speed up computing, we will need to precompute pret[i][j] = cost to bring to node i the nodes with label numbers 0...j(according to dfs order)
which are in subtree of node i.

    Overall, the complexity is O(n^3 k^2) but with low constant because it's a tree problem.

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

int n, k, wood[102], st[102], dr[102], m = -1, dist[102], poz[102], sts[102];

vector<pair<int, int> >v[102];

int dp[102][52], pret[102][102];


void dfs(int dad, int nod)
{
    ++m;
    st[nod] = m;
    poz[m] = nod;
    sts[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        int cost = v[nod][i].se;
        if(vecin == dad)
            continue;
        dist[vecin] = dist[nod] + cost;
        dfs(nod, vecin);
        sts[nod] += sts[vecin];
    }
    dr[nod] = m;
}
void dfs2(int dad, int nod)
{
    int dpprev[102][52];
    for(int i = 0; i <= 101; ++i)
        for(int j = 0; j <= 51; ++j)
            dpprev[i][j] = (1<<30);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        int cost = v[nod][i].se;
        dfs2(nod, vecin);
    }
    dpprev[dr[nod]][0] = pret[nod][dr[nod]];
    if(st[nod])
        dpprev[st[nod] - 1][0] = 0;
    bool viz[102] = {0};
    if(st[nod])
        viz[st[nod] - 1] = 1;
    for(int j = st[nod] + 1; j <= dr[nod]; ++j)
    {
        int nod2 = poz[j];
        for(int prev = st[nod] - 1; prev < j; ++prev)
        {
            if(prev >= 0 && !viz[prev])
                continue;
            for(int q = 1; q <= min(sts[nod2], k); ++q)
                if(dp[nod2][q] < (1<<30))
                    for(int cum = 0; q + cum <= min(sts[nod], k); ++cum)
                        dpprev[dr[nod2]][cum + q] = min(dpprev[dr[nod2]][cum + q], dp[nod2][q] + (prev >= 0) * dpprev[prev][cum] + pret[nod][j - 1] - (prev >= 0) * pret[nod][prev]);
            viz[dr[nod2]] = 1;
        }
    }
    for(int i = 0; i <= k; ++i)
        dp[nod][i + (nod != 0)] = (1<<30);
    for(int i = 0; i <= k; ++i)
        for(int j = st[nod] - 1; j <= dr[nod]; ++j)
            dp[nod][i + (nod != 0)] = min(dp[nod][i + (nod != 0)], dpprev[j][i] + pret[nod][dr[nod]] - pret[nod][j]);
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        int a, b;
        cin >> wood[i] >> a >> b;
        v[a].pb({i, b});
    }
    dfs(-1, 0);
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
        {
            if(j)
                pret[i][j] = pret[i][j-1];
            if(st[i] <= j && j <= dr[i])
                pret[i][j] += 1LL * wood[poz[j]] * (dist[poz[j]] - dist[i]);
        }
    dfs2(-1, 0);
    cout << dp[0][k] << '\n';
    return 0;
}
