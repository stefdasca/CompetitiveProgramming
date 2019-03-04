/*
    infoarena cartite(https://www.infoarena.ro/problema/cartite)
    
    Given an n * m matrix, a mole, some foxes and some underground roads, find 
    1. the shortest path from the mole to one of the entrances of the roads, without passing through a square attacked by a fox
    2. a path which crosses all the entrances and returns to the starting point
    
    One can use BFS for the first part of the problem and any algorithm to find the euler cycle for the second part


*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("cartite.in");
ofstream g("cartite.out");
int c, n, m, a[202][202], viz[202][202];
int k, x, y, r;
int xc, yc;
int gal[202][202], cc;
int whx[502], why[502];
vector<int>v[502];
int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};
bool bad(int x, int y)
{
    if(x == 0 || y == 0)
        return 1;
    if(x == n + 1 || y == m + 1)
        return 1;
    if(viz[x][y] || a[x][y] == -1)
        return 1;
    return 0;
}
bool was[502];
bool sters[202][202];
int main()
{
    f >> c;
    f >> n >> m;
    f >> xc >> yc;
    f >> k;
    for(int i = 1; i <= k; ++i)
    {
        f >> x >> y >> r;
        for(int j = -r; j <= r; ++j)
            for(int k = -r; k <= r; ++k)
            {
                if(abs(j) + abs(k) > r)
                    continue;
                if(x + j <= 0 || x + j > n || y + k <= 0 || y + k > m)
                    continue;
                a[x + j][y + k] = -1;
            }
    }
    f >> k;
    for(int i = 1; i <= k; ++i)
    {
        int a, b, c, d;
        f >> a >> b >> c >> d;
        if(!gal[a][b])
            ++cc, gal[a][b] = cc, whx[cc] = a, why[cc] = b;
        if(!gal[c][d])
            ++cc, gal[c][d] = cc, whx[cc] = c, why[cc] = d;
        v[gal[a][b]].push_back({gal[c][d]});
        v[gal[c][d]].push_back({gal[a][b]});
    }
    deque<pair<int, int> >d;
    viz[xc][yc] = 1;
    d.push_back({xc, yc});
    while(!d.empty())
    {
        x = d[0].first;
        y = d[0].second;
        d.pop_front();
        for(int i = 0; i <= 3; ++i)
        {
            int x0 = x + ox[i];
            int y0 = y + oy[i];
            if(bad(x0, y0))
                continue;
            a[x0][y0] = a[x][y] + 1;
            d.push_back({x0, y0});
            viz[x0][y0] = 1;
        }
    }
    if(c == 1)
    {
        int xx, yy, ans = (1<<30);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(gal[i][j] && viz[i][j] && ans > a[i][j])
                        ans = a[i][j], xx = i, yy = j;
        g << xx << " " << yy << " " << ans << '\n';
        return 0;
    }
    vector<int>anss;
    int st;
    for(int i = 1; i <= cc; ++i)
        if(viz[whx[i]][why[i]])
        {
            st = i;
            break;
        }
    deque<int>d2;
    d2.push_back(st);
    while(!d2.empty())
    {
        int xx = d2.back();
        if(v[xx].empty())
        {
            anss.push_back(xx);
            d2.pop_back();
            continue;
        }
        int nod = v[xx].back();
        v[xx].pop_back();
        if(!sters[xx][nod])
        {
            sters[xx][nod] = sters[nod][xx] = 1;
            d2.push_back(nod);
        }
    }
    for(int i = 0; i < anss.size(); ++i)
        g << whx[anss[i]] << " " << why[anss[i]] << '\n';
    return 0;
}
