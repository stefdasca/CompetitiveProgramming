#include<bits/stdc++.h>
using namespace std;
ifstream f("mexc.in");
ofstream g("mexc.out");
int n, m, d, poz;
struct valori
{
    int nr;
    int L, C;
};
valori v[802 * 802];
bool cmp(valori a, valori b)
{
    return a.nr < b.nr;
}
int pz[802][802];
int mat[802][802], tt[802 * 802], rg[802 * 802], rgmic[802 * 802];
int aans[802][802];
int Find(int x)
{
    if(tt[x] == x)
        return x;
    return tt[x] = Find(tt[x]);
}
void Union(int a, int b)
{
    if(rg[a] + rgmic[a] > rg[b] + rgmic[b])
    {
        rg[a] += rg[b];
        rgmic[a] += rgmic[b];
        tt[b] = a;
    }
    else
    {
        rg[b] += rg[a];
        rgmic[b] += rgmic[a];
        tt[a] = b;
    }
}
int main()
{
    f >> n >> m >> d;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            f >> mat[i][j];
            v[++poz] = {mat[i][j], i, j};
            pz[i][j] = poz;
            tt[poz] = poz;
            rgmic[poz] = 1;
        }
    sort(v+1, v+poz+1, cmp);
    int p2 = poz;
    for(int i = poz; i >= 1; --i)
    {
        if(i == poz || v[i].nr < v[i+1].nr)
        {
            int jj = i;
            while(jj && v[jj].nr == v[i].nr)
            {
                int ans = Find(pz[v[jj].L][v[jj].C]);
                rg[ans]++;
                rgmic[ans]--;
                --jj;
            }
        }
        while(p2 && v[p2].nr >= v[i].nr - d)
        {
            for(int j = -1; j <= 1; ++j)
                for(int k = -1; k <= 1; ++k)
                {
                    if(k == 0 && j == 0)
                        continue;
                    if(k != 0 && j != 0)
                        continue;
                    if(v[p2].L + j >= 1 && v[p2].L + j <= n && v[p2].C + k >= 1 && v[p2].C + k <= m)
                    {
                        int dif = mat[v[p2].L + j][v[p2].C + k] - mat[v[p2].L][v[p2].C];
                        if(dif >= 0)
                        {
                            int ans = Find(pz[v[p2].L][v[p2].C]);
                            int ans2 = Find(pz[v[p2].L + j][v[p2].C + k]);
                            if(ans != ans2)
                                Union(ans, ans2);
                        }
                    }
                }
            --p2;
        }
        if(i == 1 || v[i].nr > v[i-1].nr)
        {
            int jj = i;
            while(jj <= poz && v[jj].nr == v[i].nr)
            {
                int ans = Find(pz[v[jj].L][v[jj].C]);
                aans[v[jj].L][v[jj].C] = rg[ans];
                ++jj;
            }
        }
    }
    for(int i = 1; i <= n; g << '\n', ++i)
        for(int j = 1; j <= m; ++j)
            g << aans[i][j] << " ";
    return 0;
}
