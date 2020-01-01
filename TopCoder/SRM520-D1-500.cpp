/*
                SRM520-D1-500

    Let's find for each user the number of ways to get to score x. This can be done with DP. Because the recurrence is
of type dp1[i][j] = sum of dp1[i-1][x] for all x smaller than j, we can optimize this using prefix sums.

    Now let's find the number of ways to write the scoreboard, where dp2[i][j] = number of ways to write the scoreboard for the first i
users, if the last score is j

    The recurrence is similar, dp2[i][j] = sum of (dp1[3][x] * dp2[i-1][x]) for all x bigger than j. This can also be written with prefix sums.

    Be careful at the time limit, since it's quite tight. Also, because we don't have enough memory, I kept only the last 2 lines of the dp.


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

int add(int a, int b)
{
    int x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}

ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

int scor[5], dp[200002], ways[200002], sp[200002], mars[200002];

class SRMIntermissionPhase
{
    public:
        int countWays(vector <int> points, vector <string> description)
        {
            scor[0] = points[0];
            scor[1] = points[1];
            scor[2] = points[2];
            int n = (int) description.size();
            for(int i = 1; i <= n; ++i)
            {
                string x = description[i-1];
                dp[0] = 1;
                for(int j = 0; j <= 2; ++j)
                {
                    if(x[j] == 'N')
                        continue;
                    for(int x = 0; x <= 100000; ++x)
                    {
                        mars[x+1] = add(mars[x+1], dp[x]);
                        mars[x+scor[j]+1] = add(mars[x+scor[j]+1], -dp[x]);
                    }
                    for(int x = 1; x <= 200000; ++x)
                    {
                        mars[x] = add(mars[x], mars[x-1]);
                        dp[x] = mars[x];
                        mars[x-1] = 0;
                    }
                    mars[200000] = 0;
                    dp[0] = 0;
                }
                if(i == 1)
                {
                    for(int j = 0; j <= 200000; ++j)
                    {
                        sp[j] = dp[j];
                        if(j)
                            sp[j] = add(sp[j], sp[j-1]);
                        dp[j] = 0;
                    }
                }
                else
                {
                    for(int j = 0; j <= 200000; ++j)
                        ways[j] = mul(dp[j], add(sp[200000], -sp[j])), dp[j] = 0;
                    for(int j = 0; j <= 200000; ++j)
                    {
                        sp[j] = ways[j];
                        if(j)
                            sp[j] = add(sp[j], sp[j-1]);
                    }
                }
            }
            return sp[200000];
        }
};
