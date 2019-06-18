#include<bits/stdc++.h>
using namespace std;
int n, m;
char a[1002][1002];
int eq[1002][1002], mn[1002][1002], eqc[1002][1002], mn2[1002][1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);
    for(int i = 1; i <= n; ++i)
    {
        eq[i][1] = 1;
        for(int j = 2; j <= m; ++j)
            if(a[i][j] == a[i][j-1])
                eq[i][j] = eq[i][j-1] + 1;
            else
                eq[i][j] = 1;
    }
    for(int j = 1; j <= m; ++j)
    {
        eqc[1][j] = 1;
        for(int i = 2; i <= n; ++i)
            if(a[i][j] == a[i-1][j])
                eqc[i][j] = eqc[i-1][j] + 1;
            else
                eqc[i][j] = 1;
    }
    for(int j = 1; j <= m; ++j)
    {
        mn[1][j] = eq[1][j];
        int vv = eq[1][j];
        for(int i = 2; i <= n; ++i)
        {
            if(a[i][j] == a[i-1][j])
                vv = min(vv, eq[i][j]);
            else
                vv = eq[i][j];
            mn[i][j] = vv;
        }
    }
    for(int j = 1; j <= m; ++j)
    {
        mn2[n][j] = eq[n][j];
        int vv = eq[n][j];
        for(int i = n-1; i >= 1; --i)
        {
            if(a[i][j] == a[i+1][j])
                vv = min(vv, eq[i][j]);
            else
                vv = eq[i][j];
            mn2[i][j] = vv;
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            int aa = 0, bb = 0, cc = 0;
            aa = i;
            bb = aa - eqc[aa][j];
            cc = bb - eqc[bb][j];
            if(aa == 0 || bb == 0 || cc == 0)
                continue;
            if(eqc[aa][j] != eqc[bb][j])
                continue;
            if(eqc[cc][j] < eqc[aa][j])
                continue;
            int miin = min(mn[aa][j], min(mn[bb][j], mn2[cc - eqc[bb][j] + 1][j]));
            ans += miin;
        }
    }
    cout << ans << '\n';
    return 0;
}
