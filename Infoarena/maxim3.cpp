#include<bits/stdc++.h>
using namespace std;
ifstream f("maxim3.in");
ofstream g("maxim3.out");
int c;
int n, m, v[500002];
int frq[12];
int nrmax[12];
int main()
{
    f >> c;
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    for(int i = 1; i <= m; ++i)
        ++frq[v[i]];
    if(c == 1)
    {
        for(int i = 9; i >= 0; --i)
            for(int j = 1; j <= frq[i]; ++j)
                g << i;
        return 0;
    }
    --frq[v[m]];
    int ans = 0;
    for(int i = m; i <= n; ++i)
    {
        ++frq[v[i]];
        if(i > m)
            --frq[v[i-m]];
        int eq = 0;
        for(int j = 9; j >= 0; --j)
            if(frq[j] > nrmax[j])
            {
                eq = 1;
                break;
            }
            else
                if(frq[j] < nrmax[j])
                {
                    eq = -1;
                    break;
                }
        if(eq != -1)
        {
            ans = i - m + 1;
            for(int j = 9; j >= 0; --j)
                nrmax[j] = frq[j];
        }
    }
    g << ans;
    return 0;
}
