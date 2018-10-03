#include<bits/stdc++.h>
using namespace std;
ifstream f("berarii2.in");
ofstream g("berarii2.out");
int n,m,p,a,b;
int CanItReach[1000007],vv[1002];
vector<int>paths[1000007];
vector<int>v;
void dfs(int nod)
{
    for(int i=0;i<paths[nod].size();++i){
        if(!CanItReach[paths[nod][i]]){
            CanItReach[paths[nod][i]]=1;
            dfs(paths[nod][i]);
        }
    }
}
int main()
{
    f>>n>>m>>p;
    for(int i=1;i<=m;++i)
    {
        f>>a>>b;
        paths[b].push_back(a);
    }
    for(int i=1;i<=p;++i)
    {
        f>>vv[i];
        CanItReach[vv[i]]=1;
    }
    for(int i=1;i<=p;++i)
        dfs(vv[i]);
    for(int i=1;i<=n;++i)
        if(!CanItReach[i])
            v.push_back(i);
    g<<v.size()<<'\n';
    for(int i=0;i<v.size();++i)
        g<<v[i]<<'\n';
    return 0;
}
