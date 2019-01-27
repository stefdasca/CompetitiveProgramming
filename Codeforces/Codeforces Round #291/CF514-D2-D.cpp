#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, k, v[100005][6], anss[6];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> v[i][j];
    int st = 1, dr = 0;
    deque<int>a[7];
    int ans = 0;
    while(dr <= n)
    {
        ++dr;
        for(int j = 1; j <= m; ++j)
        {
            while(!a[j].empty() && v[a[j].back()][j] < v[dr][j])
                a[j].pop_back();
            a[j].push_back(dr);
        }
        int s = 0;
        for(int j = 1; j <= m; ++j)
            s += v[a[j][0]][j];
        if(s <= k)
        {
            if(dr - st + 1 > ans)
            {
                for(int j = 1; j <= m; ++j)
                    anss[j] = v[a[j][0]][j];
            }
            ans = max(ans, dr - st + 1);
        }
        else
        {
            while(1)
            {
                for(int j = 1; j <= m; ++j)
                    if(!a[j].empty() && a[j][0] == st)
                        a[j].pop_front();
                ++st;
                if(st > dr)
                    break;
                s = 0;
                for(int j = 1; j <= m; ++j)
                    s += v[a[j][0]][j];
                if(s <= k)
                    break;
            }
            if(dr - st + 1 > ans)
            {
                for(int j = 1; j <= m; ++j)
                    anss[j] = v[a[j][0]][j];
            }
            ans = max(ans, dr - st + 1);
        }
    }
    for(int j = 1; j <= m; ++j)
        cout << anss[j] << " ";
    return 0;
}

