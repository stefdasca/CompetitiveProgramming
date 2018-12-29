/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
string s;
long long val[100002];
long long dp[100002][5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    s = ' ' + s;
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i-1][0] + (s[i] == 'h') * val[i];
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + (s[i] == 'a') * val[i];
        dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + (s[i] == 'r') * val[i];
        dp[i][3] = min(dp[i-1][2], dp[i-1][3]) + (s[i] == 'd') * val[i];
    }
    long long ans = 0;
    ans = min(min(dp[n][0],dp[n][1]),min(dp[n][2],dp[n][3]));
    cout << ans;
    return 0;
}
