#include<bits/stdc++.h>
using namespace std;
ifstream f("calatorie.in");
ofstream g("calatorie.out");
long long t;
long long n,a,b;
long long dp[52][610];
long long viz[52][610];
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        if(n>1){
            f>>a>>b;
            dp[1][0]=a;
            viz[1][0]=1;
            viz[1][b]=1;
            if(b==0)
                dp[1][0]=0;
            for(long long i=2;i<n;++i)
            {
                f>>a>>b;
                for(long long j=0;j<=550;++j)
                    if(dp[i-1][j] || viz[i-1][j])
                    {
                        if(viz[i][j]==0)
                            viz[i][j]=1,dp[i][j]=dp[i-1][j]+a;
                        else
                            dp[i][j]=min(dp[i][j],dp[i-1][j]+a);
                        if(viz[i][j+b]==0)
                            viz[i][j+b]=1,dp[i][j+b]=dp[i-1][j];
                        else
                            dp[i][j+b]=min(dp[i][j+b],dp[i-1][j]);
                    }
            }
        }
        long long min1=1e9*10;
        if(n==1)
            min1=0;
        for(long long i=0;i<=550;++i)
            if(viz[n-1][i]==1)
                min1=min(min1,dp[n-1][i]+i*i*i*i);
        g<<"Consumul minim = "<<min1<<"."<<'\n';
        memset(dp,0,sizeof(dp));
        memset(viz,0,sizeof(viz));
    }
    return 0;
}
