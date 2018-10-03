#include<bits/stdc++.h>
#define mod 666013
using namespace std;
ifstream f("derdelus.in");
ofstream g("derdelus.out");
int n,m,p,x,y;
bool bad[1002][1002];
int dp[1002][1002],spV[1002][1002],spO[1002][1002];
int main()
{
    f>>n>>m>>p;
    for(int i=1;i<=p;++i)
    {
        f>>x>>y;
        bad[x][y]=1;
    }
    dp[1][1]=1;
    spV[1][1]=spO[1][1]=1;
    for(int i=2;i<=n;++i)
        for(int j=1;j<=i;++j)
        {
            if(bad[i][j])
            {
                spV[i][j]=spV[i-1][j];
                spO[i][j]=spO[i-1][j-1];
                continue;
            }
            else
            {
                dp[i][j]=spV[i-1][j]-spV[max(0,i-m-1)][j]+spO[i-1][j-1]-spO[max(0,i-m-1)][max(0,j-m-1)];
                while(dp[i][j]<0)
                    dp[i][j]+=mod;
                dp[i][j]%=mod;
                spV[i][j]=(spV[i-1][j]+dp[i][j])%mod;
                spO[i][j]=(spO[i-1][j-1]+dp[i][j])%mod;
            }
        }
    for(int i=1;i<=n;++i)
        g<<dp[n][i]<<" ";
    return 0;
}
