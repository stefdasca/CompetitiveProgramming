#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;

ll n, w, b, x;

ll dp[1005][10005], birds[10005], cost[10005];
bool viz[1005][10005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> w >> b >> x;
    for(int i = 1; i <= n; ++i)
        cin >> birds[i];
    for(int i = 1; i <= n; ++i)
        cin >> cost[i];
    dp[1][0] = w;
    viz[1][0] = 1;
    int ans = 0;
    for(int i = 2; i <= n + 1; ++i)
    {
        deque<int> d;
        for(int j = 0; j <= 10000; ++j)
        {
            if(!d.empty() && d.front() == j - birds[i - 1] - 1)
                d.pop_front();
            if(viz[i-1][j])
            {
                while(!d.empty() && dp[i-1][j] >= dp[i-1][d.back()] - 1LL * (j - d.back()) * cost[i-1])
                    d.pop_back();
                d.pb(j);
            }
            if(!d.empty() && dp[i-1][d[0]] - 1LL * (j - d[0]) * cost[i-1] >= 0)
            {
                dp[i][j] = min(w + j * b, dp[i-1][d[0]] - 1LL * (j - d[0]) * cost[i-1] + x);
                viz[i][j] = 1;
                ans = max(ans, j);
            }
        }
    }
    cout << ans;
    return 0;
}
