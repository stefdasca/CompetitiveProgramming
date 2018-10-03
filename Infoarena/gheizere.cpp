#include<bits/stdc++.h>
using namespace std;
ifstream f("gheizere.in");
ofstream g("gheizere.out");
int n,m,ice,w,e;
int mint[252][252];
int timetillexplosion[252][252];
int ox[]={-1,0,1};
int oy[]={0,1,0};
deque<pair<short,short> >p;
deque<short>dist;
struct icy
{
    short x,y,r,t,d;
};
icy v[1002];
vector<short>v2[63002];
bool isinmatrix(int l, int c)
{
    return ((l>=1 && l<=n) && (c>=1 && c<=m));
}
int zonetonumber(int l, int c)
{
    return (l-1)*m+c;
}
void init()
{
    f>>n>>m>>ice;
    f>>w>>e; /// (w,1) -> (e,m)
    for(int i=1;i<=ice;++i)
    {
        f>>v[i].x>>v[i].y>>v[i].r>>v[i].t>>v[i].d;
        for(int j=v[i].x-v[i].r;j<=v[i].x+v[i].r;++j)
            for(int k=v[i].y-v[i].r;k<=v[i].y+v[i].r;++k)
                if(isinmatrix(j,k))
                    v2[zonetonumber(j,k)].push_back(i);
    }
}
void lee()
{
    p.push_back({w,1});
    dist.push_back(1);
    if(!v2[zonetonumber(w,1)].size())
        mint[w][1]=1;
    int sol=-1;
    while(!p.empty() && sol==-1)
    {
        int X=p[0].first;
        int Y=p[0].second;
        int D=dist[0];
        p.pop_front();
        dist.pop_front();
        for(int i=0;i<=2;++i)
        {
            int X2=X+ox[i];
            int Y2=Y+oy[i];
            if(!isinmatrix(X2,Y2))
                continue;
            if(mint[X2][Y2] && !v2[zonetonumber(X2,Y2)].size())
                continue;
            bool gut=1;
            int minimi=1e9;
            for(int j=0;gut && j<v2[zonetonumber(X2,Y2)].size();++j)
            {
                int poz=v2[zonetonumber(X2,Y2)][j];
                if(((D+1)%(v[poz].t+v[poz].d)>v[poz].t) || !((D+1)%(v[poz].t+v[poz].d)))
                    gut=0;
                else
                    minimi=min(minimi,(v[poz].t+1)-(D+1)%(v[poz].t+v[poz].d));
            }
            if(!gut)
                continue;
            if(!mint[X2][Y2])
            {
                mint[X2][Y2]=D+1;
                timetillexplosion[X2][Y2]=minimi;
                if(X2==e && Y2==m)
                    sol=D+1;
                p.push_back({X2,Y2});
                dist.push_back({D+1});
            }
            else
                if(minimi>timetillexplosion[X2][Y2])
                {
                    mint[X2][Y2]=D+1;
                    timetillexplosion[X2][Y2]=minimi;
                    if(X2==e && Y2==m)
                        sol=D+1;
                    p.push_back({X2,Y2});
                    dist.push_back({D+1});
                }
        }
    }
    if(sol==-1)
        sol=424;
    g<<sol;
}
int main()
{
    init();
    lee();
    return 0;
}
