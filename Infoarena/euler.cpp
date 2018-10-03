#include<bits/stdc++.h>
#define OrezErami 262145
using namespace std;
ifstream f("euler.in");
ofstream g("euler.out");
int n,dad[OrezErami],nr;
int nrpasi,nrroots;
deque<int>d;
bool ok=1;
int main()
{
    f>>n;
    while(f>>nr)
    {
        if(d.empty())
            d.push_back(nr),dad[nr]=-1;
        else
        {
            if((d.size()==1 && nr==d[0]) ||(d.size()>=2 && nr==d[d.size()-2]))
                d.pop_back();
            else{
                if(dad[nr]!=0)
                    ok=0;
                dad[nr]=d.back(),d.push_back(nr);
            }
        }
        ++nrpasi;
    }
    if(nrpasi!=2*n-1)
        ok=0;
    for(int i=1;i<=n;++i)
        nrroots+=(!dad[i]);
    if(nrroots>=2)
        ok=0;
    if(ok==0)
        g<<"NU";
    else
    {
        g<<"DA"<<'\n';
        for(int i=1;i<=n;++i)
            if(dad[i]==-1)
                g<<0<<" ";
            else
                g<<dad[i]<<" ";
    }
    return 0;
}
