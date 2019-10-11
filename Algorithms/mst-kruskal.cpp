#include<bits/stdc++.h>
using namespace std;
ifstream f("apm.in");
ofstream g("apm.out");
int n, m;
int sz[200002], tt[200002];
struct mch
{
    int a, b, c;
};
mch v[400002];
bool cmp(mch a, mch b)
{
    return a.c < b.c;
}
int Find(int nod)
{
    if(tt[nod] == nod)
        return nod;
    return tt[nod] = Find(tt[nod]);
}
void Union(int a, int b)
{
    if(sz[a] >= sz[b])
        sz[a] += sz[b], tt[b] = a;
    else
        sz[b] += sz[a], tt[a] = b;
}
int sum = 0, q;
pair<int, int> ans[200002];
int main()
{
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
        f >> v[i].a >> v[i].b >> v[i].c;
    for(int i = 1; i <= n; ++i)
        tt[i] = i, sz[i] = 1;
    sort(v+1, v+m+1, cmp);
    for(int i = 1; i <= m; ++i)
    {
        if(Find(v[i].a) != Find(v[i].b))
        {
            Union(Find(v[i].a), Find(v[i].b));
            sum += v[i].c;
            ans[++q] = make_pair(v[i].a, v[i].b);
        }
    }
    g << sum << '\n';
    g << n-1 << '\n';
    for(int i = 1; i <= q; ++i)
        g << ans[i].first << " " << ans[i].second << '\n';
    return 0;
}
