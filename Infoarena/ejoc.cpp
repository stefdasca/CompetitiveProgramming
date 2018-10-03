#include<bits/stdc++.h>
using namespace std;
ifstream f("ejoc.in");
ofstream g("ejoc.out");
long long t,a,b;
long long cmmdc(long long x, long long y)
{
    long long z=0;
    while(y)
    {
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>a>>b;
        long long nr=max(a,b)/cmmdc(a,b)-2;
        if(nr%2==0)
            g<<"Denisa"<<'\n';
        else
            g<<"Dalila"<<'\n';
    }
    return 0;
}
