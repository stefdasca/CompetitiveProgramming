#include <bits/stdc++.h>
using namespace std;
ifstream f("fotbal2.in");
ofstream g("fotbal2.out");
int n,m,i,a,b,V[1<<17],I[1<<16],win[1<<17];
pair <int,int> E[1<<17];
vector <int> G[1<<16];
void euler(int nod)
{
    for(;I[nod]<G[nod].size();)
    {
        int edg=G[nod][I[nod]];
        ++I[nod];
        if(V[edg])
            continue;
        V[edg]=1;
        int oth=E[edg].first+E[edg].second-nod;
        win[edg]=nod;
        euler(oth);
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;++i)
    {
        f>>a>>b;
        E[i]=make_pair(a,b);
        G[a].push_back(i);
        G[b].push_back(i);
    }
    int cm=m+1;
    for(i=1;i<=n;++i)
        if(G[i].size()&1)
        {
            int st=i;
            for(i++;i<=n&&G[i].size()%2==0;++i);
            int dr=i;
            E[cm]=make_pair(st,dr);
            G[st].push_back(cm);
            G[dr].push_back(cm);
            ++cm;
        }
    for(i=1;i<=n;++i)
        if(I[i]<G[i].size())
            euler(i);
    if(cm==m+1)
        g<<"0\n";
    else
        g<<"2\n";
    for(i=1;i<=m;++i)
        g<<win[i]<<'\n';
    return 0;
}
