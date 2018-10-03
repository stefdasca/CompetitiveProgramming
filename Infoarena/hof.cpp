#include<bits/stdc++.h>
using namespace std;
ifstream f("hof.in");
ofstream g("hof.out");
long long pz;
long long v[100002];
long long maxd=2;
int main()
{
    f>>pz;
    if(pz==1)
    {
        g<<1;
        return 0;
    }
    if(pz==2)
    {
        g<<3;
        return 0;
    }
    v[1]=3;
    long long sz=1;
    long long sz2=1;
    long long val=3;
    for(long long i=3;i<=pz;++i)
    {
        ++maxd;
        if(maxd==v[sz2])
            ++maxd,++sz2;
        val+=maxd;
        if(sz+1<=100000)
            v[++sz]=val;
    }
    g<<val<<'\n';
    return 0;
}
