#include<bits/stdc++.h>
using namespace std;
ifstream f("carry.in");
ofstream g("carry.out");
int n,k;
char c[100002];
int dp[100002][101],dpt[100002][101];
int main()
{
    f>>n>>k;
    f>>(c+1);
    int mod=30211;
    if(n==1)
    {
        dp[1][0]=9-(c[1]-'0');
        dpt[1][1]=(c[1]-'0');
    }
    else
    {
        dp[n][0]=10-(c[n]-'0');
        dpt[n][1]=(c[n]-'0');
        for(int i=n-1;i>1;--i)
            for(int j=0;j<=k;++j)
            {
                dp[i][j]=(dp[i+1][j]*(10-c[i]+'0')+dpt[i+1][j]*(9-c[i]+'0'))%mod;
                dpt[i][j]=(dpt[i+1][j-1]*(c[i]-'0'+1)+dp[i+1][j-1]*(c[i]-'0'))%mod;
            }
        for(int j=0;j<=k;++j)
        {
            dp[1][j]=(dp[2][j]*(9-c[1]+'0')+dpt[2][j]*(max(0,9-(c[1]+1-'0'))))%mod;
            dpt[1][j]=(dpt[2][j-1]*(min(9,c[1]-'0'+1))+dp[2][j-1]*(c[1]-'0'))%mod;
        }
    }
  //  for(int i=n;i>=1;g<<'\n',--i)
  //      for(int j=0;j<=k;++j)
     //       g<<dp[i][j]+dpt[i][j]<<" ";
    g<<(dp[1][k]+dpt[1][k])%mod;
    return 0;
}
