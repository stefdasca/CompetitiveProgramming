#include<bits/stdc++.h>
#define MOD 66013
using namespace std;
ifstream f("autobuze.in");
ofstream g("autobuze.out");
int n, MAX, a[50010], viz[50010];
vector<pair<int,int>> v[66013];
vector<int> graf[50010];
void DFS(int x)
{
    viz[x]=1;
    for(int i=0;i<graf[x].size();++i)
        if(viz[graf[x][i]]==0)
            DFS(graf[x][i]);
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>a[i];
        MAX = max(MAX, a[i]);
        v[a[i]%MOD].push_back(make_pair(a[i], i));
    }
    for(int i=1;i<=n;++i)
        if(MAX/a[i]<=n)
            for(int j=2*a[i]; j<=MAX; j+=a[i])
            {
                int mod2=j%MOD;
                for(int k=0;k<v[mod2].size();++k)
                    if(v[mod2][k].first==j)
                    {
                        graf[i].push_back(v[mod2][k].second);
                        graf[v[mod2][k].second].push_back(i);
                        break;
                    }
            }
        else
            for(int j=1;j<=n;++j)
                if(a[j]%a[i]==0)
                    graf[i].push_back(j),graf[j].push_back(i);
    int ans=0;
    for(int i=1;i<=n;++i)
        if(viz[i]==0)
            DFS(i),++ans;
    g<<ans;
    return 0;
}
