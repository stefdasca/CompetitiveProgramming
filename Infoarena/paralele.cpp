#include<bits/stdc++.h>
using namespace std;
ifstream f("paralele.in");
ofstream g("paralele.out");
int t, n, m;
int a[40002][502];
long long sp[40002], spc[40002];
int main()
{
    f >> t >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            f >> a[i][j];
    if(t == 1)
    {
        long long ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            int ln = 0;
            for(int j = 1; j <= m; ++j)
            {
                if(a[i][j] == 1)
                    ++ln;
                else
                    ln = 0;
                if(ln)
                    sp[i] += (ln - 1);
            }
        }
        for(int j = n - 1; j >= 1; --j)
            sp[j] += sp[j+1];
        for(int j = 1; j <= n; ++j)
            ans += 1LL * (sp[j] - sp[j+1]) * sp[j+1];
        g << ans << '\n';
    }
    else
    {
        long long ans = 0;
        for(int i = 1; i <= m; ++i)
        {
            int ln = 0;
            for(int j = 1; j <= n; ++j)
            {
                if(a[j][i] == 1)
                    ++ln;
                else
                    ln = 0;
                if(ln)
                    spc[i] += (ln - 1);
            }
        }
        for(int j = m - 1; j >= 1; --j)
            spc[j] += spc[j+1];
        for(int j = 1; j <= m; ++j)
            ans += 1LL * (spc[j] - spc[j+1]) * spc[j+1];
        g << ans << '\n';
    }
    return 0;
}
