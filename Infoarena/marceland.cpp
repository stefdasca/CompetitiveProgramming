#include<bits/stdc++.h>
using namespace std;
ifstream f("marceland.in");
ofstream g("marceland.out");
int t, n, m;
char mat[102][102];
bool viz[102][102];
int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};
int nrcomp;
struct compconex
{
    bool hasMarcel;
    int Xsand, Ysand;
    bool hasSand;
    bool hasFountain;
};
compconex v[10002];
int gg(int L, int C)
{
    if(L == 0 || L == n + 1)
        return 0;
    if(C == 0 || C == m + 1)
        return 0;
    if(viz[L][C])
        return 0;
    if(mat[L][C] == '#')
        return 0;
    return 1;
}
int main()
{
    f >> t;
    for(; t; --t)
    {
        f >> n >> m;
        memset(viz, 0, sizeof(viz));
        for(int i = 1; i <= n; ++i)
            f >> (mat[i] + 1);
        for(int i = 1; i <= nrcomp; ++i)
            v[i].hasMarcel = 0, v[i].hasFountain = 0, v[i].Xsand = 0, v[i].Ysand = 0, v[i].hasSand = 0;
        nrcomp = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
            {
                if(!gg(i, j))
                    continue;
                deque<pair<int, int> >d;
                d.push_back({i, j});
                viz[i][j] = 1;
                ++nrcomp;
                while(!d.empty())
                {
                    pair<int, int> p = d[0];
                    int xx = p.first;
                    int yy = p.second;
                    d.pop_front();
                    if(mat[xx][yy] == 'M')
                        v[nrcomp].hasMarcel = 1;
                    else
                        if(mat[xx][yy] == '.')
                            v[nrcomp].hasSand = 1, v[nrcomp].Xsand = xx, v[nrcomp].Ysand = yy;
                        else
                            if(mat[xx][yy] == '@')
                                v[nrcomp].hasFountain = 1;
                    for(int R = 0; R <= 3; ++R)
                    {
                        int vecx = xx + ox[R];
                        int vecy = yy + oy[R];
                        if(!gg(vecx, vecy))
                            continue;
                        viz[vecx][vecy] = 1;
                        d.push_back({vecx, vecy});
                    }
                }
            }
        bool bad = 0;
        int nrf = 0;
        for(int i = 1; i <= nrcomp; ++i)
        {
            if(!v[i].hasMarcel)
                continue;
            if(v[i].hasFountain)
                continue;
            if(v[i].hasSand)
                mat[v[i].Xsand][v[i].Ysand] = '@', ++nrf;
            else
                bad = 1;
        }
        if(bad)
            g << -1 << '\n';
        else
        {
            g << nrf << '\n';
            for(int i = 1; i <= n; g << '\n', ++i)
                g << (mat[i] + 1);
        }
    }
    return 0;
}
