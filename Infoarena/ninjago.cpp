/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("ninjago.in");
ofstream g("ninjago.out");
int c;
int n,m;
vector<pair<int,string> >v2[32002];
string s;
bool viz[33002];
int dad[33002];
int gut;
int minp,nre,mincost;
struct muchii
{
    int a,b,ise,nre,cost;
};
muchii v[33002];
void dfs1(int nod)
{
    ++gut;
    viz[nod]=1;
    for(int i=0;i<v2[nod].size();++i)
    {
        int vecin=v2[nod][i].first;
        if(viz[vecin])
            continue;
        string s2=v2[nod][i].second;
        if( s2[0]!='E' && s2[1]!='E' && s2[2]!='E' && s2[3]!='E' )
            dfs1(vecin);
    }
}
inline bool cmp(muchii a, muchii b)
{
    if(a.nre==b.nre)
        return a.cost<b.cost;
    return a.nre<b.nre;
}
inline int arb(int nod)
{
    if(dad[nod]==nod)
        return nod;
    return dad[nod]=arb(dad[nod]);
}
int main()
{
    f>>c;
    f>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int a,b;
        f>>a>>b>>s;
        v2[a].push_back({b,s});
        v2[b].push_back({a,s});
        v[i].a=a;
        v[i].b=b;
        v[i].nre=(s[0]=='E')+(s[1]=='E')+(s[2]=='E')+(s[3]=='E');
        v[i].ise=(v[i].nre>0);
        v[i].cost=(s[0]!='E')*(s[0]-'A'+1)+5*(s[1]!='E')*(s[1]-'A'+1)+25*(s[2]!='E')*(s[2]-'A'+1)+125*(s[3]!='E')*(s[3]-'A'+1);
    }
    if(c==1){
        dfs1(1);
        g<<gut;
    }
    else
    {
        sort(v+1,v+m+1,cmp);
        for(int i=1;i<=n;++i)
            dad[i]=i;
        int j=0;
        for(int i=1;j<=n && i<=m;++i)
        {
            int x=arb(v[i].a);
            int y=arb(v[i].b);
            if(x!=y)
            {
                dad[x]=y;
                ++j;
                nre+=v[i].nre;
                minp+=v[i].ise;
                mincost+=v[i].cost;
            }
        }
        if(c==2)
            g<<minp<<'\n'<<nre;
        else
            g<<mincost;
    }
    return 0;
}
