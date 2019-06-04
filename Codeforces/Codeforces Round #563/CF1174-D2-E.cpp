#include<bits/stdc++.h>
#define mod 1000000007
#pragma GCC optimize("O3")
using namespace std;
int n;
int dp[1000002][22][2];
int ff[25][5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int oo = 0;
    while((1 << (oo + 1)) <= n)
        ++oo;
    dp[1][oo][0] = 1;
    if((1 << (oo - 1)) * 3 <= n)
        dp[1][oo - 1][1] = 1;
    for(int i = 0; i <= 22; ++i)
        for(int j = 0; j <= 4; ++j)
        {
            int pr = 1;
            for(int q = 1; q <= i; q++)
                pr = (pr * 2);
            for(int q = 1; q <= j; ++q)
                pr = (pr * 3);
            ff[i][j] = n / pr;
        }
    for(int i = 1; i < n; ++i)
        for(int j = 0; j <= oo; ++j)
            for(int k = 0; k <= 1; ++k)
            {
                if(ff[j][k] > i)
                {
                    long long ofz = (1LL * dp[i+1][j][k] + 1LL * dp[i][j][k] * (ff[j][k] - i)) % mod;
                    dp[i+1][j][k] = ofz;
                }
                if(j)
                {
                    long long ofz = (1LL * dp[i+1][j-1][k] + 1LL * dp[i][j][k] * (ff[j-1][k] - ff[j][k])) % mod;
                    dp[i+1][j-1][k] = ofz;
                }
                if(k)
                {
                    long long ofz = (1LL * dp[i+1][j][k-1] + 1LL * dp[i][j][k] * (ff[j][k-1] - ff[j][k])) % mod;
                    dp[i+1][j][k-1] = ofz;
                }
            }
    cout << dp[n][0][0];
    return 0;
}
