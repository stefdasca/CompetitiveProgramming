#include<bits/stdc++.h>
using namespace std;
ifstream f("elmer.in");
ofstream g("elmer.out");
int n,m,hme;
struct punct
{
    long long x,y;
};
punct v[1002];
struct segment
{
    long long x,h;
};
segment v2[1002];
bool cmp(segment a, segment b)
{
    return a.x<b.x;
}
struct events
{
    long long poz;
    bool inorout;
};
events vv[1000002];
events vx[5002];
bool cmp2(events a, events b)
{
    return a.poz<b.poz;
}
double fct(int a, int b)
{
    if(v[a].y<=v2[b].h)
        return -1;
    double sol=v[a].x+(0.0+v[a].y)/(0.0+v[a].y-v2[b].h)*(0.0+v2[b].x-v[a].x);
    if(sol<1)
        return -1;
    return sol;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i].x>>v[i].y;
    f>>m;
    for(int i=1;i<=m;++i)
        f>>v2[i].x>>v2[i].h;
    sort(v2+1,v2+m+1,cmp);
    v2[m+1].x=2e18;
    vx[0]={1,0};
    for(int i=1;i<=n;++i)
    {
        int k=0;
        bool badhappened=0;
        for(int j=1;j<=m;++j)
        {
            long long poz=ceil(fct(i,j));
            if(v2[j].x<v[i].x)
            {
                if(poz==-1)
                    badhappened=1,poz=1;
                vx[++k]={poz,1};
                vx[++k]={v2[j].x+1,0};
            }
            else
                if(v2[j].x>v[i].x)
                {
                    vx[++k]={v2[j].x,1};
                    if(poz!=-1)
                        vx[++k]={poz,0};
                }
                else
                {
                    vx[++k]={v2[j].x,1};
                    if(v2[j+1].x!=v2[j].x+1);
                        vx[++k]={v2[j].x+1,0};
                }
        }
        sort(vx+1,vx+k+1,cmp2);
        bool bd=1;
        long long lp=-125;
        int dif=0;
        int prr=0;
        for(int j=((!(vx[0].poz!=vx[1].poz)) || badhappened);j<=k;++j)
            if(vx[j].poz!=lp)
            {
                if(lp!=-125)
                    if(dif<=0 && bd)
                    {
                        vv[++hme]={lp,1};
                        bd=0;
                        ++prr;
                    }
                    else
                        if(prr && dif>=0 && !bd)
                        {
                            vv[++hme]={lp,0};
                            bd=1;
                        }
                lp=vx[j].poz;
                if(vx[j].inorout)
                    ++dif;
                else
                    --dif;
            }
            else
                if(vx[j].inorout)
                    ++dif;
                else
                    --dif;
        if(dif==0 && bd){
            vv[++hme]={lp,1};
            bd=0;
            ++prr;
        }
        else
            if(prr && dif>0 && !bd)
            {
                vv[++hme]={lp,0};
                bd=1;
            }
    }
    int hm=0,mx=0;
    sort(vv+1,vv+hme+1,cmp2);
    for(int i=1;i<=hme;++i)
    {
        if(vv[i].inorout)
            ++hm;
        else
            --hm;
        mx=max(mx,hm);
    }
    g<<mx<<'\n';
    return 0;
}
