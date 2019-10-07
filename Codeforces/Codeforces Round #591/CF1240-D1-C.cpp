
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, k, t;
vector<pair<int, int> >v[500002];
ll dp[3][500002];
int cc[500002];
void dfs(int dad, int nod)
{
    vector<pair<int, int> >c;
    vector<ll>sp, sp2, sp3;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        if(vecin == dad)
            continue;
        cc[vecin] = v[nod][i].se;
        dfs(nod, vecin);
        c.pb({v[nod][i].se + dp[0][vecin] - dp[1][vecin], vecin});
    }
    sort(c.begin(), c.end());
    sp.resize(c.size());
    sp2.resize(c.size());
    sp3.resize(c.size());
    for(int i = 0; i < c.size(); ++i)
    {
        if(i == 0)
            sp[i] = dp[0][c[i].se];
        else
            sp[i] = sp[i-1] + dp[0][c[i].se];
        if(i == 0)
            sp2[i] = dp[1][c[i].se];
        else
            sp2[i] = sp2[i-1] + dp[1][c[i].se];
        if(i == 0)
            sp3[i] = cc[c[i].se];
        else
            sp3[i] = cc[c[i].se] + sp3[i-1];
    }
    if(c.size())
        dp[0][nod] = dp[1][nod] = sp2[c.size() - 1];
    for(int i = c.size() - 1; i >= 0; --i)
    {
        if(c.size() - i > k)
            break;
        if(c.size() - i < k)
        {
            if(i > 0)
            {
                dp[1][nod] = max(dp[1][nod], sp3[c.size() - 1] - sp3[i-1] + sp[c.size() - 1] - sp[i-1] + sp2[i-1]);
                dp[0][nod] = max(dp[0][nod], sp3[c.size() - 1] - sp3[i-1] + sp[c.size() - 1] - sp[i-1] + sp2[i-1]);
            }
            else
            {
                dp[1][nod] = max(dp[1][nod], sp3[c.size() - 1] + sp[c.size() - 1]);
                dp[0][nod] = max(dp[0][nod], sp3[c.size() - 1] + sp[c.size() - 1]);
            }
        }
        if(c.size() - i == k)
        {
             if(i > 0)
                dp[1][nod] = max(dp[1][nod], sp3[c.size() - 1] - sp3[i-1] + sp[c.size() - 1] - sp[i-1] + sp2[i-1]);
             else
                dp[1][nod] = max(dp[1][nod], sp3[c.size() - 1] + sp[c.size() - 1]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i)
            v[i].clear(), dp[0][i] = dp[1][i] = 0;
        for(int i = 1; i < n; ++i)
        {
            int x, y, cost;
            cin >> x >> y >> cost;
            v[x].pb({y, cost});
            v[y].pb({x, cost});
        }
        dfs(0, 1);
        cout << max(dp[0][1], dp[1][1]) << '\n';
    }
    return 0;
}
