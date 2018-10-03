#include<bits/stdc++.h>
using namespace std;
ifstream f("xspe.in");
ofstream g("xspe.out");
int n;
int v[1000002];
int smd[1000002],sol[1000002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    smd[n]=n+1;
    sol[n]=v[n];
    for(int i=n-1;i>=1;--i)
    {
        if(v[i+1]<v[i])
            smd[i]=i+1,sol[i]=v[i]+v[i+1];
        else
        {
            smd[i]=smd[i+1];
            while(v[smd[i]]>=v[i])
                smd[i]=smd[smd[i]];
            sol[i]=v[i]+v[smd[i]];
        }
    }
    for(int i=1;i<=n;++i)
        g<<sol[i]<<" ";
    return 0;
}
