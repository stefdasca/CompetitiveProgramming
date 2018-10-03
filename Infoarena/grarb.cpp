#include<bits/stdc++.h>
using namespace std;
ifstream f("grarb.in");
ofstream g("grarb.out");
int n,m,a,b;
bool viz[100002];
int nrcon,LG;
int much;
vector<int>v[100002];
void dfs(int nod)
{
    viz[nod]=1;
    ++LG;
    for(int j=0;j<v[nod].size();++j)
        if(viz[v[nod][j]]==0)
            dfs(v[nod][j]);
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;++i)
    {
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;++i)
        if(!viz[i]){
            LG=0;
            dfs(i),++nrcon;
            much+=LG-1;
        }
    g<<m-much<<'\n';
    g<<nrcon-1<<'\n';
    return 0;
}
