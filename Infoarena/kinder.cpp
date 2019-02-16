
#include<bits/stdc++.h>
using namespace std;
ifstream f("kinder.in");
ofstream g("kinder.out");
int n, m, q;
struct Trie
{
    int sumval;
    Trie *fii[2];
    Trie()
    {
        sumval = 0;
        memset(fii, 0, sizeof(fii));
    }
};
struct aint
{
    Trie *t[2];
};
aint v[200002];
void Baga(int care, int poz, int tip, int nr)
{
    Trie *r;
    r = v[poz].t[care];
    for(int i = 15; i >= 0; --i)
    {
        int z = (tip & (1<<i));
        if(z)
            z = 1;
        if(r -> fii[z] == NULL)
            r -> fii[z] = new Trie;
        r = r -> fii[z];
        r -> sumval += nr;
    }
}
int Query1(int care, int poz, int tip)
{
    Trie *r;
    r = v[poz].t[care];
    for(int i = 15; i >= 0; --i)
    {
        int z = (tip & (1<<i));
        if(z)
            z = 1;
        if(r -> fii[z] == NULL)
            return 0;
        r = r -> fii[z];
    }
    return r -> sumval;
}
void upd(int nod, int st, int dr, int wh, int tip, int cul, int nr)
{
    if(v[nod].t[cul] == NULL)
        v[nod].t[cul] = new Trie;
    Baga(cul, nod, tip, nr);
    if(st == dr)
        return;
    int mid = (st + dr) / 2;
    if(wh <= mid)
        upd(nod << 1, st, mid, wh, tip, cul, nr);
    else
        upd(nod << 1|1, mid + 1, dr, wh, tip, cul, nr);
}
int valzero, valunu;
void ch(int nod, int st, int dr, int poz, int tip)
{
    if(v[nod].t[0] == NULL)
        v[nod].t[0] = new Trie;
    if(v[nod].t[1] == NULL)
        v[nod].t[1] = new Trie;
    if(st == dr)
    {
        valzero = Query1(0, nod, tip);
        valunu = Query1(1, nod, tip);
        Baga(0, nod, tip, valunu - valzero);
        Baga(1, nod, tip, valzero - valunu);
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        ch(nod << 1, st, mid, poz, tip);
    else
        ch(nod << 1|1, mid + 1, dr, poz, tip);
    Baga(0, nod, tip, valunu - valzero);
    Baga(1, nod, tip, valzero - valunu);
}
int nrr;
Trie *poz[50];
bool disabled[50];
void qu(int nod, int st, int dr, int l, int r, int cul)
{
    if(dr < l || st > r)
        return;
    if(l <= st && dr <= r)
    {
        if(v[nod].t[cul] != NULL)
        {
            ++nrr;
            poz[nrr] = v[nod].t[cul];
            disabled[nrr] = 0;
        }
        return;
    }
    int mid = (st + dr) / 2;
    qu(nod << 1, st, mid, l, r, cul);
    qu(nod << 1|1, mid + 1, dr, l, r, cul);
}
int main()
{
    f >> n >> m >> q;
    for(int i = 1; i <= q; ++i)
    {
        int tip;
        f >> tip;
        if(tip == 1)
        {
            int c, t, p, nr;
            f >> c >> t >> p >> nr;
            upd(1, 1, n, c, t, p, nr);
        }
        if(tip == 2)
        {
            int a, b;
            f >> a >> b;
            ch(1, 1, n, a, b);
        }
        if(tip == 3)
        {
            int a, b, p, x;
            f >> a >> b >> p >> x;
            nrr = 0;
            qu(1, 1, n, a, b, p);
            int ans = 0;
            for(int k = 15; k >= 0; --k)
            {
                int potsum = 0;
                for(int j = 1; j <= nrr; ++j)
                {
                    if(disabled[j])
                        continue;
                    if(poz[j] -> fii[0] != NULL)
                        potsum += poz[j] -> fii[0] -> sumval;
                }
                bool nxt = 0;
                if(x - potsum > 0)
                {
                    x -= potsum;
                    ans += (1<<k);
                    nxt = 1;
                }
                for(int j = 1; j <= nrr; ++j)
                {
                    if(disabled[j])
                        continue;
                    if(poz[j] -> fii[nxt] != NULL)
                        poz[j] = poz[j] -> fii[nxt];
                    else
                        disabled[j] = 1;
                }
            }
            g << ans << '\n';
        }
    }
    return 0;
}
