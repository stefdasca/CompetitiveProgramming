/*
Arbore de intervale + lazy update
Mascarea minimului de fiecare data
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("biscuiti.in");
ofstream g("biscuiti.out");
int n;
int v[100002];
const long long inf=10000000000000000;
long long segtree[400002],who[400002],lazy[400002],dif;
struct ans
{
    long long val;
    long long who;
};
void build(int nod, int left, int right)
{
    if(left==right)
    {
        segtree[nod]=v[left];
        who[nod]=left;
        return;
    }
    int mid=(left+right)/2;
    build(nod<<1,left,mid);
    build(nod<<1|1,mid+1,right);
    if(segtree[nod<<1]<=segtree[nod<<1|1])
    {
        segtree[nod]=segtree[nod<<1];
        who[nod]=who[nod<<1];
    }
    else
    {
        segtree[nod]=segtree[nod<<1|1];
        who[nod]=who[nod<<1|1];
    }
}
ans query(int nod, int st, int dr, int i, int j)
{
    if(lazy[nod] != 0){
        segtree[nod] += lazy[nod];
        if(st != dr){
            lazy[nod*2] += lazy[nod];
            lazy[nod*2+1] += lazy[nod];
        }
        lazy[nod] = 0;
    }
    if(st >= i && dr <= j)
        return {segtree[nod],who[nod]};
    int m = (st+dr)/2;
    ans rasp={inf,0};
    if(m >= i)
        rasp= query(nod<<1, st, m, i, j);
    if(m < j){
        ans doi=query(nod<<1|1, m+1, dr, i, j);
        if(doi.val<rasp.val)
            rasp=doi;
    }
    return rasp;
}
void lazy_update(int nod, int left, int right, int st, int dr, long long val)
{
    if(lazy[nod])
    {
        segtree[nod]+=lazy[nod];
        if(left!=right)
        {
            lazy[nod<<1]+=lazy[nod];
            lazy[nod<<1|1]+=lazy[nod];
        }
        lazy[nod]=0;
    }
    if(left>dr || right<st)
        return;
    if(st<=left && right<=dr)
    {
        segtree[nod]+=val;
        if(left!=right){
            lazy[nod<<1]+=val;
            lazy[nod<<1|1]+=val;
        }
        return;
    }
    int mid=(left+right)/2;
    lazy_update(nod<<1,left,mid,st,dr,val);
    lazy_update(nod<<1|1,mid+1,right,st,dr,val);
    if(segtree[nod<<1]<=segtree[nod<<1|1])
    {
        segtree[nod]=segtree[nod<<1];
        who[nod]=who[nod<<1];
    }
    else
    {
        segtree[nod]=segtree[nod<<1|1];
        who[nod]=who[nod<<1|1];
    }
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i],dif+=v[i];
    build(1,1,n);
    for(int i=1;i<=n;++i)
    {
        ans x=query(1,1,n,1,n);
        int poz=x.who;
        dif-=x.val;
        lazy_update(1,1,n,poz,poz,inf);
        if(poz!=1)
            lazy_update(1,1,n,1,poz-1,i);
    }
    g<<-dif;
    return 0;
}
