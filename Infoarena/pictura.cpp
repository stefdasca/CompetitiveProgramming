/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("pictura.in");
ofstream g("pictura.out");
int n,m,a[1002][1002],maxc,q;
int hm[1002][1002];
struct colors
{
    int nz,nd,ni;
};
colors v[1000002];
deque< pair<int,int> >d;
deque< pair<int,int> >p;
int Lp,Cp,L2,C2;
int ox[]={-1,0,1,0};
int oy[]={0,1,0,-1};
void dfs(int L, int C, int val)
{
    ++hm[L][C];
    if(hm[L][C]>=2)
        ++v[val].ni;
    d.push_back(make_pair(L,C));
    for(int i=0;i<=3;++i)
    {
        if(a[L+ox[i]][C+oy[i]]!=a[L][C] || (L+ox[i]==Lp && C+oy[i]==Cp))
            continue;
        else
            p.push_back(make_pair(L+ox[i],C+oy[i]));
    }
    if(!p.size())
        return;
    int Ro=-1;
    if(Lp==0 && Cp==0)
        Ro=0;
    else
        for(int i=0;i<p.size();++i)
            if(L-Lp==p[i].first-L && C-Cp==p[i].second-C)
                Ro=i;
    if(Ro!=-1 || (Lp==0 && Cp==0))
    {
        L2=p[Ro].first;
        C2=p[Ro].second;
        p.clear();
        Lp=L;
        Cp=C;
        dfs(L2,C2,val);
    }
    else
    {
        L2=p[0].first;
        C2=p[0].second;
        p.clear();
        ++v[val].nd;
        Lp=L;
        Cp=C;
        dfs(L2,C2,val);
    }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>a[i][j],maxc=max(maxc,a[i][j]);
    g<<maxc<<'\n';
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]!=0)
            {
                int nrv=(a[i-1][j]==a[i][j])+(a[i+1][j]==a[i][j])+(a[i][j-1]==a[i][j])+(a[i][j+1]==a[i][j]);
                if(nrv<=1)
                {
                    ++v[a[i][j]].nz;
                    q=0;
                    Lp=0;
                    Cp=0;
                    dfs(i,j,a[i][j]);
                    while(!d.empty())
                    {
                        a[d[0].first][d[0].second]=0;
                        d.pop_front();
                    }
                }
            }
    for(int i=1;i<=maxc;++i)
        g<<v[i].nz<<" "<<v[i].nd<<" "<<v[i].ni<<'\n';
    return 0;
}
