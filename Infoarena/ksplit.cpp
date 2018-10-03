#include<fstream>
using namespace std;
ifstream f("ksplit.in");
ofstream g("ksplit.out");
long long n,v[100002];
struct sume
{
    long long val;
    int who;
};
sume ssmaxs[100002],ssmaxd[100002],ssmins[100002],ssmind[100002];
long long ab(long long x)
{
    if(x>=0)
        return x;
    return -x;
}
int main()
{
    f>>n;
    ssmaxs[0].val=-1;
    ssmins[0].val=1e17;
    ssmaxd[n+1].val=-1;
    ssmind[n+1].val=1e17;
    for(int i=1;i<=n;++i)
    {
        f>>v[i];
        if(ssmaxs[i-1].val+v[i]>=v[i])
            ssmaxs[i].val=ssmaxs[i-1].val+v[i],ssmaxs[i].who=ssmaxs[i-1].who;
        else
            ssmaxs[i].val=v[i],ssmaxs[i].who=i;
        if(ssmins[i-1].val+v[i]<=v[i])
            ssmins[i].val=ssmins[i-1].val+v[i],ssmins[i].who=ssmins[i-1].who;
        else
            ssmins[i].val=v[i],ssmins[i].who=i;
    }
    for(int i=n;i>=1;--i)
    {
        if(ssmaxd[i+1].val+v[i]>=v[i])
            ssmaxd[i].val=ssmaxd[i+1].val+v[i],ssmaxd[i].who=ssmaxd[i+1].who;
        else
            ssmaxd[i].val=v[i],ssmaxd[i].who=i;
        if(ssmind[i+1].val+v[i]<=v[i])
            ssmind[i].val=ssmind[i+1].val+v[i],ssmind[i].who=ssmind[i+1].who;
        else
            ssmind[i].val=v[i],ssmind[i].who=i;
    }
    long long dmax=0;
    int len=0;
    for(int i=1;i<n;++i)
    {
        if(ab(ssmaxs[i].val-ssmind[i+1].val)>dmax)
            dmax=ab(ssmaxs[i].val-ssmind[i+1].val),len=(ssmind[i+1].who-i)+(i-ssmaxs[i].who+1);
        else
            if(ab(ssmaxs[i].val-ssmind[i+1].val)==dmax)
                len=max(len,(ssmind[i+1].who-i)+(i-ssmaxs[i].who+1));
        if(ab(ssmins[i].val-ssmaxd[i+1].val)>dmax)
            dmax=ab(ssmins[i].val-ssmaxd[i+1].val),len=(ssmaxd[i+1].who-i)+(i-ssmins[i].who+1);
        else
            if(ab(ssmins[i].val-ssmaxd[i+1].val)==dmax)
                len=max(len,(ssmaxd[i+1].who-i)+(i-ssmins[i].who+1));
    }
    g<<dmax<<'\n';
    g<<len;
    return 0;
}
