/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("camp.in");
ofstream g("camp.out");
int n;
int minp,maxp;
long long sum;
int cs,cd;
struct punct
{
    int x,y;
};
punct v[100002];
int prv[100002];
int nxt[100002];
void prec()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>v[i].x>>v[i].y;
        if(i==1)
            minp=1;
        else
            if(v[i].x<v[minp].x)
                minp=i;
            else
                if(v[i].x==v[minp].x && v[i].y<v[minp].y)
                    minp=i;
        if(i==1)
            maxp=1;
        else
            if(v[i].x>v[maxp].x)
                maxp=i;
            else
                if(v[i].x==v[maxp].x && v[i].y>v[maxp].y)
                    maxp=i;
    }
    for(int i=1;i<=n;++i)
        prv[i]=i-1,nxt[i]=i+1;
    nxt[n]=1;
    prv[1]=n;
}
void solve()
{
    cs=cd=minp;
    while(v[cs].x==v[minp].x)
        cs=prv[cs];
    while(v[cd].x==v[minp].x)
        cd=nxt[cd];
    sum+=1LL*v[nxt[cs]].x*(v[prv[cd]].y-v[nxt[cs]].y+1)+1LL*(v[prv[cd]].y*(1LL+v[prv[cd]].y))/2-1LL*(v[nxt[cs]].y*(-1LL+v[nxt[cs]].y))/2;
    for(int i=v[minp].x+1;i<v[maxp].x;++i)
    {
        double rap,abscs,rap2,abscd;
        if(v[cs].x==i)
            abscs=v[cs].y;
        else
        {
            rap=(0.0+i-v[nxt[cs]].x)/(0.0+v[cs].x-i);
            abscs=1.0*(v[nxt[cs]].y+rap*v[cs].y)/(rap+1.0);
        }
        if(v[cd].x==i)
            abscd=v[cd].y;
        else
        {
            rap2=(0.0+i-v[prv[cd]].x)/(0.0+v[cd].x-i);
            abscd=1.0*(v[prv[cd]].y+rap2*v[cd].y)/(rap2+1.0);
        }
        int a,b;
        a=ceil(min(abscs,abscd));
        b=floor(max(abscs,abscd));
        if(b>=a)
            sum+=1LL*i*(b-a+1)+1LL*(b*(1LL+b))/2-1LL*a*(-1LL+a)/2;
        while(v[cs].x==i)
            cs=prv[cs];
        while(v[cd].x==i)
            cd=nxt[cd];
    }
    int mx=max(v[cd].y,v[cs].y);
    int mn=min(v[cd].y,v[cs].y);
    sum+=1LL*v[cs].x*(mx-mn+1)+1LL*(mx*(1LL+mx))/2-1LL*(mn*(-1LL+mn))/2;
    g<<sum;
}
int main()
{
    prec();
    solve();
    return 0;
}
