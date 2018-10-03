/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("plus2.in");
ofstream g("plus2.out");
long long n,nr;
int dp,dpmax;
vector<int>v[2002];
int ccmax;
int vint[20002];
int prl[20002],ssz;
int sta,sfa,stb,sfb,maxit,pz,nreq;
void cmp()
{
    if(nreq>ccmax){
        ccmax=nreq;
        for(int i=1;i<=pz;++i)
            prl[i]=vint[i];
        ssz=pz;
        return;
    }
    if(nreq<ccmax)
        return;
    if(nreq==ccmax)
    {
        if(pz>ssz)
        {
            ssz=pz;
            for(int i=1;i<=ssz;++i)
                prl[i]=vint[i];
            return;
        }
        if(pz<ssz)
            return;
        if(pz==ssz)
        {
            int q=0;
            for(int i=1;i<=ssz && !q;++i)
                if(prl[i]>vint[i])
                    q=-1;
                else
                    if(prl[i]<vint[i])
                        q=1;
            if(q==1)
                for(int i=1;i<=ssz;++i)
                    prl[i]=vint[i];
            return;
        }
    }
}
void clc(int sz)
{
  ///  g<<"Rose Marie"<<'\n';
   // g<<'\n';
   // for(int i=0;i<v[sz].size();++i)
   //     g<<v[sz][i];
   // g<<'\n';
   // for(int i=0;i<v[sz-1].size();++i)
  //      g<<v[sz-1][i];
  //  g<<'\n';
   // g<<'\n';
    ssz=0;
    ccmax=0;
    sta=0;
    sfa=v[sz].size()-1;
    stb=sfa;
    sfb=sfa+v[sz-1].size()-1;
    int MX=max(v[sz].size(),v[sz-1].size());
    maxit=v[sz].size()+v[sz-1].size()-1;
    pz=0;
    nreq=0;
    for(int m=1;m<=maxit;++m)
    {
        pz=0;
        nreq=0;
        for(int i=min(stb, sta);i<=max(sfa, sfb);++i)
        {
            if((i>=sta && i<=sfa) && (i>=stb && i<=sfb))
                if(v[sz][i-sta]!=v[sz-1][i-stb])
                    vint[pz+1]=v[sz][i-sta]+v[sz-1][i-stb],++pz;
                else
                    ++nreq;
            else
                if(i>=sta && i<=sfa)
                    vint[pz+1]=v[sz][i-sta],++pz;
                else
                    if(i>=stb && i<=sfb)
                        vint[pz+1]=v[sz-1][i-stb],++pz;
        }
        int pz2=pz;
        while(pz2>1)
        {
            if(vint[pz2]>9)
                vint[pz2-1]++,vint[pz2]-=10;
            --pz2;
        }
        ++sta;
        ++sfa;
        if(nreq>0)
            cmp();
    }
    v[sz].clear();
    v[sz-1].clear();
  //  g<<ccmax<<'\n';
    if(ccmax==0 || ccmax==MX){
        v[sz-1].push_back(0);
    //    g<<0<<'\n';
     //   g<<'\n';
        return;
    }
    if(prl[1]>=10)
        v[sz-1].push_back(1),v[sz-1].push_back(prl[1]-10);
    else
        v[sz-1].push_back(prl[1]);
    for(int i=2;i<=ssz;++i)
        v[sz-1].push_back(prl[i]);
  //  for(int i=0;i<v[sz-1].size();++i)
    //    g<<v[sz-1][i];
   // g<<'\n';
   // g<<'\n';
}
int main()
{
    f>>n;
    int sz=0;
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        if(nr==-1)
            ++sz,v[sz].push_back(-1),++dp;
        else
            if(nr==-2)
            {
                if(v[sz][0]==-1)
                    v[sz].clear();
                else{
                    v[sz-1].clear();
                    for(int j=0;j<v[sz].size();++j)
                        v[sz-1].push_back(v[sz][j]);
                    v[sz].clear();
                }
                --sz,--dp;
            }
            else
            {
                ++sz;
                do
                {
                    v[sz].push_back(nr%10);
                    nr/=10;
                }while(nr);
                reverse(v[sz].begin(),v[sz].end());
            }
        while(sz>1 && v[sz][0]>=0 && v[sz-1][0]>=0)
            clc(sz),--sz;
        dpmax=max(dpmax,dp);
    }
    g<<dpmax<<'\n';
    for(int j=0;j<v[1].size();++j)
        g<<v[1][j];
    return 0;
}
