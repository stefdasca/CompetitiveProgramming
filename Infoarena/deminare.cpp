#include<bits/stdc++.h>
using namespace std;
ifstream f("deminare.in");
ofstream g("deminare.out");
int v, l, c, gg[502][502], n, m, frq[502], mx;
int main()
{
    f >> v;
    f >> l >> c;
    f >> m;
    for(int i = 1; i <= m; ++i)
    {
        int x, y;
        f >> x >> y;
        gg[x][y] = 1;
        ++frq[x];
        if(frq[x] > mx)
            mx = frq[x];
    }
    if(v == 1)
    {
        for(int i = 1; i <= l; ++i)
            if(frq[i] == mx)
                g << i << " ";
        g << '\n';
        return 0;
    }
    for(int i = 1; i <= l; ++i)
        for(int j = 1; j <= c; ++j)
            gg[i][j] = gg[i][j] + gg[i-1][j] + gg[i][j-1] - gg[i-1][j-1];
    int ans = (1<<30);
    for(int j = 1; j <= l; ++j)
        for(int k = 1; k <= c; ++k)
        {
            if(j * k != m)
                continue;
            for(int r = j; r <= l; ++r)
                for(int s = k; s <= c; ++s)
                    ans = min(ans, m - (gg[r][s] - gg[r - j][s] - gg[r][s - k] + gg[r - j][s - k]));
        }
    if(ans == (1<<30))
        g << -1;
    else
        g << ans;
    return 0;
}
