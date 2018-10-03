#include<bits/stdc++.h>
#define mod 2000003
using namespace std;
ifstream f("sandokan.in");
ofstream g("sandokan.out");
int n,z,k;
long long pw(long long b, int ex)
{
    long long sol=1;
    while(ex)
    {
        if(ex&1)
            sol=(sol*b)%mod;
        b=(b*b)%mod;
        ex/=2;
    }
    return sol;
}
long long Comb(int n, int k)
{
    long long sol=1;
    for(int i=2;i<=n;++i)
        sol=(sol*i)%mod;
    long long a=1;
    long long b=1;
    for(int i=1;i<=k;++i)
        a=(a*i)%mod;
    for(int i=1;i<=n-k;++i)
        b=(b*i)%mod;
    sol=(sol*pw(a,mod-2))%mod;
    sol=(sol*pw(b,mod-2))%mod;
    return sol;
}
int main()
{
    f>>n>>z;
    k=n%(z-1);
    if(k==0)
        k=z-1;
    --k;
    --n;
    g<<Comb(n,k);
    return 0;
}
