#include<bits/stdc++.h>
using namespace std;
ifstream f("permlcs.in");
ofstream g("permlcs.out");
int n,k;
int poz[1002][12];
vector<int>v[1002];
int maxans[1002];
int sool=1;
bool viz[1002];
void dfs(int nod)
{
    viz[nod]=1;
    for(int i=0;i<v[nod].size();++i)
    {
        if(!viz[v[nod][i]])
            dfs(v[nod][i]);
        maxans[nod]=max(maxans[nod],maxans[v[nod][i]]+1);
    }
    maxans[nod]=max(maxans[nod],1);
    sool=max(sool,maxans[nod]);
}
int main()
{
    f>>n>>k;
    for(int i=1;i<=k;++i)
        for(int j=1;j<=n;++j){
            int nr;
            f>>nr;
            poz[nr][i]=j;
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(i==j)
                continue;
            bool ok=1;
            for(int p=1;p<=k;++p)
                if(poz[i][p]<poz[j][p])
                    ok=0;
            if(ok)
                v[i].push_back(j);
        }
    for(int i=1;i<=n;++i)
        if(!viz[i])
            dfs(i);
    g<<sool;
    return 0;
}
