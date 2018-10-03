/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("plopi.in");
ofstream g("plopi.out");
long long n,d[100002],sol,pr,im;
vector<pair<int,int>>v[100002];
bool viz[100002];
void dfs1(int nod)
{
    viz[nod]=1;
    if(d[nod]&1)
        ++im;
    else
        ++pr;
    for(int i=0;i<v[nod].size();++i)
        if(!viz[v[nod][i].first]){
            d[v[nod][i].first]=d[nod]+v[nod][i].second;
            dfs1(v[nod][i].first);
        }
}
int main()
{
    f>>n;
    for(int i=1;i<n;++i)
    {
        int a,b,c;
        f>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs1(1);
    g<<pr*im;
    return 0;
}
