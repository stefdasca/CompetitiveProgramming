#include<bits/stdc++.h>
using namespace std;
ifstream f("suma6.in");
ofstream g("suma6.out");
int n,sz,v[100002],s,q;
long long ans[200002],sol;
int frq[1000002];
struct ask
{
    int l,r,pi;
};
ask vv[200002];
bool cmp(ask a, ask b)
{
    int x=a.l/sz;
    int y=b.l/sz;
    if(x!=y)
        return x<y;
    return a.r<b.r;
}
void add(int nr)
{
    nr=v[nr];
    if(s-nr>=0)
        sol+=frq[s-nr];
    ++frq[nr];
}
void scoate(int nr)
{
    nr=v[nr];
    if(s-nr>=0)
        sol-=frq[s-nr];
    --frq[nr];
}
int main()
{
    f>>n>>s;
    sz=sqrt(n);
    for(int i=1;i<=n;++i)
        f>>v[i];
    f>>q;
    for(int i=1;i<=q;++i)
    {
        f>>vv[i].l>>vv[i].r;
        vv[i].pi=i;
    }
    sort(vv+1,vv+q+1,cmp);
    int L=1;
    int R=0;
    for(int i=1;i<=q;++i)
    {
        int x=vv[i].l;
        int y=vv[i].r;
        while(L>x)
            add(--L);
        while(R<y)
            add(++R);
        while(x>L)
            scoate(L++);
        while(R>y)
            scoate(R--);
        ans[vv[i].pi]=sol;
    }
    for(int i=1;i<=q;++i)
        g<<ans[i]<<'\n';
    return 0;
}
