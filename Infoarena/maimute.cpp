#include<bits/stdc++.h>
#define Nmax (1<<17)
using namespace std;
ifstream f("maimute.in");
ofstream g("maimute.out");
int n,q,m;
vector<int>v[Nmax];
bool viz[Nmax];
int st[Nmax],dr[Nmax]; /// Parcurgere Euler
void dfs(int varf)
{
    st[varf]=++m;
    viz[varf]=1;
    for(int i=0;i<v[varf].size();++i)
        if(!viz[v[varf][i]])
            dfs(v[varf][i]);
    dr[varf]=++m;
}
int main()
{
    f>>n;
    int a,b,x,y,lug,k,sol;
    for(int i=1;i<n;++i)
    {
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    f>>q;
    for(int i=1;i<=q;++i)
    {
        f>>a>>b;
        if(st[a]<st[b] && dr[a]>dr[b] || st[b]<st[a] && dr[b]>dr[a])
            g<<"DA"<<'\n';
        else
            g<<"NU"<<'\n';
    }
    return 0;
}
