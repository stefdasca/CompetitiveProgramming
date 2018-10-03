#include<bits/stdc++.h>
using namespace std;
ifstream f("stalpisori.in");
ofstream g("stalpisori.out");
int v[1000005];
int n,k,i,st=1,dr,d,dmax;
int main()
{
    f>>n>>k;
    for(i=1;i<=n;i++)
        f>>v[i];
    dr=k;
    for(i=1;i<=n;i++)
    {
        d=2000000000;
        while(st<=i && dr<=n && max(v[i]-v[st],v[dr]-v[i])<d)
            d=max(v[i]-v[st],v[dr]-v[i]),st++,dr++;
        st--;
        dr--;
        dmax=max(dmax,d);
    }
    g<<dmax;
    return 0;
}
