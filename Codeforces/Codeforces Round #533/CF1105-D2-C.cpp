/// 2222 by 1 february, thx

#include<bits/stdc++.h>
#define mod 1000000007
#pragma GCC optimize("O3")
using namespace std;
long long n, l, r;
long long dp[200002][5];
long long countt[5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l >> r;
    dp[0][0] = 1;
    if(r - l + 1 <= 100)
    {
        for(int i = l; i <= r; ++i)
            countt[i % 3]++;
    }
    else
    {
        while(l % 3 != 0)
            countt[l % 3]++, ++l;
        while(r % 3 != 2)
            countt[r % 3]++, --r;
        int diff = r - l;
        for(int i = 0; i <= 2; ++i)
            countt[i % 3] += (diff + 1) / 3;
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <= 2; ++j)
        {
            dp[i+1][j] = (dp[i+1][j] + dp[i][j] * countt[0]) % mod;
            dp[i+1][(j+1) % 3] = (dp[i+1][(j+1)% 3] + dp[i][j] * countt[1]) % mod;
            dp[i+1][(j+2) % 3] = (dp[i+1][(j+2)%3] + dp[i][j] * countt[2]) % mod;
        }
    }
    cout << dp[n][0] << '\n';
    return 0;
}


