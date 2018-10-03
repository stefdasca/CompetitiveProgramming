#include<bits/stdc++.h>
using namespace std;
ifstream f("diff.in");
ofstream g("diff.out");
int n,m;
int v[100002];
struct querysolve
{
    int l,r;
};
querysolve v2[200002];
void MinSum()
{
    int st=1,dr=1;
}
void MaxSum()
{
    int smax=0,st=0,dr=0,s=0,L=1;
    for(int i=1;i<=n;++i)
    {
        int val;
        if(v[i]==1)
            val=1;
        else
            val=-1;
        if(val>s+val)
            L=i,s=val;
        else
            s+=val;
        if(s>smax)
            smax=s,st=L,dr=i;
    }
    s=0;
    for(int i=st;i<=dr;++i)
    {
        if(v[i]==1)
            ++s;
        else
            --s;
        if(!v2[100000+s].l)
            v2[100000+s]={st,i};
    }
    smax=0,st=0,dr=0,s=0,L=1;
    for(int i=1;i<=n;++i)
    {
        int val;
        if(v[i]==0)
            val=1;
        else
            val=-1;
        if(val>s+val)
            L=i,s=val;
        else
            s+=val;
        if(s>smax)
            smax=s,st=L,dr=i;
    }
    s=0;
    for(int i=st;i<=dr;++i)
    {
        if(v[i]==1)
            ++s;
        else
            --s;
        if(!v2[100000+s].l)
            v2[100000+s]={st,i};
    }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
    {
        f>>v[i];
        if(i!=1 && v[i]+v[i-1]==1)
            v2[100000]={i-1,i};
    }
    MaxSum();
    for(int i=1;i<=m;++i)
    {
        int nr;
        f>>nr;
        if(abs(nr)>n)
            g<<-1<<'\n';
        else
            if(!v2[nr+100000].l)
                g<<-1<<'\n';
            else
                g<<v2[nr+100000].l<<" "<<v2[nr+100000].r<<'\n';
    }
    return 0;
}
