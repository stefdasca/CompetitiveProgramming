/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("dominouri.in");
ofstream g("dominouri.out");
int n,q,p;
vector<int>v[100002];
int nd[100002];
int hm[100002];
bool cmp(int a, int b)
{
    return nd[a]<nd[b];
}
void dfs(int nod)
{
    if(!v[nod].size()){
        nd[nod]=1;
        return;
    }
    int minam=0;
    for(int i=0;i<v[nod].size();++i)
        dfs(v[nod][i]);
    sort(v[nod].begin(),v[nod].end(),cmp);
    for(int i=0;i<hm[nod];++i)
        minam+=nd[v[nod][i]];
    nd[nod]=minam;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>q;
        for(int j=1;j<=q;++j){
            f>>p;
            v[i].push_back(p);
        }
    }
    for(int i=1;i<=n;++i)
        f>>hm[i];
    dfs(1);
    g<<nd[1]<<'\n';
    return 0;
}
