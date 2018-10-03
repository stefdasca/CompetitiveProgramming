/*
I love you Rose
I hope you love me too
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("zvon.in");
ofstream g("zvon.out");
int t,a,b,x,n,ar[60][100003];
vector<int>v[100003];
bool cmp(int a, int b)
{
    return ar[x][a]>ar[x][b];
}
void dfs(int nod)
{
    int mm=v[nod].size();
    for(int i=0;i<mm;++i)
        dfs1(v[nod][i]);
    sort(v[nod].begin(),v[nod].end(),cmp);
    for(int i = 0; i < v[nod].size(); ++i)
        ar[x][nod] = max(ar[x][nod],ar[x][v[nod][i]]+i+1);
}
int main()
{
    f>>t;
    for(x=1;x<=t;++x)
    {
        f>>n;
        for(int i=1;i<=n;++i)
            v[i].clear();
        for(int i=1;i<n;++i)
        {
            f>>a>>b;
            v[a].push_back(b);
        }
        dfs(1);
        g<<ar[x][1]<<'\n';
    }
    return 0;
}
