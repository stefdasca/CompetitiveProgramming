#include<bits/stdc++.h>
using namespace std;
ifstream f("spiridusi.in");
ofstream g("spiridusi.out");
int n,c;
vector<int>v[100002];
int sp[100002],coe[100002];
int maxx=-2e9;
int anc[100002][18],niv[100002];
int nrsp[100002][18],Sf[100002][18];
void dfs(int dad, int nod)
{
    anc[nod][0]=dad;
    nrsp[nod][0]=sp[dad];
    Sf[nod][0]=coe[dad];
    int q=0;
    int nn=dad;
    while(anc[nn][q]!=0)
    {
        anc[nod][q+1]=anc[nn][q];
        nrsp[nod][q+1]=nrsp[nod][q]+nrsp[nn][q];
        Sf[nod][q+1]=Sf[nod][q]+Sf[nn][q];
        nn=anc[nn][q];
        ++q;
    }
    niv[nod]=q;
    for(int i=0;i<v[nod].size();++i)
    {
        int vecin=v[nod][i];
        if(vecin!=dad)
            dfs(nod, vecin);
    }
}
void cb(int nod, int &sf, int &ss)
{
    sf=ss=0;
    sf=coe[nod];
    ss=sp[nod];
    while(ss+nrsp[nod][0]<=c)
    {
        int b=0;
        int e=niv[nod];
        while(b<=e)
        {
            int mid=(b+e)/2;
            if(ss+nrsp[nod][mid]<=c && (mid==niv[nod] || ss+nrsp[nod][mid+1]>c) )
            {
                ss+=nrsp[nod][mid];
                sf+=Sf[nod][mid];
                nod=anc[nod][mid];
                break;
            }
            if(ss+nrsp[nod][mid]<=c)
                b=mid+1;
            else
                e=mid-1;
        }
    }
}
void dfs2(int dad, int nod, int coF, int sum)
{
    if(coF<coe[nod])
    {
        coF=coe[nod];
        sum=sp[nod];
    }
    if(sum>c)
        cb(nod,coF,sum);
    for(int i=0;i<v[nod].size();++i)
    {
        int vecin=v[nod][i];
        if(vecin!=dad)
            dfs2(nod, vecin, coF+coe[vecin],sum+sp[vecin]);
    }
    if(coF>maxx)
        maxx=coF;
}
int main()
{
    f>>n>>c;
    for(int i=1;i<=n;++i)
        f>>sp[i];
    for(int i=1;i<=n;++i)
    {
        f>>coe[i];
        if(sp[i]<=c)
            maxx=max(maxx,coe[i]);
    }
    for(int i=1;i<n;++i)
    {
        int a,b;
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0,1);
    dfs2(0,1,0,0);
    g<<maxx<<'\n';
    return 0;
}
