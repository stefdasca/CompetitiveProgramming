/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("triunghi3.in");
ofstream g("triunghi3.out");
unsigned int n,mat[1002][1002],sumparl[1002][1002],sumparc[1002][1002];
long long dp[1002][1002]; /// dp[i][j] = minimul, daca s-au taiat i parti din stanga si j din dreapta
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        for(int L=i,C=1;L>=1;--L,++C)
            f>>mat[L][C];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n-i+1;++j)
        {
            sumparc[i][j]=mat[i][j]+sumparc[i-1][j];
            sumparl[i][j]=mat[i][j]+sumparl[i][j-1];
        }
    for(int i=1;i<=n-1;++i)
        for(int j=i,k=0;j>=0;--j,++k)
            dp[j][k]=1e18;
    for(int i=0;i<=n-2;++i)
        for(int j=i,k=0;j>=0;--j,++k)
        {
            dp[j+1][k]=min(dp[j+1][k],dp[j][k]+(sumparc[n-j-1][j+1]+sumparc[n-j-1][j+2]-sumparc[k][j+1]-sumparc[k][j+2])*(n-i-1)+2*(sumparc[n-j][j+1]-sumparc[k][j+1])-mat[n-j][j+1]-mat[k+1][j+1]);
            dp[j][k+1]=min(dp[j][k+1],dp[j][k]+(sumparl[k+1][n-k-1]+sumparl[k+2][n-k-1]-sumparl[k+1][j]-sumparl[k+2][j])*(n-i-1)+2*(sumparl[k+1][n-k]-sumparl[k+1][j])-mat[k+1][n-k]-mat[k+1][j+1]);
         //   g<<dp[j+1][k]<<" "<<dp[j][k+1]<<'\n';
        }
    long long min1=1e18;
    for(int i=0;i<=n-1;++i)
        min1=min(min1,dp[i][n-i-1]);
    g<<min1;
    return 0;
}
