#include<bits/stdc++.h>
using namespace std;
ifstream f("hotel.in");
ofstream g("hotel.out");
int n, q;
struct aint
{
    int lazy;
    int seqmax1, seqleft1, seqright1;
    int seqmax0, seqleft0, seqright0;
};
aint v[400002];
void build(int nod, int st, int dr)
{
    if(st==dr)
    {
        v[nod].seqmax0=v[nod].seqleft0=v[nod].seqright0=1;
        return;
    }
    int mid=(st+dr)/2;
    build(nod<<1, st, mid);
    build(nod<<1|1, mid+1, dr);
    v[nod].seqmax0=v[nod].seqleft0=v[nod].seqright0=(dr-st+1);
}
void lazy(int nod, int st, int dr)
{
    v[nod].lazy=0;
    if(st!=dr)
    {
        v[nod<<1].lazy^=1;
        v[nod<<1|1].lazy^=1;
    }
    swap(v[nod].seqmax0, v[nod].seqmax1);
    swap(v[nod].seqleft0, v[nod].seqleft1);
    swap(v[nod].seqright0, v[nod].seqright1);
}
void upd(int nod, int st, int dr, int L, int R)
{
    if(v[nod].lazy)
        lazy(nod, st, dr);
    if(dr<L || st>R)
        return;
    if(L<=st && dr<=R)
    {
        v[nod].lazy^=1;
        if(v[nod].lazy)
            lazy(nod, st, dr);
        return;
    }
    int mid=(st+dr)/2;
    upd(nod<<1, st, mid, L, R);
    upd(nod<<1|1, mid+1, dr, L, R);
    int sz=mid-st+1;
    int sz2=dr-(mid+1)+1;
    v[nod].seqleft0=v[nod<<1].seqleft0+v[nod<<1|1].seqleft0*(v[nod<<1].seqleft0==sz);
    v[nod].seqleft1=v[nod<<1].seqleft1+v[nod<<1|1].seqleft1*(v[nod<<1].seqleft1==sz);
    v[nod].seqright0=v[nod<<1|1].seqright0+v[nod<<1].seqright0*(v[nod<<1|1].seqright0==sz2);
    v[nod].seqright1=v[nod<<1|1].seqright1+v[nod<<1].seqright1*(v[nod<<1|1].seqright1==sz2);
    v[nod].seqmax0=max(v[nod<<1].seqmax0, max(v[nod<<1|1].seqmax0, max(v[nod].seqleft0, v[nod].seqright0)));
    v[nod].seqmax0=max(v[nod].seqmax0, v[nod<<1].seqright0+v[nod<<1|1].seqleft0);
    v[nod].seqmax1=max(v[nod<<1].seqmax1, max(v[nod<<1|1].seqmax1, max(v[nod].seqleft1, v[nod].seqright1)));
    v[nod].seqmax1=max(v[nod].seqmax1, v[nod<<1].seqright1+v[nod<<1|1].seqleft1);
}
int main()
{
    f>>n>>q;
    build(1, 1, n);
    for(int i=1;i<=q;++i)
    {
        int tip;
        f>>tip;
        if(tip==3)
            g<<v[1].seqmax0<<'\n';
        else
        {
            int L, R;
            f>>L>>R;
            R=R+L-1;
            upd(1, 1, n, L, R);
        }
    }
    return 0;
}
