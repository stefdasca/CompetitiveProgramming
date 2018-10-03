#define Nmax 1505
#define eps 1e-8
#define Love 104659
#include<bits/stdc++.h>
using namespace std;
ifstream f("dmin.in");
ofstream g("dmin.out");
int n,m,a,b,di;
bool mat[Nmax][Nmax];
int dist[Nmax][Nmax];
vector<int>nod[Nmax];
vector<int>cost[Nmax];
double lg[Nmax];
int nrways[Nmax];
bool viz[Nmax];
deque<int>d;
void dijkstra()
{
    while(!d.empty())
    {
        int ro=d[0];
        for(int j=0;j<nod[ro].size();++j)
        {
            double zi=lg[ro]+log10(cost[ro][j]);
            if(!viz[nod[ro][j]])
            {
                viz[nod[ro][j]]=1;
                lg[nod[ro][j]]=zi;
                d.push_back(nod[ro][j]);
            }
            else
                if(lg[nod[ro][j]]-zi>eps)
                {
                    lg[nod[ro][j]]=zi;
                    d.push_back(nod[ro][j]);
                }
        }
        d.pop_front();
    }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;++i)
    {
        f>>a>>b>>di;
        nod[a].push_back(b);
        nod[b].push_back(a);
        mat[a][b]=mat[b][a]=1;
        dist[b][a]=dist[a][b]=di;
        cost[a].push_back(di);
        cost[b].push_back(di);
    }
    viz[1]=1;
    nrways[1]=1;
    d.push_back(1);
    dijkstra();
    for(int i=2;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(mat[i][j]==1)
                if(abs(lg[i]-(lg[j]+log10(dist[i][j])))<=eps)
                    nrways[i]=(nrways[i]+nrways[j])%Love;
    for(int i=2;i<=n;++i)
        g<<nrways[i]<<" ";
    return 0;
}
