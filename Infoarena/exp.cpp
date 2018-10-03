#include<bits/stdc++.h>
using namespace std;
ifstream f("exp.in");
ofstream g("exp.out");
int o,n,nr;
bitset<30001>v;
int pr[10002],nrp;
int frq[10002];
int fr[30001];
void ciur()
{
    v[1]=v[0]=1;
    for(int i=4;i<=30000;i+=2)
        v[i]=1;
    nrp=1,pr[1]=2;
    for(long long i=3;i<=29999;i+=2)
        if(!v[i])
        {
            ++nrp,pr[nrp]=i;
            if(i*i<=29999)
                for(long long j=i*i;j<=29999;j+=2*i)
                    v[j]=1;
        }
}
int main()
{
    f>>o;
    f>>n;
    ciur();
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        fr[nr]++;
    }
    int qp=0;
    for(int i=2;i<=30000;++i)
    {
        int nr=i;
        if(fr[i])
            for(int j=1;j<=nrp && nr>1;++j)
                while(nr%pr[j]==0)
                {
                    frq[j]+=fr[i];
                    nr/=pr[j];
                }
    }
    int ok=1;
    for(int j=1;j<=nrp;++j)
        if(frq[j]%o){
            ok=0;
            break;
        }
    g<<ok<<'\n';
    if(ok)
        for(int j=1;j<=nrp;++j)
            if(frq[j])
                g<<pr[j]<<" "<<frq[j]/o<<'\n';
    return 0;
}
