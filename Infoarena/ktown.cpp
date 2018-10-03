#include<bits/stdc++.h>
using namespace std;
ifstream f("ktown.in");
ofstream g("ktown.out");
int n,k;
const long long INF=(1LL<<61)-1;
long long v1[3005], v2[3005];
long long dp[3005][3005];
int main()
{
    f>>n>>k;
    for (int i = 1; i <= n; ++i)
    {
        f>>v1[i];
        v1[i]-=1LL*(i-1)*k;
        v2[i]=v1[i];
        dp[i][0]=INF;
    }
    sort(v1+1,v1+n+1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j] + abs(v1[j] - v2[i]));
    g<<dp[n][n];
    return 0;
}
