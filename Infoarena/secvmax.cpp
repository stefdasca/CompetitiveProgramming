#include<bits/stdc++.h>
using namespace std;
ifstream f("secvmax.in");
ofstream g("secvmax.out");
int n, q;
struct qu
{
    int nr, pi;
};
qu v[100002];
qu ar[100002];
int tt[100002], nr[100002];
int len[100002];
int ans;
int sol[100002];
bool cmp(qu a, qu b)
{
    if(a.nr == b.nr)
        return a.pi < b.pi;
    return a.nr < b.nr;
}
int Find(int nod)
{
    int rang;
    for(rang = tt[nod]; rang != tt[rang]; rang = tt[rang]);
    int x = nod;
    while(x != rang)
    {
        int aa = tt[x];
        tt[x] = rang;
        x = aa;
    }
    return rang;
}
void unite(int a, int b)
{
    if(len[a] < len[b])
    {
        len[b] += len[a];
        tt[a] = b;
        len[a] = 0;
    }
    else
    {
        len[a] += len[b];
        tt[b] = a;
        len[b] = 0;
    }
    ans = max(ans, len[a] + len[b]);
}
int main()
{
    f >> n >> q;
    for(int i = 1; i <= n; ++i)
        tt[i] = i;
    for(int i = 1; i <= n; ++i)
    {
        f >> ar[i].nr;
        nr[i] = ar[i].nr;
        ar[i].pi = i;
    }
    sort(ar+1, ar+n+1, cmp);
    for(int i = 1; i <= q; ++i)
    {
        f >> v[i].nr;
        v[i].pi = i;
    }
    sort(v+1, v+q+1, cmp);
    int pos = 1;
    for(int i = 1; i <= q; ++i)
    {
        while(pos <= n && ar[pos].nr <= v[i].nr)
        {
            len[ar[pos].pi] = 1;
            ans = max(ans, 1);
            if(ar[pos].pi != 1 && nr[ar[pos].pi - 1] <= nr[ar[pos].pi])
                unite(Find(ar[pos].pi-1), Find(ar[pos].pi));
            if(ar[pos].pi != n && nr[ar[pos].pi + 1] < nr[ar[pos].pi])
                unite(Find(ar[pos].pi+1), Find(ar[pos].pi));
            ++pos;
        }
        sol[v[i].pi] = ans;
    }
    for(int i = 1; i <= q; ++i)
        g << sol[i] << '\n';
    return 0;
}
