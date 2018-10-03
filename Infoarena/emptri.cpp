/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("emptri.in");
ofstream g("emptri.out");
long long n,v[1000005];
long long x;
bool pr[1000005];
void Sieve()
{
    pr[1]=1;
    for(int i=1;i<=n;++i)
        v[i]=i;
    for(int i=1;i<=n;i++)
    {
        if(!pr[i])
            for(int j=i;j<=n;j+=i)
                pr[j]=1,v[j]/=i,v[j]*=(i-1);
        x+=v[i]+v[i];
    }
}
int main()
{
    f>>n;
    Sieve();
    g<<x-1;
    return 0;
}
