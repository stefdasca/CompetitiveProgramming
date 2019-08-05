#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int v[200002];
int aint[2][20][800002];
int rg[2][20][200002], max_level;
void build(int pz, int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[0][pz][nod] = rg[0][pz][st];
        aint[1][pz][nod] = rg[1][pz][st];
        return;
    }
    int mid = (st + dr) / 2;
    build(pz, nod << 1, st, mid);
    build(pz, nod << 1|1, mid+1, dr);
    aint[0][pz][nod] = min(aint[0][pz][nod << 1], aint[0][pz][nod << 1|1]);
    aint[1][pz][nod] = max(aint[1][pz][nod << 1], aint[1][pz][nod << 1|1]);
}
int mxx, mnn;
void qu(int pz, int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        mxx = max(mxx, aint[1][pz][nod]);
        mnn = min(mnn, aint[0][pz][nod]);
        return;
    }
    int mid = (st + dr) / 2;
    qu(pz, nod << 1, st, mid, L, R);
    qu(pz, nod << 1|1, mid+1, dr, L, R);
}
int cb(int pz)
{
    int Lv = 0;
    while(rg[0][Lv][pz + n/2] > rg[1][Lv][pz] + 1)
        ++Lv;
    int worst_answer = (1<<Lv);
    int R = pz + n/2;
    int L = pz;
    int ans = 0;
    for(int i = Lv-1; i >= 0; --i)
    {
        mxx = -(1<<20);
        mnn = (1<<20);
        qu(i, 1, 1, n, pz, L);
        int pL = mxx;
        int ppR = mnn;
        mxx = -(1<<20);
        mnn = 1<<20;
        qu(i, 1, 1, n, R, pz + n/2);
        int pR = mnn;
        int ppL = mxx;
        if(ppR + n/2 <= pR)
            pR = ppR + n/2;
        if(ppL - n/2 >= pL)
            pL = ppL - n/2;
        if(pL + 1 < pR)
            ans += (1<<i), L = pL, R = pR;
    }
    if(L + 1 < R)
        ++ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], v[n+i] = v[i];
    n *= 2;
    max_level = 0;
    for(int i = 1; i <= n; ++i)
    {
        rg[0][0][i] = i - v[i];
        rg[1][0][i] = i + v[i];
    }
    build(0, 1, 1, n);
    for(int level = 1; (1 << level) <= n; ++level, ++max_level)
    {
        for(int i = 1; i <= n; ++i)
        {
            mxx = -(1<<20);
            mnn = (1<<20);
            qu(level-1, 1, 1, n, rg[0][level-1][i], rg[1][level-1][i]);
            rg[0][level][i] = mnn;
            rg[1][level][i] = mxx;
        }
        build(level, 1, 1, n);
    }
    for(int i = 1; i <= n/2; ++i)
        cout << cb(i) << " ";
    return 0;
}
