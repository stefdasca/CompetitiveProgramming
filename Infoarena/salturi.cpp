#include<bits/stdc++.h>
using namespace std;
ifstream f("salturi.in");
ofstream g("salturi.out");
int t,n,v[250002],sol[250002],good;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        for(int i=1;i<=n;++i)
            f>>v[i];
        good=1;
        int stc=0;
        int beg=0;
        int maxx=0;
        for(int i=1;i<=n && good;++i)
        {
            if(v[i]>i-stc)
                good=0;
            if(v[i]>maxx+1)
                good=0;
            maxx=max(maxx,v[i]);
            if(v[i]==1 && i!=1)
            {
                for(int a=stc+1;a<i;++a)
                    sol[a]=beg+maxx-v[a]+1;
                beg+=maxx;
                maxx=1;
                stc=i-1;
            }
        }
        for(int a=stc+1;a<=n;++a)
            sol[a]=beg+maxx-v[a]+1;
        if(!good)
            g<<-1<<'\n';
        else
        {
            for(int i=1;i<=n;++i)
                g<<sol[i]<<" ";
            g<<'\n';
        }
    }
    return 0;
}
