#include<bits/stdc++.h>
using namespace std;
ifstream f("tvshow.in");
ofstream g("tvshow.out");
int n;
struct en
{
    int m,p;
};
en v[302];
int p2[1002],v1[1002],v2[1002],p,minp;
int l1=1,l2=1,ll;
int main()
{
    f>>n;
    for(int i=1;i<n;++i)
        f>>v[i].m>>v[i].p;
    f>>p;
    v2[1]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=l2;++j)
            v2[j]*=2;
        for(int j=1;j<=l2;++j)
            v2[j+1]+=v2[j]/10,v2[j]%=10;
        if(v2[l2+1])
            ++l2;
    }
    int xmax=-2,ymax=-2,sp;
    for(int i=1;i<=p;++i)
    {
        int x=0,y=0;
        for(int j=1;j<n;++j){
            if(v[j].m+v[j].p<p+i)
                ++x;
            if(v[j].m-v[j].p>=p+i)
            {
                x=-1;
                break;
            }
        }
        for(int j=1;j<n;++j){
            if(v[j].m+v[j].p<p-i)
                ++y;
            if(v[j].m-v[j].p>=p-i)
            {
                y=-1;
                break;
            }
        }
        if(max(x,y)>max(xmax,ymax))
            xmax=x,ymax=y,sp=i;

    }
    if(xmax==-1 && ymax==-1)
        g<<0<<'\n'<<0<<'\n'<<1<<'\n';
    else
    {
        g<<sp<<'\n';
        for(int i=0;i<=max(xmax,ymax);++i)
        {
            if(i==0)
                p2[1]=1;
            else{
                for(int j=1;j<=l1;++j)
                    p2[j]+=p2[j];
                for(int j=1;j<=l1;++j)
                    p2[j+1]+=p2[j]/10,p2[j]%=10;
                if(p2[l1+1])
                    ++l1;
            }
            if(i==xmax || i==ymax)
            {
                ll=l1;
                for(int j=1;j<=ll;++j)
                    v1[j]+=p2[j];
            }
        }
        for(int j=1;j<=ll;++j)
           v1[j+1]+=v1[j]/10,v1[j]%=10;
        if(v1[ll+1])
            ++ll;
        while(v1[1]%2==0)
        {
            for(int i=ll;i>=1;--i){
                if(v1[i]%2==1)
                    v1[i-1]+=10;
                v1[i]/=2;
            }
            for(int i=l2;i>=1;--i){
                if(v2[i]%2==1)
                    v2[i-1]+=10;
                v2[i]/=2;
            }
        }
        while(v1[ll]==0)
            --ll;
        while(v2[l2]==0)
            --l2;
        for(int i=ll;i>=1;--i)
            g<<v1[i];
        g<<'\n';
        for(int i=l2;i>=1;--i)
            g<<v2[i];
        g<<'\n';
    }
    return 0;
}
