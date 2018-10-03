/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("mts.in");
ofstream g("mts.out");
int n,k,t;
int s[200002];
int dorg[200002];
int mx;
int main()
{
    f>>n>>k>>t;
    for(int i=1;i<=n;++i)
    {
        f>>s[i];
        s[i]+=s[i-1];
    }
    for(int i=1;i<=n;++i)
        f>>dorg[i];
    int b=1;
    int e=n;
    while(b<=e)
    {
        int m=(b+e)/2;
        bool ok=0;
      //  g<<m<<'\n';
        for(int j=max(1,k-m+1);j<=min(k,n-m+1);++j)
        {
           // g<<j+m-1<<" "<<j-1<<'\n';
            int dt=s[j+m-1]-s[j-1]+dorg[j+m-1]-dorg[j]+min(dorg[k]-dorg[j],dorg[j+m-1]-dorg[k]);
            if(dt<=t)
                ok=1;
        }
        if(ok)
        {
            mx=m;
            b=m+1;
        }
        else
            e=m-1;
    }
    g<<mx;
    return 0;
}
