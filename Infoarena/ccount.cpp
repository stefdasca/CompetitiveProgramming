#include<bits/stdc++.h>
#define mod 9007
using namespace std;
ifstream f("ccount.in");
ofstream g("ccount.out");
int n,m;
bool known[100002];
int v[100002];
int main()
{
    f>>n>>m;
    known[1]=known[2]=1;
    for(;m;--m)
    {
        int nr;
        f>>nr;
        known[nr]=1;
    }
    for(int i=3;i<=n;++i)
        if(!known[i])
            v[i]=(1+v[i-1]+v[i-2])%mod;
    g<<v[n]<<'\n';
    return 0;
}
