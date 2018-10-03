#include<bits/stdc++.h>
#define mod 4001
using namespace std;
ifstream f("div3.in");
ofstream g("div3.out");
int n,k,dp[3][5];
bool gut[12];
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
    {
        int nr;
        f>>nr;
        gut[nr]=1;
        int val=nr%3;
    	dp[1][val]++;
    }
    for(int i=2;i<=k;++i)
    {
        for(int j=1;j<=9;++j)
        {
            if(gut[j])
                for(int p=0;p<=2;++p)
                {
                    int nr=(p+j)%3;
                    dp[2][nr]=(dp[2][nr]+dp[1][p])%mod;
                }
        }
    	for(int j=0;j<=2;++j)
            dp[1][j]=dp[2][j];
        dp[2][0]=dp[2][1]=dp[2][2]=0;
    }
    g<<dp[1][0];
    return 0;
}
