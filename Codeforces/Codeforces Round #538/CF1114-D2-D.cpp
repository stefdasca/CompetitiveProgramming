#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int vv[5002];
int frq[5002];
int dp[5002][5002][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int mn = 5001;
    int mx = 0;
    for(int i = 1; i <= n; ++i)
        cin >> vv[i], mn = min(mn, vv[i]), mx = max(mx, vv[i]);
    if(mx == mn)
    {
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i == j)
                dp[i][j][0] = dp[i][j][1] = 0;
            else
                dp[i][j][0] = dp[i][j][1] = (1<<30);
    for(int r = 1; r <= n; ++r)
        for(int l = r; l >= 1; --l)
            for(int e = 0; e != 2; ++e)
            {
                int c = 0;
                if(e == 0)
                    c = vv[l];
                else
                    c = vv[r];
                if(l >= 1)
                    dp[l - 1][r][0] = min(dp[l - 1][r][0], dp[l][r][e] + (c != vv[l - 1]));
                if(r < n)
                    dp[l][r + 1][1] = min(dp[l][r + 1][1], dp[l][r][e] + (c != vv[r + 1]));
            }
    cout << min(dp[1][n][0], dp[1][n][1]) << "\n";
    return 0;
}

