#include<bits/stdc++.h>
using namespace std;
long long n, m, q;
struct times
{
    long long wh;
    long long pi;
};
times v[500002];
long long frq[500002];
long long dd;
long long aib[500002];
void add(long long nod)
{
    for(; nod <= m; nod += (nod & (-nod)))
        aib[nod]++;
}
long long compute(long long nod)
{
    long long ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans += aib[nod];
    return ans;
}
long long sa[500002];
bool cmp(long long a, long long b)
{
    return frq[a] < frq[b];
}
bool cmp2(times a, times b)
{
    return a.wh < b.wh;
}
long long ans[500002];
long long cb(long long val)
{
    long long st = 1;
    long long dr = m;
    while(st <= dr)
    {
        long long mid = (st + dr) / 2;
        long long aa = compute(mid);
        long long bb = compute(mid - 1);
        if(aa == val && bb == val - 1)
            return mid;
        if(aa >= val)
            dr = mid - 1;
        else
            st = mid + 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> q;
    for(long long i = 1; i <= n; ++i)
    {
        long long nr;
        cin >> nr;
        frq[nr]++;
    }
    for(long long i = 1; i <= m; ++i)
        sa[i] = i;
    sort(sa + 1, sa + m + 1, cmp);
    long long lp = 0;
    long long pp = 1;
    for(long long i = 1; i <= q; ++i)
    {
        cin >> v[i].wh;
        v[i].pi = i;
    }
    sort(v + 1, v + q + 1, cmp2);
    long long timm = n + 1;
    long long pozz = 1;
    while(timm <= v[q].wh)
    {
      //  cout << pp << '\n';
        long long st = pp;
        while(st <= m && frq[sa[st]] == frq[sa[pp]])
        {
            add(sa[st]);
            ++st;
        }
        long long nxtchk;
        if(st > m)
            nxtchk = (1LL<<62);
        else
            nxtchk = timm + 1LL * (st - 1) * (frq[sa[st]] - frq[sa[pp]]);
      //  cout << timm << " " << st << " " << pp << " " << nxtchk << '\n';
        pp = st;
        while(pozz <= q && v[pozz].wh < nxtchk)
        {
        //    cout << v[pozz].wh << " " << (v[pozz].wh - timm) % (st - 1) + 1 << '\n';
            ans[v[pozz].pi] = cb((v[pozz].wh - timm) % (st - 1) + 1);
            ++pozz;
        }
        timm = nxtchk;
    }
    for(long long i = 1; i <= q; ++i)
        cout << ans[i] << '\n';
    return 0;
}
