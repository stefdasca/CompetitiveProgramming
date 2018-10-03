/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
ifstream f("razboi.in");
ofstream g("razboi.out");
int t;
int n;
bool viz[16002];
int sol[16002],minsol;
struct mx
{
    int dmax,dmax2;
    int who1,who2;
};
mx v2[16002];
vector<pair<int,int> >v[16002];
void dfs1(int nod)
{
    viz[nod]=1;
    for(int i=0;i<v[nod].size();++i)
    {
        int vecin=v[nod][i].x;
        if(viz[vecin])
            continue;
        int dist=v[nod][i].y;
        dfs1(vecin);
        if(v2[vecin].dmax+dist>v2[nod].dmax)
        {
            v2[nod].dmax2=v2[nod].dmax;
            v2[nod].who2=v2[nod].who1;
            v2[nod].who1=vecin;
            v2[nod].dmax=v2[vecin].dmax+dist;
        }
        else
            if(v2[vecin].dmax+dist>v2[nod].dmax2)
            {
               v2[nod].who2=vecin;
               v2[nod].dmax2=v2[vecin].dmax+dist;
            }
    }
}
void dfs2(int nod, int mx)
{
   // g<<"Rose "<<nod<<" "<<mx<<'\n';
    /// I have used once more this helper
    sol[nod]=max(mx,v2[nod].dmax);
    viz[nod]=1;
    for(int i=0;i<v[nod].size();++i)
    {
        int vecin=v[nod][i].x;
        int dist=v[nod][i].y;
        if(viz[vecin])
            continue;
      //  g<<nod<<" "<<vecin<<'\n';
        if(nod!=1)
        {
        ///    g<<v2[nod].who1<<" "<<v2[nod].who2<<'\n';
            if(v2[nod].who1==vecin)
                dfs2(vecin,max(mx+dist,dist+v2[nod].dmax2));
            else
                dfs2(vecin,max(mx+dist,dist+v2[nod].dmax));
        }
        else
        {
            if(v2[1].who1==v[1][i].x)
                mx=v2[1].dmax2;
            else
                mx=v2[1].dmax;
            dfs2(vecin,mx+dist);
        }
    }
}
int main()
{
    f>>t;
    for(int R=1;R<=t;++R)
    {
        f>>n;
        minsol=2e9;
        for(int i=1;i<n;++i)
        {
            int a,b,d;
            f>>a>>b>>d;
            v[a].push_back({b,d});
            v[b].push_back({a,d});
        }
        dfs1(1);
        memset(viz,0,sizeof(viz));
        dfs2(1,0);
        sol[1]=v2[1].dmax;
        g<<"Testul nr #"<<R<<'\n';
    //   for(int i=1;i<=n;++i)
   //         g<<v2[i].dmax<<" "<<v2[i].who1<<" "<<v2[i].dmax2<<" "<<v2[i].who2<<'\n';
        for(int i=1;i<=n;++i)
            if(sol[i]<minsol)
                minsol=sol[i];
        for(int i=1;i<=n;++i)
            if(sol[i]==minsol)
                g<<i<<'\n';
        for(int i=1;i<=n;++i)
        {
            sol[i]=0;
            v2[i]={0,0,0,0};
            v[i].clear();
            viz[i]=0;
        }
    }
    return 0;
}
