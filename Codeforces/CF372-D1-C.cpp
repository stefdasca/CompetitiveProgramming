#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, m, d;
long long dp[4][150002];
struct events
{
    int a, b, t;
};
events v[502];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> n >> m >> d;
    for(int i = 1; i <= m; ++i)
        cin >> v[i].a >> v[i].b >> v[i].t;
    for(int i = 1; i <= n; ++i)
        dp[1][i] = v[1].b - abs(v[1].a - i);
    for(int p = 2; p <= m; ++p)
    {
        long long dt = min(1LL * n, 1LL * (v[p].t - v[p-1].t) * d);
        deque<int>d;
        for(int i = 1; i <= dt + 1; ++i)
        {
            while(!d.empty() && dp[1][i] > dp[1][d.back()])
                d.pop_back();
            d.push_back(i);
        }
        for(int i = 1; i <= n; ++i)
        {
            if(i > dt + 1)
                if(!d.empty() && d.front() == i - dt - 1)
                    d.pop_front();
            if(i > 1 && i + dt <= n)
            {
                while(!d.empty() && dp[1][i + dt] > dp[1][d.back()])
                    d.pop_back();
                d.push_back(i + dt);
            }
            dp[2][i] = v[p].b - abs(v[p].a - i);
            dp[2][i] += dp[1][d[0]];
        }
        for(int i = 1; i <= n; ++i)
            dp[1][i] = dp[2][i], dp[2][i] = 0;
    }
    long long ans = -(1LL<<62);
    for(int i = 1; i <= n; ++i)
        ans = max(ans, dp[1][i]);
    cout << ans;
    return 0;
}
