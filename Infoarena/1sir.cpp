#include<bits/stdc++.h>
#define MOD 194767
using namespace std;
ifstream f("1-sir.in");
ofstream g("1-sir.out");
int s,n,dp[3][34000];
int main()
{
    f>>n>>s;
    if(abs(s)>n*(n+1)/2)
    {
        g<<0;
        return 0;
    }
    dp[1][0]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<=(i-1)*i/2;j++)
            dp[i%2][j]=(dp[(i-1)%2][abs(j+1-i)]+dp[(i-1)%2][abs(j-1+i)])%MOD;
    g<<dp[n%2][s];
    return 0;
}
