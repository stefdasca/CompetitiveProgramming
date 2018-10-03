#include<bits/stdc++.h>
using namespace std;
ifstream f("reborn.in");
ofstream g("reborn.out");
int n,m,q,v[19][200005],capd[200005];
int cautbin(int a, int b)
{
    int i, step;
    if(a==b)
        return 0;
    for (step = 1; step < n; step <<= 1);
        step >>= 1;
    int qq = log2(step);
    for (i = 0; step; step >>= 1, --qq)
        if (v[qq][a] < b)
            i += step, a = v[qq][a];
    i += 1;
    if (v[0][a] < b)
        return -1;
    if (i == 0)
        return 1;
    return i;
}
int main()
{
    f >> n >> m >> q;
    int i, x, y;
    for (i = 1; i <= n; ++i)
        capd[i] = i;
    for (i = 1; i <= m; ++i)
    {
        f >> x >> y;
        capd[x] = max (capd[x], y);
    }
    for (int i = 1; i <= n; ++i)
        v[0][i] = max(v[0][i - 1],capd[i]);
    for (x = 1; 1 << x <= n; ++x)
        for (i = 1; i <= n; ++i)
            v[x][i] = v[x - 1][v[x - 1][i]];
    for (i = 1; i <= q; ++i)
    {
        f >> x >> y;
        if (x > y)
            swap(x, y);
        g << cautbin(x, y) << '\n';
    }
    return 0;
}
