/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define mod 666013
using namespace std;
ifstream f("contrasens.in");
ofstream g("contrasens.out");
int n,k;
char a,b;
bool mat[100002][5];
int dp[100002][5];
int sum1,sum2;
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
    {
        f>>a>>b;
        if(a=='1')
            mat[i][2]=1;
        if(b=='1')
            mat[i][3]=1;
    }
    for(int i=1;i<=4;++i)
        dp[1][i]=(mat[1][i]==0);
    for(int i=1;i<=n;++i)
    {
        sum1=(sum1+dp[i][2])%mod;
        sum2=(sum2+dp[i][3])%mod;
        if(i>=k)
        {
            sum1-=dp[i-k][2];
            sum2-=dp[i-k][3];
        }
        if(sum1<0)
            sum1+=mod;
        if(sum2<0)
            sum2+=mod;
        if(i<n)
        {
            dp[i+1][1]=(mod+(i<k)+sum1)%mod;
            dp[i+1][4]=(mod+(i<k)+sum2)%mod;
            if(mat[i+1][2]==0)
                dp[i+1][2]=(dp[i][1]+dp[i][2]+dp[i][3])%mod;
            if(mat[i+1][3]==0)
                dp[i+1][3]=(dp[i][3]+dp[i][2]+dp[i][4])%mod;
        }
    }
    g<<(dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4])%mod;
    return 0;
}
