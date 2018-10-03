#include<bits/stdc++.h>
using namespace std;
ifstream f("transport2.in");
ofstream g("transport2.out");
int n,m;
vector<int>v[100002];
vector<int>dst[100002];
deque<int>nods;
bool viz[100002];
bool bfs(int mid)
{
    nods.clear();
    memset(viz,0,n+1);
    nods.push_back(1);
    viz[1]=1;
    while(!nods.empty())
    {
        for(int i=0;i<v[nods.front()].size();++i)
            if(dst[nods.front()][i]>=mid && viz[v[nods.front()][i]]==0)
            {
                viz[v[nods.front()][i]]=1;
                nods.push_back(v[nods.front()][i]);
                if(v[nods.front()][i]==n)
                    return 1;
            }
        nods.pop_front();
    }
    return 0;
}
void bin_search()
{
    int st=1;
    int sf=10000;
    int min1=1e5;
    while(st<=sf)
    {
        int mid=(st+sf)/2;
        if(bfs(mid)==1)
            st=mid+1,min1=mid;
        else
            sf=mid-1;
    }
    g<<min1;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int a,b,d;
        f>>a>>b>>d;
        v[a].push_back(b);
        dst[a].push_back(d);
        v[b].push_back(a);
        dst[b].push_back(d);
    }
    bin_search();
    return 0;
}
