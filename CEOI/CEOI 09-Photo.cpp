/*
        CEOI 09-Photo

    It is quite easy to observe that in any optimal way to arrange the rectangles, the rectangles are either
disjoint or nested.

    Thus, we can define a recursive dp solution, dp[i][j][k] = min number of rectangles to cover
points in range [i, j] (points are sorted first and if more points have the same x coordinate, we keep
only the biggest y coordinate - it makes implementation easier), if the smallest height is k.

    In order to find the answer for a state (i, j, k) we have two different cases:

        1. we either split the range in two parts
        2. we add another rectangle which will cover all the points in the range, thus reducing the range
we need to cover(we will still need bigger rectangles to cover points with bigger height).

    Since we only have n distinct heights, we don't need to keep the values of the dp recurrence for all the possible a
heights, so we need to precompute first some prefix sum to optimize the memory required for the task.

*/
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

// #define fisier 1

using namespace std;

typedef long long ll;

int n, a, ps[200002], dp[102][102][102];
pair<int, int> pct[102];
map<int, int> mp;

int fnd(int st, int dr)
{
    return a / max(1, pct[dr].fi - pct[st].fi);
}
int solve(int st, int dr, int height)
{
    if(dp[st][dr][ps[height]] != -1)
        return dp[st][dr][ps[height]];
    if(st > dr)
        return 0;
    if(pct[st].se <= height)
        return dp[st][dr][ps[height]] = solve(st + 1, dr, height);
    if(pct[dr].se <= height)
        return dp[st][dr][ps[height]] = solve(st, dr - 1, height);
    dp[st][dr][ps[height]] = (1<<30);
    if(ps[fnd(st, dr)] > ps[height])
        dp[st][dr][ps[height]] = min(dp[st][dr][ps[height]], solve(st, dr, fnd(st, dr)) + 1);
    for(int i = st; i < dr; ++i)
        dp[st][dr][ps[height]] = min(dp[st][dr][ps[height]], solve(st, i, height) + solve(i+1, dr, height));
    return dp[st][dr][ps[height]];
}

int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a;
    for(int i = 1; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        mp[a] = max(mp[a], b);
    }
    n = 0;
    for(auto it : mp)
    {
        pct[++n] = it;
        ps[pct[n].se] = 1;
    }
    for(int i = 1; i <= a; ++i)
        ps[i] += ps[i-1];
    memset(dp, -1, sizeof(dp));
    cout << solve(1, n, 0) << '\n';
    return 0;
}
