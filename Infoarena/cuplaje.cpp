#include<bits/stdc++.h>
using namespace std;
ifstream f("cuplaje.in");
ofstream g("cuplaje.out");
int n, m;
set<int>s;
int v1[200002];
int v2[200002];
int ans;
struct q
{
    int mx, nr;
};
q v[200002];
bool cmp(q a, q b)
{
    return a.mx > b.mx;
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> v1[i];
    for(int i = 1; i <= m; ++i)
        f >> v2[i];
    for(int i = 1; i <= n; ++i)
        v[i] = {v1[i], i};
    sort(v+1, v+n+1, cmp);
    int pz = 1;
    for(int i = m; i >= 1; --i)
    {
        while(v[pz].mx >= i && pz <= n)
            s.insert(v[pz].nr), ++pz;
        if(!s.empty())
        {
            set<int> ::iterator it;
            it = s.lower_bound(v2[i]);
            if(*it > v2[i] || it == s.end())
            {
                if(it == s.begin())
                    continue;
                else
                    --it;
            }
            ++ans, s.erase(*it);
        }
    }
    int ans2 = 0;
    for(int i = 1; i <= m; ++i)
        v[i] = {v2[i], i};
    sort(v+1, v+m+1, cmp);
    pz = 1;
    s.clear();
    for(int i = n; i >= 1; --i)
    {
        while(v[pz].mx >= i && pz <= m)
            s.insert(v[pz].nr), ++pz;
        if(!s.empty())
        {
            set<int> ::iterator it;
            it = s.lower_bound(v1[i]);
            if(*it > v1[i] || it == s.end())
            {
                if(it == s.begin())
                    continue;
                else
                    --it;
            }
            ++ans2, s.erase(*it);
        }
    }
    g << max(ans, ans2) << '\n';
    return 0;
}
