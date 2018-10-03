#include<bits/stdc++.h>
using namespace std;
ifstream f("nrcuv1.in");
ofstream g("nrcuv1.out");
int n;
long long fact[10002],nrcuv[10002],sol[10002];
int main()
{
    f>>n;
    fact[1]=1;
    int l1=1;
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=l1;++j)
            fact[j]*=i;
        for(int j=1;j<=l1;++j)
        {
            fact[j+1]+=fact[j]/10;
            fact[j]%=10;
            if(fact[l1+1])
                ++l1;
        }
    }
    int l2=1;
    nrcuv[1]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=l2;++j)
            nrcuv[j]*=n;
        for(int j=1;j<=l2;++j)
        {
            nrcuv[j+1]+=nrcuv[j]/10;
            nrcuv[j]%=10;
            if(nrcuv[l2+1])
                ++l2;
        }
    }
    for(int i=1;i<=l2;++i){
        sol[i]=nrcuv[i]-fact[i];
        if(sol[i]<0)
            --nrcuv[i+1],sol[i]+=10;
    }
    int ok=0;
    for(int i=l2;i>=1;--i)
    {
        if(sol[i]>0)
            ok=1;
        if(ok==1)
            g<<sol[i];
    }
    return 0;
}
