#include<bits/stdc++.h>
using namespace std;
ifstream f("catun.in");
ofstream g("catun.out");
int n,m,k,a,b,d;
deque<int>nod;
vector<int>dst[37002];
vector<int>paths[37002];
int dmin[40002],who[40002],isf[40002];
void find_the_rose()
{
    while(!nod.empty()){
        int D=dst[nod[0]].size();
        for(int j=0;j<D;++j)
            if(isf[paths[nod[0]][j]]==0)
                if(who[paths[nod[0]][j]]==0)
                {
                    dmin[paths[nod[0]][j]]=dmin[nod[0]]+dst[nod[0]][j];
                    who[paths[nod[0]][j]]=who[nod[0]];
                    nod.push_back(paths[nod[0]][j]);
                }
                else
                    if(dmin[nod[0]]+dst[nod[0]][j]<dmin[paths[nod[0]][j]])
                    {
                        dmin[paths[nod[0]][j]]=dmin[nod[0]]+dst[nod[0]][j];
                        who[paths[nod[0]][j]]=who[nod[0]];
                        nod.push_back(paths[nod[0]][j]);
                    }
                    else
                        if(dmin[nod[0]]+dst[nod[0]][j]==dmin[paths[nod[0]][j]])
                        {
                            who[paths[nod[0]][j]]=min(who[paths[nod[0]][j]],who[nod[0]]);
                            nod.push_back(paths[nod[0]][j]);
                        }
        nod.pop_front();
    }
}
int main()
{
    f>>n>>m>>k;
    for(int i=1;i<=k;++i)
        f>>a,nod.push_back(a),isf[a]=1,who[a]=a;
    for(int i=1;i<=m;++i)
    {
        f>>a>>b>>d;
        paths[a].push_back(b);
        paths[b].push_back(a);
        dst[a].push_back(d);
        dst[b].push_back(d);
    }
    find_the_rose();
    for(int i=1;i<=n;++i)
        if(isf[i]==1)
            g<<0<<" ";
        else
            g<<who[i]<<" ";
    return 0;
}
