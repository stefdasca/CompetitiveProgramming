/*

    * Instead of doing 2*M additions, let's do M operations which will be of 4 types: BB, BR, RB, RR.

    * Since the normal dp[i][j] recurrence(number of ways to do i operations if we are left with j red bricks) will result in overcounting,
Let's define a special operation to consist in doing a RB or RR move when we are left with only 1 red brick(thus, getting to 0 red bricks at some point)

    * Let's define dp[i][j][0/1] = number of ways to do i operations, if we are left with j red bricks and we did a special operation.

    * Thus, we can go from dp[i][j][k] to dp[i+1][j-1][1](RR) if j > 0, to dp[i+1][j][1](RB) if j > 0, to dp[i+1][j][k](RB),
if j < n and dp[i+1][j+1][k](RR) if j < n.

    * The total complexity will be O(n * m).


*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, m;
int add(int a, int b)
{
    int x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
int dp[3002][3002][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i <= n; ++i)
        dp[0][i][(i == 0)] = 1;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j <= n; ++j)
            for(int k = 0; k <= 1; ++k)
            {
                if(j > 0)
                {
                    dp[i + 1][j - 1][k | (j == 1)] = add(dp[i + 1][j - 1][k | (j == 1)], dp[i][j][k]);
                    dp[i + 1][j][k | (j == 1)] = add(dp[i + 1][j][k | (j == 1)], dp[i][j][k]);
                }
                if(j < n)
                {
                    dp[i + 1][j + 1][k] = add(dp[i + 1][j + 1][k], dp[i][j][k]);
                    dp[i + 1][j][k] = add(dp[i + 1][j][k], dp[i][j][k]);
                }
            }
    int ans = 0;
    for(int i = 0; i <= n; ++i)
        ans = add(ans, dp[m][i][1]);
    cout << ans;
    return 0;
}
