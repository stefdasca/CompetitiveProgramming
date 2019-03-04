/*
		infoarena cifru(https://www.infoarena.ro/problema/cifru)
	
	"Given n and k, find how many permutations of the first n numbers have a period = k. A period of a permutation is the number of 
	times such that if we multiply the permutation by itself, we will get back to the starting permutation"
	
	Firstly, we have to find the divisors of k.
	Then, we can use combinatorics to solve this problem. Firstly, we will compute a matrix where a[i][j] = j! * (i choose j), then we will 
use the formulas to find the number of permutations which have cycles of different lengths, with the total cycle length n. We can use a dp
approach to solve this, based on the matrix computed previously.

*/
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
