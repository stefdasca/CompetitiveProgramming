#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
struct pa
{
    int a, b, pi;
    int ans, fw;
};
pa v[300002];
pa v2[300002];
bool cmp(pa a, pa b)
{
    return a.a > b.a;
}
bool cmp2(pa a, pa b)
{
    return a.a < b.a;
}
int x, y;
int aint[2500002];
int cn[2500002];
void upd(int nod, int st, int dr, int poz, int val, int zz)
{
    if(st == dr)
    {
        aint[nod] = val;
        cn[nod] = zz;
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        upd(nod << 1, st, mid, poz, val, zz);
    else
        upd(nod << 1|1, mid+1, dr, poz, val, zz);
    if(aint[nod << 1] > aint[nod << 1|1])
        aint[nod] = aint[nod << 1], cn[nod] = cn[nod << 1];
    else
        aint[nod] = aint[nod << 1|1], cn[nod] = cn[nod << 1|1];
}
int query(int nod, int st, int dr, int L, int R)
{
    if(L <= st && dr <= R)
        return nod;
    if(dr < L || st > R)
        return 0;
    int mid = (st + dr) / 2;
    int xx = query(nod << 1, st, mid, L, R);
    int yy = query(nod << 1|1, mid+1, dr, L, R);
    if(aint[xx] > aint[yy])
        return xx;
    return yy;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int o, z;
        cin >> o >> z;
        if(o < z)
            v[++x] = {o, z, i};
        else
            v2[++y] = {o, z, i};
    }
    sort(v + 1, v + x + 1, cmp);
    sort(v2 + 1, v2 + y + 1, cmp2);
    int mx1 = 0, p1 = 0;
    for(int i = 1; i <= x; ++i)
    {
        int aa = query(1, 1, 2 * n, v[i].a + 1, 2 * n);
        v[i].ans = aint[aa] + 1;
        v[i].fw = cn[aa];
        if(v[i].ans > mx1)
            mx1 = v[i].ans, p1 = i;
        upd(1, 1, 2 * n, v[i].b, v[i].ans, i);
    }
    memset(aint, 0, sizeof(aint));
    memset(cn, 0, sizeof(cn));
    int mx2 = 0, p2 = 0;
    for(int i = 1; i <= y; ++i)
    {
        int aa = query(1, 1, 2 * n, 1, v2[i].a - 1);
        v2[i].ans = aint[aa] + 1;
        v2[i].fw = cn[aa];
        if(v2[i].ans > mx2)
            mx2 = v2[i].ans, p2 = i;
        upd(1, 1, 2 * n, v2[i].b, v2[i].ans, i);
    }
    if(mx1 >= mx2)
    {
        cout << mx1 << '\n';
        deque<int>ans;
        while(p1)
        {
            ans.push_front(v[p1].pi);
            p1 = v[p1].fw;
        }
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << " ";
    }
    else
    {
        cout << mx2 << '\n';
        deque<int>ans;
        while(p2)
        {
            ans.push_front(v2[p2].pi);
            p2 = v2[p2].fw;
        }
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << " ";
    }
    return 0;
}
