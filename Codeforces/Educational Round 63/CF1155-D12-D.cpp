#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, x;
long long v[300002], dp[300002][5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        dp[i][0] = max(0LL, max(dp[i-1][0] + v[i], v[i]));
        dp[i][1] = max(0LL, max(max(dp[i-1][0], dp[i-1][1]) + v[i] * x, v[i] * x));
        dp[i][2] = max(0LL, max(dp[i-1][2], dp[i-1][1]) + v[i]);
        ans = max(ans, max(dp[i][0], max(dp[i][1], dp[i][2])));
    }
    cout << ans;
    return 0;
}
