/*
        infoarena padurari

    "Given n integers sorted in increasing order, take k pairs such that you minimize sum(max(ai.first, ai.second) - max(ai.first, ai.second))"

    This task is solvable with aliens dp.

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ifstream f("padurari.in");
ofstream g("padurari.out");
ll n, k, v[200002];
pair<ll, ll> dp[200002];
int get(int penalty)
{
    dp[0] = dp[1] = {0, 0};
    for(int i = 2; i <= n; i++)
    {
        if(dp[i - 1].first < dp[i - 2].first + v[i] - v[i - 1] - penalty)
            dp[i] = dp[i - 1];
        else
            dp[i] = {dp[i - 2].first + v[i] - v[i - 1] - penalty, dp[i - 2].second + 1};
    }
    return dp[n].second;
}
int main()
{
    f >> n >> k;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    int st = 0;
    int dr = 1000000000;
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(get(mid) >= k)
            dr = mid - 1;
        else
            st = mid + 1;
    }
    get(st);
    g << dp[n].first + 1LL * k * st;
    return 0;
}
