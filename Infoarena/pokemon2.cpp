#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
ifstream f("pokemon2.in");
ofstream g("pokemon2.out");
int i, j, N, S, sum = 0;
int x[112], dp[100100];
int main()
{
    f>>N>>S;
    for (i = 1; i <= N; i ++)
        f>>x[i];
    for (i = N - 1; i >= 1; i --)
    {
        sum += x[i];
        S = S - sum;
    }
    dp[0] = 1;
    for (i = 1; i <= N; i ++)
        for (j = 0; j + i <= S; j ++)
            dp[i + j] = (dp[i + j] + dp[j]) % MOD;
    g<<dp[S];
    return 0;
}
