#include<bits/stdc++.h>
using namespace std;
ifstream f("inception.in");
ofstream g("inception.out");
int n,q,k;
int dad[300002];
int value[300002],ancestors[300002][22],sz[300002],niv[300002];
int tip,id,nr,val,x,y,co=1;
void dfs()
{
    for(int i=co;i>=1;--i)
        value[dad[i]]+=value[i];
}
int find_anc(int who, int alc)
{
    while(alc && who)
    {
        int b=0;
        int e=sz[who];
        if(alc>=(1<<e))
        {
            alc-=(1<<e);
            who=ancestors[who][e];
        }
        else
            while(b<=e)
            {
                int m=(b+e)/2;
                if((1<<m)<=alc && (1<<(m+1))>alc)
                {
                    who=ancestors[who][m];
                    alc-=(1<<m);
                    break;
                }
                else
                    if((1<<m)<=alc)
                        b=m+1;
                    else
                        e=m-1;
            }
    }
    return who;
}
int main()
{
    f>>n>>q>>k;
    for(int i=1;i<=q;++i)
    {
        f>>tip;
        if(tip==1)
        {
            f>>id>>x>>y;
            ++co;
            dad[co]=id;
            ancestors[co][0]=id;
            int nr=id;
            int poz=0;
            while(ancestors[nr][poz])
            {
                ancestors[co][poz+1]=ancestors[nr][poz];
                ++poz;
                nr=ancestors[co][poz];
            }
            sz[co]=poz;
        }
        else
        {
            f>>id>>nr>>val;
            value[id]+=val;
            value[find_anc(id,nr)]-=val;
        }
    }
    dfs();
    for(int i=1;i<=k;++i)
    {
        int nr;
        f>>nr;
        g<<value[nr]<<" ";
    }
    return 0;
}
