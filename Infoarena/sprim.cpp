#include<bits/stdc++.h>
using namespace std;
ifstream f("sprim.in");
ofstream g("sprim.out");
int n;
int nr,st,sf,nop=1;
long long sol;
int prim[1000002];
bool pr[1000002];
int nrp[82002];
void sieve()
{
    nrp[1]=2;
    for(int i=4;i<=1000000;i+=2)
        pr[i]=1;
    for(int i=3;i<=999999;i+=2)
        if(pr[i]==0)
        {
            nrp[++nop]=i;
            for(int j=i+i;j<=999999;j+=i)
                pr[j]=1;
        }
}
struct fp
{
    vector<int>prim;
};
fp v[100002];
int main()
{
    sieve();
    f>>n;
    st=1;
    sf=0;
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        ++sf;
        int nr2=nr;
        int f2=0;
        for(int j=1;nrp[j]*nrp[j]<=nr2;++j)
            if(nr2%nrp[j]==0)
            {
                ++prim[nrp[j]];
                if(prim[nrp[j]]==2)
                    ++f2;
                v[i].prim.push_back(nrp[j]);
                while(nr2%nrp[j]==0)
                    nr2/=nrp[j];
            }
        if(nr2>1)
        {
            ++prim[nr2];
            if(prim[nr2]==2)
                ++f2;
            v[i].prim.push_back(nr2);
        }
        while(f2)
        {
            for(int j=0;j<v[st].prim.size();++j){
                --prim[v[st].prim[j]];
                if(prim[v[st].prim[j]]==1)
                    --f2;
            }
            ++st;
        }
        sol+=sf-st;
    }
    g<<sol;
    return 0;
}
