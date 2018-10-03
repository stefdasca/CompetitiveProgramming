#include<bits/stdc++.h>
using namespace std;
ifstream f("sediu.in");
ofstream g("sediu.out");
int n;
vector<int>paths[16002];
vector<int>truetree[16002];
bool viz[16002];
int szsubtree[16002];
int max1[16002];
deque<int>d;
void find_the_tree()
{
    d.push_back(1);
    viz[1]=1;
    while(!d.empty())
    {
        for(int i=0;i<paths[d[0]].size();++i)
            if(viz[paths[d[0]][i]]==0)
            {
                truetree[d[0]].push_back(paths[d[0]][i]);
                viz[paths[d[0]][i]]=1;
                d.push_back(paths[d[0]][i]);
            }
        d.pop_front();
    }
}
void dfs(int nod)
{
    szsubtree[nod]=1;
    for(int i=0;i<truetree[nod].size();++i)
    {
        dfs(truetree[nod][i]);
        szsubtree[nod]+=szsubtree[truetree[nod][i]];
        max1[nod]=max(max1[nod],szsubtree[truetree[nod][i]]);
    }
    max1[nod]=max(max1[nod],n-szsubtree[nod]);
}
int main()
{
    f>>n;
    for(int i=1;i<n;++i)
    {
        int a,b;
        f>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    find_the_tree();
    dfs(1);
    int min1=1e9,nr=0;
    for(int i=1;i<=n;++i)
        if(max1[i]<min1)
            min1=max1[i],nr=1;
        else
            if(max1[i]==min1)
                ++nr;
    g<<min1<<" "<<nr<<'\n';
    for(int i=1;i<=n;++i)
        if(max1[i]==min1)
            g<<i<<" ";
    return 0;
}
