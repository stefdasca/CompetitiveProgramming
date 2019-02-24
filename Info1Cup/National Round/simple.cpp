/*

    simple : given a array of n elements and q queries(type 0, add a to every element in range [x, y], 
 type 1, find the max odd number and the min even number from range [x, y]), answer to the queries of type 1)
    
    Classical lazy propagation task

*/
#include<bits/stdc++.h>
using namespace std;
int n, q;
long long v[200002], aint[5][800002], lazy[800002];
long long Minpar, Maximpar;
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[0][nod] = aint[2][nod] = (1LL<<60);
        aint[1][nod] = aint[3][nod] = -(1LL<<60);
        if(v[st] % 2 == 0)
            aint[0][nod] = aint[1][nod] = v[st];
        else
            aint[2][nod] = aint[3][nod] = v[st];
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid + 1, dr);

    long long minpar = (1LL<<60);
    if(aint[0][2 * nod] != (1LL<<60))
        minpar = min(minpar, aint[0][nod * 2]);
    if(aint[0][2 * nod + 1] != (1LL<<60))
        minpar = min(minpar, aint[0][nod * 2 + 1]);
    aint[0][nod] = minpar;

    long long maxpar = -(1LL<<60);
    if(aint[1][2 * nod] != -(1LL<<60))
        maxpar = max(maxpar, aint[1][nod * 2]);
    if(aint[1][2 * nod + 1] != -(1LL<<60))
        maxpar = max(maxpar, aint[1][nod * 2 + 1]);
    aint[1][nod] = maxpar;

    minpar = (1LL<<60);
    if(aint[2][2 * nod] != (1LL<<60))
        minpar = min(minpar, aint[2][nod * 2]);
    if(aint[2][2 * nod + 1] != (1LL<<60))
        minpar = min(minpar, aint[2][nod * 2 + 1]);
    aint[2][nod] = minpar;

    maxpar = -(1LL<<60);
    if(aint[3][2 * nod] != -(1LL<<60))
        maxpar = max(maxpar, aint[3][nod * 2]);
    if(aint[3][2 * nod + 1] != -(1LL<<60))
        maxpar = max(maxpar, aint[3][nod * 2 + 1]);
    aint[3][nod] = maxpar;
}
void update(int nod, int st, int dr, int l, int r, int val)
{
    if(l <= st && dr <= r)
        lazy[nod] += val;
    if(lazy[nod])
    {
        if(aint[0][nod] != (1LL<<60))
            aint[0][nod] += lazy[nod], aint[1][nod] += lazy[nod];
        if(aint[2][nod] != (1LL<<60))
            aint[2][nod] += lazy[nod], aint[3][nod] += lazy[nod];
        if(lazy[nod] % 2 == 1)
        {
            swap(aint[0][nod], aint[2][nod]);
            swap(aint[1][nod], aint[3][nod]);
        }
        if(st != dr)
        {
            lazy[2 * nod] += lazy[nod];
            lazy[2 * nod + 1] += lazy[nod];
        }
        lazy[nod] = 0;
    }
    if(dr < l || st > r)
        return;
    if(l <= st && dr <= r)
        return;
    int mid = (st + dr) / 2;
    update(nod * 2, st, mid, l, r, val);
    update(nod * 2 + 1, mid + 1, dr, l, r, val);
    long long minpar = (1LL<<60);
    if(aint[0][2 * nod] != (1LL<<60))
        minpar = min(minpar, aint[0][nod * 2]);
    if(aint[0][2 * nod + 1] != (1LL<<60))
        minpar = min(minpar, aint[0][nod * 2 + 1]);
    aint[0][nod] = minpar;

    long long maxpar = -(1LL<<60);
    if(aint[1][2 * nod] != -(1LL<<60))
        maxpar = max(maxpar, aint[1][nod * 2]);
    if(aint[1][2 * nod + 1] != -(1LL<<60))
        maxpar = max(maxpar, aint[1][nod * 2 + 1]);
    aint[1][nod] = maxpar;

    minpar = (1LL<<60);
    if(aint[2][2 * nod] != (1LL<<60))
        minpar = min(minpar, aint[2][nod * 2]);
    if(aint[2][2 * nod + 1] != (1LL<<60))
        minpar = min(minpar, aint[2][nod * 2 + 1]);
    aint[2][nod] = minpar;

    maxpar = -(1LL<<60);
    if(aint[3][2 * nod] != -(1LL<<60))
        maxpar = max(maxpar, aint[3][nod * 2]);
    if(aint[3][2 * nod + 1] != -(1LL<<60))
        maxpar = max(maxpar, aint[3][nod * 2 + 1]);
    aint[3][nod] = maxpar;
}
void query(int nod, int st, int dr, int l, int r)
{
    if(lazy[nod])
    {
        if(aint[0][nod] != (1LL<<60))
            aint[0][nod] += lazy[nod], aint[1][nod] += lazy[nod];
        if(aint[2][nod] != (1LL<<60))
            aint[2][nod] += lazy[nod], aint[3][nod] += lazy[nod];
        if(lazy[nod] % 2 == 1)
        {
            swap(aint[0][nod], aint[2][nod]);
            swap(aint[1][nod], aint[3][nod]);
        }
        if(st != dr)
        {
            lazy[2 * nod] += lazy[nod];
            lazy[2 * nod + 1] += lazy[nod];
        }
        lazy[nod] = 0;
    }
    if(dr < l || st > r)
        return;
    if(l <= st && dr <= r)
    {
        if(aint[0][nod])
            Minpar = min(Minpar, aint[0][nod] + lazy[nod]);
        if(aint[3][nod])
            Maximpar = max(Maximpar, aint[3][nod] + lazy[nod]);
        return;
    }
    int mid = (st + dr) / 2;
    query(nod * 2, st, mid, l, r);
    query(nod * 2 + 1, mid + 1, dr, l, r);

    long long minpar = (1LL<<60);
    if(aint[0][2 * nod] != (1LL<<60))
        minpar = min(minpar, aint[0][nod * 2]);
    if(aint[0][2 * nod + 1] != (1LL<<60))
        minpar = min(minpar, aint[0][nod * 2 + 1]);
    aint[0][nod] = minpar;

    long long maxpar = -(1LL<<60);
    if(aint[1][2 * nod] != -(1LL<<60))
        maxpar = max(maxpar, aint[1][nod * 2]);
    if(aint[1][2 * nod + 1] != -(1LL<<60))
        maxpar = max(maxpar, aint[1][nod * 2 + 1]);
    aint[1][nod] = maxpar;

    minpar = (1LL<<60);
    if(aint[2][2 * nod] != (1LL<<60))
        minpar = min(minpar, aint[2][nod * 2]);
    if(aint[2][2 * nod + 1] != (1LL<<60))
        minpar = min(minpar, aint[2][nod * 2 + 1]);
    aint[2][nod] = minpar;

    maxpar = -(1LL<<60);
    if(aint[3][2 * nod] != -(1LL<<60))
        maxpar = max(maxpar, aint[3][nod * 2]);
    if(aint[3][2 * nod + 1] != -(1LL<<60))
        maxpar = max(maxpar, aint[3][nod * 2 + 1]);
    aint[3][nod] = maxpar;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    build(1, 1, n);
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        int tip;
        cin >> tip;
        if(tip == 0)
        {
            int a, b, val;
            cin >> a >> b >> val;
            update(1, 1, n, a, b, val);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            Maximpar = -(1LL<<60);
            Minpar = (1LL<<60);
            query(1, 1, n, a, b);
            if(Minpar == (1LL<<60))
                cout << -1 << " ";
            else
                cout << Minpar << " ";
            if(Maximpar == -(1LL<<60))
                cout << -1 << '\n';
            else
                cout << Maximpar << '\n';
        }
    }
    return 0;
}
