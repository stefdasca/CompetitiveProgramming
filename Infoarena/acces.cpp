#include<bits/stdc++.h>
using namespace std;
ifstream f("acces.in");
ofstream g("acces.out");
int m[1002][1002];
int dp[1002][1002];
int x,y,q;
int a,b;
int main()
{
    f>>x>>y;
    for(int i=1;i<=x;++i)
        for(int j=1;j<=y;++j)
            f>>m[i][j];
    for(int i=1;i<=y;++i)
        if(m[1][i]==0)
            dp[1][i]=dp[1][i-1]+1;
        else
            dp[1][i]=0;
    for(int i=1;i<=x;++i)
        if(m[i][1]==0)
            dp[i][1]=dp[i-1][1]+1;
        else
            dp[i][1]=0;
    for(int i=2;i<=x;++i)
        for(int j=2;j<=y;++j){
            if(m[i][j]==0){
                if (dp[i-1][j]>0 && dp[i][j-1]>0)
				{
					dp[i][j]=1+dp[i-1][j]+dp[i][j-1];
                    dp[i][j]=dp[i][j]-max(dp[i-1][j-1],-dp[i-1][j-1]);
				}
				else
					if(dp[i-1][j]>0)
                        dp[i][j]=1+dp[i-1][j];
					else
                        if(dp[i][j-1]>0)
                            dp[i][j]=1+dp[i][j-1];
                        else
                            dp[i][j]=1;
            }
            else
            {
                if (dp[i-1][j]==0 || dp[i][j-1]==0)
					dp[i][j]=0;
				else
                    if (dp[i-1][j]>0 && dp[i][j-1]>0)
                        dp[i][j]=-dp[i-1][j-1];
                    else
                        dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
            }
        }
    f>>q;
    for(int i=1;i<=q;++i)
    {
        f>>a>>b;
        g<<dp[a][b]<<'\n';
    }
    return 0;
}
