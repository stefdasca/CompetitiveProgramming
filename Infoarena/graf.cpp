#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
ifstream f ("graf.in");
ofstream g ("graf.out");
const int nmax=75e2+3;
queue <int> q;
vector <int> v[nmax];
int usua[nmax],usub[nmax],x,y,c,m,n,p,viz[2*nmax],bun,a,b,sol[nmax];
void bfs(int nod,int d[])
{
    q.push(nod);
    d[nod]=0;
    while(!q.empty())
    {
        x=q.front();
        for(int i=0;i<v[x].size();++i)
        {
            if(d[v[x][i]]>d[x]+1)
            {
                d[v[x][i]]=d[x]+1;
                q.push(v[x][i]);
            }
        }
        q.pop();
    }
}
int main()
{
    f>>n>>m>>x>>y;
    for(int i=1;i<=n;++i)
        usub[i]=usua[i]=inf;
    for(int i=1;i<=m;++i)
    {
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(x,usua);
    bun=usua[y];
    bfs(y,usub);
    for(int i=1;i<=n;++i)
        if(usua[i]+usub[i]==bun)
            ++viz[usua[i]];
    int k=0;
    for(int i=1;i<=n;++i)
        if(usua[i]+usub[i]==bun&&viz[usua[i]]==1)
            sol[++k]=i;
    g<<k<<'\n';
    for(int i=1;i<=k;++i)
        g<<sol[i]<<' ';
    return 0;
}
