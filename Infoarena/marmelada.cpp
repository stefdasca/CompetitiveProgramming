#include<bits/stdc++.h>
using namespace std;
ifstream f("marmelada.in");
ofstream g("marmelada.out");
int n,m,a,b,Zor=1;
vector<int>v[100002];
int va[100002];
int vb[100002];
struct vert
{
    int a,b,pinit;
    int poz;
};
vert zoli[100002];
inline bool test(vert a, vert b)
{
    if(a.a==b.a)
        return a.b<b.b;
    return a.a<b.a;
}
struct cui
{
    int val,init;
};
cui rr[100002];
inline bool test2(cui a, cui b)
{
    return a.val<b.val;
}
inline bool test3(vert a, vert b)
{
    return a.pinit<b.pinit;
}
deque<int>lsol;
inline void bfs1(int nod, int p)
{
    deque<int>d;
    d.push_back(nod);
    while(!d.empty())
    {
        int r=d[0];
        for(int i=0;i<v[r].size();++i)
            if(p==1){
                if(va[v[r][i]]==0 && v[r][i]!=nod){
                    va[v[r][i]]=va[r]+1;
                    d.push_back(v[r][i]);
                }
            }
            else
                if(vb[v[r][i]]==0 && v[r][i]!=nod){
                    vb[v[r][i]]=vb[r]+1;
                    d.push_back(v[r][i]);
                }
        d.pop_front();
    }
}
inline void bfs(int nod)
{
    lsol.push_back(nod);
    if(nod==b)
        return;
    int mindist=1e9;
    int who=0;
    for(int i=0;i<v[nod].size();++i)
        if(vb[v[nod][i]]<mindist)
            mindist=vb[v[nod][i]],who=v[nod][i];
    bfs(who);
}
inline void Read()
{
    f>>n>>m>>a>>b;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        zoli[i].a=x;
        zoli[i].b=y;
        zoli[i].pinit=i;
    }
    sort(zoli+1,zoli+m+1,test);
    for(int i=1;i<=m;++i)
        f>>rr[i].val,rr[i].init=i;
    sort(rr+1,rr+m+1,test2);
}
inline bool BinSearch(int a, int b)
{
    int st=1,sf=m;
    bool Hmmm=0; /// reference
    while(st<=sf)
    {
        int M=(st+sf)/2;
        if(zoli[M].a==a && zoli[M].b==b)
        {
            Hmmm=1;
            zoli[M].poz=rr[Zor].init;
            ++Zor;
            return 1;
        }
        else
            if(zoli[M].a>a || (zoli[M].a==a && zoli[M].b>b))
                sf=M-1;
            else
                st=M+1;
    }
    return 0;
}
inline void finito()
{
    for(int i=0;i<lsol.size()-1;++i)
    {
        int a=lsol[i];
        int b=lsol[i+1];
        int zp=Zor;
        BinSearch(a,b);
        if(Zor==zp)
            BinSearch(b,a);
    }
    sort(zoli+1,zoli+m+1,test3);
    for(int i=1;i<=m;++i){
        if(!zoli[i].poz)
            zoli[i].poz=rr[Zor].init,++Zor;
        g<<zoli[i].poz<<'\n';
    }
}
int main()
{
    Read();
    bfs1(a,1);
    bfs1(b,2);
    bfs(a);
    finito();
    return 0;
}
