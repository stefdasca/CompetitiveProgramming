/// #bettercoderthanshebeautiful
/// 7h 40min till i escape from this day
#include<bits/stdc++.h>
using namespace std;
ifstream f("reinvent.in");
ofstream g("reinvent.out");
int n,m,nrc;
int dmin[100002];
vector<int>v[100002];
int vis[100002];
int fo[100002];
deque< pair< pair<int,int>, int> >d;
int main()
{
    f>>n>>m>>nrc;
    for(int i=1;i<=m;++i)
    {
        int a,b;
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=nrc;++i)
    {
        int nr;
        f>>nr;
        d.push_back({{nr,nr},0});
        vis[nr]=1;
        fo[nr]=nr;
    }
    int sol=1e9;
    while(!d.empty())
    {
        int A=d[0].first.first;
        int B=d[0].first.second;
        int C=d[0].second;
        d.pop_front();
        for(int i=0;i<v[A].size();++i)
            if(!vis[v[A][i]])
            {
                fo[v[A][i]]=B;
                dmin[v[A][i]]=C+1;
                d.push_back({{v[A][i],B},C+1});
                vis[v[A][i]]=1;
            }
            else
                if(B!=fo[v[A][i]] && vis[v[A][i]]==1)
                {
                  // g<<dmin[v[A][i]]<<" "<<C<<" "<<fo[v[A][i]]<<" "<<B<<'\n';
                    sol=min(sol,dmin[v[A][i]]+C+1);
                    vis[v[A][i]]=2;
                    d.push_back({{v[A][i],B},C+1});
                }
    }
    g<<sol;
    return 0;
}
