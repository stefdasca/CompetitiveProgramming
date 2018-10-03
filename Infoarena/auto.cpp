#include <bits/stdc++.h>
using namespace std;
ifstream f("auto.in");
ofstream g("auto.out");
int t,n,i,a[5<<11],b[5<<11];
bool Check(int k)
{
    memset(b,0,sizeof b);
    int s=0;
    for(int i=1;i<=n;++i)
    {
        if(i>k)
            s-=b[i-k];
        if(s>a[i])
            return 0;
        s+=(b[i]=a[i]-s);
    }
    return s==b[n-k+1];
}
int main()
{
    f>>t;
    while(t--)
    {
        int s=0;
        f>>n;
        for(i=1;i<=n;++i)
            f>>a[i],s+=a[i];
        g<<"1 ";
        for(i=2;i<=n;++i)
            if(!(s%i))
                if(Check(i))
                    g<<i<<' ';
        g<<'\n';
    }
    return 0;
}
