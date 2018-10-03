#include <bits/stdc++.h>

using namespace std;
ifstream f("admitere.in");
ofstream g("admitere.out");
const int MaxN = 2005, inf = 1e9;
int n, m, a[MaxN], b[MaxN], t, viz[MaxN], vizfin[MaxN];
struct miau{int a, b, poz;} v[MaxN];

bool cmp(miau x, miau y) {
    return x.a < y.a;
}

bool cmp2(miau x, miau y) {
    return x.b < y.b;
}

int main()
{
    f >> t;
    f >> n >> m;
    for (int i = 1; i <= m; ++i) f >> a[i];
    for (int i = 1; i <= m; ++i) f >> b[i];
    for (int i = 1; i <= n; ++i) {
        f >> v[i].a >> v[i].b;
        v[i].poz = i;
    }
    if (t == 1)
    {
        sort(v + 1, v + n + 1, cmp);
        memset(viz, 0, sizeof viz);
        int it1 = m, it2 = n, luati = 0, ansa = 0, ansb = 0;
        while (luati < m)
        {
            if (a[it1] > v[it2].a)
                ++luati, --it1;
            else
                if (it2 >= 1)
                    ++luati, viz[v[it2].poz] = 1, --it2, ++ansa;
        }
        sort(v + 1, v + n + 1, cmp2);
        memset(vizfin, 0, sizeof vizfin);
        it1 = m, it2 = n, luati = 0;
        while (luati < m)
        {
            if (b[it1] > v[it2].b)
                ++luati, --it1;
            else
                if (it2 >= 1)
                    ++luati, vizfin[v[it2].poz] = 1, --it2, ++ansb;
        }
        if (ansa > ansb)
        {
            g << ansa << '\n';
            for (int i = 1; i <= n; ++i)
                if (viz[i])
                    g << 'R';
                else
                    g << 'X';
        }
        else
        {
            g << ansb << '\n';
            for (int i = 1; i <= n; ++i)
                if (vizfin[i])
                    g << 'U';
                else
                    g << 'X';
        }
        return 0;
    }
    sort(v + 1, v + n + 1, cmp);
    int maxi = -1;
    for (int k = 1; k <= min(n, m); ++k)
    {
        int prag = b[k], actk = 0;
        memset(viz, 0, sizeof viz);
        for (int i = 1; i <= n; ++i)
            if (v[i].b > prag && actk < k)
                ++actk, viz[v[i].poz] = 1;
        int it1 = m, it2 = n, luati = 0;
        while (luati < m)
        {
            while (it2 >= 0 && viz[v[it2].poz])
                --it2;
            if (a[it1] > v[it2].a)
                ++luati, --it1;
            else
                if (it2 >= 1)
                    ++luati, viz[v[it2].poz] = 2, --it2, ++actk;
        }
        if (actk > maxi)
        {
            maxi = actk;
            for (int i = 1; i <= n; ++i)
                vizfin[i] = viz[i];
        }
    }
    g << maxi << '\n';
    for (int i = 1; i <= n; ++i)
        if (vizfin[i] == 0)
            g << 'X';
        else
            if (vizfin[i] == 1)
                g << 'U';
            else
                g << 'R';
    return 0;
}
