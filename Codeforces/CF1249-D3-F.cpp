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
 
int n, k, maxi, dp[202][202], prf[202][202], cost[202], lvl[202];
 
vector<int> v[202];
void dfs(int dad, int nod)
{
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        lvl[vecin] = lvl[nod] + 1;
        dfs(nod, vecin);
    }
    // take the current node
    dp[nod][lvl[nod]] = cost[nod];
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        int mxx = prf[vecin][min(201, lvl[nod] + k + 1)];
        dp[nod][lvl[nod]] += mxx;
    }
 
    // don't take it
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        for(int j = lvl[nod] + 1; j <= 200; ++j)
            dp[nod][j] = max(dp[nod][j], dp[vecin][j]);
    }
    int rec[3][n+5];
    int prx[3][n+5];
    memset(rec, 0, sizeof(rec));
    memset(prx, 0, sizeof(prx));
    bool fi = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        if(!fi)
        {
            for(int nxt_lvl = lvl[nod] + 1; nxt_lvl <= n; ++nxt_lvl)
                rec[1][nxt_lvl] = dp[vecin][nxt_lvl];
            fi = 1;
        }
        else
        {
             for(int j = lvl[nod] + 1; j <= n; ++j)
             {
                 int min_lvl = max(lvl[nod] + 1, lvl[nod] + (k + 1) - (j - lvl[nod]));
                 for(int x = min_lvl; x <= n; ++x)
                    rec[2][min(j, x)] = max(rec[2][min(j, x)], prx[1][j] + prf[vecin][x]);
                 rec[2][j] = max(rec[2][j], prf[vecin][j]);
                 rec[2][j] = max(rec[2][j], rec[1][j]);
             }
             for(int bfr = 0; bfr <= n; ++bfr)
                rec[1][bfr] = rec[2][bfr], rec[2][bfr] = 0;
        }
        for(int j = n; j >= 0; --j)
            prx[1][j] = max(prx[1][j+1], rec[1][j]);
    }
    for(int bfr = lvl[nod] + 1; bfr <= n; ++bfr)
        dp[nod][bfr] = max(dp[nod][bfr], rec[1][bfr]);
    for(int i = 0; i <= n; ++i)
        maxi = max(maxi, dp[nod][i]);
    for(int i = n; i >= 0; --i)
        prf[nod][i] = max(dp[nod][i], prf[nod][i+1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> cost[i];
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0, 1);
    cout << maxi;
    return 0;
}
