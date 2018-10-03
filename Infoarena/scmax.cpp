/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("scmax.in");
ofstream g("scmax.out");
int n,v[100003],i,mj,k,st,dr,d[100003],t[100003],sol[100003],j;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>v[i];
    d[1]=1;
    k=1;
    for(i=2;i<=n;i++)
    {
        st=1;
        dr=k;
        while(st<=dr)
        {
            mj=(st+dr)/2;
            if(v[d[mj]]<v[i])
              st=mj+1;
            else
              dr=mj-1;
        }
        if(st>k)
            k++;
        d[st]=i;
        t[i]=d[st-1];
    }
    g<<k<<'\n';
    i=d[k];
    while(i!=0)
    {
        sol[++j]=i;
        i=t[i];
    }
    for(i=k;i>=1;i--)
        g<<v[sol[i]]<<" ";
    return 0;
}
