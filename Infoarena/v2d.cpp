/*
            Infoarena v2d(https://www.infoarena.ro/problema/v2d)
            
     Translation works fine enough here too :) 
     
     We can reduce this problem to DP. We will run the DP 4 times for each day, starting from each corner of the matrix.
     The complexity will be O(n^2 T), but one has to be quite careful because the time limit is quite tight.
     
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("v2d.in");
ofstream g("v2d.out");
int n, t, q, mat[502][502], nw[502][502];
int dp[5][502][502];
int main()
{
    f >> n >> t >> q;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            f >> mat[i][j];
    for(int i = 1; i <= t; ++i)
    {
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k)
            {
                if(dp[1][j-1][k] - 1 > nw[j][k])
                    nw[j][k] = dp[1][j-1][k] - 1;
                if(dp[1][j][k-1] - 1 > nw[j][k])
                    nw[j][k] = dp[1][j][k-1] - 1;
                dp[1][j][k] = max(mat[j][k], max(dp[1][j-1][k] - 1, dp[1][j][k-1] - 1));
            }
        for(int j = n; j >= 1; --j)
            for(int k = 1; k <= n; ++k)
            {
                if(dp[2][j+1][k] - 1 > nw[j][k])
                    nw[j][k] = dp[2][j+1][k] - 1;
                if(dp[2][j][k-1] - 1 > nw[j][k])
                    nw[j][k] = dp[2][j][k-1] - 1;
                dp[2][j][k] = max(mat[j][k], max(dp[2][j+1][k] - 1, dp[2][j][k-1] - 1));
            }
        for(int j = 1; j <= n; ++j)
            for(int k = n; k >= 1; --k)
            {
                if(dp[3][j-1][k] - 1 > nw[j][k])
                    nw[j][k] = dp[3][j-1][k] - 1;
                if(dp[3][j][k+1] - 1 > nw[j][k])
                    nw[j][k] = dp[3][j][k+1] - 1;
                dp[3][j][k] = max(mat[j][k], max(dp[3][j-1][k] - 1, dp[3][j][k+1] - 1));
            }
        for(int j = n; j >= 1; --j)
            for(int k = n; k >= 1; --k)
            {
                if(dp[4][j+1][k] - 1 > nw[j][k])
                    nw[j][k] = dp[4][j+1][k] - 1;
                if(dp[4][j][k+1] - 1 > nw[j][k])
                    nw[j][k] = dp[4][j][k+1] - 1;
                dp[4][j][k] = max(mat[j][k], max(dp[4][j+1][k] - 1, dp[4][j][k+1] - 1));
            }
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k)
            {
                long long mm = i + 1 + (mat[j][k] + 1LL * i * nw[j][k]) % q;
                mat[j][k] = mm;
                nw[j][k] = 0;
            }
    }
    long long s = 0;
    for(int j = 1; j <= n; ++j)
        for(int k = 1; k <= n; ++k)
            s = (s + mat[j][k]) % q;
    g << s << '\n';
    return 0;
}
