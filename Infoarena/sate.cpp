#include<bits/stdc++.h>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
int n,m,x,y,a,b,c;
int dmin=1e8;
vector<int>v[30002];
bool afa[30002];
void dfs(int nod,int dsf)
{
    if(nod==y)
    {
        dmin=min(dmin,dsf);
        return;
    }
    for(int i=0;i<v[nod].size();i+=2){
        if(afa[v[nod][i]]==0){
            afa[v[nod][i]]=1;
            dfs(v[nod][i],dsf+v[nod][i+1]);
        }
    }
    afa[nod]=1;
}
int main()
{
    f>>n>>m>>x>>y;
    for(int i=1;i<=m;++i)
    {
        f>>a>>b>>c;
        v[a].push_back(b);
        v[a].push_back(c);
        v[b].push_back(a);
        v[b].push_back(-c);
    }
    dfs(x,0);
    g<<dmin;
    return 0;
}
