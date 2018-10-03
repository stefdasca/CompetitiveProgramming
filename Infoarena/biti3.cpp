#include<bits/stdc++.h>
using namespace std;
ifstream f("biti3.in");
ofstream g("biti3.out");
long long n,m;
long long nrc;
int pos1,pos2,pos3;
int main()
{
    f>>n>>m;
    nrc=1ll*(n-1)*n*(n-2)/6;
    m=nrc-m;
    long long z=(n-2)*(n-1)/2;
    int r=n-2;
    int fn=1;
    while(m>z)
    {
        m-=z;
        if(m)
            ++fn;
        --r;
        z=r*(r+1)/2;
    }
    pos1=fn;
    pos2=pos1+1;
    ++m;
    while(n-pos2<m)
        m=m-(n-pos2),++pos2;
    pos3=pos2+m;
    for(int i=1;i<=n;++i)
        if(i==pos1 || i==pos2 || i==pos3)
            g<<1;
        else
            g<<0;
    return 0;
}
