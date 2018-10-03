#include<bits/stdc++.h>
using namespace std;
ifstream f("pairs.in");
ofstream g("pairs.out");
int n,nr;
int sol[1000002];
bool frq[1000002];
bool pr[1002];
int qq[550],np=1;
void Sieve()
{
    qq[1]=2;
    for(int i=4;i<=1000;i+=2)
        pr[i]=1;
    for(int i=3;i<=1000;i+=2)
        if(!pr[i])
        {
            qq[++np]=i;
            for(int j=i*i;j<=1000;j+=i)
                pr[j]=0;
        }
}
int main()
{
    f>>n;
    Sieve();
    long long sl=0;
    int MaxN=0;
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        MaxN=max(MaxN,nr);
        frq[nr]=1;
    }
    for(int i=1;i<=MaxN;++i)
        for(int j=i;j<=MaxN;j+=i)
            sol[i]+=frq[j];
    for(int i=2;i<=MaxN;++i)
    {
        bool ok=1;
        int nfp=0;
        int Orez=i;
        if(sol[i]<2)
            continue;
        for(int j=1;qq[j]!=0 && Orez>1;++j)
            if(Orez%qq[j]==0)
            {
                ++nfp;
                int ex=0;
                while(Orez%qq[j]==0)
                    Orez/=qq[j],++ex;
                if(ex>=2)
                {
                    ok=0;
                    break;
                }
            }
        if(ok){
            if(Orez>1)
                ++nfp;
            if(nfp%2==1)
                sl+=1ll*sol[i]*(sol[i]-1)/2;
            else
                sl-=1ll*sol[i]*(sol[i]-1)/2;
        }
    }
    sl=1ll*n*(n-1)/2-sl;
    g<<sl;
    return 0;
}
