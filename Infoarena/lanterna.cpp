/// 2 burned, 5 left
#include<bits/stdc++.h>
using namespace std;
ifstream f("lanterna.in");
ofstream g("lanterna.out");
struct edge
{
    int nod,t,w;
};
vector<edge> v[55];
queue<pair<int,int> > q;
int n,k,tip[55],d[55][1010],vaz[55][1010];
int solve(int s)
{
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
        {
            d[i][j]=1e9;
            vaz[i][j]=0;
        }
    d[1][s]=0;
    q.push({1,s});
    while(!q.empty())
    {
        int nod=q.front().first;
        int val=q.front().second;
        q.pop();
        vaz[nod][val]=0;
        for(int i=0;i<v[nod].size();i++)
        {
            int c=val-v[nod][i].w;
            if(c<0)
                continue;
            int vec=v[nod][i].nod;
            if(tip[vec]==1)
                c=s;
            if(d[nod][val]+v[nod][i].t<d[vec][c])
            {
                d[vec][c]=d[nod][val]+v[nod][i].t;
                if(vaz[vec][c]==0)
                    q.push({vec,c});
            }
        }
    }
    int sol=1e9;
    for(int i=0;i<=k;i++)
        sol=min(sol,d[n][i]);
    return sol;
}
int main()
{
    int x,y,t,w,m;
    f>>n>>k;
    for(int i=1;i<=n;i++)
        f>>tip[i];
    f>>m;
    for(int i=1;i<=m;i++)
    {
        f>>x>>y>>t>>w;
        if(w>k)
            continue;
        v[x].push_back({y,t,w});
        v[y].push_back({x,t,w});
    }
    int tmin=solve(k);
    int st=1,dr=k;
    while(st<=dr)
    {
        int mid=(st+dr)/2;
        if(solve(mid)>tmin)
            st=mid+1;
        else
            dr=mid-1;
    }
    g<<tmin<<" "<<st<<'\n';
    return 0;
}
