/*
        CEOI 17-museum(practice session)

    Let's use dp on trees to solve this problem. Let dp[0/1][i][j] be the smallest cost of a path which starts in node i, visits j nodes and it returns
to node i or not(1 = it doesn't return, 0 = it returns)

    In order to compute this, we will use a DFS and a knapsack-like approach to find the answer, which is not really hard to implement using 2 additional
2*(subtree size) 2d arrays.

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

// #define fisier

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
int n, k, x;
int dp[2][10002][10002];
int xtr[10002][10002];

vector<pair<int, int> >v[10002];

vector<int> dp2[2][10002];
vector<int> xtr2[2][10002];
vector<bool> viz2[2][10002];
int sts[10002];
void dfs(int dad, int nod, int cost)
{
    sts[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        if(vecin == dad)
            continue;
        dfs(nod, vecin, v[nod][i].se);
        sts[nod] += sts[vecin];
    }

    dp2[0][nod].resize(sts[nod] + 2, 0);
    dp2[1][nod].resize(sts[nod] + 2, 0);

    xtr2[0][nod].resize(sts[nod] + 2, 0);
    xtr2[1][nod].resize(sts[nod] + 2, 0);

    viz2[0][nod].resize(sts[nod] + 2, 0);
    viz2[1][nod].resize(sts[nod] + 2, 0);


    viz2[0][nod][1] = 1;
    sts[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        if(vecin == dad)
            continue;
        int edcost = v[nod][i].se;
        for(int j = min(k, sts[nod]); j >= 1; --j)
            for(int sz = 1; sz <= min(sts[vecin], k - j); ++sz)
            {
                if(!viz2[1][nod][j + sz] || dp2[0][nod][j] + dp[1][vecin][sz] + edcost < dp2[1][nod][j + sz])
                {
                    dp2[1][nod][j + sz] = dp2[0][nod][j] + dp[1][vecin][sz] + edcost;
                    viz2[1][nod][j + sz] = 1;
                    xtr2[1][nod][j + sz] = xtr[vecin][sz];
                }
                else
                    if(dp2[0][nod][j] + dp[1][vecin][sz] + edcost == dp2[1][nod][j + sz])
                        xtr2[1][nod][j + sz] = min(xtr2[1][nod][j + sz], xtr[vecin][sz]);
                for(int trb = 0; trb <= 1; ++trb)
                {
                    if(!viz2[trb][nod][j + sz] || dp2[trb][nod][j] + dp[0][vecin][sz] + 2 * edcost < dp2[trb][nod][j + sz])
                    {
                        dp2[trb][nod][j + sz] = dp2[trb][nod][j] + dp[0][vecin][sz] + 2 * edcost;
                        viz2[trb][nod][j + sz] = 1;
                        xtr2[trb][nod][j + sz] = xtr2[trb][nod][j];
                    }
                    else
                        if(dp2[trb][nod][j] + dp[0][vecin][sz] + 2 * edcost == dp2[trb][nod][j + sz])
                            xtr2[trb][nod][j + sz] = min(xtr2[trb][nod][j + sz], xtr2[trb][nod][j]);
                }
            }
        sts[nod] += sts[vecin];
    }
    for(int i = 2; i <= min(k, sts[nod]); ++i)
    {
        dp[1][nod][i] = dp2[1][nod][i];
        xtr[nod][i] = xtr2[1][nod][i];
        dp[0][nod][i] = dp2[0][nod][i];
    }
    for(int i = 1; i <= min(k, sts[nod]); ++i)
        xtr[nod][i] += cost;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> x;
    for(int i = 1; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].pb({b, c});
        v[b].pb({a, c});
    }
    dfs(0, x, 0);
    cout << dp[1][x][k] << '\n';
    return 0;
}
