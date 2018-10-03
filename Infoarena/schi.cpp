#include<bits/stdc++.h>
using namespace std;
ifstream f("schi.in");
ofstream g("schi.out");
int n;
int aib[30002];
int pos[30002];
int v[30002];
void add(int nr, int val)
{
    for(;nr<=n;nr+=(nr&(-nr)))
        aib[nr]+=val;
}
int compute(int nr)
{
    int sol=0;
    for(;nr;nr-=(nr&(-nr)))
        sol+=aib[nr];
    return sol;
}
int cb(int val)
{
    int b=1;
    int e=n;
    int sol=0;
    while(b<=e)
    {
        int m=(b+e)/2;
        int a=compute(m);
        int aa=compute(m-1);
        if(a==val && aa<val)
            return m;
        if(a>=val)
            e=m-1;
        else
            b=m+1;
    }
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i],add(i,1);
    for(int i=n;i>=1;--i)
    {
        int ans=cb(v[i]);
        pos[ans]=i;
        add(ans,-1);
    }
    for(int i=1;i<=n;++i)
        g<<pos[i]<<'\n';
    return 0;
}
