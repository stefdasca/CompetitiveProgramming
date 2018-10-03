/// #bettercoderthanshebeautiful
#include<fstream>
using namespace std;
ifstream f("scara3.in");
ofstream g("scara3.out");
int n,k,a,b;
int dp[1203];
int cost[1203];
int wt[1203],ju[1203];
bool isw[1203],isju[1203];
void read()
{
    f>>n;
    f>>k;
    for(int i=1;i<=n;++i)
        dp[i]=1e9;
    for(int i=1;i<=k;++i)
    {
        f>>a>>b;
        isw[a]=1;
        wt[a]=b;
    }
    f>>k;
    for(int i=1;i<=k;++i)
    {
        f>>a>>b;
        isju[a]=1;
        ju[a]=b;
    }
}
void solve()
{
    dp[0]=0;
    for(int i=0;i<n;++i)
    {
      //  g<<dp[i]<<" "<<cost[i]<<'\n';
        if(dp[i]+1<dp[i+1])
        {
            dp[i+1]=dp[i]+1;
            cost[i+1]=cost[i];
        }
        else
            if(dp[i+1]==dp[i]+1)
                cost[i+1]=min(cost[i+1],cost[i]);
        if(isw[i])
            for(int j=i+1;j<=min(n,i+wt[i]);++j)
                if(dp[i]+1<dp[j])
                {
                    dp[j]=dp[i]+1;
                    cost[j]=cost[i];
                }
                else
                    if(dp[j]==dp[i]+1)
                        cost[j]=min(cost[j],cost[i]);
        if(isju[i])
            for(int j=i+1;j<=min(n,i+2*ju[i]);++j)
                if(dp[i]+1<dp[j])
                {
                    dp[j]=dp[i]+1;
                    cost[j]=cost[i]+(j-i)/2+((j-i)&1);
                }
                else
                    if(dp[j]==dp[i]+1)
                        cost[j]=min(cost[j],cost[i]+(j-i)/2+((j-i)&1));
    }
    g<<dp[n]<<" "<<cost[n]<<'\n';
}
int main()
{
    read();
    solve();
    return 0;
}
