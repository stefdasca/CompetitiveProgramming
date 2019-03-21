#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int p[5010],c[5010],k[5010],ans[5010],cup1[5010],cup2[5010];
char vaz1[5010],vaz[5010];
vector<int> v[5010];
int cupleaza(int nod)
{
    if(vaz[nod]==1)
        return 0;
    vaz[nod]=1;
    for(int i=0; i<v[nod].size(); i++)
        if(cup2[v[nod][i]]==0)
        {
            cup1[nod]=v[nod][i];
            cup2[v[nod][i]]=nod;
            return 1;
        }
    for(int i=0; i<v[nod].size(); i++)
        if(cupleaza(cup2[v[nod][i]])==1)
        {
            cup1[nod]=v[nod][i];
            cup2[v[nod][i]]=nod;
            return 1;
        }
    return 0;
}
int n, m, d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> p[i];
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    cin >> d;
    for(int i = 1; i <= d; ++i)
        cin >> k[i], vaz1[k[i]] = 1;
    for(int i = 1; i <= n; i++)
        if(vaz1[i]==0)
            v[p[i] + 1].push_back(c[i]);
    int mex=0;
    for(int i=d; i>=1; i--)
    {
        memset(vaz,0,sizeof(vaz));
        while(cupleaza(mex+1))
        {
            mex++;
            memset(vaz,0,sizeof(vaz));
        }
        ans[i]=mex;
        v[p[k[i]]+1].push_back(c[k[i]]);
    }
    for(int i = 1; i <= d; ++i)
        cout << ans[i] << '\n';
    return 0;
}
