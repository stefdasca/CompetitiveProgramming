#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, d;
long long v[100002], srt[100002], ps[100002];
bool cmp(long long a, long long b)
{
    return v[a] < v[b];
}
long long aint[400002], cn[400002];
long long dp[100002];
long long wh[100002];
vector<long long>ans;
long long mm, ww;
void query(long long nod, long long st, long long dr, long long L, long long R)
{
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        if(aint[nod] > mm)
            mm = aint[nod], ww = cn[nod];
        return;
    }
    long long mid = (st + dr) / 2;
    query(nod << 1, st, mid, L, R);
    query(nod << 1|1, mid + 1, dr, L, R);
}
void update(long long nod, long long st, long long dr, long long p, long long q)
{
    if(st == dr)
    {
        aint[nod] = dp[q];
        cn[nod] = q;
        return;
    }
    long long mid = (st + dr) / 2;
    if(p <= mid)
        update(nod << 1, st, mid, p, q);
    else
        update(nod << 1|1, mid + 1, dr, p, q);
    if(aint[nod << 1] > aint[nod << 1|1])
        aint[nod] = aint[nod << 1], cn[nod] = cn[nod << 1];
    else
        aint[nod] = aint[nod << 1|1], cn[nod] = cn[nod << 1|1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> d;
    for(long long i = 1; i <= n; ++i)
        cin >> v[i], srt[i] = i;
    sort(srt + 1, srt + n + 1, cmp);
    for(long long i = 1; i <= n; ++i)
        ps[srt[i]] = i;
    for(long long i = 1; i <= n; ++i)
    {
        long long st = 1;
        long long dr = n;
        long long ansL = 0;
        while(st <= dr)
        {
            long long mid = (st + dr) / 2;
            if(v[srt[mid]] <= v[i] - d)
                ansL = mid, st = mid + 1;
            else
                dr = mid - 1;
        }
        mm = 0, ww = 0;
        if(ansL != 0)
            query(1, 1, n, 1, ansL);
        if(mm > dp[i])
            dp[i] = mm, wh[i] = ww;
        st = 1;
        dr = n;
        long long ansR = 0;
        while(st <= dr)
        {
            long long mid = (st + dr) / 2;
            if(v[srt[mid]] >= v[i] + d)
                ansR = mid, dr = mid - 1;
            else
                st = mid + 1;
        }
        mm = 0, ww = 0;
        if(ansR != 0)
            query(1, 1, n, ansR, n);
        if(mm > dp[i])
            dp[i] = mm, wh[i] = ww;
        ++dp[i];
        update(1, 1, n, ps[i], i);
    }
    long long mx = 0;
    for(long long i = 1; i <= n; ++i)
        if(dp[i] > dp[mx])
            mx = i;
    while(mx)
        ans.push_back(mx), mx = wh[mx];
    cout << ans.size() << '\n';
    for(long long i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << " ";
    return 0;
}

