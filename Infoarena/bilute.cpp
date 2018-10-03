#include<bits/stdc++.h>
using namespace std;
ifstream f("bilute.in");
ofstream g("bilute.out");
long long n;
long long va[30002];
long long dt[30002];
long long sum;
long long min1,opt1;
long long sst,sdr;
long long nrst,nrdr;
void lily()
{
    f>>n;
    for(long long i=1;i<=n;++i)
    {
        f>>va[i]>>dt[i];
        sum+=va[i]*dt[i];
    }
    for(long long i=n;i>1;--i)
        sdr+=va[i]*(i-1),nrdr+=va[i];
    min1=sum+sdr-va[1]*dt[1];
    opt1=1;
}
void rose()
{
    for(long long i=2;i<=n;++i)
    {
        nrst+=va[i-1];
        sst+=nrst;
        sdr-=nrdr;
        nrdr-=va[i];
        if(sum+sst+sdr-va[i]*dt[i]<min1)
            min1=sum+sst+sdr-va[i]*dt[i],opt1=i;
    }
    g<<opt1<<" "<<min1<<'\n';
}
int main()
{
    lily();rose();
    return 0;
}
