#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

using namespace std;

typedef long long ll;


ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

int n;

ll dp[2][1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    dp[1][0] = 1;
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        int x = (i-1);
        if(x % 2 == 0)
        {
            int par = (1 + x/2) % 2;
            dp[par][i] = mul(dp[!par][x/2], dp[0][x/2]);
        }
        else
        {
            for(int j = x/2; j <= 1 + x/2; j++)
            {
                int par = (1 + j) % 2;
                dp[par][i] = mul(dp[!par][j], dp[0][i - j - 1]);
            }
        }
    }
    cout << (dp[1][n] + dp[0][n]) % mod;
    return 0;
}

