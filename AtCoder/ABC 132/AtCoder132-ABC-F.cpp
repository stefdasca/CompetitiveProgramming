#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
long long n, k, rad, dp[102][40002], dpmare[102][40002];
long long sp[102][40002], sp2[102][40002];
/// dp[i][j] = nr de multimi, ultimul = j
/// dpmare[i][j] = nr de multimi, cel mai mare multiplu posibil e j
long long countt[40002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    rad = sqrt(n);
    for(int i = rad; i >= 1; --i)
    {
        int na = n/(i+1);
        int nb = n/i;
        countt[i] += nb-na;
    }
    if(rad * (rad+1) > n)
        --countt[rad];
    for(int i = 1; i <= rad; ++i)
        dp[1][i] = 1;
    for(int i = 1; i <= rad; ++i)
        dpmare[1][i] = countt[i];
    for(int i = 1; i < k; ++i)
    {
        long long s = 0;
        for(int j = 1; j <= rad; ++j)
            s = (s + dp[i][j]) % mod;
        for(int j = 1; j <= rad; ++j)
            dp[i+1][j] += s;
        for(int j = 1; j <= rad; ++j)
        {
            sp[i+1][1] = (sp[i+1][1] + dpmare[i][j]);
            sp[i+1][j+1] = (sp[i+1][j+1] - dpmare[i][j]);
        }
        for(int j = 1; j <= rad; ++j)
        {
            sp2[i+1][rad] = (sp2[i+1][rad] + dp[i][j]);
            sp2[i+1][j-1] = (sp2[i+1][j-1] - dp[i][j]);
        }
        for(int j = 1; j <= rad; ++j)
        {
            sp[i+1][j] += sp[i+1][j-1];
            dp[i+1][j] = (dp[i+1][j] + sp[i+1][j]) % mod;
        }
        for(int j = rad; j >= 1; --j)
        {
            sp2[i+1][j] += sp2[i+1][j+1];
            dpmare[i+1][j] = (sp2[i+1][j] * countt[j]) % mod;
        }
    }
    long long ans = 0;
    for(int i = 1; i <= rad; ++i)
        ans = (ans + dp[k][i] + dpmare[k][i]) % mod;
    cout << ans;
    return 0;
}
