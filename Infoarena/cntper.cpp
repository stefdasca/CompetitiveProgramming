#include<bits/stdc++.h>
#define capat 1000000
#define mod 666013
using namespace std;
ifstream f("cntper.in");
ofstream g("cntper.out");
int t,n;
int vp[capat+2],vnep[capat+2];
void gen()
{
    int p=1;
    for(int i=1;i<=capat;++i)
    {
        p=p*26%mod;
        vnep[i]=p-vp[i];
        if(vnep[i]<0)
            vnep[i]+=mod;
        for(int j=i+i;j<=capat;j+=i)
            vp[j]=(vp[j]+vnep[i])%mod;
    }
}
int main()
{
    gen();
    f>>t;
    for(;t;--t)
    {
        f>>n;
        g<<vnep[n]<<'\n';
    }
    return 0;
}
