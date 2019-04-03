/*
        editorial at https://csacademy.com/contest/romanian-ioi-2017-selection-1/task/rooms/solution/
        it can also be found on infoarena(https://www.infoarena.ro/problema/camere)
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("camere.in");
ofstream g("camere.out");
int n, m;
char a[2002][2002];
bool viz[2002][2002];
int q, cc;
struct quu
{
    int Xa, Ya, Xb, Yb, ans;
};
quu v2[5002];
int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};
int ans[2002][2002], zona[2002][2002];
int spL[4000002], spC[4000002];
int ap[4000002];
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> (a[i] + 1);
    f >> q;
    for(int i = 1; i <= q; ++i)
        f >> v2[i].Xa >> v2[i].Ya >> v2[i].Xb >> v2[i].Yb;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(!viz[i][j])
            {
                deque<pair<int, int> >d;
                vector<pair<int, int> >p;
                viz[i][j] = 1;
                d.push_back({i, j});
                p.push_back({i, j});
                ++cc;
                spL[cc] = i;
                spC[cc] = j;
                ans[i][j]++;
                while(!d.empty())
                {
                    int L = d[0].first;
                    int C = d[0].second;
                    zona[L][C] = cc;
                    d.pop_front();
                    for(int dir = 0; dir <= 3; ++dir)
                    {
                        int nwL = L + ox[dir];
                        int nwC = C + oy[dir];
                        if(nwL == 0 || nwC == 0 || nwC == m+1 || nwL == n+1)
                            continue;
                        if(viz[nwL][nwC])
                            continue;
                        if(a[nwL][nwC] == a[i][j])
                        {
                            viz[nwL][nwC] = 1;
                            d.push_back({nwL, nwC});
                            p.push_back({nwL, nwC});
                        }
                    }
                }
            }
        }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            ans[i][j] = ans[i][j] + ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
    for(int i = 1; i <= q; ++i)
    {
        v2[i].ans = ans[v2[i].Xb][v2[i].Yb] - ans[v2[i].Xa - 1][v2[i].Yb] - ans[v2[i].Xb][v2[i].Ya - 1] + ans[v2[i].Xa - 1][v2[i].Ya - 1];
        for(int j = v2[i].Ya; j <= v2[i].Yb; ++j)
        {
            if(!(v2[i].Xa <= spL[zona[v2[i].Xa][j]] && spL[zona[v2[i].Xa][j]] <= v2[i].Xb && v2[i].Ya <= spC[zona[v2[i].Xa][j]] && spC[zona[v2[i].Xa][j]] <= v2[i].Yb))
                if(!ap[zona[v2[i].Xa][j]])
                    ++v2[i].ans, ap[zona[v2[i].Xa][j]] = 1;
            if(!(v2[i].Xa <= spL[zona[v2[i].Xb][j]] && spL[zona[v2[i].Xb][j]] <= v2[i].Xb && v2[i].Ya <= spC[zona[v2[i].Xb][j]] && spC[zona[v2[i].Xb][j]] <= v2[i].Yb))
                if(!ap[zona[v2[i].Xb][j]])
                    ++v2[i].ans, ap[zona[v2[i].Xb][j]] = 1;
        }
        for(int j = v2[i].Xa; j <= v2[i].Xb; ++j)
        {
            if(!(v2[i].Xa <= spL[zona[j][v2[i].Ya]] && spL[zona[j][v2[i].Ya]] <= v2[i].Xb && v2[i].Ya <= spC[zona[j][v2[i].Ya]] && spC[zona[j][v2[i].Ya]] <= v2[i].Yb))
                if(!ap[zona[j][v2[i].Ya]])
                    ++v2[i].ans, ap[zona[j][v2[i].Ya]] = 1;
            if(!(v2[i].Xa <= spL[zona[j][v2[i].Yb]] && spL[zona[j][v2[i].Yb]] <= v2[i].Xb && v2[i].Ya <= spC[zona[j][v2[i].Yb]] && spC[zona[j][v2[i].Yb]] <= v2[i].Yb))
                if(!ap[zona[j][v2[i].Yb]])
                    ++v2[i].ans, ap[zona[j][v2[i].Yb]] = 1;
        }
        for(int j = v2[i].Ya; j <= v2[i].Yb; ++j)
        {
            ap[zona[v2[i].Xb][j]] = 0;
            ap[zona[v2[i].Xa][j]] = 0;
        }
        for(int j = v2[i].Xa; j <= v2[i].Xb; ++j)
        {
            ap[zona[j][v2[i].Ya]] = 0;
            ap[zona[j][v2[i].Yb]] = 0;
        }
        g << v2[i].ans << '\n';
    }
    return 0;
}
