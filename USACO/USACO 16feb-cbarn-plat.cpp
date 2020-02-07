/*
        USACO 16feb-cbarn-plat

    This problem can be solved using divide and conquer DP. We can precompute mincost[i][j] = min cost to move cows to positions [i, j]
if we open the door at position i.

    For each rotation of the circle, we are going to use DP. Let dp[i][j] = mincost to move the cows from start_pos to i opening j doors.
The recurrence is basically

    * j = 1 => dp[i][j] = mincost[start_pos][i]
    * j > 1 => dp[i][j] = min(dp[x][j-1] + mincost[x+1][i]), for all possible x.

    Since dp[i][j] is increasing if we fix j, while mincost[i][j] is decreasing if we fix i, opt[i][j] >= opt[i-1][j], so we can run D&C DP.

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

#define fisier 1

using namespace std;

typedef long long ll;

int n, k;

int v[2002];

ll mincost[2002][2002];

ll dp[2002][8], ans = (1LL<<60);

int opt[2002][8];

void divide(int st, int dr, int optst, int optdr, int ct)
{
    if(st > dr)
        return;
    int mid = (st + dr) / 2;
    dp[mid][ct] = (1LL<<60);
    int poz = -1;
    for(int i = min(optst, mid); i <= min(optdr, mid); ++i)
    {
        if(dp[i][ct-1] + mincost[i+1][mid] < dp[mid][ct])
        {
            dp[mid][ct] = dp[i][ct-1] + mincost[i+1][mid];
            poz = i;
        }
    }
    divide(st, mid - 1, optst, poz, ct);
    divide(mid + 1, dr, poz, optdr, ct);
}

void solve(int start_pos)
{
    for(int ct = 1; ct <= k; ++ct)
    {
        if(ct == 1)
            for(int j = start_pos + ct - 1; j <= start_pos + n - 1; ++j)
                dp[j][ct] = mincost[start_pos][j];
        else
            divide(start_pos, start_pos + n - 1, start_pos, start_pos + n - 1, ct);
    }
    ans = min(ans, dp[start_pos + n - 1][k]);
}
int main()
{

    #ifdef fisier
        ifstream f("cbarn.in");
        ofstream g("cbarn.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    f >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        f >> v[i];
        v[n+i] = v[i];
    }
    for(int start = 1; start <= n+n; ++start)
        for(int sf = start; sf <= min(n+n, start + n - 1); ++sf)
            mincost[start][sf] = mincost[start][sf - 1] + (sf - start) * v[sf];
    for(int start_pos = 1; start_pos <= n; start_pos++)
    {
        memset(dp, 0, sizeof(dp));
        solve(start_pos);
    }
    g << ans;
    return 0;
}
