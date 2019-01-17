/*
                    Infoarena-culmi(infoarena.ro/problema/culmi)

    "Given two integers n and k, find how many paths between (0, 0) and (2n, 0) exist
such that there are k peaks. The available moves are from (i, j) to (i+1, j+1) and (i+1, j-1)
with the condition that j can never be < 0. A peak is a sequence of 2 moves such that the first one
was ascending, and the second one is descending"

    There are two possible approaches for this problem, one of them is based on math and one of them
is based on DP

    The DP approach consists of finding at some point, the number of such paths between (0, 0) and (i, j)
with 0 <= j <= i. Since the memory limit is small, we will have to keep the information just for the last two
states(positions i and i-1). Our recurrence will be dp[pos][up][p][lst][digit], which means the number of ways
to do pos steps, if you used up ascending moves, you had p peaks, and the last move was of type q, where q is 0 or 1
Since the answer can get large and we need to print the full answer, working with big integers and base 1e9 for speeding up
the approach is necessary.

    The other approach, which is faster and more efficient is basically finding that ans(n, k) = N(n, k),
where N(a, b) is the corresponding Narayana number (https://en.wikipedia.org/wiki/Narayana_number)

*/
#include<bits/stdc++.h>
#define base 1e9
#pragma gcc optimize("O3")
using namespace std;
ifstream f("culmi.in");
ofstream g("culmi.out");
int n, k;
int dp[2][102][102][2][6]; // number of first type, special, last, countt
int dg[2][102][102][2];
int c[22], gg;
inline void add(int a[6], int b[6], int c, int &d)
{
    for(int i = 1; i <= c; ++i)
        b[i] += a[i];
    if(c > d)
        d = c;
    for(int i = 1; i <= d; ++i)
    {
        if(b[i] >= base)
        {
            b[i+1]++;
            b[i] -= base;
            if(i == d)
                ++d;
        }
    }
}
int main()
{
    f >> n >> k;
    dp[0][1][0][0][1] = 1;
    dg[0][1][0][0] = 1;
    for(int i = 1; i < 2 * n; ++i)
    {
        int lm = min(n, i);
        for(int j = 0; j <= lm; ++j)
        {
            int difference = j - (i - j);
            if(difference < 0)
                continue;
            for(int z = 0; z <= k; ++z)
                for(int lst = 0; lst <= 1; ++lst)
                {
                    if(!dg[0][j][z][lst])
                        continue;
                    if(j != n)
                        add(dp[0][j][z][lst], dp[1][j + 1][z][0], dg[0][j][z][lst], dg[1][j + 1][z][0]);
                    if(difference == 0)
                        continue;
                    add(dp[0][j][z][lst], dp[1][j][z + (lst == 0)][1], dg[0][j][z][lst], dg[1][j][z + (lst == 0)][1]);
                }
        }
        memcpy(dp[0], dp[1], sizeof(dp[1]));
        memcpy(dg[0], dg[1], sizeof(dg[1]));
        memset(dp[1], 0, sizeof(dp[1]));
        memset(dg[1], 0, sizeof(dg[1]));
    }
    add(dp[0][n][k][1], c, dg[0][n][k][1], gg);
    add(dp[0][n][k][0], c, dg[0][n][k][0], gg);
    for(int i = gg; i >= 1; --i)
    {
        if(i == gg)
            g << c[i];
        else
        {
            long long p = c[i];
            while(p * 10 < base)
                g << 0, p *= 10;
            g << c[i];
        }
    }
    return 0;
}
