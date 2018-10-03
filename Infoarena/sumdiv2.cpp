#include<bits/stdc++.h>
using namespace std;
ifstream f("sumdiv2.in");
ofstream g("sumdiv2.out");
int n,a,b;
unsigned long long v[1000002];
void sum()
{
    for(int i=1;i<=1000000;++i)
        for(int j=i;j<=1000000;j+=i)
            v[j]+=i;
    for(int i=2;i<=1000000;++i)
        v[i]+=v[i-1];
}
int main()
{
    f>>n;
    sum();
    for(int i=1;i<=n;++i)
    {
        f>>a>>b;
        g<<v[b]-v[a-1]<<'\n';
    }
    return 0;
}
