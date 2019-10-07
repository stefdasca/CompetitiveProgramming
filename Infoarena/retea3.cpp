/*
                        Infoarena retea3

    "Given m*n grid, find how many ways to draw segments between points from consecutive lines
exist such that there are no intersecting segments, modulo 666013"

    * The first and the most obvious observation is that we only need to compute the answer for the
first 2 lines, and then we can raise the answer at power (m-1).

    * We can solve this simpler task using dp. dp[i][j] = number of ways to do the stated requirement
if we link i points from the first line with j points from the second line.
        - dp[i][j] = dp[j][i]
        - if i is 1, dp[i][j] = 2^j
        - otherwise, if j >= i, dp[i][j] = dp[i-1][j] + dp[i-1][j] + 2 * dp[i-1][j-1] + .... + 2^(j-1) * dp[i-1][1];
        - this can be computed in O(n^2) overall using prefix sums.

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ifstream f("retea3.in");
ofstream g("retea3.out");

int m, n;
const int mod = 666013;

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int dp[1002][1002], sp[1002][1002];
int main()
{
    f >> m >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(i <= j)
            {
                if(i == 1 || j == 1)
                    dp[i][j] = pw(2, j);
                else
                {
                    dp[i][j] = dp[i-1][j] + sp[i-1][j];
                    dp[i][j] %= mod;
                }
            }
            else
                dp[i][j] = dp[j][i];
            sp[i][j] = 2 * sp[i][j-1] + dp[i][j];
            sp[i][j] %= mod;
        }
    g << pw(dp[n][n], m - 1) << '\n';
    return 0;
}
