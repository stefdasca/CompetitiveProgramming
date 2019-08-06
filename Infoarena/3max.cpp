/*
        infoarena 3max

    We can use a segment tree to solve the queries. Firstly, we can precompute st[i] = max sum subarray ending in some position <= i
and dr[i] = max sum subarray ending in some position >= i

    When building the segment tree, we will keep for each node the sum of the node, the max prefix, the max suffix and the max sum, in order
to be able to answer each of the queries in logarithmic time.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("3max.in");
ofstream g("3max.out");
int n, m, v[50002];
int st[50002], dr[50002];
struct aint
{
    long long sum;
    long long prf, sf, mx;
};
aint seg[200002];
void build(int nod, int L, int R)
{
    if(L == R)
    {
        seg[nod].sum = v[L];
        seg[nod].sf = max(st[L-1], v[L] + st[L-1]);
        seg[nod].prf = max(dr[L+1], v[L] + dr[L+1]);
        seg[nod].mx = st[L-1] + dr[L+1] + max(v[L], 0);
        return;
    }
    int mid = (L + R) / 2;
    build(nod << 1, L, mid);
    build(nod << 1|1, mid+1, R);
    seg[nod].sum = seg[nod << 1].sum + seg[nod << 1|1].sum;
    seg[nod].sf = max(seg[nod << 1|1].sf, seg[nod << 1|1].sum + seg[nod << 1].sf);
    seg[nod].prf = max(seg[nod << 1].prf, seg[nod << 1].sum + seg[nod << 1|1].prf);
    seg[nod].mx = max(seg[nod << 1].mx, seg[nod << 1|1].mx);
    seg[nod].mx = max(seg[nod].mx, seg[nod << 1].sf + seg[nod << 1|1].prf);
}
int Lq, Rq;
long long ans, sc;
void query(int nod, int L, int R)
{
    if(R < Lq || L > Rq)
        return;
    if(Lq <= L && R <= Rq)
    {
        ans = max(ans, sc + seg[nod].prf);
        sc = max(sc + seg[nod].sum, seg[nod].sf);
        ans = max(ans, max(sc, seg[nod].mx));
        return;
    }
    int mid = (L + R) / 2;
    query(nod << 1, L, mid);
    query(nod << 1|1, mid+1, R);
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    long long sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        st[i] = st[i-1];
        sum = max(sum + v[i], 1LL * v[i]);
        if(sum > st[i])
            st[i] = sum;
    }
    sum = 0;
    for(int i = n; i >= 1; --i)
    {
        dr[i] = dr[i+1];
        sum = max(sum + v[i], 1LL * v[i]);
        if(sum > dr[i])
            dr[i] = sum;
    }
    build(1, 1, n);
    for(int i = 1; i <= m; ++i)
    {
        f >> Lq >> Rq;
        ans = 0;
        sc = st[Lq-1];
        query(1, 1, n);
        g << ans << '\n';
    }
    return 0;
}
