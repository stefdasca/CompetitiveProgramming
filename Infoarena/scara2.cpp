#include<bits/stdc++.h>
using namespace std;
ifstream f("scara2.in");
ofstream g("scara2.out");
int h, n, m, p;
double dp[(1<<15)];
bool viz[(1<<15)];
int vct[(1<<15)][15];
int arr[15], pz;
int tr[15], ss;
double ansF;
int ans[15];
int main()
{
    f >> h >> n >> m >> p;
    for(int i = 1; i < (1<<m); ++i)
    {
        pz = 0;
        int snsd = 0;
        for(int j = 0; j < m; ++j)
            if(i & (1<<j))
                arr[pz++] = j + 1, snsd += (j + 1);
        if(pz > n || snsd > h)
            continue;
        for(int j = 1; j < (1<<pz); ++j)
        {
            int drp = 0;
            int s = 0;
            int nr = 0;
            for(int q = 0; q < pz; ++q)
                if(j & (1<<q))
                {
                    ++nr;
                    s += arr[q];
                    drp += (1<<(arr[q] - 1));
                }
            if(s > m)
                continue;
            double eff;
            if(nr > 1)
                eff = p + (0.0000 + s) / (0.0000 + nr) + dp[i - drp];
            else
                eff = s + dp[i - drp];
            for(int q = 1; q <= vct[i - drp][0]; ++q)
                tr[q] = vct[i - drp][q];
            ss = vct[i - drp][0];
            for(int q = 0; q < pz; ++q)
                if(j & (1<<q))
                    tr[++ss] = arr[q];
            if(!viz[i] || eff < dp[i])
            {
                dp[i] = eff;
                for(int j = 1; j <= ss; ++j)
                    vct[i][j] = tr[j];
                vct[i][0] = ss;
                viz[i] = 1;
            }
            else
                if(eff == dp[i])
                {
                    bool ok = 0;
                    for(int j = 1; j <= ss; ++j)
                    {
                        if(tr[j] < vct[i][j])
                        {
                            ok = 1;
                            break;
                        }
                        if(tr[j] > vct[i][j])
                            break;
                    }
                    if(ok)
                    {
                        for(int j = 1; j <= ss; ++j)
                            vct[i][j] = tr[j];
                        vct[i][0] = ss;
                    }
                }
        }
        if(pz == n && snsd == h)
        {
            if(ansF == 0 || ansF > dp[i])
            {
                ansF = dp[i];
                for(int j = 1; j <= n; ++j)
                    ans[j] = vct[i][j];
            }
            else
                if(ansF == dp[i])
                {
                    bool ok = 0;
                    for(int j = 1; j <= n; ++j)
                    {
                        if(ans[j] > vct[i][j])
                        {
                            ok = 1;
                            break;
                        }
                        if(ans[j] < vct[i][j])
                            break;
                    }
                    if(ok)
                        for(int j = 1; j <= n; ++j)
                            ans[j] = vct[i][j];
                }
        }
    }
    g << fixed << setprecision(2) << ansF << '\n';
    for(int i = 1; i <= n; ++i)
        g << ans[i] << " ";
    return 0;
}
