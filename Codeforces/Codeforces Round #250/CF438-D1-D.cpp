#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
int v[100002];
long long sum[400002], mx[400002];
int prevVal, pz;
pair<int, int> p;
void update2(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        v[st] = sum[nod] = mx[nod] = val;
        return;
    }
    if(st == dr)
        return;
    int mid = (st + dr) / 2;
    if(poz <= mid)
        update2(nod << 1, st, mid, poz, val);
    else
        update2(nod << 1|1, mid+1, dr, poz, val);
    sum[nod] = sum[nod << 1] + sum[nod << 1|1];
    mx[nod] = max(mx[nod << 1], mx[nod << 1|1]);
}
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        sum[nod] = mx[nod] = v[st];
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    sum[nod] = sum[nod << 1] + sum[nod << 1|1];
    mx[nod] = max(mx[nod << 1], mx[nod << 1|1]);
}
void update1(int nod, int st, int dr, int L, int R, int md)
{
    if(dr < L || st > R)
        return;
    if(st == dr)
    {
        v[st] = v[st] % md;
        sum[nod] = mx[nod] = v[st];
        return;
    }
    int mid = (st + dr) / 2;
    if(mx[nod << 1] >= md)
        update1(nod << 1, st, mid, L, R, md);
    if(mx[nod << 1|1] >= md)
        update1(nod << 1|1, mid+1, dr, L, R, md);
    sum[nod] = sum[nod << 1] + sum[nod << 1|1];
    mx[nod] = max(mx[nod << 1], mx[nod << 1|1]);
}
long long query(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return 0;
    if(L <= st && dr <= R)
        return sum[nod];
    int mid = (st + dr) / 2;
    return query(nod << 1, st, mid, L, R) + query(nod << 1|1, mid+1, dr, L, R);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    build(1, 1, n);
    for(int i = 1; i <= m; ++i)
    {
        int tip;
        cin >> tip;
        if(tip == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
        if(tip == 2)
        {
            int l, r, x;
            cin >> l >> r >> x;
            update1(1, 1, n, l, r, x);
        }
        if(tip == 3)
        {
            int k, x;
            cin >> k >> x;
            update2(1, 1, n, k, x);
        }
    }
    return 0;
}
