/*
        APIO 17-merchant

    We can use binary search on the answer, if we rewrite the given ratio as a - b*mid, thus we reduced the problem
to finding an non-negative cost cycle.

    Instead of finding an non-negative cycle, we will negate the edges and use floyd-warshall.

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

// #define fisier 1

using namespace std;

typedef long long ll;

int n, m, k, buy[102][1002], sell[102][1002];

ll cost[102][102], cost2[102][102];

int maxdif[102][102];

void fw(ll c[102][102])
{
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= k; ++j)
            cin >> buy[i][j] >> sell[i][j];
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cost[i][j] = (1LL<<60);
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = c;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i != j)
                for(int x = 1; x <= k; ++x)
                    if(buy[i][x] != -1 && sell[j][x] != -1)
                        maxdif[i][j] = max(maxdif[i][j], sell[j][x] - buy[i][x]);

    fw(cost);
    ll st = 1;
    ll dr = 1000000000;
    ll ans = 0;
    while(st <= dr)
    {
        ll mid = (st + dr) / 2;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                cost2[i][j] = min(cost[i][j], (1LL<<62)/mid/2) * mid - maxdif[i][j];
        fw(cost2);
        bool ok = 0;
        for(int i = 1; i <= n; ++i)
            if(cost2[i][i] <= 0)
                ok = 1;
        if(ok)
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    cout << ans;
    return 0;
}
