/// editorial = https://codeforces.com/blog/entry/59625

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

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
bool viz[1000002];
vector<pair<int, int> >v[1000002];
int ans = 2000000000;
int n, m, k;
void dfs(int nod, int ct, int dst)
{
    if(ct < k && nod == n)
        return;
    viz[nod] = 1;
    if(ct == k)
    {
        if(nod == n)
            ans = min(ans, dst);
        viz[nod] = 0;
        return;
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        if(!viz[vecin])
            dfs(vecin, ct+1, dst + v[nod][i].se);
    }
    viz[nod] = 0;
}
struct ed
{
    int a, b, c;
};
ed ve[1000002];
int dp[3][1000002][6];
int ct[3][1000002];
int fw[3][1000002][6];
int pp;
void dfs2(int nod, int prv, int dist, int nr)
{
    if(nr == 2)
    {
        if(prv == 1 || prv == n || nod == 1 || nod == n)
            return;
        for(int i = ct[pp][nod]; i >= 0; --i)
            if(dist >= dp[pp][nod][i])
            {
                dp[pp][nod][i+1] = dist;
                fw[pp][nod][i+1] = prv;
                break;
            }
            else
            {
                dp[pp][nod][i+1] = dp[pp][nod][i];
                fw[pp][nod][i+1] = fw[pp][nod][i];
            }
        ct[pp][nod] = min(ct[pp][nod] + 1, 4);
        return;
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        dfs2(vecin, nod, dist + v[nod][i].se, nr+1);
    }
}
void solve2()
{
    pp = 1;
    dfs2(1, 0, 0, 0);
    pp = 2;
    dfs2(n, 0, 0, 0);
    if(k == 3)
        for(int i = 0; i < v[n].size(); ++i)
        {
            int vecin = v[n][i].first;
            if(vecin != 1 && dp[1][vecin][1])
                ans = min(ans, dp[1][vecin][1] + v[n][i].second);
        }
    if(k == 4)
        for(int i = 2; i < n; ++i)
            for(int j = 1; j <= ct[1][i]; ++j)
                for(int p = 1; p <= ct[2][i]; ++p)
                {
                    if(fw[2][i][p] == fw[1][i][j])
                        continue;
                    ans = min(ans, dp[1][i][j] + dp[2][i][p]);
                }
    if(k == 5)
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= ct[1][ve[i].a]; ++j)
                for(int p = 1; p <= ct[2][ve[i].b]; ++p)
                    if(fw[1][ve[i].a][j] != ve[i].b && fw[1][ve[i].a][j] != fw[2][ve[i].b][p] && ve[i].a != fw[2][ve[i].b][p])
                        ans = min(ans, dp[1][ve[i].a][j] + ve[i].c + dp[2][ve[i].b][p]);
            for(int j = 1; j <= ct[1][ve[i].b]; ++j)
                for(int p = 1; p <= ct[2][ve[i].a]; ++p)
                    if(fw[1][ve[i].b][j] != ve[i].a && fw[1][ve[i].b][j] != fw[2][ve[i].a][p] && ve[i].b != fw[2][ve[i].a][p])
                        ans = min(ans, dp[1][ve[i].b][j] + ve[i].c + dp[2][ve[i].a][p]);
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ve[i] = {a, b, c};
        v[a].pb({b, c});
        v[b].pb({a, c});
    }
    if(n <= 5 || m <= 5 || k <= 2)
        dfs(1, 0, 0);
    else
        if(k <= 5)
            solve2();
    if(ans == 2000000000)
        ans = -1;
    cout << ans << '\n';
    return 0;
}
