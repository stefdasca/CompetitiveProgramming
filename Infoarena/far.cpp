#include<bits/stdc++.h>
using namespace std;
ifstream f("far.in");
ofstream g("far.out");
long long t,n,m,mod;
long long prim[15];
long long md[15],mnum[15],mnumi[15];
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n>>m>>mod;
        --n;
        --m;
        if(n==0 && m==0)
        {
            g<<1<<'\n';
            continue;
        }
        long long Q=0;
        for(long long j=2;j*j<=mod;++j)
            if(mod%j==0)
            {
                prim[++Q]=j;
                md[Q]=mnum[Q]=mnumi[Q]=0;
                while(mod%j==0)
                    mod/=j,++md[Q];
            }
        if(mod>1)
            prim[++Q]=mod,md[Q]=1,mnum[Q]=mnumi[Q]=0;
        long long S=n+m;
        for(long long i=1;i<=Q;++i)
        {
            long long A=S/prim[i];
            while(A)
            {
                mnum[i]+=A;
                A/=prim[i];
            }
            A=n/prim[i];
            while(A)
            {
                mnumi[i]+=A;
                A/=prim[i];
            }
            A=m/prim[i];
            while(A)
            {
                mnumi[i]+=A;
                A/=prim[i];
            }
        }
        bool ok=1;
        for(long long i=1;i<=Q;++i)
            if(mnum[i] && mnum[i]>=mnumi[i] && (mnum[i]-mnumi[i])>=md[i]);
            else
                ok=0;
        g<<ok<<'\n';
    }
    return 0;
}
