
#include<bits/stdc++.h>
using namespace std;
ifstream f("profit.in");
ofstream g("profit.out");
int n,k;
const long long INF=(1LL<<61)-1;
long long v1[2005], v2[2005];
long long dp[3][2005];
int main()
{
    f>>n;
    for (int i = 1; i <= n; ++i)
    {
        f>>v1[i];
        v2[i]=v1[i];
    }
    sort(v1+1,v1+n+1);
    for (int i = 1; i <= n; ++i)
    {
        int x = (i&1);
        dp[x][0] = INF;
        for (int j = 1; j <= n; ++j)
            dp[x][j] = min(dp[x][j - 1], dp[x^1][j] + abs(v1[j] - v2[i]));
    }
    long long sol = dp[(n&1)][n];
    reverse(v1+1, v1+n+1);
    for (int i = n; i >= 1; --i)
    {
        int x = (i&1);
        dp[x][n+1] = INF;
        for (int j = n; j >= 1; --j)
            dp[x][j] = min(dp[x][j + 1], dp[x^1][j] + abs(v1[j] - v2[i]));
    }
    sol = min(sol, dp[1][1]);
    g << sol;
    return 0;
}
