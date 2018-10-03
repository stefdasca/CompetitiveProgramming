/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define mod 31607
using namespace std;
ifstream f("drumuri1.in");
ofstream g("drumuri1.out");
int n,m,k,l,sol;
bool isToken[252][252];
int dp[3][252][252];
int main()
{
    f>>n>>m>>k>>l;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        f>>x>>y;
        isToken[x][y]=1;
    }
    dp[1][1][isToken[1][1]]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(i+j==2)
                continue;
            for(int K=0;K<=k;++K)
            {
                if(i>=2)
                    dp[i%2][j][K]=0;
                if(isToken[i][j] && k>0)
                    dp[i%2][j][K]=(dp[i%2][j-1][K-1]+dp[(i-1)%2][j][K-1])%mod;
                if(!isToken[i][j])
                    dp[i%2][j][K]=(dp[i%2][j-1][K]+dp[(i-1)%2][j][K])%mod;
            }
            if(i+j-1==l)
                sol=(sol+dp[i%2][j][k])%mod;
        }
    g<<sol;
    return 0;
}
