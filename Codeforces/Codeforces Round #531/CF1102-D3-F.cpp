/// 2222 by 1 february, thx

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, m;
int arr[18][10002];
int mindif[18][18], lf[18][18];
int dp[(1<<17)][17][17]; // max difference if we have mask i, first was j and last is k
bool viz[(1<<17)][17][17];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> arr[i][j];
    if(n == 1)
    {
        int ans = (1<<30);
        for(int i = 1; i < m; ++i)
            ans = min(ans, abs(arr[1][i] - arr[1][i+1]));
        cout << ans;
        return 0;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i != j)
            {
                int mini = (1<<30);
                for(int z = 1; z <= m; ++z)
                    mini = min(mini, abs(arr[i][z] - arr[j][z]));
                mindif[i][j] = mini;
            }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i != j)
            {
                int mini = (1<<30);
                for(int z = 1; z < m; ++z)
                    mini = min(mini, abs(arr[i][z] - arr[j][z+1]));
                lf[i][j] = mini;
            }
    for(int i = 1; i <= n; ++i)
        viz[(1<<(i-1))][i][i] = 1;
    int ans = 0;
    for(int i = 1; i < (1<<n); ++i)
    {
        int nb = 0;
        for(int j = 0; j < n; ++j)
            if(i & (1<<j))
                ++nb;
        if(i == (1<<n) - 1)
        {
            for(int j = 1; j <= n; ++j)
                for(int k = 1; k <= n; ++k)
                    if(viz[i][j][k])
                        ans = max(ans, min(dp[i][j][k], lf[j][k]));
            break;
        }
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k)
            {
                if(!viz[i][j][k])
                    continue;
                for(int p = 1; p <= n; ++p)
                {
                    if(i & (1<<(p-1)))
                        continue;
                    viz[i + (1<<(p-1))][j][p] = 1;
                    if(nb == 1)
                        dp[i + (1<<(p-1))][j][p] = max(dp[i + (1<<(p-1))][j][p], mindif[k][p]);
                    else
                        dp[i + (1<<(p-1))][j][p] = max(dp[i + (1<<(p-1))][j][p], min(dp[i][j][k], mindif[k][p]));
                }
            }
    }
    cout << ans;
    return 0;
}
