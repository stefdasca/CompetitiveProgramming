/// 2222 by 1 february, thx

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, k;
int dp[200002];
int tier[200002];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    cin >> s;
    s = ' ' + s;
    tier[1] = 1;
    for(int i = 2; i <= n; ++i)
        if(s[i] == s[i-1])
            tier[i] = tier[i-1];
        else
            tier[i] = tier[i-1] + 1;
    int ans = 0;
    for(int i = 0; i <= 25; ++i)
    {
        memset(dp, 0, sizeof(dp));
        char x = 'a' + i;
        for(int j = k; j <= n; ++j)
        {
            if(tier[j] == tier[j - k + 1] && s[j] == x)
                dp[j] = dp[j - k] + 1;
            else
                dp[j] = dp[j - k];
            dp[j] = max(dp[j], dp[j-1]);
            ans = max(ans, dp[j]);
        }
    }
    cout << ans;
    return 0;
}


