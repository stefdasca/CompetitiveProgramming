#include<bits/stdc++.h>
#define Hmmm 666013
using namespace std;
ifstream f("scenariu.in");
ofstream g("scenariu.out");
int n,nra,v[10002],sact;
long long pw(long long b, int ex)
{
    long long sol=1;
    while(ex)
    {
        if(ex&1)
            sol=(sol*b)%Hmmm;
        b=(b*b)%Hmmm;
        ex>>=1;
    }
    return sol;
}
long long Comb(int n, int k)
{
    long long sol=1;
    for(int i=1;i<=n;++i)
        sol=(sol*i)%Hmmm;
    long long x1=1;
    long long x2=1;
    for(int i=1;i<=k;++i)
        x1=(x1*i)%Hmmm;
    for(int i=1;i<=n-k;++i)
        x2=(x2*i)%Hmmm;
    sol=(sol*pw(x1,Hmmm-2))%Hmmm*pw(x2,Hmmm-2)%Hmmm;
    return sol;
}
int main()
{
    f>>n>>nra;
    for(int i=1;i<=nra;++i)
        f>>v[i],sact+=v[i];
    g<<Comb(n-1,sact-1);
    return 0;
}
