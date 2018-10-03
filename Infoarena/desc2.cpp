#include<bits/stdc++.h>
#define mod 10007
using namespace std;
ifstream f("desc2.in");
ofstream g("desc2.out");
int n,k,x;
int dp[10002];
int main()
{
    f>>n>>k>>x;
    n-=k*(k-1)*x/2+k;
    dp[0]=1;
    for(int i=1;i<=k;++i)
        for(int j=0;j+i<=n;++j)
            dp[i+j]=(dp[i+j]+dp[j])%mod;
    g<<dp[n];
    return 0;
}
