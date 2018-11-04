#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
ifstream f("zmeu.in");
ofstream g("zmeu.out");
int n, p, mat[102][102], cost[102][102];
int poz[102][102];
bool pus[102][102];
vector<int>mare;
deque<vector<int> >d;
deque<pair<int, int> >linie;
inline int minn(int a, int b)
{
    if(a < b)
        return a;
    return b;
}
int main()
{
    f >> n >> p;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            f >> mat[i][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            f >> cost[i][j];
    for(int i = 0; i <= p+1; ++i)
        mare.push_back(0);
    d.push_back(mare);
    for(int i = 0; i <= p+1; ++i)
        mare[i] = (1<<30);
    linie.push_back({1, 1});
    while(!d.empty())
    {
        int cate = linie.size();
        for(int i = 0; i < cate; ++i)
        {
            int a = linie[i].first;
            int b = linie[i].second;
            if(a + 1 <= n && !pus[a+1][b])
            {
                pus[a+1][b] = 1;
                poz[a+1][b] = linie.size();
                d.push_back(mare);
                linie.push_back({a+1, b});
            }
            if(b + 1 <= n && !pus[a][b+1])
            {
                pus[a][b+1] = 1;
                poz[a][b+1] = linie.size();
                d.push_back(mare);
                linie.push_back({a, b+1});
            }
        }
        for(int i = 0; i < cate; ++i)
        {
            int a = linie[i].first;
            int b = linie[i].second;
            if(a + 1 <= n)
            {
                int qx = poz[a+1][b];
                for(int j = 0; j <= p; ++j)
                {
                    if(j + mat[a+1][b] <= p && d[i][j] < d[qx][j + mat[a+1][b]])
                        d[qx][j + mat[a+1][b]] = d[i][j];
                    if(d[i][j] + cost[a+1][b] < d[qx][j])
                        d[qx][j] = d[i][j] + cost[a+1][b];
                }
            }
            if(b + 1 <= n)
            {
                int qx = poz[a][b+1];
                for(int j = 0; j <= p; ++j)
                {
                    if(j + mat[a][b+1] <= p && d[i][j] < d[qx][j + mat[a][b+1]])
                        d[qx][j + mat[a][b+1]] = d[i][j];
                    if(d[i][j] + cost[a][b+1] < d[qx][j])
                        d[qx][j] = d[i][j] + cost[a][b+1];
                }
            }
        }
        if(d.size() == 1)
        {
            int mini = d[0][0];
            for(int i = 1; i <= p; ++i)
                mini = minn(mini, d[0][i]);
            g << mini << '\n';
            return 0;
        }
        for(int i = 1; i <= cate; ++i)
            d.pop_front(), linie.pop_front();
    }
    return 0;
}
