#include<bits/stdc++.h>
#define mod 9001
using namespace std;
ifstream f("propozitie.in");
ofstream g("propozitie.out");
int n,k;
char c[100002];
int dp[100002];
int nrv,pl,s;
int main()
{
    f>>n>>k;
    f>>(c+1);
    dp[0]=1;
    pl=0,s=1;
    for(int i=1;i<=n;++i)
    {
        if(c[i]=='a' || c[i]=='e' || c[i]=='i' || c[i]=='o' || c[i]=='u')
            ++nrv;
        while(nrv>k)
        {
            nrv-=(c[pl]=='a' || c[pl]=='e' || c[pl]=='i' || c[pl]=='o' || c[pl]=='u');
            if(pl)
                s+=-dp[pl-1];
            if(s<0)
                s+=mod;
            ++pl;
        }
        dp[i]=s;
        s+=dp[i];
        if(s>=mod)
            s-=mod;
    }
    g<<dp[n];
    return 0;
}
