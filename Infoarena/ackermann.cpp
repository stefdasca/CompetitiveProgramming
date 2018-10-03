#include<bits/stdc++.h>
using namespace std;
ifstream f("ackermann.in");
ofstream g("ackermann.out");
int t,a,b,p;
int etf(int nr)
{
    int sol=nr;
    for(int i=2;i*i<=nr;++i)
        if(nr%i==0)
        {
            sol=(sol/i)*(i-1);
            while(nr%i==0)
                nr/=i;
        }
    if(nr>1)
        sol=(sol/nr)*(nr-1);
    return sol;
}
int lgput(int b, int ex, int mod)
{
    int sol=1;
    while(ex)
    {
        if(ex&1)
            sol=(1LL*sol*b)%mod;
        b=(1LL*b*b)%mod;
        ex/=2;
    }
    return sol;
}
int solve(int pas, int mod)
{
    if(pas==1 || mod==1)
        return a%mod;
    return lgput(a,solve(pas-1,etf(mod)),mod);
}
int main()
{
    f>>t;
    while(t)
    {
        f>>a>>b>>p;
        g<<solve(b,p)<<'\n';
        --t;
    }
    return 0;
}
