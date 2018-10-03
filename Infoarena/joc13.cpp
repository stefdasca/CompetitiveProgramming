/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("joc13.in");
ofstream g("joc13.out");
int n,k;
int mat[3][5002];
int dp[3][5002][12];
int main()
{
    f>>n>>k;
    for(int i=1;i<=2;++i)
        for(int j=1;j<=n;++j)
            f>>mat[i][j];
    for(int i=1;i<=2;++i)
        for(int j=1;j<=n;++j)
            for(int q=1;q<=k;++q)
                dp[i][j][q]=-1e9;
    dp[1][1][1]=mat[1][1];
    dp[2][1][1]=mat[1][1]+mat[2][1];
    for(int i=1;i<n;++i)
        for(int j=1;j<=min(i,k);++j)
        {
            dp[1][i+1][j+1]=mat[1][i+1]+dp[1][i][j];
            dp[2][i+1][j+1]=mat[2][i+1]+dp[2][i][j];
            if(j<k)
            {
                dp[2][i+1][1]=max(dp[2][i+1][1],dp[1][i+1][j+1]+mat[2][i+1]);
                dp[1][i+1][1]=max(dp[1][i+1][1],dp[2][i+1][j+1]+mat[1][i+1]);
            }
        }
    /*
    for(int i=1;i<=2;g<<'\n',++i)
        for(int j=1;j<=n;g<<'\n',++j)
            for(int q=1;q<=k;++q)
                g<<dp[i][j][q]<<" ";
    */
    int sol=-1e9;
    for(int i=1;i<=min(n,k);++i)
        sol=max(sol,dp[2][n][i]);
    g<<sol;
    return 0;
}
