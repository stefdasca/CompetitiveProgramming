#include<bits/stdc++.h>
using namespace std;
ifstream f("cai.in");
ofstream g("cai.out");
int t,n;
int G[1002],I[1002];
int dp[1002][1002];
int main()
{
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>n;
        for(int j=1;j<=n;++j)
            f>>G[j];
        for(int j=1;j<=n;++j)
            f>>I[j];
        sort(G+1,G+n+1);
        sort(I+1,I+n+1);
        reverse(G+1,G+n+1);
        reverse(I+1,I+n+1);
        // dp[i][j] = costul maxim folosind primii i cai si ultimii j
        int sol=-20000000;
        for(int j=1;j<=n;++j)
        {
            dp[0][j]=dp[0][j-1];
            if(I[j]<G[n-j+1])
                dp[0][j]+=200;
            if(I[j]>G[n-j+1])
                dp[0][j]-=200;
            dp[j][0]=dp[j-1][0];
            if(I[j]<G[j])
                dp[j][0]+=200;
            if(I[j]>G[j])
                dp[j][0]-=200;
        }
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n-j;++k)
            {
                int val1=dp[j-1][k];
                if(I[j+k]<G[j])
                    val1+=200;
                if(I[j+k]>G[j])
                    val1-=200;
                int val2=dp[j][k-1];
                if(I[j+k]<G[n-k+1])
                    val2+=200;
                if(I[j+k]>G[n-k+1])
                    val2-=200;
                dp[j][k]=max(val1,val2);
            }
        for(int j=0;j<=n;++j)
            sol=max(sol,dp[j][n-j]);
        for(int j=0;j<=n;++j)
            for(int k=0;k<=n-j;++k)
                dp[j][k]=0;
        g<<sol<<'\n';
    }
    return 0;
}
