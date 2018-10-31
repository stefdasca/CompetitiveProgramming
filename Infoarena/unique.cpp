#include<bits/stdc++.h>
using namespace std;
ifstream f("unique.in");
ofstream g("unique.out");
int tt[100005],rg[100005],d[100005],v[100005],st[100005],lst[100005];
int n,i,j,u,y,aux,t,ans;
int finds(int x)
{
    y=x;
    while(x!=tt[x])
        x=tt[x];
    while(y!=x)
    {
        aux=tt[y];
        tt[y]=x;
        y=aux;
    }
    return x;
}
void unite(int A,int B)
{
    if(rg[A]>rg[B])
    {
        rg[A]+=rg[B];
        d[A]+=d[B];
        tt[B]=A;
    }
    else
    {
        rg[B]+=rg[A];
        d[B]+=d[A];
        tt[A]=B;
    }
}
int main()
{
    f>>t;
    for(int cnt=1; cnt<=t; cnt++)
    {
        f>>n;
        for(i=1; i<=n+1; i++)
            tt[i]=i,rg[i]=1,d[i]=0,lst[i]=0;
        u=0;
        ans=0;
        v[n+1]=n+1;
        for(i=1; i<=n; i++)
            f>>v[i];
        for(i=1; i<=n+1; i++)
        {
            while(u>0 && v[i]>v[st[u]])
            {
                unite(finds(i),finds(st[u]));
                if(d[finds(st[u])]==v[st[u]])
                    ans=max(ans,i-st[u-1]-1);
                u--;
            }
            st[++u]=i;
            if(lst[v[i]])
                d[finds(lst[v[i]])]--;
            d[finds(i)]++;
            lst[v[i]]=i;
        }
        g<<ans<<'\n';
    }
    return 0;
}
