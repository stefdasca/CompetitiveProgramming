#include<bits/stdc++.h>
#define mod 666013
#define ll long long
using namespace std;
ifstream f("nmult.in");
ofstream g("nmult.out");
int n,k,w;
ll pw(ll b, ll ex)
{
    ll sol=1;
    while(ex)
    {
        if(ex&1)
            sol=(sol*b)%mod;
        b=(b*b)%mod;
        ex>>=1;
    }
    return sol;
}
ll Comb(ll n, ll k)
{
    ll fa=1;
    ll fb=1;
    for(int i=max(k+1,n-k+1);i<=n;++i)
        fa=(fa*i)%mod;
    for(int i=1;i<=min(k,n-k);++i)
        fb=(fb*i)%mod;
    fa=(fa*pw(fb,mod-2))%mod;
    return fa;
}
int main()
{
    f>>n>>k>>w;
    n-=(k-1)*(w-1);
    if(n<k)
        g<<0;
    else
        g<<Comb(n,k);
    return 0;
}
