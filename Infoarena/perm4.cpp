#include <bits/stdc++.h>
using namespace std;
ifstream f("perm4.in");
ofstream g("perm4.out");
const int MOD = 666013, N = 3005;
int dp[2][N];
int n, k;
int main() {
    f >> n >> k;
    dp[1][0] = 1;
    for (int i = 2; i <= n; ++i){
        swap(dp[0], dp[1]);
        dp[1][0] = (dp[0][0] * (i - 1) + dp[0][1]) % MOD;
        for (int j = 1; j < i; ++j)
            dp[1][j] = (dp[0][j - 1] + dp[0][j] * (i - j - 1) + dp[0][j + 1] * (j + 1)) % MOD;
    }
    g<< dp[1][k] <<'\n';
    return 0;
}
