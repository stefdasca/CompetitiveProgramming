#include<bits/stdc++.h>
using namespace std;
ifstream f("suman.in");
ofstream g("suman.out");
long long n,v[22],k;
long long p,sol;
long long cmmmc[(1<<20)+4];
short nrm[(1<<20)+4];
int cp2[(1<<20)+4];
long long mc(long long a,long long b)
{
    long long d=a*b;
    long long c=0;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return d/a;
}
int main()
{
    f>>n;
    f>>k;
    for(int i=1;i<=k;++i)
        f>>v[i];
    int cb=(1<<k)-1;
    int x=1;
    for(int i=1;i<=cb;i<<=1,++x){
        cmmmc[i]=v[x],nrm[i]++;
        cp2[i]=i;
    }
    for(int i=1;i<=cb;++i)
        if(cp2[i]==0)
            cp2[i]=cp2[i-1];
    for(int i=1;i<=cb;++i){
        if(cmmmc[cp2[i]]<=n && cmmmc[i-cp2[i]]<=n)
            if(i!=cp2[i])
                cmmmc[i]=mc(cmmmc[cp2[i]],cmmmc[i-cp2[i]]),nrm[i]=nrm[cp2[i]]+nrm[i-cp2[i]];
        if(cmmmc[i]<=n && cmmmc[i]>0)
            if(nrm[i]&1)
                sol+=cmmmc[i]*(n/cmmmc[i])*(n/cmmmc[i]+1)/2;
            else
                sol-=cmmmc[i]*(n/cmmmc[i])*(n/cmmmc[i]+1)/2;
        }
    g<<sol;
    return 0;
}
