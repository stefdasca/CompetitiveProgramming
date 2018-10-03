/// Fill in the blanks
/// this task is as beautiful as ....
/// right answer in last line(maybe)
/// O(n log n + m log n)
#include<bits/stdc++.h>
#define Maxd 1000002
using namespace std;
ifstream f("eliminare.in");
ofstream g("eliminare.out");
struct tree
{
    int mx,who,lz;
};
tree ArbInt[3*Maxd];
int n,m,Q,v[Maxd];
bool wdeleted[Maxd];
int nr,pos;
inline void build(int nod, int B, int E)
{
    if(B==E)
    {
        ArbInt[nod].mx=v[B];
        ArbInt[nod].who=B;
        ArbInt[nod].lz=1;
        return;
    }
    int m=(B+E)>>1;
    build(nod+nod,B,m);
    build(nod+nod+1,m+1,E);
    if(ArbInt[nod+nod].mx>=ArbInt[nod+nod+1].mx)
        ArbInt[nod].mx=ArbInt[nod+nod].mx,ArbInt[nod].who=ArbInt[nod+nod].who;
    else
        ArbInt[nod].mx=ArbInt[nod+nod+1].mx,ArbInt[nod].who=ArbInt[nod+nod+1].who;
    ArbInt[nod].lz=ArbInt[nod+nod].lz+ArbInt[nod+nod+1].lz;
}
int query_real_position( int nod, int st ,int dr,int x )
{
    if(st==dr)
        return st;
    int mid=(st+dr)>>1;
    if(ArbInt[nod<<1].lz >= x)
        return query_real_position( nod << 1, st, mid,x );
    else
        return query_real_position( nod<<1|1, mid+1,dr, x - ArbInt[nod<<1].lz);
}
inline void update2(int nod, int B, int E, int x)
{
    if(B>x || E<x)
        return;
    if(B==E)
    {
        ArbInt[nod].mx=-1;
        ArbInt[nod].lz=0;
        return;
    }
    int m=(B+E)>>1;
    update2(nod+nod,B,m,x);
    update2(nod+nod+1,m+1,E,x);
    if(ArbInt[nod+nod].mx>=ArbInt[nod+nod+1].mx)
        ArbInt[nod].mx=ArbInt[nod+nod].mx,ArbInt[nod].who=ArbInt[nod+nod].who;
    else
        ArbInt[nod].mx=ArbInt[nod+nod+1].mx,ArbInt[nod].who=ArbInt[nod+nod+1].who;
    ArbInt[nod].lz=ArbInt[nod+nod].lz+ArbInt[nod+nod+1].lz;
}
int max1,wh,cs,cd;
tree query_pozitie(int nod, int st, int dr, int x, int y){
    if( st>y || dr<x){
        return {-1e9,-1,0};
    }
    if(st>=x && dr<=y){
        return ArbInt[nod];
    }
    int mid = ( st + dr ) >> 1;
    tree stanga = query_pozitie( nod<<1,st,mid,x,y );
    tree dreapta = query_pozitie( nod<<1|1,mid+1,dr,x,y );
    if(stanga.mx >= dreapta.mx )
        return stanga;
    else
        return dreapta;
}
int main()
{
    f>>n>>Q;
    for(int i=1;i<=n;++i) /// n log n
        f>>v[i];
    build(1,1,n);
    for(int i=1;i<=Q;++i)
    {
        f>>cs>>cd;
        cs=query_real_position(1,1,n,cs);
        cd=query_real_position(1,1,n,cd);
        int pozitie = query_pozitie(1,1,n,cs,cd).who;
        wdeleted[pozitie]=1;
        update2(1,1,n,pozitie);
    }
    for(int i=1;i<=n;++i)
        if(!wdeleted[i])
            g<<v[i]<<'\n';
    return 0;
}
