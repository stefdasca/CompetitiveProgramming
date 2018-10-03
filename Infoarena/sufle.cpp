#include<bits/stdc++.h>
using namespace std;
ifstream f("sufle.in");
ofstream g("sufle.out");
int n, q, rv[100002], pre[100002][22];
struct aaa
{
    int nr, qt;
};
aaa v[25], v2[25], v3[25];
int main()
{
    f >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        f >> rv[i];
        for(int j = 20; j >= 0; --j)
        {
            pre[i][j] = pre[i-1][j];
            if(rv[i] & (1<<j))
                pre[i][j]++;
        }
    }
    for(int i = 1; i <= q; ++i)
    {
        long long sol = 0;
        int L, R;
        f >> L >> R;
        int sz1 = 1, sz2 = 0, sz3 = 0;
        v[1] = {0, R-L+1};
        for(int j = 19; j >= 0; --j)
        {
            int dif = (pre[R][j] - pre[L-1][j]);
            int a = 1;
            sz2 = 0;
            sz3 = 0;
            for(; a <= sz1 && dif; ++a)
            {
                int aa = v[a].nr;
                int bb = v[a].qt;
                if(dif > bb)
                {
                    sol = sol - 1LL * bb * aa * aa;
                    sol = sol + 1LL * bb *(aa + (1<<j)) * (aa + (1<<j));
                    dif -= bb;
                    v2[++sz2] = {aa + (1<<j), bb};
                }
                else
                {
                    sol = sol - 1LL * dif * aa * aa;
                    sol = sol + 1LL * dif *(aa + (1<<j)) * (aa + (1<<j));
                    v2[++sz2] = {aa + (1<<j), dif};
                    v[a].qt -= dif;
                    if(dif == bb)
                        ++a;
                    int Rose = 1;
                    while(a <= sz1 && Rose <= sz2)
                    {
                        if(v[a].nr == v2[Rose].nr)
                        {
                            v3[++sz3] = {v[a].nr, v[a].qt + v2[Rose].qt};
                            ++a;
                            ++Rose;
                        }
                        else
                            if(v[a].nr < v2[Rose].nr)
                            {
                                v3[++sz3] = {v[a].nr, v[a].qt};
                                ++a;
                            }
                            else
                            {
                                v3[++sz3] = {v2[Rose].nr, v2[Rose].qt};
                                ++Rose;
                            }
                    }
                    while(a <= sz1)
                        v3[++sz3] = {v[a].nr, v[a].qt}, ++a;
                    while(Rose <= sz2)
                        v3[++sz3] = {v2[Rose].nr, v2[Rose].qt}, ++Rose;
                    for(int aa = 1; aa <= sz3; ++aa)
                        v[aa] = v3[aa];
                    sz1 = sz3;
                    break;
                }
            }

        }
        g << sol << '\n';
    }
    return 0;
}
