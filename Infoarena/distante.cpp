#include<bits/stdc++.h>
using namespace std;
ifstream f("distante.in");
ofstream g("distante.out");
int t;
int n,m,s;
int vinit[50002];
int dminx[50002];
bool viz[50002];
vector<int>v[50002];
vector<int>dist[50002];
void find_the_flower()  /// generic name for my deepest wish in my heart
{                       /// top kek
    deque<int>d;
    d.push_back(s);
    while(!d.empty())
    {
        for(int j=0;j<v[d[0]].size();++j)
            if(!viz[v[d[0]][j]] || dminx[d[0]]+dist[d[0]][j]<dminx[v[d[0]][j]])
            {
                viz[v[d[0]][j]]=1;
                dminx[v[d[0]][j]]=dminx[d[0]]+dist[d[0]][j];
                d.push_back(v[d[0]][j]);
            }
        d.pop_front();
    }
}
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n>>m>>s;
        for(int i=1;i<=n;++i)
            v[i].clear(),dist[i].clear(),viz[i]=0,dminx[i]=0;
        for(int i=1;i<=n;++i)
            f>>vinit[i];
        viz[s]=1;
        for(int i=1;i<=m;++i)
        {
            int a,b,d;
            f>>a>>b>>d;
            v[a].push_back(b);
            v[b].push_back(a);
            dist[a].push_back(d);
            dist[b].push_back(d);
        }
        find_the_flower();
        bool ok=1;
        for(int i=1;i<=n;++i)
            if(dminx[i]!=vinit[i])
                ok=0;
        if(ok)
            g<<"DA"<<'\n';
        else
            g<<"NU"<<'\n';
    }
    return 0;
}
