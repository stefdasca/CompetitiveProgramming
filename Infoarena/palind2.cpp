#define max_roses 5002
#include<bits/stdc++.h>
using namespace std;
ifstream f("palind2.in");
ofstream g("palind2.out");
int t,n;
int vp[max_roses],vi[max_roses];
int st1,st2,poz1,poz2;
int sma,nra;
int smb,nrb;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        int nri=n/2+n%2;
        int nrp=n/2;
        int nr;
        st1=0;st2=0;sma=1e9;smb=1e9;nra=1;nrb=1;
        poz1=0,poz2=0;
        vp[1]=1;
        if(n==1)
            smb=0;
        for(int i=1;i<=n;++i)
        {
            f>>nr;
            if(i&1)
                st1+=nr,vi[i/2+1]=nr;
            else
                st2+=nr,vp[i/2]=nr;
        }
        sort(vp+1,vp+nrp+1);
        sort(vi+1,vi+nri+1);
        int ssi=0,ssp=0;
        for(int i=vi[1];i<=vi[nri];++i)
        {
            while(poz1<nri && i>=vi[poz1+1])
                ssi+=vi[poz1+1],st1-=vi[poz1+1],++poz1;
            int q1=poz1*i-ssi+st1-(nri-poz1)*i;
            if(q1<sma)
                sma=q1,nra=1;
            else
                if(q1==sma)
                    ++nra;
        }
        for(int i=vp[1];i<=vp[nrp];++i)
        {
            while(poz2<nrp && i>=vp[poz2+1])
                ssp+=vp[poz2+1],st2-=vp[poz2+1],++poz2;
            int q2=poz2*i-ssp+st2-(nrp-poz2)*i;
            if(q2<smb)
                smb=q2,nrb=1;
            else
                if(q2==smb)
                    ++nrb;
        }
        g<<sma+smb<<" "<<1ll*nra*nrb<<'\n';
    }
    return 0;
}
