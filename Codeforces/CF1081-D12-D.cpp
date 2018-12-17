/// be happy!

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, k;
int speciale[100002];
int tt[100002];
int rg[100002];
int costuri[100002];
struct muchii
{
    int a, b, c;
};
muchii v[100002];
bool cmp(muchii a, muchii b)
{
    return a.c < b.c;
}
int Find(int a)
{
    if(tt[a] == a)
        return a;
    return tt[a] = Find(tt[a]);
}
bool sp[100002];
int stop;
void Union(int a, int b, int c)
{
    if(rg[a] > rg[b])
        tt[b] = a, rg[a] += rg[b], sp[a] += sp[b], sp[b] = 0, costuri[a] = c;
    else
        tt[a] = b, rg[b] += rg[a], sp[b] += sp[a], sp[a] = 0, costuri[b] = c;
    stop = max(stop, max(rg[a], rg[b]));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; ++i)
        cin >> speciale[i], sp[speciale[i]] = 1;
    for(int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[i] = {a, b, c};
    }
    for(int i = 1; i <= n; ++i)
        rg[i] = sp[i], tt[i] = i;
    sort(v+1, v+m+1, cmp);
    for(int i = 1; i <= m; ++i)
    {
        if(stop == k)
            break;
        if(Find(v[i].a) != Find(v[i].b))
        {
            Union(Find(v[i].a), Find(v[i].b), v[i].c);
        }
    }
    for(int i = 1; i <= k; ++i)
        cout << costuri[Find(speciale[i])] << " ";
    return 0;
}
