#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, q;
int v[300002];
int v2[300002];
int aint[3][4000002];
void upd(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        aint[1][nod] += val;
        aint[2][nod] += val;
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        upd(nod << 1, st, mid, poz, val);
    else
        upd(nod << 1|1, mid+1, dr, poz, val);
    aint[2][nod] = min(aint[2][nod << 1], aint[1][nod << 1] + aint[2][nod << 1|1]);
    aint[1][nod] = aint[1][nod << 1] + aint[1][nod << 1|1];
}
int aa, bb, sum;
void Find2(int nod, int st, int dr, int mx)
{
    if(dr <= mx)
    {
        bb = min(bb, sum + aint[2][nod]);
        sum += aint[1][nod];
        return;
    }
    if(st > mx)
        return;
    int mid = (st + dr) / 2;
    Find2(nod << 1, st, mid, mx);
    Find2(nod << 1|1, mid+1, dr, mx);
}
int cb()
{
    int st = 1;
    int dr = 1000000;
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        aa = bb = sum = 0;
        Find2(1, 1, 1000000, mid);
        if(bb <= -1)
            ans = mid, dr = mid - 1;
        else
            st = mid + 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], upd(1, 1, 1000000, 1000000 - v[i] + 1, -1);
    for(int i = 1; i <= m; ++i)
        cin >> v2[i], upd(1, 1, 1000000, 1000000 - v2[i] + 1, 1);
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        int tip, who, pr;
        cin >> tip >> who >> pr;
        if(tip == 1)
        {
            upd(1, 1, 1000000, 1000000 - v[who] + 1, 1);
            v[who] = pr;
            upd(1, 1, 1000000, 1000000 - v[who] + 1, -1);
        }
        else
        {
            upd(1, 1, 1000000, 1000000 - v2[who] + 1, -1);
            v2[who] = pr;
            upd(1, 1, 1000000, 1000000 - v2[who] + 1, 1);
        }
        bb = sum = 0;
        Find2(1, 1, 1000000, 1000000);
        if(bb == 0)
            cout << -1 << '\n';
        else
            cout << 1000000 - cb() + 1 << '\n';
    }
    return 0;
}
