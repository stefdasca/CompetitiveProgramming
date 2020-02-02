/*
            POI 16-Christmas

    It is quite obvious that the answer is equal to the number of connected components of the resulted graph, if we draw an edge for every
pair (a, b) such that a has to be equal to b. There can be O(n^2) edges, so the trivial approach won't work.

    We can use sqrt decomposition and dsu to solve this problem. Namely, we're going to split the queries in pieces of length sqrt n.

    Why are we going to do this? One can observe that if we have a pair (a, b), a pair (b, c) and a pair(a, c), the pair(a, c) won't be
processed because it's redundant, so we can use another DSU to avoid running unnecessary updates.

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

using namespace std;

int n, m, tq;

int tt[500002], rg[500002], ans;

int tt2[500002], rg2[500002];
int Find(int nod)
{
    if(tt[nod] == nod)
        return nod;
    return tt[nod] = Find(tt[nod]);
}
void Union(int a, int b)
{
    if(a == b)
        return;
    if(rg[a] < rg[b])
        swap(a, b);
    rg[a] += rg[b];
    tt[b] = a;
}

int Find2(int nod)
{
    if(tt2[nod] == nod)
        return nod;
    return tt2[nod] = Find2(tt2[nod]);
}
void Union2(int a, int b)
{
    if(a == b)
        return;
    if(rg2[a] < rg2[b])
        swap(a, b);
    rg2[a] += rg2[b];
    tt2[b] = a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        tt[i] = i, rg[i] = 1;
        tt2[i] = i, rg2[i] = 1;
    }
    ans = n;
    for(int i = 1; i <= m; ++i)
    {
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        if(aa > bb)
            swap(aa, bb);
        while(cc)
        {
            if(cc >= 800)
            {
                if(Find2(aa) != Find2(bb))
                {
                    Union2(Find2(aa), Find2(bb));
                    for(int j = 0; j < 800; ++j)
                        if(Find(aa + j) != Find(bb + j))
                            --ans, Union(Find(aa + j), Find(bb + j));
                }
                aa += 800;
                bb += 800;
                cc -= 800;
            }
            else
            {
                for(int j = 0; j <= cc - 1; ++j)
                    if(Find(aa + j) != Find(bb + j))
                        --ans, Union(Find(aa + j), Find(bb + j));
                cc = 0;
            }
        }
    }
    cout << ans;
    return 0;
}
