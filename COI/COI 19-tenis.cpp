/*
            COI 19-tenis

    Let's build a directed graph where we will draw an edge between x and y if x can beat y. One can observe that if max_ranking(x) < max_ranking(y),
x can beat y. Thus, we can use a segment tree to find the min number k such that k - count(k) = 0, where count(k) = number of players such that their
max rating is at most k.

    One can keep this information updated using lazy segment tree and binary search in segment tree to answer to the query as fast as possible.
*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
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

int n, q;
int ord[4][100002], poz[4][100002];

int find_worst(int x)
{
    return max(poz[1][x], max(poz[2][x], poz[3][x]));
}

int aint[400002], lazy[400002];
void lz(int nod, int st, int dr)
{
    aint[nod] += lazy[nod];
    if(st != dr)
    {
        lazy[nod << 1] += lazy[nod];
        lazy[nod << 1|1] += lazy[nod];
    }
    lazy[nod] = 0;
}
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod] = st;
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    aint[nod] = min(aint[nod << 1], aint[nod << 1|1]);
}
void update(int nod, int st, int dr, int L, int R, int val)
{
    lz(nod, st, dr);
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        lazy[nod] += val;
        lz(nod, st, dr);
        return;
    }
    int mid = (st + dr) / 2;
    update(nod << 1, st, mid, L, R, val);
    update(nod << 1|1, mid+1, dr, L, R, val);
    aint[nod] = min(aint[nod << 1], aint[nod << 1|1]);
}
int query(int nod, int st, int dr)
{
    lz(nod, st, dr);
    if(st == dr)
        return st;
    int mid = (st + dr) / 2;
    int ans = 0;
    if(aint[nod << 1] + lazy[nod << 1] == 0)
        ans = query(nod << 1, st, mid);
    else
        ans = query(nod << 1|1, mid+1, dr);
    aint[nod] = min(aint[nod << 1], aint[nod << 1|1]);
    return ans;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int j = 1; j <= 3; ++j)
        for(int i = 1; i <= n; ++i)
            cin >> ord[j][i], poz[j][ord[j][i]] = i;
    build(1, 1, n);
    for(int i = 1; i <= n; ++i)
        update(1, 1, n, find_worst(i), n, -1);
    for(; q; --q)
    {
        int tip, val;
        cin >> tip;
        if(tip == 1)
        {
            cin >> val;
            int ans = query(1, 1, n);
            cout << ((find_worst(val) <= ans) ? "DA" : "NE") << '\n';
        }
        else
        {
            int wh, a, b;
            cin >> wh >> a >> b;
            update(1, 1, n, find_worst(a), n, 1);
            update(1, 1, n, find_worst(b), n, 1);
            int x = poz[wh][a];
            int y = poz[wh][b];
            swap(ord[wh][x], ord[wh][y]);
            swap(poz[wh][a], poz[wh][b]);
            update(1, 1, n, find_worst(a), n, -1);
            update(1, 1, n, find_worst(b), n, -1);
        }
    }
    return 0;
}
