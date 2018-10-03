#include<bits/stdc++.h>
using namespace std;
ifstream f("camionas.in");
ofstream g("camionas.out");
int n,m,R;
int mind[50002];
bool viz[50002];
/// gulbahar = rose
struct gulbahar{int dest, rez;};
vector<gulbahar>v[50002];
struct compar1
{
    bool operator()( int x, int y ){
        return mind[x]>mind[y];
    }
};
priority_queue <int,vector<int>,compar1>nod;
void dijkstra()
{
    nod.push(1);
    viz[1]=1;
    while(!nod.empty())
    {
        int nn=nod.top();
        nod.pop();
        for(int j=0;j<v[nn].size();++j)
        {
            int Rp=mind[nn];
            if(v[nn][j].rez<R)
                ++Rp;
            if(!viz[v[nn][j].dest] || Rp<mind[v[nn][j].dest])
            {
                 viz[v[nn][j].dest]=1;
                 mind[v[nn][j].dest]=Rp;
                 nod.push(v[nn][j].dest);
            }
        }
        if(viz[n])
            break;
    }
}
int main()
{
    f>>n>>m>>R;
    for(int i=1;i<=m;++i)
    {
        int a,b,r;
        f>>a>>b>>r;
        v[a].push_back({b,r});
        v[b].push_back({a,r});
    }
    dijkstra();
    g<<mind[n]<<'\n';
    return 0;
}
