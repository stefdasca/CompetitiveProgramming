#include<bits/stdc++.h>
using namespace std;
ifstream f("asmax.in");
ofstream g("asmax.out");
int n,v[16002];
int summax[16002];
bool viz[16002];
vector<int>paths[16002];
vector<int>truetree[16002];
void Constructor()
{
    deque<int>z;
    z.push_back(1);
    viz[1]=1;
    while(!z.empty())
    {
        for(int i=0;i<paths[z[0]].size();++i)
            if(viz[paths[z[0]][i]]==0)
            {
                truetree[z[0]].push_back(paths[z[0]][i]);
                viz[paths[z[0]][i]]=1;
                z.push_back(paths[z[0]][i]);
            }
        z.pop_front();
    }
}
void dfs(int nod)
{
    if(!truetree[nod].size()){
        summax[nod]=max(0,v[nod]);
        return;
    }
    for(int i=0;i<truetree[nod].size();++i)
    {
        dfs(truetree[nod][i]);
        summax[nod]+=summax[truetree[nod][i]];
    }
    summax[nod]=max(0,max(summax[nod]+v[nod],v[nod]));
}
int main()
{
    f>>n;
    int maxe=-1e9;
    for(int i=1;i<=n;++i)
        f>>v[i],maxe=max(maxe,v[i]);
    for(int i=1;i<n;++i)
    {
        int a,b;
        f>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    Constructor();
    dfs(1);
    int max1=0;
    for(int i=1;i<=n;++i)
        max1=max(max1,summax[i]);
    if(max1==0)
        g<<maxe;
    else
        g<<max1;
    return 0;
}
