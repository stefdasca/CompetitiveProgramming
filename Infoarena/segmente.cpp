/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("segmente.in");
ofstream g("segmente.out");
int n,lh,lv;
struct hor{int st,sf,ord;};
hor vh[1002],vv[1002];
bool test(hor a, hor b)
{
    return a.ord<b.ord;
}
inline int mx(int a, int b, int c, int d, int e, int f)
{
    int mxd=0;
    if(a<=0)
        a=0;
    mxd=a;
    if(b<=0)
        b=0;
    mxd=max(mxd,b);
    if(c<=0)
        c=0;
    mxd=max(mxd,c);
    if(d<=0)
        d=0;
    mxd=max(mxd,d);
    if(e<=0)
        e=0;
    mxd=max(mxd,e);
    if(f<=0)
        f=0;
    mxd=max(mxd,f);
    return mxd;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        int a,b,c,d;
        f>>a>>b>>c>>d;
        if(b==d)
        {
            ++lh;
            vh[lh].st=min(a,c);
            vh[lh].sf=max(a,c);
            vh[lh].ord=b;
        }
        else
        {
            ++lv;
            vv[lv].st=min(b,d);
            vv[lv].sf=max(b,d);
            vv[lv].ord=a;
        }
    }
    sort(vh+1,vh+lh+1,test);
    int sol=1000000000;
    for(int i=1;i<lh;++i)
        for(int j=i+1;j<=lh;++j){
            int fp=0,sp=0;
            for(int k=1;k<=lv;++k)
            {
                int dif=mx(vh[i].st-vv[k].ord,vv[k].ord-vh[i].sf,vh[j].st-vv[k].ord,vv[k].ord-vh[j].sf,vh[j].ord-vv[k].sf,vv[k].st-vh[i].ord);
                if(k<=2)
                {
                    if(k==1)
                        fp=dif;
                    else{
                        sp=dif;
                        if(sp<fp)
                            swap(sp,fp);
                    }
                    continue;
                }
                if(dif<fp)
                    sp=fp,fp=dif;
                else
                    if(dif<sp)
                        sp=dif;
            }
            sol=min(sol,sp);
        }
    g<<sol;
    return 0;
}
