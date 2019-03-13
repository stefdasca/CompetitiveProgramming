
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#define mod 1000000007
using namespace std;
long long t,k;
long long dp[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t>>k;
    dp[0]=1;
    for(int i=0;i<100000;++i)
    {
        dp[i]%=mod;
        dp[i+1]+=dp[i];
        dp[i+k]+=dp[i];
    }
    for(int i=2;i<=100000;++i)
        dp[i]=(dp[i]+dp[i-1])%mod;
    dp[0]=0;
    for(int i=1;i<=t;++i)
    {
        int a,b;
        cin>>a>>b;
        long long sol=(dp[b]-dp[a-1]+mod)%mod;
        cout<<sol<<'\n';
    }
    return 0;
}
