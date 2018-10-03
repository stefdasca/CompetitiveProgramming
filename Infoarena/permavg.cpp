/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("permavg.in");
ofstream g("permavg.out");
int n,v[17002];
void perm(int poz, int n)
{
    if(n==1)
    {
        v[poz]=1;
        return;
    }
    int m=n/2;
    perm(poz, m);
    for(int i=poz; i<poz+m; i++)
        v[i]=v[i]*2;
    perm(poz+m, n-m);
    for(int i=poz+m;i<poz+n; i++)
        v[i]=v[i]*2-1;
}
int main()
{
    f>>n;
    perm(1,n);
    for(int i=1;i<=n;++i)
        g<<v[i]<<" ";
    return 0;
}
