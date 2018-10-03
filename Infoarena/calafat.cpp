#include<bits/stdc++.h>
using namespace std;
ifstream f("calafat.in");
ofstream g("calafat.out");
int n,q,v[200002],last[200002];
long long crans, anss[200002],aib[200002];
struct queries
{
    int a,b;
};
queries upd[200002];
vector<pair<int,int> >qq[200002];
void add(int nod, int val)
{
    for(;nod<=n;nod+=(nod&(-nod)))
        aib[nod]+=val;
}
long long compute(int nod)
{
    long long sol=0;
    for(;nod;nod-=(nod&(-nod)))
        sol+=aib[nod];
    return sol;
}
int main()
{
    f>>n>>q;
    for(int i=1;i<=n;++i)
    {
        f>>v[i];
        if(last[v[i]])
            upd[i].a=last[v[i]],upd[i].b=i-last[v[i]];
        last[v[i]]=i;
    }
    for(int i=1;i<=q;++i)
    {
        int l,r;
        f>>l>>r;
        qq[r].push_back({l,i});
    }
    for(int i=1;i<=n;++i)
    {
        if(upd[i].a)
            add(upd[i].a,upd[i].b);
        for(int j=0;j<qq[i].size();++j)
            anss[qq[i][j].second]=compute(i)-compute(qq[i][j].first-1);
    }
    for(int i=1;i<=q;++i)
        g<<anss[i]<<'\n';
    return 0;
}
