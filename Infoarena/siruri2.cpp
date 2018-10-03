#include<bits/stdc++.h>
#define base 10000
using namespace std;
ifstream f("siruri2.in");
ofstream g("siruri2.out");
int n,m,k;
int sol[8002],len;
int vv[8002],len2;
inline void add(int a[], int b[], int &x, int y)
{
    x=max(x,y);
    int t=0;
    for(int i=1;i<=x;++i)
    {
        a[i]=a[i]+b[i]+t;
        t=a[i]/base;
        a[i]%=base;
    }
    if(t)
        a[++x]=t;
}
inline void imp(int a[], int &x, int nr)
{
    int md=0;
    for(int i=x;i>=1;--i)
    {
        a[i]=a[i]+md*base;
        md=a[i]%nr;
        a[i]/=nr;
    }
    while(!a[x] && x)
        --x;
}
inline void inm(int a[], int &x, int nr)
{
    for(int i=1;i<=x;++i)
        a[i]*=nr;
    for(int i=1;i<=x;++i)
    {
        a[i+1]+=a[i]/base;
        a[i]%=base;
    }
    while(a[x+1])
    {
        ++x;
        a[x+1]=a[x]/base;
        a[x]%=base;
    }
}
int main()
{
    f>>n>>m>>k;
    int mm=m;
    while(mm)
    {
        vv[++len2]=mm%base;
        mm/=base;
    }
    for(int i=1;i<=k;++i)
    {
        add(sol,vv,len,len2);
        inm(vv,len2,n-i);
        inm(vv,len2,m-i);
        imp(vv,len2,i);
        imp(vv,len2,i+1);
    }
    for(int i=len;i>=1;--i)
    {
        if(i==len)
            g<<sol[i];
        else
        {
            int p10=1;
            while(p10<base)
            {
                if(p10>sol[i])
                    g<<0;
                p10*=10;
            }
            g<<sol[i];
        }
    }
    return 0;
}
