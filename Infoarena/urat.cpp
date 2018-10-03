#include<bits/stdc++.h>
#define mod 543217
using namespace std;
ifstream f("urat.in");
ofstream g("urat.out");
int n,v[12];
long long sol,dp[500002];
int main()
{
    f>>n;
    sol=1;
    int np=2;
    for(int i=3;i<=n;++i)
    {
        if(i%2==0)
            np+=2;
        sol+=np;
    }
    g<<sol<<'\n';
    dp[2]=2;
    long long p2=1;
    for(int i=3;i<=n;++i)
    {
        if(i&1)
            dp[i]=(dp[i-1]*(i-1))%mod;
        else
            dp[i]=(dp[i-2]*p2*p2)%mod,p2=(p2+1)%mod;
    }
    g<<dp[n]<<'\n';
    if(n%2==0)
    {
        int a=n/2;
        int b=n;
        for(int i=1;i<=n;++i)
            if(i&1)
                g<<a--<<" ";
            else
                g<<b--<<" ";
    }
    else
    {
        int a=n/2+2;
        int b=1;
        for(int i=1;i<n;++i)
            if(i&1)
                g<<a++<<" ";
            else
                g<<b++<<" ";
        g<<b;
    }
    return 0;
}
