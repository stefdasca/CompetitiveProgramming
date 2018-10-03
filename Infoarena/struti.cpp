#include<bits/stdc++.h>
using namespace std;
ifstream f("struti.in");
ofstream g("struti.out");
int n,m,p,best,s;
short a[1002][1002];
short mx[1002][1002], mn[1002][1002], mxx[1002][1002], mnn[1002][1002];
void solve(int L, int C)
{
    deque<int>d;
    deque<int>d2;
    for(int i = 1; i <= n; ++i)
    {
        d.clear();
        d2.clear();
        for(int j = 1; j <= m; ++j)
        {
            if(d[0] == j - C)
                d.pop_front();
            if(d2[0] == j - C)
                d2.pop_front();
            while(!d.empty() && a[i][j] > a[i][d.back()])
                d.pop_back();
            while(!d2.empty() && a[i][j] < a[i][d2.back()])
                d2.pop_back();
            d.push_back(j), d2.push_back(j);
            if(j >= C)
                mx[i][j] = a[i][d[0]], mn[i][j] = a[i][d2[0]];
        }
    }
    for(int i = C; i <= m; ++i)
    {
        d.clear();
        d2.clear();
        for(int j = 1; j <= n; ++j)
        {
            if(d[0] == j - L)
                d.pop_front();
            if(d2[0] == j - L)
                d2.pop_front();
            while(!d.empty() && mx[j][i] > mx[d.back()][i])
                d.pop_back();
            while(!d2.empty() && mn[j][i] < mn[d2.back()][i])
                d2.pop_back();
            d.push_back(j), d2.push_back(j);
            if(j >= L)
            {
                mxx[j][i] = mx[d[0]][i], mnn[j][i] = mn[d2[0]][i];
                if(mxx[j][i] - mnn[j][i] < best)
                    best = mxx[j][i] - mnn[j][i], s = 1;
                else
                    if(mxx[j][i] - mnn[j][i] == best)
                        ++s;
            }
        }
    }
}
int main()
{
    f >> n >> m >> p;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            f >> a[i][j];
    for(int i = 1; i <= p; ++i)
    {
        best = 8002;
        s = 0;
        int x, y;
        f >> x >> y;
        solve(x, y);
        if(y != x)
            solve(y, x);
        g << best << " " << s << '\n';
    }
    return 0;
}
