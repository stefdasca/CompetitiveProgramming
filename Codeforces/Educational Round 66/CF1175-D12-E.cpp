#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
int tt[500002][22];
int mn[500002];
int mn2[500002];
bool viz[500002];
vector<int>v[500002];
void dfs(int nod, int dad)
{
    viz[nod] = 1;
    int q = 0;
    tt[nod][0] = dad;
    while(tt[nod][q] != -1)
    {
        tt[nod][q + 1] = tt[tt[nod][q]][q];
        ++q;
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(vecin, nod);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i <= 500000; ++i)
        mn[i] = i;
    for(int i = 0; i <= 500000; ++i)
        for(int j = 0; j <= 20; ++j)
            tt[i][j] = -1;
    for(int i = 1; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        mn[b] = min(mn[b], a);
    }
    for(int i = 500000; i >= 0; --i)
    {
        if(i != 500000)
            mn[i] = min(mn[i], mn[i+1]);
        if(mn[i] != i)
            v[i].push_back(mn[i]), v[mn[i]].push_back(i);
    }
    for(int i = 0; i <= 500000; ++i)
        if(!viz[i])
            dfs(i, -1);
    for(int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        bool rau = 0;
        while(y > x)
        {
            int init = y;
            int i = 0;
            if(tt[y][0] == -1)
            {
                rau = 1;
                break;
            }
            for(; tt[y][i] != -1; ++i)
            {
                if(tt[y][i] <= x)
                    break;
            }
            if(i == 0 && tt[y][i] <= x)
            {
                ++ans;
                break;
            }
            --i;
            ans += (1<<i);
            y = tt[y][i];
        }
        if(rau)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}

