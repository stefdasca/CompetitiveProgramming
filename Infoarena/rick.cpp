/// That moment when you do noob mistakes
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
ifstream f("rick.in");
ofstream g("rick.out");
int n,nr;
int old[500002];
int p2[500002];
int frq[500002];
long long soll[500002];
long long sol=1;
int main()
{
    f>>n;
    p2[0]=1;
    for(int i=1;i<=n;++i)
        p2[i]=(p2[i-1]*2)%mod;
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        frq[nr]++;
    }
    for(int i=1;i<=500000;++i)
        if(frq[i])
        {
            for(int j=1;j*j<=i;++j)
                if(i%j==0)
                {
                    old[j]+=frq[i];
                    if(j*j!=i)
                        old[i/j]+=frq[i];
                }
        }
    for(int i=1;i<=500000;++i)
        soll[i]=p2[old[i]]-1;
    for(int i=500000;i>=1;--i)
    {
        if(!soll[i])
            continue;
        sol=(sol+((1LL*soll[i]*i)%mod))%mod;
        for(int j=1;j*j<=i;++j)
            if(i%j==0)
            {
                soll[j]=soll[j]-soll[i];
                if(soll[j]<0)
                    soll[j]+=mod;
                if(j!=i/j && j!=1)
                {
                    soll[i/j]=soll[i/j]-soll[i];
                    if(soll[i/j]<0)
                        soll[i/j]+=mod;
                }
            }
    }
    g<<sol;
    return 0;
}
