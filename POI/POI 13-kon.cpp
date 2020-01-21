/*
        POI 13-kon

    We are going to simulate the updates and queries using lazy segment tree. It can be observed that we are going to visit the leaf nodes
only once, then the nodes above leaves twice and so on, so we will have an amortized algorithm running in O(n log n)

    Alternative solution using sqrt decomposition: https://oj.uz/submission/197599
*/
#include<bits/stdc++.h>
#include "koninc.h"
using namespace std;

const int MAXN = 300001;

int N, K, v[MAXN+5];

struct nod
{
    int mn, cnt;
    int lazy;
};
nod aint[MAXN * 4 + 5];
void solve_lazy(int nod)
{
    if(2 * nod + 1 <= 4 * N)
    {
        aint[2 * nod].lazy += aint[nod].lazy;
        aint[2 * nod + 1].lazy += aint[nod].lazy;
    }
    aint[nod].lazy = 0;
}
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod].mn = K - v[st];
        if(aint[nod].mn <= 0)
            aint[nod] = {(1<<30), 1, 0};
        return;
    }
    int mid = (st + dr) / 2;
    build(2 * nod, st, mid);
    build(2 * nod + 1, mid + 1, dr);
    aint[nod].cnt = aint[2 * nod].cnt + aint[2 * nod + 1].cnt;
    aint[nod].mn = min(aint[2 * nod].mn + aint[2 * nod].lazy, aint[2 * nod + 1].mn + aint[2 * nod + 1].lazy);
}

void update(int nod, int st, int dr, int l, int r)
{
    if(l <= st && dr <= r && aint[nod].mn + aint[nod].lazy - 1 > 0)
    {
        aint[nod].lazy--;
        return ;
    }
    if(st == dr)
    {
        aint[nod] = {(1<<30), 1, 0};
        return;
    }
    solve_lazy(nod);
    int mid = (st + dr) / 2;
    if(l <= mid)
        update(2 * nod, st, mid, l, r);
    if(mid < r)
        update(2 * nod + 1, mid + 1, dr, l, r);
    aint[nod].cnt = aint[2 * nod].cnt + aint[2 * nod + 1].cnt;
    aint[nod].mn = min(aint[2 * nod].mn + aint[2 * nod].lazy, aint[2 * nod + 1].mn + aint[2 * nod + 1].lazy);
}

int query(int nod, int st, int dr, int l, int r)
{
    if(l <= st && dr <= r)
        return aint[nod].cnt;
    int mid = (st + dr) / 2;
    int ans = 0;
    if(l <= mid)
        ans += query(2 * nod, st, mid, l, r);
    if(mid < r)
        ans += query(2 * nod + 1, mid + 1, dr, l, r);
    return ans;
}
void inicjuj(int n, int k, int *D)
{
    N = n, K = k;
    for(int i = 1; i <= n; ++i)
        v[i] = D[i-1];
    build(1, 1, n);
}

void podlej(int a, int b)
{
    ++a, ++b;
    update(1, 1, N, a, b);
}

int dojrzale(int a, int b)
{
    ++a, ++b;
    return query(1, 1, N, a, b);
}
