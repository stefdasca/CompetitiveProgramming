#include<bits/stdc++.h>
using namespace std;
int n, q;
bool direction;
int aint[400002];
int v[100002];
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod] = 1;
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1 | 1, mid + 1, dr);
    aint[nod] = aint[nod << 1] + aint[nod << 1 | 1];
}
int Le, Re;
int Query(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return 0;
    if(L <= st && dr <= R)
        return aint[nod];
    int mid = (st + dr) / 2;
    return Query(nod << 1, st, mid, L, R) + Query(nod << 1 | 1, mid + 1, dr, L, R);
}
void Update(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        aint[nod] += val;
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        Update(nod << 1, st, mid, poz, val);
    else
        Update(nod << 1 | 1, mid + 1, dr, poz, val);
    aint[nod] = aint[nod << 1] + aint[nod << 1 | 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    build(1, 1, n);
    Le = 1, Re = n;
    for(int i = 1; i <= n; ++i)
        v[i] = 1;
    for(int i = 1; i <= q; ++i)
    {
        int tip, st, dr, wh;
        cin >> tip;
        if(tip == 2)
        {
            cin >> st >> dr;
            ++st;
            if(direction == 0)
                cout << Query(1, 1, n, Le + st - 1, Le + dr - 1) << '\n';
            else
                cout << Query(1, 1, n, Re - dr + 1, Re - st + 1) << '\n';
        }
        else
        {
            cin >> wh;
            if(direction == 0)
            {
                int Tl = (Re - Le + 1) / 2;
                if(wh <= Tl)
                {
                    int Nn = wh + Le;
                    for(int j = wh + Le - 1; j >= Le; --j)
                    {
                        Update(1, 1, n, j, -v[j]);
                        Update(1, 1, n, Nn, v[j]);
                        v[Nn] += v[j];
                        v[j] = 0;
                        ++Nn;
                    }
                    Le = wh + Le;
                }
                else
                {
                    int Nn = wh + Le - 1;
                    for(int j = wh + Le; j <= Re; ++j)
                    {
                        Update(1, 1, n, j, -v[j]);
                        Update(1, 1, n, Nn, v[j]);
                        v[Nn] += v[j];
                        v[j] = 0;
                        --Nn;
                    }
                    Re = wh + Le - 1;
                    direction = 1;
                }
            }
            else
            {
                int Tl = (Re - Le + 1) / 2;
                if(wh <= Tl)
                {
                    wh = Re - wh + 1;
                    int Nn = wh - 1;
                    for(int j = wh; j <= Re; ++j)
                    {
                        Update(1, 1, n, j, -v[j]);
                        Update(1, 1, n, Nn, v[j]);
                        v[Nn] += v[j];
                        v[j] = 0;
                        --Nn;
                    }
                    Re = wh - 1;
                }
                else
                {
                    wh = Re - wh + 1;
                    int Nn = wh;
                    for(int j = wh - 1; j >= Le; --j)
                    {
                        Update(1, 1, n, j, -v[j]);
                        Update(1, 1, n, Nn, v[j]);
                        v[Nn] += v[j];
                        v[j] = 0;
                        ++Nn;
                    }
                    Le = wh;
                    direction = 0;
                }
            }
        }
    }
    return 0;
}
