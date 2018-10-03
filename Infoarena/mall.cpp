/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("mall.in");
ofstream g("mall.out");
int n,k;
int l,e,h,prag;
int dp[1032][1032];
deque<int>d;
int main()
{
    f>>n>>k;
    memset(dp,-2e9,sizeof(dp));
    for(int i=1;i<=n;++i)
    {
        f>>l>>e>>h>>prag;
        if(i==1)
        {
            for(int j=0;j<prag;++j)
                dp[i][j]=l;
            dp[i][prag]=e;
            for(int j=prag+1;j<=k;++j)
                dp[i][j]=h;
        }
        else
        {
            d.clear();
            for(int j=0;j<=k;++j)
            {
                while(j-d.front()>=prag)
                    d.pop_front();
                while(!d.empty() && dp[i-1][j]>dp[i-1][d.back()])
                    d.pop_back();
                d.push_back(j);
             //   g<<d.front()<<" ";
                dp[i][j]=max(dp[i][j],dp[i-1][d.front()]+l);
            }
           // g<<'\n';
            for(int j=0;j<=k-prag;++j)
                dp[i][j+prag]=max(dp[i][j+prag],dp[i-1][j]+e);
            d.clear();
            for(int j=prag+1;j<=k;++j)
            {
                while(!d.empty() && dp[i-1][j-prag-1]>dp[i-1][d.back()])
                    d.pop_back();
                d.push_back(j-prag-1);
                dp[i][j]=max(dp[i][j],dp[i-1][d.front()]+h);
            }
        }
    }
   // for(int i=1;i<=n;g<<'\n',++i)
   //     for(int j=0;j<=k;++j)
     //       g<<dp[i][j]<<" ";
    g<<dp[n][k];
    return 0;
}
