/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, x, k, dp[5002][5002], v[5002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> x;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i <= k; ++i)
        dp[1][i] = v[i];
    for(int i = 2; i <= x; ++i)
    {
        deque<int>d;
        for(int j = 1; j <= n; ++j)
        {
            if(!d.empty() && d.front() == j - k - 1)
                d.pop_front();
            if(!d.empty())
                dp[i][j] = dp[i-1][d[0]] + v[j];
            while(!d.empty() && dp[i-1][j] > dp[i-1][d.back()])
                d.pop_back();
            if(dp[i-1][j] != 0)
                d.push_back(j);
        }
    }
    long long maxans = 0;
    for(int i = n - k + 1; i <= n; ++i)
        if(dp[x][i])
            maxans = max(maxans, dp[x][i]);
    if(maxans == 0)
        cout << -1;
    else
        cout << maxans;
    return 0;
}
