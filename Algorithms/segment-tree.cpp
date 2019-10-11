/// https://infoarena.ro/problema/arbint

#include<bits/stdc++.h>
using namespace std;
ifstream f("arbint.in");
ofstream g("arbint.out");

int n, q, v[100002], aint[400002];

void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod] = v[st];
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    aint[nod] = max(aint[nod << 1], aint[nod << 1|1]);
}

void update(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        aint[nod] = val;
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        update(nod << 1, st, mid, poz, val);
    else
        update(nod << 1|1, mid+1, dr, poz, val);
    aint[nod] = max(aint[nod << 1], aint[nod << 1|1]);
}

int query(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return -1;
    if(L <= st && dr <= R)
        return aint[nod];
    int mid = (st + dr) / 2;
    return max(query(nod << 1, st, mid, L, R), query(nod << 1|1, mid+1, dr, L, R));
}
int main()
{
    f >> n >> q;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    build(1, 1, n);
    for(int i = 1; i <= q; ++i)
    {
        int tip;
        f >> tip;
        if(tip == 0)
        {
            int L, R;
            f >> L >> R;
            g << query(1, 1, n, L, R) << '\n';
        }
        else
        {
            int poz, val;
            f >> poz >> val;
            update(1, 1, n, poz, val);
        }
    }
    return 0;
}
