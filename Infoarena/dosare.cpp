#include<bits/stdc++.h>
using namespace std;
ifstream f("dosare.in");
ofstream g("dosare.out");
long long n,Hmm[16002];
long long sum[16002];
vector<int>v[16002];
bool cmp(int a, int b)
{
    return Hmm[a]>Hmm[b];
}
void dfs(int nod)
{
    for(int i=0;i<v[nod].size();++i)
        dfs(v[nod][i]);
    for(int i=0;i<v[nod].size();++i)
    {
        sum[nod]+=sum[v[nod][i]];
        Hmm[nod]+=Hmm[v[nod][i]];
    }
    sort(v[nod].begin(),v[nod].end(),cmp);
    for(int i=0;i<v[nod].size();++i)
        sum[nod]+=Hmm[v[nod][i]]*i;
    sum[nod]+=Hmm[nod];
}
int main()
{
    f>>n;
    for(int i=2;i<=n;++i)
    {
        int nr;
        f>>nr;
        v[nr].push_back(i);
    }
    for(int i=1;i<=n;++i)
        f>>Hmm[i];
    dfs(1);
    g<<sum[1]<<'\n';
    return 0;
}
