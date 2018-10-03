#include<bits/stdc++.h>
using namespace std;
ifstream f("painting.in");
ofstream g("painting.out");
int n,m;
vector<int>p[100002];
vector<int>t[100002];
bool wait[100002];
int col[100002];
struct q
{
    int a,b;
};
q v[100002];
void ftt(int nod)
{
    wait[nod]=1;
    for(int j=0;j<p[nod].size();++j)
        if(wait[p[nod][j]]==0)
        {
            t[nod].push_back(p[nod][j]);
            ftt(p[nod][j]);
        }
}
void dfs(int nod)
{
    for(int i=0;i<t[nod].size();++i)
        if(col[t[nod][i]]==0)
        {
            col[t[nod][i]]=col[nod];
            dfs(t[nod][i]);
        }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<n;++i)
    {
        int a,b;
        f>>a>>b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    for(int i=1;i<=m;++i)
        f>>v[i].a>>v[i].b;
    ftt(1);
    memset(wait, 0, n+1);
    for(int i=m;i>=1;--i)
    {
        if(col[v[i].a]==0){
            col[v[i].a]=v[i].b;
            dfs(v[i].a);
        }
    }
    for(int i=1;i<=n;++i)
        if(col[i]==0)
            g<<1<<" ";
        else
            g<<col[i]<<" ";
}
