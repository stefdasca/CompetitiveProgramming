#include<bits/stdc++.h>
using namespace std;
ifstream f("ferma.in");
ofstream g("ferma.out");
int n, k;
int ans = 0;
int v[10002], s[10002];
int dp[1002][10002];
int main()
{
    f >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        f >> v[i];
        s[i] = s[i-1] + v[i];
    }
    for(int i = 1; i <= k; i++)
    {
        int maxi = dp[i-1][i-1] - s[i-1];
        for(int j = i; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j-1], maxi + s[j]);
            maxi = max(maxi, dp[i-1][j] - s[j]);
        }
    }
    ans = max(ans, dp[k][n]);
    for(int i = 1; i <= n; i++)
        dp[1][i] = max(dp[1][i-1], s[i]);
    for(int i = 2; i <= k; i++)
    {
        dp[i][1] = v[1];
        int maxi = 0;
        for (int j = 2; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j-1], s[j] + maxi);
            maxi = max(maxi, dp[i-1][j] - s[j]);
        }
    }
    for (int i = k; i <= n; i++)
        ans = max(ans, dp[k][i] + s[n] - s[i]);
    g << ans;
    return 0;
}
