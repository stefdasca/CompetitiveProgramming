/*
        POI 06-Tetris_3D

    editorial : https://github.com/nikolapesic2802/Programming-Practice/blob/master/tetris%203d/main.cpp

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("Ofast")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 1

using namespace std;

typedef long long ll;

int q, n, m;

int tr[2][2050][2050], lz[2][2050][2050];

void prop(int plz, int org, int nod)
{
    tr[plz][org][nod << 1] = max(tr[plz][org][nod << 1], lz[plz][org][nod]);
    tr[plz][org][nod << 1|1] = max(tr[plz][org][nod << 1|1], lz[plz][org][nod]);
    lz[plz][org][nod << 1] = max(lz[plz][org][nod << 1], lz[plz][org][nod]);
    lz[plz][org][nod << 1|1] = max(lz[plz][org][nod << 1|1], lz[plz][org][nod]);
    lz[plz][org][nod] = 0;
}
void upd2(int org, int plz, int st, int dr, int val, int nod = 1, int L = 0, int R = 1000)
{
    if(dr < L || st > R)
        return;
    if(st <= L && R <= dr)
    {
        tr[plz][org][nod] = max(tr[plz][org][nod], val);
        lz[plz][org][nod] = max(lz[plz][org][nod], val);
        return;
    }
    prop(plz, org, nod);
    int mid = (L + R) / 2;
    upd2(org, plz, st, dr, val, nod << 1, L, mid);
    upd2(org, plz, st, dr, val, nod << 1|1, mid + 1, R);
    tr[plz][org][nod] = max(tr[plz][org][nod << 1], tr[plz][org][nod << 1|1]);
}
void upd(int L, int R, int L2, int R2, int val, int nod = 1, int st = 0, int dr = 1000)
{
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        upd2(nod, 0, L2, R2, val);
        upd2(nod, 1, L2, R2, val);
        return;
    }
    int mid = (st + dr) / 2;
    upd(L, R, L2, R2, val, nod << 1, st, mid);
    upd(L, R, L2, R2, val, nod << 1|1, mid + 1, dr);
    upd2(nod, 0, L2, R2, val);
}

int mx2(int org, int plz, int st, int dr, int nod = 1, int L = 0, int R = 1000)
{
    if(dr < L || st > R)
        return 0;
    if(st <= L && R <= dr)
        return tr[plz][org][nod];
    prop(plz, org, nod);
    int mid = (L + R) / 2;
    return max(mx2(org, plz, st, dr, nod << 1, L, mid), mx2(org, plz, st, dr, nod << 1|1, mid + 1, R));
}
int mx(int st, int dr, int L2, int R2, int nod = 1, int L = 0, int R = 1000)
{
    if(dr < L || st > R)
        return 0;
    if(st <= L && R <= dr)
        return mx2(nod, 0, L2, R2);
    int mid = (L + R) / 2;
    return max(mx(st, dr, L2, R2, nod << 1, L, mid), max(mx(st, dr, L2, R2, nod << 1|1, mid + 1, R), mx2(nod, 1, L2, R2)));
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    for(; q; --q)
    {
        int h, w, sz, xa, ya;
        cin >> h >> w >> sz >> xa >> ya;
        upd(xa, xa + h - 1, ya, ya + w - 1, mx(xa, xa + h - 1, ya, ya + w - 1) + sz);
    }
    cout << mx(0, n - 1, 0, m - 1);
    return 0;
}
