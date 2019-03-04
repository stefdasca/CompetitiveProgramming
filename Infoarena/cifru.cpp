#include<bits/stdc++.h>
#define mod 19997
using namespace std;
ifstream f("cifru.in");
ofstream g("cifru.out");
int n, k;
int ar[2002][2002];
long long dp[2002];
int main()
{
    f >> n >> k;
    ar[0][0] = ar[1][0] = ar[1][1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        ar[i][0] = 1;
        for(int j = 1; j <= i; ++j)
        {
            ar[i][j] = ar[i-1][j] + ar[i-1][j-1] * j;
            ar[i][j] %= mod;
        }
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
		for(int j = 1; j <= i; j++)
			if(k % j == 0)
				dp[i] = (dp[i] + ar[i - 1][j - 1] * dp[i - j]) % mod;
    g << dp[n] << '\n';
    return 0;
}
