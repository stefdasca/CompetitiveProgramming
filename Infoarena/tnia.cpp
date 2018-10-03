#include<bits/stdc++.h>
using namespace std;
ifstream f("tnia.in");
ofstream g("tnia.out");
int n,m;
int Coverage[100002];
long long sp[100002];
int q;
int a,b,c,d;
int cb(int b, int e, int val)
{
    if(Coverage[b]>=val)
        return b;
    while(b<=e)
    {
        int mid=(b+e)/2;
        if(Coverage[mid]>=val && Coverage[mid-1]<val)
            return mid;
        if(Coverage[mid]>=val)
            e=mid-1;
        else
            b=mid+1;
    }
}
long long ans(long long xa, long long ya, long long xb, long long yb)
{
    int ls,lsf;
    long long ans=0;
    if(Coverage[xb]<ya)
        return 0;
    else
        ls=cb(xa,xb,ya);
    if(Coverage[xb]<yb)
        lsf=xb;
    else
    {
        lsf=cb(xa,xb,yb)-1;
        ans+=1LL*(xb-lsf)*(yb-ya+1);
    }
    ans=ans+sp[lsf]-sp[ls-1];
    ans-=1LL*(lsf-ls+1)*(ya-1);
    return ans;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
    {
        f>>Coverage[i];
        sp[i]=Coverage[i]+sp[i-1];
    }
    f>>q;
    for(int i=1;i<=q;++i)
    {
        f>>a>>b>>c>>d;
        g<<ans(a,b,c,d)<<'\n';
    }
    return 0;
}
