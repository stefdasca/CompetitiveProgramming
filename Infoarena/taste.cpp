#include<bits/stdc++.h>
using namespace std;
ifstream f("taste.in");
ofstream g("taste.out");
long long x,y;
int q;
int main()
{
    f>>x>>y;
    long long smin=1ll*1e18;
    long long x1=0,x2=0;
    long long p2=1;
    while(p2<=y)
    {
        long long z=x/p2;
        if(x%p2)
            ++z;
        if(z*p2<=y && z+q<smin)
            smin=z+q,x1=z,x2=q;
        p2*=2;
        ++q;
    }
    g<<x1<<" "<<x2;
    return 0;
}
