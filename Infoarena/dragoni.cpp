#include<bits/stdc++.h>
#define nmax 801
#define inf 2e9-1
using namespace std;
ifstream f("dragoni.in");
ofstream g("dragoni.out");
vector<pair<int,int> >v[nmax];
priority_queue< pair<pair<int,int>, int>, vector<pair<pair<int,int>, int> >, greater< pair<pair<int,int>, int> > > h;
queue <int> q;
int dr[nmax],nod,n,m,p,i,a,b,c,d[nmax][nmax],fr[nmax],mx=inf,drag,j,maxim=inf;
void Read()
{
    f>>p;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>dr[i];
    for(i=1;i<=m;i++)
    {
        f>>a>>b>>c;
        v[a].push_back(make_pair(c,b));
        v[b].push_back(make_pair(c,a));
    }
}
int main()
{
    Read();
    if(p==1)
    {
        q.push(1);
        while(!q.empty())
        {
            nod=q.front();
            q.pop();
            for(i=0;i<v[nod].size();i++)
                if(v[nod][i].first<=dr[1] && !fr[v[nod][i].second]){
                    fr[v[nod][i].second]=1;
                    q.push(v[nod][i].second);
                }
        }
        mx=0;
        for(i=1;i<=n;i++)
            if(fr[i] && mx<dr[i])
                mx=dr[i];
        g<<mx;
    }
    else
    {
        h.push(make_pair(make_pair(0,1),1));
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                d[i][j]=inf;
        d[1][1]=0;
        fr[1]=0;
        while(!h.empty())
        {
            nod=h.top().first.second;
            drag=h.top().second;
            h.pop();
            if(dr[drag]<dr[nod])
            {
                d[nod][nod]=d[nod][drag];
                drag=nod;
            }
            for(i=0;i<v[nod].size();i++)
                if(v[nod][i].first<=dr[drag] && v[nod][i].first+d[nod][drag]<d[v[nod][i].second][drag] && v[nod][i].first+d[nod][drag]<maxim)
                {
                    d[v[nod][i].second][drag]=v[nod][i].first+d[nod][drag];
                    h.push(make_pair(make_pair(d[v[nod][i].second][drag],v[nod][i].second),drag));
                    if(v[nod][i].second==n)
                        maxim=d[v[nod][i].second][drag];
                }
        }
        mx=d[n][1];
        for(i=2;i<=n;i++)
            if(mx>d[n][i])
               mx=d[n][i];
        g<<mx;
    }
    return 0;
}
