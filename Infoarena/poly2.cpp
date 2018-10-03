#include<bits/stdc++.h>
#define mod 30103
using namespace std;
ifstream f("poly2.in");
ofstream g("poly2.out");
int n;
long long ans1=1,ans2=1;
long long pw(long long a, long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        ans2=ans2*i%mod;
    for(int i=n+2;i<=n+n;++i)
        ans1=ans1*i%mod;
    g<<ans1*pw(ans2,mod-2)%mod;
    return 0;
}
