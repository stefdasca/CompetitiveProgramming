/// Long code incoming
#include<bits/stdc++.h>
#define Nmax (1<<16)
#define LogMax 16
#define x first
#define y second
using namespace std;
ifstream f("atac.in");
ofstream g("atac.out");
int n,q,p;
vector<pair<int,int>>v[Nmax/2];
int X,Y,A,B,C,D;
inline void Read()
{
    f>>n>>q>>p;
    for(int i=2;i<=n;++i)
    {
        int a,b;
        f>>a>>b;
        v[a].push_back({i,b});
        v[i].push_back({a,b});
    }
    f>>X>>Y>>A>>B>>C>>D;
}
int nod[Nmax],niv[Nmax],Lap[Nmax/2],e;
bool viz[Nmax/2];
int anc[Nmax/2][LogMax],min1[Nmax/2][LogMax];
inline void dfs(int dad, int prec, int vf, int lvl)
{
    ++e;
    nod[e]=vf;
    niv[e]=lvl;
    viz[vf]=1;
    anc[vf][0]=dad;
    min1[vf][0]=prec;
    int dad2=dad,exp=1;
    while(dad2>1)
    {
        anc[vf][exp]=anc[dad2][exp-1];
        min1[vf][exp]=min(min1[vf][exp-1],min1[dad2][exp-1]);
        dad2=anc[vf][exp];
        ++exp;
    }
    for(int i=0;i<v[vf].size();++i)
    {
        if(!viz[v[vf][i].x])
        {
            dfs(vf,v[vf][i].y,v[vf][i].x,lvl+1);
            ++e;
            nod[e]=vf;
            niv[e]=lvl;
        }
    }
    Lap[vf]=e;
}
/// even that girl hasn't disappointed me so hard
int RMQ[LogMax][Nmax],LG[Nmax];
inline void rmq()
{
    for(int i=2;i<=e;++i)
        LG[i]=LG[i/2]+1;
    for(int i=1;i<=e;++i)
        RMQ[0][i]=i;
    for(int i=1;(1<<i)<=e;++i)
        for(int j=(1<<i);j<=e;++j)
        {
            int k=(1<<(i-1));
            RMQ[i][j]=RMQ[i-1][j];
            int x=niv[RMQ[i-1][j]];
            int y=niv[RMQ[i-1][j-k]];
            if(x>y)
                RMQ[i][j]=RMQ[i-1][j-k];
        }
}
inline int solve(int x, int y)
{
    int X1,X2,lung,logs,LCA,z1,z2,z3,dif,mina,minb;
    X1=min(Lap[x],Lap[y]);
    X2=max(Lap[x],Lap[y]);
    lung=(X2-X1+1);
    logs=LG[lung];
    LCA=RMQ[logs][X2];
    if(niv[LCA]>niv[RMQ[logs][X1+(1<<logs)-1]])
        LCA=RMQ[logs][X1+(1<<logs)-1];
    z1=niv[Lap[x]];
    z2=niv[Lap[y]];
    z3=niv[LCA];
    LCA=nod[LCA];
    dif=z1-z3;
    mina=1e9;
    minb=1e9;
    int p2=1,nn=0,who=x;
    while(p2*2<=dif)
        p2*=2,nn++;
    while(dif>0)
    {
        mina=min(mina,min1[who][nn]);
        dif-=p2;
        who=anc[who][nn];
        while(p2>dif)
            p2/=2,--nn;
    }
    dif=z2-z3;
    p2=1,nn=0,who=y;
    while(p2*2<=dif)
        p2*=2,nn++;
    while(dif>0)
    {
        minb=min(minb,min1[who][nn]);
        dif-=p2;
        who=anc[who][nn];
        while(p2>dif)
            p2/=2,--nn;
    }
    return min(mina,minb);
}
inline void Queries()
{
    for(int i=1;i<=q;++i)
    {
        int Z=1e9;
        if(X==Y)
            Z=0;
        else
            Z=solve(X,Y);
        if(i>q-p)
            g<<Z<<'\n';
        int Xp=X;
        int Yp=Y;
        X=(Xp*A+Yp*B)%n+1;
        Y=(Yp*C+Z*D)%n+1;
    }
}
int main()
{
    Read();
    dfs(0,0,1,0);
    rmq();
    Queries();
    return 0;
}
