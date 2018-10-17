#include<bits/stdc++.h>
using namespace std;
ifstream f("copii2.in");
ofstream g("copii2.out");
int n, k;
vector<pair<int, int> >a[100002];
vector<pair<int, int> >b[100002];
int main()
{
    f >> n >> k;
    if(n == k)
    {
        g << 1 << '\n';
        g << n << '\n';
        for(int i = 1; i <= n; ++i)
            g << 1 << " " << i << '\n';
        return 0;
    }
    int sol = 0;
    int aa = n;
    while(aa)
    {
        ++sol;
        if(aa <= k)
            break;
        int md = 0;
        if(aa%k)
            ++md;
        aa = aa/k + md;
    }
    g << sol << '\n';
    for(int i = 1; i <= sol; ++i)
    {
        int mx = 0;
        if(i == 1)
        {
            int gr = 1;
            for(int j = 1; j <= n; ++j)
            {
                a[gr].push_back({j, gr});
                mx = max(mx, gr);
                ++gr;
                if(gr > k)
                    gr = 1;
            }g << mx << '\n';
            for(int j = 1; j <= mx; ++j)
            {
                g << a[j].size() << " ";
                for(int jj = 0; jj < a[j].size(); ++jj)
                    g << a[j][jj].first << " ";
                g << '\n';
            }
        }
        else
        {
            for(int j = 1; j <= n; ++j)
            {
                int gr = 1;
                for(int aa = 0; aa < a[j].size(); ++aa)
                {
                    if(aa == 0 || a[j][aa].second != a[j][aa - 1].second)
                        gr = 1;
                    b[gr].push_back({a[j][aa].first, a[j][aa].second + 200000});
                    mx = max(mx, gr);
                    ++gr;
                    if(gr > k)
                        gr = 1;
                }
            }
            g << mx << '\n';
            for(int j = 1; j <= mx; ++j)
                a[j] = b[j], b[j].clear();
            for(int j = 1; j <= mx; ++j)
            {
                g << a[j].size() << " ";
                for(int jj = 0; jj < a[j].size(); ++jj)
                    g << a[j][jj].first << " ";
                g << '\n';
            }
        }
    }
    return 0;
}
