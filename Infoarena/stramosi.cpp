// cu parsare ia 100
#include<bits/stdc++.h>
using namespace std;
ifstream f("stramosi.in");
ofstream g("stramosi.out");
int n,m,q,p,nr[250002];
int ancestors[250002][20];
vector<int>gul[250002];
void dfs(int dad, int nod)
{
    ancestors[nod][0]=dad;
    int lvl=0;
    int fth=dad;
    while(ancestors[fth][lvl])
    {
        ancestors[nod][lvl+1]=ancestors[fth][lvl];
        ++lvl;
        fth=ancestors[nod][lvl];
    }
    for(int i=0;i<gul[nod].size();++i)
        dfs(nod,gul[nod][i]);
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
    {
        f>>nr[i];
        if(nr[i]!=0)
            gul[nr[i]].push_back(i);
    }
    for(int i=1;i<=n;++i)
        if(!nr[i])
            dfs(0,i);
    for(int i=1;i<=m;++i)
    {
        f>>q>>p;
        int p2=1,lvl=0;
        while(p2*2<=p)
            p2*=2,lvl++;
        int father=q;
        while(p && father!=0)
        {
            p-=p2;
            father=ancestors[father][lvl];
            while(p<p2)
                p2/=2,--lvl;
        }
        g<<father<<'\n';
    }
    return 0;
}
