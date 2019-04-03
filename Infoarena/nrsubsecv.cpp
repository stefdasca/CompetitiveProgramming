#include<bits/stdc++.h>
using namespace std;
ifstream f("nrsubsecv.in");
ofstream g("nrsubsecv.out");
int n, m, v[1000002], st[1000002], dr[1000002];
long long ans, cc[1000002];
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    deque<int>d;
    for(int i = 1; i <= n; ++i)
    {
        while(!d.empty() && v[d.back()] >= v[i])
            d.pop_back();
        if(!d.empty())
            st[i] = d.back();
        d.push_back(i);
    }
    d.clear();
    for(int i = n; i >= 1; --i)
    {
        while(!d.empty() && v[d.back()] > v[i])
            d.pop_back();
        if(!d.empty())
            dr[i] = d.back();
        else
            dr[i] = n+1;
        d.push_back(i);
        cc[v[i]] += 1LL * (dr[i] - i) * (i - st[i]);
    }
    for(int i = 1000000; i >= 0; --i)
        cc[i] += cc[i+1];
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        f >> a >> b;
        long long ans = cc[a] - cc[b+1];
        g << ans << '\n';
    }
    return 0;
}
