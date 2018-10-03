/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("munte.in");
ofstream g("munte.out");
int Hmax,L,ksp;
int vsp[52];
long long dp[102][52][52][2];
int main()
{
    f>>Hmax>>L>>ksp;
    for(int i=1;i<=ksp;++i)
        f>>vsp[i];
    vsp[ksp+1]=1e9;
    dp[0][0][0][0]=1;
    for(int i=0;i<L;++i)
        for(int j=0;j<=min(i,Hmax);++j)
            for(int q=0;q<=min(i,ksp);++q)
            {
              //  g<<i<<" "<<j<<" "<<q<<" "<<dp[i][j][q][0]<<" "<<dp[i][j][q][1]<<'\n';
                /// R=0;
                dp[i+1][j+1][q+((j+1)==vsp[q+1])][((j+1)==Hmax)]+=dp[i][j][q][0];
                if(j>0)
                    dp[i+1][j][q+(j==vsp[q+1])][0]+=dp[i][j][q][0];
                if(j>1 || (j==1 && i==L-1))
                    dp[i+1][j-1][q+((j-1)==vsp[q+1])][0]+=dp[i][j][q][0];
                /// R=1;
                dp[i+1][j+1][q+((j+1)==vsp[q+1])][1]+=dp[i][j][q][1];
                if(j>0)
                    dp[i+1][j][q+(j==vsp[q+1])][1]+=dp[i][j][q][1];
                if(j>1 || (j==1 && i==L-1))
                    dp[i+1][j-1][q+((j-1)==vsp[q+1])][1]+=dp[i][j][q][1];
            }
    long long sol=dp[L][0][ksp][1];
    g<<sol<<'\n';
    return 0;
}
