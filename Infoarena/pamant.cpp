#include<bits/stdc++.h>
using namespace std;
ifstream f("pamant.in");
ofstream g("pamant.out");
int n,m,a,b;
vector<int>v[100002];
vector<int>sola;
vector<int>solb;
deque<int>path;
int nrc[100002],dad[100002],niv[100002],lw[100002];
bool viz[100002];
void dfs(int nod)
{
    viz[nod]=1;
    niv[nod]=niv[dad[nod]]+1;
    path.push_front(nod);
    lw[nod]=niv[nod];
    for(int i=0;i<v[nod].size();++i)
    {
        int vecin=v[nod][i];
        if(viz[vecin])
        {
            if(vecin!=dad[nod])
                lw[nod]=min(lw[nod],niv[vecin]);
            continue;
        }
        dad[vecin]=nod;
        dfs(vecin);
        lw[nod]=min(lw[vecin],lw[nod]);
        if(niv[nod]<=lw[vecin])
        {
            int k;
            do
            {
                k=path[0];
                ++nrc[k];
                path.pop_front();
            }while(k!=vecin);
            ++nrc[nod];
        }
    }
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
        if(!viz[i])
        {
            dfs(i);
            sola.push_back(i);
        }
    g<<sola.size()<<'\n';
    for(int i=0;i<sola.size();++i)
        g<<sola[i]<<" ";
    g<<'\n';
    for(int i=1;i<=n;++i)
        if(nrc[i]>=2)
            solb.push_back(i);
    g<<solb.size()<<'\n';
    for(int i=0;i<solb.size();++i)
        g<<solb[i]<<" ";
    return 0;

}
