#include<bits/stdc++.h>
using namespace std;
ifstream f("echilibru.in");
ofstream g("echilibru.out");
int t;
int v[17];
int bits[33];
int n,m,S[20],s;
bool ok=0;
void comb(int k)
{
    if(ok)
        return;
    int i;
    if(k==n)
    {
        int s2=0;
        for(i=1;i<=n;++i)
            s2+=v[S[i]];
        if(s2*2==s)
            ok=1;
    }
    else
    {
        for(i=S[k]+1; i<=n+n; i++)
        {
            S[k+1]=i;
            comb(k+1);
        }
    }
}
int main()
{
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>n;
        s=0;
        ok=0;
        for(int i=1;i<=n+n;++i)
            f>>v[i],s+=v[i];
        comb(0);
        bits[i]=ok;
    }
    int p2=1;
    int nr=0;
    for(int i=t;i>=1;--i,p2+=p2)
        nr+=p2*bits[i];
    g<<nr;
    return 0;
}
