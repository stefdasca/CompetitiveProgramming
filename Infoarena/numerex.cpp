/*
                            Infoarena numerex - https://www.infoarena.ro/problema/numerex
        (Given an array of size n, which at the beginning has all elements equal with 0, operate some updates and answer to the query
described by the statement)

        Despite the fact that this problem is a classical application of lazy propagation method in segment tree, I have used sqrt 
decomposition instead, approached based by a trick I have recently learnt. I grouped numbers in buckets of sqrt(N) each and queries in
buckets of sqrt(M) each, so that I had update in O(sqrtN) and query in O(sqrtN). Once at sqrt(M) queries, I rebuild all the array based on
the previous sqrt(M) queries.

*/

#include<bits/stdc++.h>
using namespace std;
ifstream f("numerex.in");
ofstream g("numerex.out");
long long n, m, bucketSize, cnt;
long long v[100002];
long long bucketsum[502];
long long bkt[100002];
long long st[502], sf[502];
long long xtr[502];
struct ranges
{
    long long nr, st, sf;
};
ranges z[502][502];
long long countt[502];
void add(long long stt, long long drr, long long stval)
{
    drr = drr + stt - 1;
    drr = min(n, drr);
    for(long long i = stt; i <= drr; )
    {
        if(i + bucketSize - 1 <= drr)
        {
            if(bkt[i] == bkt[i + bucketSize - 1])
            {
                ++countt[bkt[i]];
                long long first = i - stt + 1;
                long long last = i + bucketSize - stt;
                long long gauss = 1LL * (last + 1) * last / 2 - 1LL * (first - 1) * first / 2;
                xtr[bkt[i]] += gauss * stval;
                z[bkt[i]][countt[bkt[i]]] = {stval, first, last};
                i += bucketSize;
            }
            else
            {
                long long j = i;
                for(j = i; (bkt[i] == bkt[j]); ++j)
                    v[j] += 1LL * (j - stt + 1) * stval, bucketsum[bkt[i]] += 1LL * (j - stt + 1) * stval;
                i = j;
            }
        }
        else
        {
            for(long long j = i; j <= drr; ++j)
                v[j] += 1LL * (j - stt + 1) * stval, bucketsum[bkt[j]] += 1LL * (j - stt + 1) * stval;
            i = drr + 1;
        }
    }
}
long long compute(long long stt, long long drr)
{
    long long ans = 0;
    for(long long i = stt; i <= drr; )
    {
      //  g << stt << " " << drr << " " << i << " " << ans << '\n';
        if(i + bucketSize - 1 <= drr)
        {
            if(bkt[i] == bkt[i + bucketSize - 1])
            {
                ans += xtr[bkt[i]];
                ans += bucketsum[bkt[i]];
                i += bucketSize;
            }
            else
            {
                long long j = i;
                for(j = i; (bkt[i] == bkt[j]); ++j)
                    ans += v[j];
                for(long long q = 1; q <= countt[bkt[i]]; ++q)
                {
                    long long endd = z[bkt[i]][q].sf;
                    long long beginn = (z[bkt[i]][q].st + (i - 1 - st[bkt[i]]));
                    long long gs = 1LL * endd * (endd + 1) / 2 - 1LL * beginn * (beginn + 1) / 2;
                    ans += gs * z[bkt[i]][q].nr;
                }
                i = j;
            }
        }
        else
        {
            long long j;
            for(j = i; j <= drr; ++j)
                ans += v[j];
            long long sffbkti = min(drr, sf[bkt[i]]);
            for(long long q = 1; q <= countt[bkt[i]]; ++q)
            {
                long long endd = z[bkt[i]][q].st + (sffbkti - st[bkt[i]]);
                long long beginn = (z[bkt[i]][q].st + (i - st[bkt[i]])) - 1;
                long long gs = 1LL * endd * (endd + 1) / 2 - 1LL * beginn * (beginn + 1) / 2;
                ans += gs * z[bkt[i]][q].nr;
            }
            if(sffbkti < drr)
            {
                for(long long q = 1; q <= countt[bkt[j]]; ++q)
                {
                    long long endd = z[bkt[j]][q].st + (drr - st[bkt[j]]);
                    long long beginn = z[bkt[j]][q].st - 1;
                    long long gs = 1LL * endd * (endd + 1) / 2 - 1LL * beginn * (beginn + 1) / 2;
                    ans += gs * z[bkt[j]][q].nr;
                }
            }
            i = drr + 1;
        }
    }
    return ans;
}
void calc()
{
    for(long long i = 1; i <= n; i += bucketSize)
    {
        long long ratie = 0;
        long long suma = 0;
        for(long long j = 1; j <= countt[bkt[i]]; ++j)
            ratie +=  z[bkt[i]][j].nr, suma += 1LL * z[bkt[i]][j].nr * z[bkt[i]][j].st;
        xtr[bkt[i]] = 0;
        countt[bkt[i]] = 0;
        for(long long j = i; j <= sf[bkt[i]]; ++j)
            bucketsum[bkt[i]] += suma, v[j] += suma, suma += ratie;
    }
}
int main()
{
    f >> n >> m;
    bucketSize = sqrt(n);
    cnt = 0;
    for(long long i = 1; i <= n; i += bucketSize)
    {
        ++cnt;
        st[cnt] = i;
        sf[cnt] = min(i + bucketSize - 1, n);
        for(long long j = i; j <= sf[cnt]; ++j)
            bkt[j] = cnt, bucketsum[cnt] += v[i];
    }
    long long bucket2 = sqrt(m);
    for(long long i = 1; i <= m; ++i)
    {
        long long tip, x, l, k;
        f >> tip;
        if(tip == 0)
        {
            f >> x >> l >> k;
            add(x, l, k);
        }
        else
        {
            f >> x >> l;
            g << compute(x, l) << '\n';
        }
        if(i % bucket2 == 0)
            calc();
    }
    return 0;
}
