/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define maxn 200002
using namespace std;
ifstream f("comisia.in");
ofstream g("comisia.out");
int n,Aint[4*maxn],v[maxn];
long long sum[maxn],minsum=1e18;
void build(int nod, int st, int dr)
{
    if(st==dr){
        Aint[nod]=v[st];
        return;
    }
    int mid=(st+dr)/2;
    build(2*nod,st,mid);
    build(2*nod+1,mid+1,dr);
    Aint[nod]=max(Aint[nod+nod],Aint[nod+nod+1]);
}
int a,b,prcres,max1;
void query(int nod, int st, int dr)
{
    if(dr<a || st>b)
        return;
    if(a<=st && dr<=b){
        max1=max(max1,Aint[nod]);
        return;
    }
    int mid=(st+dr)/2;
    if(a<=mid)
        query(2*nod,st,mid);
    if(mid<b)
        query(2*nod+1,mid+1,dr);
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=1;i<=n;++i)
    {
        f>>sum[i];
        sum[i]+=sum[i-1];
    }
    build(1,1,n);
    for(int i=1;i<=n;++i)
    {
        prcres=i;
        max1=0;
        a=i;
        b=i;
        do
        {
            max1=0;
            query(1,1,n);
            prcres=b;
            b=i+max1-1;
        }while(b>prcres && b<=n);
        if(b<=n)
            minsum=min(minsum,sum[i+max1-1]-sum[i-1]);
    }
    g<<minsum;
    return 0;
}
