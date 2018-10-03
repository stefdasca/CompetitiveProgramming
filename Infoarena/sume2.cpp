#include<bits/stdc++.h>
using namespace std;
ifstream f("sume.in");
ofstream g("sume.out");
int n,v[50002],s[(1<<21)+5];
long long k;
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        f>>v[i],s[v[i]]++;
    sort(v+1,v+n+1);
    for(int i=1;i<=(1<<21)+2;++i)
        s[i]+=s[i-1];
    int b=1;
    int e=(1<<21)+2;
    while(b<=e)
    {
        int m=(b+e)/2;
        long long sq=0;
        for(int i=1;i<=n && m>=v[i];++i)
            sq+=1ll*s[m-v[i]];
        if(sq>=k)
            e=m-1;
        else
            b=m+1;
    }
    long long sq=0;
    for(int i=1;i<=n && e>=v[i];++i)
        sq+=1ll*s[e-v[i]];
    if(sq>=k)
        g<<e;
    else
        g<<b;
    return 0;
}
