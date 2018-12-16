/// be happy!

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, q, k;
struct punct
{
    int v[6];
};
punct v[200002];
struct aint
{
    int mini, maxi;
};
aint segtree[800002][22];
int mini[22], maxi[22];
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        for(int i = 0; i < (1<<(k - 1)); ++i)
        {
            int sum = 0;
            for(int j = 1; j <= k; ++j)
                if((i & (1<<(j - 1))))
                    sum -= v[st].v[j];
                else
                    sum += v[st].v[j];
            segtree[nod][i] = {sum, sum};
        }
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1 | 1, mid + 1, dr);
    for(int i = 0; i < (1<<(k - 1)); ++i)
    {
        segtree[nod][i].maxi = max(segtree[nod << 1][i].maxi, segtree[nod << 1 | 1][i].maxi);
        segtree[nod][i].mini = min(segtree[nod << 1][i].mini, segtree[nod << 1 | 1][i].mini);
    }
}
int nv[6];
void upd(int nod, int st, int dr, int poz)
{
    if(st == dr)
    {
        for(int j = 1; j <= k; ++j)
            v[st].v[j] = nv[j];
        for(int i = 0; i < (1<<(k - 1)); ++i)
        {
            int sum = 0;
            for(int j = 1; j <= k; ++j)
                if(i & (1<<(j - 1)))
                    sum -= v[st].v[j];
                else
                    sum += v[st].v[j];
            segtree[nod][i] = {sum, sum};
        }
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        upd(nod << 1, st, mid, poz);
    else
        upd(nod << 1 | 1, mid + 1, dr, poz);
    for(int i = 0; i < (1<<(k - 1)); ++i)
    {
        segtree[nod][i].maxi = max(segtree[nod << 1][i].maxi, segtree[nod << 1 | 1][i].maxi);
        segtree[nod][i].mini = min(segtree[nod << 1][i].mini, segtree[nod << 1 | 1][i].mini);
    }
}
void query(int nod, int l, int r, int st, int dr)
{
    if(st > r || dr < l)
        return;
    if(st <= l && r <= dr)
    {
        for(int i = 0; i < (1<<(k - 1)); ++i)
        {
            maxi[i] = max(maxi[i], segtree[nod][i].maxi);
            mini[i] = min(mini[i], segtree[nod][i].mini);
        }
        return;
    }
    int mid = (l + r) / 2;
    query(nod << 1, l, mid, st, dr);
    query(nod << 1|1, mid + 1, r, st, dr);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= k; ++j)
            cin >> v[i].v[j];
    }
    build(1, 1, n);
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        int tip;
        cin >> tip;
        if(tip == 1)
        {
            int where;
            cin >> where;
            for(int j = 1; j <= k; ++j)
                cin >> nv[j];
            upd(1, 1, n, where);
        }
        else
        {
            int st, dr;
            cin >> st >> dr;
            for(int j = 0; j < (1<<(k - 1)); ++j)
                maxi[j] = -(1<<30), mini[j] = (1<<30);
            query(1, 1, n, st, dr);
            long long mx = 0;
            for(int j = 0; j < (1<<(k - 1)); ++j)
                mx = max(mx, 1LL * (maxi[j] - mini[j]));
            cout << mx << '\n';
        }
    }
    return 0;
}
