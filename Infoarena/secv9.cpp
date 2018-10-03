#include<bits/stdc++.h>
using namespace std;
ifstream f("secv9.in");
ofstream g("secv9.out");
int n,v[100002],s;
int maxlen;
struct sum
{
    int nr;
    int poz;
};
sum v2[100002];
bool test(sum a, sum b)
{
    if(a.nr==b.nr)
        return a.poz<b.poz;
    return a.nr<b.nr;
}
int main()
{
    f>>n>>s;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=1;i<=n;++i)
        v2[i].nr=v2[i-1].nr+v[i],v2[i].poz=i;
    sort(v2,v2+n+1,test);
    int j=0;
    int i=0;
    while(v2[i].nr-v2[j].nr<s)
        ++i;
    int minp=v2[0].poz;
    while(i<=n)
    {
        maxlen=max(maxlen,v2[i].poz-minp);
        ++i;
        while(v2[i].nr-v2[j+1].nr>=s)
            ++j,minp=min(minp,v2[j].poz);
    }
    g<<maxlen;
    return 0;
}
