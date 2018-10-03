#include<bits/stdc++.h>
using namespace std;
ifstream f("bazaf.in");
ofstream g("bazaf.out");
int c;
long long nr;
deque<long long>d;
long long fct,hm;
void desc(long long R)
{
    fct=1,hm=1;
    while(fct*hm<=R)
        fct*=hm,++hm;
    g<<hm-1<<" ";
    --hm;
    while(hm)
    {
        long long x=min(hm,R/fct);
        d.push_front(x);
        R=R-x*fct;
        fct/=hm;
        --hm;
    }
    for(int i=0;i<d.size();++i)
        g<<d[i]<<" ";
}
int main()
{
    f>>c;
    if(c==1)
    {
        f>>nr;
        desc(nr);
    }
    else
    {
        f>>nr;
        long long tr=0;
        for(long long i=1;i<=nr;++i)
        {
            long long fi;
            f>>fi;
            fi=fi+tr;
            tr=fi/(i+1);
            d.push_back(fi%(i+1));
        }
        long long i=nr+1;
        while(tr)
        {
            d.push_back(tr%(i+1));
            tr=tr/(i+1);
            ++i;
        }
        g<<d.size()<<" ";
        for(int i=0;i<d.size();++i)
            g<<d[i]<<" ";
    }
    return 0;
}
