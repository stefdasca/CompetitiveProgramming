/*
        APIO 17-rainbow

    https://github.com/dolphingarlic/CompetitiveProgramming/blob/master/APIO/APIO%2017-rainbow.cpp

*/

#include "rainbow.h"
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

using namespace std;

const int maxsz = 2e7;

int cnt = 1, segtree[maxsz], left_c[maxsz], right_c[maxsz];

struct aint
{
    set<int> data[200002];
    int roots[200002];
    void add(int x, int y)
    {
        data[x].insert(y);
    }
    void build()
    {
        for(int i = 1; i <= 200000; ++i)
        {
            roots[i+1] = roots[i];
            for(set<int> ::iterator it = data[i].begin(); it != data[i].end(); ++it)
                update(*it, roots[i+1]);
        }
    }
    void update(int pos, int &node, int l = 1, int r = 200000)
    {
        segtree[cnt] = segtree[node] + 1;
        left_c[cnt] = left_c[node];
        right_c[cnt] = right_c[node];
        node = cnt++;
        if (l == r)
            return;
        int mid = (l + r) / 2;
        if (pos > mid)
            update(pos, right_c[node], mid + 1, r);
        else
            update(pos, left_c[node], l, mid);
    }

    int query(int l1, int r1, int l2, int r2)
    {
        if (l2 > r2)
            return 0;
        return query2(l2, r2, roots[r1 + 1], 1, 200000) - query2(l2, r2, roots[l1], 1, 200000);
    }
    int query2(int a, int b, int node, int l, int r)
    {
        if (a > r || b < l)
            return 0;
        if (a <= l && b >= r)
            return segtree[node];
        int mid = (l + r) / 2;
        return query2(a, b, left_c[node], l, mid) + query2(a, b, right_c[node], mid + 1, r);
    }
} nod, muchiiH, muchiiV, rau;

int mxL, mnL = (1<<20), mxC, mnC = (1<<20);

void add_river(int L, int C)
{
    mxL = max(mxL, L);
    mxC = max(mxC, C);
    mnL = min(mnL, L);
    mnC = min(mnC, C);
    nod.add(L, C);
    nod.add(L + 1, C);
    nod.add(L, C + 1);
    nod.add(L + 1, C + 1);
    muchiiH.add(L, C);
    muchiiH.add(L + 1, C);
    muchiiV.add(L, C);
    muchiiV.add(L, C + 1);
    rau.add(L, C);
}
void init(int R, int C, int sr, int sc, int M, char *S)
{
    add_river(sr, sc);
    for(int i = 0; i < M; ++i)
    {
        sr += (S[i] == 'S');
        sr -= (S[i] == 'N');
        sc += (S[i] == 'E');
        sc -= (S[i] == 'W');
        add_river(sr, sc);
    }
    nod.build();
    muchiiH.build();
    muchiiV.build();
    rau.build();
}

int colour(int ar, int ac, int br, int bc)
{
    int E = muchiiH.query(ar + 1, br, ac, bc) + muchiiV.query(ar, br, ac + 1, bc);
    int V = nod.query(ar + 1, br, ac + 1, bc);
    int R = rau.query(ar, br, ac, bc);
    int C;
    if(ar >= mnL || br <= mxL || ac >= mnC || bc <= mxC)
        C = 1;
    else
        C = 2;
    return E - V + C - R;
}
