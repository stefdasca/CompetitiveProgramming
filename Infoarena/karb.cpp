#include<bits/stdc++.h>
using namespace std;
ifstream f("karb.in");
ofstream g("karb.out");
int n, m, k;
int qq;
struct ans
{
    int a, b, c;
};
ans vv[100002], v[200002];
int tt[100002], rg[100002];
int Find(int a)
{
    if(tt[a] == a)
        return a;
    return tt[a] = Find(tt[a]);
}
void Union(int a, int b)
{
    if(rg[a] > rg[b])
        tt[b] = a, rg[a] += rg[b];
    else
        tt[a] = b, rg[b] += rg[a];
}
int main()
{
    f >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        tt[i] = i, rg[i] = 1;
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        f >> a >> b >> c;
        if(c == 0)
            Union(Find(a), Find(b));
        v[i] = {a, b, c};
    }
    for(int i = 1; i <= m; ++i)
        if(qq < k && v[i].c == 1)
        {
            int a = Find(v[i].a);
            int b = Find(v[i].b);
            if(a != b)
                Union(a, b), vv[++qq] = {v[i].a, v[i].b};
        }
    for(int i = 1; i <= n; ++i)
        tt[i] = i, rg[i] = 1;
    for(int i = 1; i <= qq; ++i)
        Union(Find(vv[i].a), Find(vv[i].b));
    for(int i = 1; i <= m; ++i)
        if(qq < k && v[i].c == 1)
        {
            int a = Find(v[i].a);
            int b = Find(v[i].b);
            if(a != b)
                Union(a, b), vv[++qq] = {v[i].a, v[i].b};
        }
    for(int i = 1; i <= m; ++i)
        if(v[i].c == 0)
        {
            int a = Find(v[i].a);
            int b = Find(v[i].b);
            if(a != b)
                Union(a, b), vv[++qq] = {v[i].a, v[i].b};
        }
    for(int i = 1; i <= qq; ++i)
        g << vv[i].a << " " << vv[i].b << '\n';
    return 0;
}
