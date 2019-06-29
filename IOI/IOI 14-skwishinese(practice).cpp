// solution = https://www.hackerrank.com/contests/ioi-2014-practice-contest-1/challenges/skwishinese-ioi14/editorial

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
string s;
int dp[402][402][402];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    for(int i = n; i >= 0; --i)
        for(int j = 0; j < n; ++j)
            for(int k = max(j-1, 0); k < n; ++k)
                if(j > k)
                    dp[i][j][k] = 0;
                else
                    if(i >= n)
                        dp[i][j][k] = (1<<20);
                    else
                    {
                        dp[i][j][k] = dp[i+1][j][k];
                        if(s[i] != s[j] && s[i] != s[k])
                            dp[i][j][k] = min(dp[i][j][k], 1 + dp[i+1][j][k]);
                        if(s[i] != s[j] && s[i] == s[k])
                            dp[i][j][k] = min(dp[i][j][k], 1 + dp[i+1][j][k-1]);
                        if(s[i] == s[j] && s[i] != s[k])
                            dp[i][j][k] = min(dp[i][j][k], 1 + dp[i+1][j+1][k]);
                        if(s[i] == s[j] && s[i] == s[k])
                            dp[i][j][k] = min(dp[i][j][k], 1 + dp[i+1][j+1][k-1]);
                    }
    cout << dp[0][0][n-1] << '\n';
    return 0;
}
