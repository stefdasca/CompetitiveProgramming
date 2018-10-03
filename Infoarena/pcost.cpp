#include<bits/stdc++.h>
using namespace std;
ifstream f("pcost.in");
ofstream g("pcost.out");
int n,nr;
int v[1000002];
int main()
{
    f>>n;
    for(;n;--n)
    {
        f>>nr;
        for(int i=2;i*i<=nr;++i)
            if(nr%i==0)
            {
                ++v[i];
                while(nr%i==0)
                    nr/=i;
            }
        if(nr>1)
            v[nr]++;
    }
    long long sol=0;
    for(int i=2;i<=1000000;++i)
    {
        long long z=1ll*i*i*(v[i]-1)*v[i]/2;
        sol+=z;
    }
    g<<sol;
    return 0;
}
