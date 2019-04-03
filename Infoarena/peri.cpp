#include<bits/stdc++.h>
using namespace std;
ifstream f("peri.in");
ofstream g("peri.out");
int n, m;
int a[300][300], spc[300][300];
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            f >> a[i][j];
            if(a[i][j] == 0)
                a[i][j] = -1;
        }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            spc[i][j] = spc[i-1][j] + a[i][j];
    long long mx = -100000;
    long long ct = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = i+1; j <= n; ++j)
        {
            long long mn, nr;
            for(int q = 2; q <= m; ++q)
            {
                if(q == 2)
                {
                    mn = spc[j][1] - spc[i-1][1];
                    nr = 1;
                }
                else
                {
                    if(mn + a[i][q-1] + a[j][q-1] < spc[j][q-1] - spc[i-1][q-1])
                        mn = spc[j][q-1] - spc[i-1][q-1], nr = 1;
                    else
                        if(mn + a[i][q-1] + a[j][q-1] == spc[j][q-1] - spc[i-1][q-1])
                            mn = mn + a[i][q-1] + a[j][q-1], ++nr;
                        else
                            mn = mn + a[i][q-1] + a[j][q-1];
                }
                int dif = mn + (spc[j][q] - spc[i-1][q]);
                if(dif > mx)
                    mx = dif, ct = nr;
                else
                    if(dif == mx)
                        ct += nr;
            }
        }
    g << mx << " " << ct << '\n';
    return 0;
}
