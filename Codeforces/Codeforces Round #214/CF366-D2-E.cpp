#include<bits/stdc++.h>
using namespace std;
int n, m, k, s, v[100002], a[2002][2002], ds[11][11], dp[2002][2002][5];
int ans;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k >> s;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for(int i = 1; i <= s; ++i)
        cin >> v[i];
    for(int z = 1; z <= k; ++z)
    {
        for(int j = 0; j <= n+1; ++j)
            for(int q = 0; q <= m+1; ++q)
                dp[j][q][1] = dp[j][q][2] = dp[j][q][3] = dp[j][q][4] = 13495493;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
            {
                dp[i][j][1] = min(dp[i-1][j][1], dp[i][j-1][1]);
                if(a[i][j] == z && dp[i][j][1] > i + j)
                    dp[i][j][1] = i+j;
                ds[a[i][j]][z] = max(ds[a[i][j]][z], (i+j) - dp[i][j][1]);
            }
        for(int i = 1; i <= n; ++i)
            for(int j = m; j >= 1; --j)
             {
                dp[i][j][2] = min(dp[i-1][j][2], dp[i][j+1][2]);
                if(a[i][j] == z &&  dp[i][j][2] > i + (m - j) )
                    dp[i][j][2] = i + (m - j);
                ds[a[i][j]][z] = max(ds[a[i][j]][z], (i + (m - j)) - dp[i][j][2]);
            }
        for(int i = n; i >= 1; --i)
            for(int j = 1; j <= m; ++j)
            {
                dp[i][j][3] = min(dp[i+1][j][3], dp[i][j-1][3]);
                if(a[i][j] == z && dp[i][j][3] > (n - i) + j)
                    dp[i][j][3] = (n - i) + j;
                ds[a[i][j]][z] = max(ds[a[i][j]][z], ((n - i) + j) - dp[i][j][3]);
            }
        for(int i = n; i >= 1; --i)
            for(int j = m; j >= 1; --j)
             {
                dp[i][j][4] = min(dp[i+1][j][4], dp[i][j+1][4]);
                if(a[i][j] == z && dp[i][j][4] > (n - i) + (m - j))
                      dp[i][j][4] = (n - i) + (m - j);
                ds[a[i][j]][z] = max(ds[a[i][j]][z], (n - i) + (m - j) - dp[i][j][4]);
            }  
    }
    for(int i = 1; i + 1 <= s; ++i)
        ans = max(ans, ds[v[i]][v[i+1]]);
    cout << ans;
    return 0;
}