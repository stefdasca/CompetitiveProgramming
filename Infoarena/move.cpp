/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("move.in");
ofstream g("move.out");
int n,v[100002],d[100002],k,t[100002],sol[100002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    d[1]=1;
    k=1;
    for(int i=2;i<=n;++i)
    {
        int b=1;
        int e=k;
        while(b<=e)
        {
            int m=(b+e)/2;
            if(v[d[m]]<v[i])
                b=m+1;
            else
                e=m-1;
        }
        if(b>k)
            k++;
        d[b]=i;
        t[i]=d[b-1];
    }
    int i=d[k];
    int j=0;
    while(i!=0)
    {
        sol[++j]=i;
        i=t[i];
    }
    g<<n-k<<'\n';
    int p=1,poz=k;
    while(p<=n)
    {
        while(p==v[sol[poz]])
            ++p,--poz;
        if(p<=n){
            g<<p<<" "<<p-1<<'\n';
            ++p;
        }
    }
    return 0;
}
