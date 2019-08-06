/*


*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("lcdr.in");
ofstream g("lcdr.out");
int n, m, q;
struct str
{
    int C, L1, L2, nr;
};
vector<str>v[502];
char c[502][502];
int mx[502][502], spc[502][502], mxL[502], L, C, L1, L2, dp[502][502];
bool ans[500002];
int main()
{
    f >> n >> m >> q;
    for(int i = 1; i <= n; ++i)
        f >> (c[i] + 1);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            spc[i][j] = spc[i-1][j] + (c[i][j] - '0');
    for(int i = 1; i <= q; ++i)
    {
        f >> L >> C >> L1 >> L2;
        if(L2 - L1 + 1 >= L)
            v[L].push_back({C, L1, L2, i});
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!v[i].size())
            continue;
        memset(mxL, 0, sizeof(mxL));
        for(int x = i; x <= n; ++x)
            for(int y = m; y >= 1; --y)
            {
                if(spc[x][y] - spc[x - i][y] == i)
                    dp[x][y] = dp[x][y+1] + 1;
                else
                    dp[x][y] = 0;
                if(dp[x][y] > mxL[x])
                    mxL[x] = dp[x][y];
            }
        for(int x = 1; x <= n; ++x)
            for(int y = x; y <= n; ++y)
                mx[x][y] = max(mx[x][y-1], mxL[y]);
        for(int x = 0; x < v[i].size(); ++x)
            if(mx[v[i][x].L1 + i - 1][v[i][x].L2] >= v[i][x].C)
                ans[v[i][x].nr] = 1;
    }
    for(int i = 1; i <= q; ++i)
        g << ans[i] << '\n';
    return 0;
}
