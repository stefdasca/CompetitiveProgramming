#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, p;
int mp[12][1000002],  mpc[12][1000002], sz[12];
int neww[1000002], neww2[1000002];
int sp[1002];
char c[1002][1002];
bool viz[1002][1002];
int ct[102];
int rem;
int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> p;
    for(int i = 1; i <= p; ++i)
        cin >> sp[i];
    for(int i = 1; i <= n; ++i)
        cin >> (c[i] + 1);
    rem = n * m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(c[i][j] >= '1' && c[i][j] <= '9')
            {
                int x = c[i][j] - '0';
                viz[i][j] = 1, ct[x]++;
                --rem;
                ++sz[x];
                mp[x][sz[x]] = i;
                mpc[x][sz[x]] = j;
            }
            if(c[i][j] == '#')
                viz[i][j] = 1, --rem;
        }
    int t = 1;
    while(rem)
    {
        int s = 0;
        for(int j = 1; j <= p; ++j)
            s += sz[j];
        if(s == 0)
            break;
        if(sz[t])
            for(int i = 1; i <= sp[t]; ++i)
            {
                int sz2 = 0;
                for(int j = 1; j <= sz[t]; ++j)
                {
                    int line = mp[t][j];
                    int column = mpc[t][j];
                    for(int z = 0; z <= 3; ++z)
                    {
                        int xx = line + ox[z];
                        int yy = column + oy[z];
                        if(xx == 0 || xx == n + 1)
                            continue;
                        if(yy == 0 || yy == m + 1)
                            continue;
                        if(viz[xx][yy])
                            continue;
                        --rem;
                        viz[xx][yy] = 1;
                        ++ct[t];
                        ++sz2;
                        neww[sz2] = xx;
                        neww2[sz2] = yy;
                    }
                }
                for(int j = 1; j <= sz2; ++j)
                    mp[t][j] = neww[j], mpc[t][j] = neww2[j];
                sz[t] = sz2;
                if(rem == 0 || sz[t] == 0)
                    break;
            }
        ++t;
        if(t == p + 1)
            t = 1;
    }
    for(int i = 1; i <= p; ++i)
        cout << ct[i] << " ";
    return 0;
}
