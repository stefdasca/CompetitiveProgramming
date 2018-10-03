#include<bits/stdc++.h>
#define mod 666013
#define mx 7520
using namespace std;
ifstream f("bilute2.in");
ofstream g("bilute2.out");
int n,nr,s;
int dp[mx/10][mx];
bool eq(int nr, int ss)
{
    double avg1=0,avg2=0;
    avg1=(ss+0.0)/(nr+0.0);
    if(nr!=n)
        avg2=(s-ss+0.0)/(n-nr+0.0);
    return (avg1==avg2);
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        for(int j=i-1;j>=1;--j)
            for(int k=1;k<=j*9;++k)
                if(dp[j][k])
                    dp[j+1][k+nr]=(dp[j][k]+dp[j+1][k+nr])%mod;
        dp[1][nr]++;
        s+=nr;
    }
    int sol=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=mx;++j)
            if(dp[i][j] && eq(i,j))
                sol=(sol+dp[i][j])%mod;
    g<<sol<<'\n';
    return 0;
}
