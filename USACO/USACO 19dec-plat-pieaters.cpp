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

ifstream f("pieaters.in");
ofstream g("pieaters.out");
ll n, m;
int mx[302][302], dp[302][302];

int bstcut[302][302][302];

int solve(int st, int dr)
{
    if(st > dr)
        return 0;
    if(dp[st][dr] != -1)
        return dp[st][dr];
    dp[st][dr] = 0;
    for(int i = st; i < dr; ++i)
        dp[st][dr] = max(dp[st][dr], solve(st, i) + solve(i+1, dr));
    for(int cut = st; cut <= dr; ++cut)
        dp[st][dr] = max(dp[st][dr], bstcut[st][dr][cut] + solve(st, cut-1) + solve(cut+1, dr));
    return dp[st][dr];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int am, l, r;
        f >> am >> l >> r;
        mx[l][r] = max(mx[l][r], am);
    }
    for(int len = 1; len <= n; ++len)
        for(int j = 1; j + len - 1 <= n; ++j)
        {
            for(int x = j; x <= j + len - 1; ++x)
            {
                bstcut[j][j + len - 1][x] = max(bstcut[j][j + len - 2][x], mx[j][j + len - 1]);
                bstcut[j][j + len - 1][x] = max(bstcut[j][j + len - 1][x], bstcut[j + 1][j + len - 1][x]);
            }
        }
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; ++j)
            dp[i][j] = -1;
    g << solve(1, n) << '\n';
    return 0;
}
