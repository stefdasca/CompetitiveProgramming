#include<bits/stdc++.h>
using namespace std;
ifstream f("purice2.in");
ofstream g("purice2.out");
int t;
int n;
int v[52];
int dc(int a, int b)
{
    int c=0;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        for(int i=1;i<=n;++i)
            f>>v[i];
        sort(v+1,v+n+1);
        int d=v[2]-v[1];
        for(int i=2;i<n;++i)
            d=dc(d,v[i+1]-v[i]);
        if(d==1)
            g<<1<<'\n';
        else
            g<<0<<'\n';
    }
    return 0;
}
