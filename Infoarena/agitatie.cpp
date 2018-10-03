#include <bits/stdc++.h>
using namespace std;
ifstream f("agitatie.in");
ofstream g("agitatie.out");
int n,i,j,ind,v[3010],s[3010],dp[2][3010];
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
        f>>v[i]>>s[i];
    for(i=n;i>=1;--i)
        for(j=3000,ind^=1,dp[ind][j+1]=1<<30;j>=0;--j)
            dp[ind][j]=min(dp[ind][j+1],abs(v[i]+s[i]*j)+dp[ind^1][j]);
    g<<dp[ind][0];
    return 0;
}
