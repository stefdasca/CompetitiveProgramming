#include<bits/stdc++.h>
#define mod 30103
using namespace std;
ifstream f("functii.in");
ofstream g("functii.out");
int n,k;
long long sol;
int q1=1,q2=1,q3=1,pp=1;
long long pw(int b, int ex)
{
    long long ss=1;
    while(ex){
        if(ex&1)
            ss=(ss*b)%mod;
        b=(b*b)%mod;
        ex/=2;
    }
    return ss;
}
void CalcSol()
{
    sol=(1ll*q1*pp)%mod;
    sol=sol*pw(q2,mod-2)*pw(q3,mod-2);
    sol%=mod;
}
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        q1=(q1*i)%mod;
    for(int i=1;i<=n-k;++i)
        q2=(q2*i)%mod;
    for(int i=1;i<=k;++i)
        q3=(q3*i)%mod;
    for(int i=1;i<=k;++i)
        pp=(pp*2)%mod;
    pp-=2;
    if(pp<0)
        pp+=mod;
    CalcSol();
    g<<sol;
    return 0;
}
