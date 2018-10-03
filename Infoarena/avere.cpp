#include<bits/stdc++.h>
using namespace std;
ifstream f("avere.in");
ofstream g("avere.out");
int n;
long long nr,dp[702][702],sp[702][702];
int main()
{
    f>>n>>nr;
    dp[1][1]=sp[1][1]=1;
    dp[0][0]=1;
    for(int i=2;i<=n;++i)
        for(int j=1;j<=i;++j)
        {
            if(i!=j)
                dp[i][j]=sp[i-j][min(i-j,j-1)];
            else
                dp[i][j]=1;
            sp[i][j]=sp[i][j-1]+dp[i][j];
        }
    g<<sp[n][n]<<'\n';
    int a=n;
    int b=1;
    while(a)
    {
        while(dp[a][b]<nr)
            nr-=dp[a][b],++b;
        g<<b<<" ";
        a-=b;
        b=1;
    }
    return 0;
}
