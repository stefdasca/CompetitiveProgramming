/*
    "Find the number of n*n binary matrices such that each line has two ones, each column has two ones and there are no
four ones such that they form a rectangle"

    * Let's consider a valid configuration for a n*n matrix. We will label it as (a1, b1), (a2, b2), ..., (an, bn), where (ai, bi)
are the positions of ones on line i. From this configuration we can go to two subsequent configurations:
     1. n lines -> (n+1) lines -> replace (ai, bi) with (ai, n+1) and (bi, n+1) - there are n such options, so ans[i+1] = ans[i+1] + ans[i] * i;
     2. n lines -> (n+2) lines -> replace any pair of two lines with a tuple of four lines - there are n*(n-1)/2 such options,
so ans[i+3] = ans[i+3] + ans[i] * (i+2) * (i+1) / 2;

    At the end, we will multiply by n! to get the final answer.

*/
#include<bits/stdc++.h>
#define mod 200003
using namespace std;
ifstream f("matcnt.in");
ofstream g("matcnt.out");
long long n, fact[100002], dp[100002];
int main()
{
    f >> n;
    fact[0] = 1;
    for(long long i = 1; i <= n; ++i)
        fact[i] = (fact[i-1] * i) % mod;
    dp[3] = 1;
    for(long long i = 4; i <= n; ++i)
    {
        dp[i] += ((dp[i-1] * (i-1)) % mod);
        dp[i] += ((dp[i-3] * (i-1) * (i-2) / 2) % mod);
        dp[i] %= mod;
    }
    for(int i = 3; i <= 10; ++i)
        g << dp[i] << " ";
    g << '\n';
    dp[n] *= fact[n];
    g << dp[n] % mod;
    return 0;
}
