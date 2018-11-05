#include<bits/stdc++.h>
using namespace std;
ifstream f("rfinv.in");
ofstream g("rfinv.out");
int t, n, m, is[102][102], rf[102][102], cost[102][102];
int main()
{
    f >> t;
    for(; t; --t)
    {
        f >> n >> m;
        memset(is, 0, sizeof(is));
        for(int i = 1; i <= m; ++i)
        {
            int a, b;
            f >> a >> b;
            is[a][b] = 1;
            is[b][a] = 1;
        }
        bool rau = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
            {
                f >> cost[i][j];
                if(is[i][j] || i == j)
                    rf[i][j] = cost[i][j];
                else
                    rf[i][j] = 99999999;
            }
        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    if(rf[i][k] + rf[k][j] < rf[i][j])
                        rf[i][j] = rf[i][k] + rf[k][j];
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(rf[i][j] != cost[i][j])
                    rau = 1;
        if(rau)
            g << "NU\n";
        else
            g << "DA\n";
    }
    return 0;
}
