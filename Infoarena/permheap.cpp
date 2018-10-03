#include<bits/stdc++.h>
#define Hmmm 666013
using namespace std;
ifstream f("permheap.in");
ofstream g("permheap.out");
long long n,v[200002];
long long fact[200002];
long long sol[200002];
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
void Build()
{
    f>>n;
    fact[0]=1;
    sol[0]=1;
    for(int i=1;i<=n;++i){
        fact[i]=(fact[i-1]*i)%Hmmm;
        sol[i]=pw(fact[i],Hmmm-2);
    }
    v[0]=v[1]=1;
}
long long comb(int n, int k)
{
    return (fact[n]*sol[k])%Hmmm*sol[n-k]%Hmmm;
}
int main()
{
    Build();
    int p2=1;
    for(int i=2;i<=n;++i)
    {
        while(p2+p2<=i)
            p2+=p2;
        int m=i+1-p2;
        int hf=p2/2;
        int L=hf-1+min(hf,m);
        int R=hf-1+max(0,m-hf);
        v[i]=((v[L]*v[R])%Hmmm)*comb(i-1,L)%Hmmm;
    }
    g<<v[n];
    return 0;
}
