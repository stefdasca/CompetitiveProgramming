#include<bits/stdc++.h>
using namespace std;
ifstream f("expectedpos.in");
ofstream g("expectedpos.out");
int n,k,m;
int v[100002];
int sz[1002];
int xa,xb;
int Euclid(int a, int b)
{
    int c;
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
    f>>n>>k;
    int len=0;
    for(int i=1;i<=k;++i)
    {
        f>>sz[i];
        for(int j=1;j<=sz[i];++j)
            f>>v[++len];
    }
    xb=k;
    f>>m;
    sort(v+1,v+n+1);
    v[n+1]=v[n]+1;
    for(int i=1;i<=m;++i)
    {
        int nr;
        f>>nr;
        xa=k;
        int b=1;
        int e=n;
        int max1=0;
        while(b<=e)
        {
            int m=(b+e)/2;
            if(v[m]<=nr)
            {
                max1=max(max1,m);
                b=m+1;
            }
            else
                e=m-1;
        }
        xa+=max1;
        g<<xa/Euclid(xa,xb)<<"/"<<xb/Euclid(xa,xb)<<'\n';
    }
    return 0;
}
