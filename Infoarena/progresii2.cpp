#include<bits/stdc++.h>
using namespace std;
ifstream f("progresii2.in");
ofstream g("progresii2.out");
int t,v,n;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>v>>n;
        --n;
        if(n==0)
            g<<v<<'\n';
        else
        {
            long long sol=0;
            long long imax=v/n;
            sol=sol+imax*v;
            sol=sol-n*(imax+1)*imax/2;
            g<<sol<<'\n';
        }
    }
    return 0;
}
