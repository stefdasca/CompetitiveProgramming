/*
        infoarena kcons - Romanian IOI selection task(2010)

    Let's solve the problem for K = 1.

    * Let dp1[i][j] = the number of permutations of the first i numbers such that there are
j groups of 2 consecutive numbers.
      dp1[i][j] = dp1[i-1][j] * (i - j - 1) + dp1[i-1][j-1] + dp1[i-1][j+1] * (j+1)
(we can either put i next to (i-1), put i such that we split one of the (j+1) groups created or put
it anywhere else, without affecting the result)

    The answer will be found in dp1[n][0].

    Now, for K > 1, the problem is equivalent to finding the number of ways to split the array
1, 2, ..., N in groups with length at most k.

    * dp2[i][j] = number of ways to split 1, 2, ..., i in j groups with length at most k.

    Obviously, dp2[i][j] = dp2[i-k][j-1] + dp2[i-k+1][j-1] + ... + dp[i-1][j-1];

    Now, all we have to do is to label each permutation in one split with numbers from 1 to j,
therefore the problem transforms into finding the number of permutations such that there aren't two
consecutive numbers one after another, thing which we have already solved.

    The answer will be sum from 0 to n of dp2[n][i] * dp1[i][0]

*/
#include<bits/stdc++.h>
#define mod 30013
using namespace std;
ifstream f("kcons.in");
ofstream g("kcons.out");
int n, k, dp1[2002][2002], dp2[2002][2002], sp[2002];
int main()
{
    f >> n >> k;
    dp1[1][0] = 1;
    for(int i = 2; i <= n; ++i)
        for(int j = 0; j <= i; ++j)
        {
            dp1[i][j] = dp1[i-1][j] * (i - j - 1) + (j > 0) * dp1[i-1][j-1] + dp1[i-1][j+1] * (j+1);
            dp1[i][j] %= mod;
        }
    dp2[1][1] = 1;
    dp2[0][0] = 1;
    sp[0] = 1;
    sp[1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(i > k)
            for(int j = 0; j <= i; ++j)
            {
                sp[j] = sp[j] - dp2[i - k - 1][j];
                if(sp[j] < 0)
                    sp[j] += mod;
            }
        for(int j = i; j >= 1; --j)
        {
            dp2[i][j] = sp[j-1];
            sp[j] += dp2[i][j];
            if(sp[j] >= mod)
                sp[j] -= mod;
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; ++i)
    {
        ans += dp2[n][i] * dp1[i][0];
        ans %= mod;
    }
    g << ans << '\n';
    return 0;
}
