#include<bits/stdc++.h>
#define Hmmm 30013
using namespace std;
ifstream f("drum3.in");
ofstream g("drum3.out");
int n,k;
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
    sol=sol*pw(x1,Hmmm-2)*pw(x2,Hmmm-2);
    return sol%Hmmm;
}
int main()
{
    f>>n>>k;
    int A=(k+2)/2-1;
    int B=(k+1)/2-1;
    long long sol=2;
    sol=sol*Comb(n-2,A)*Comb(n-2,B);
    g<<sol%Hmmm;
    return 0;
}
