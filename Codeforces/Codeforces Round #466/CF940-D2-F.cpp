#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;

const int maxn = 100010;

int n, q, block, tot, a[maxn], h[maxn<<1], belong[maxn], ans[maxn];
int seqp[maxn], seqv0[maxn], seqv1[maxn], num1[maxn<<1], num2[maxn];

struct cmd
{
    int l, r, t, id;
};
cmd c[maxn];
bool cmp(cmd a, cmd b)
{
    if(belong[a.l] == belong[b.l])
    {
        if(belong[a.r] == belong[b.r])
            return a.t < b.t;
        return belong[a.r] < belong[b.r];
    }
    return belong[a.l] < belong[b.l];
}
void add(int x)
{
    --num2[num1[x]];
    ++num2[++num1[x]];
}

void del(int x)
{
    --num2[num1[x]];
    ++num2[--num1[x]];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    int block = 2000;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        h[i] = a[i];
        belong[i] = (i - 1) / block + 1;
    }
    int cnt = 0, time = 0;
    for (int i = 1; i <= q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            ++cnt;
            cin >> c[cnt].l >> c[cnt].r;
            c[cnt].t = time, c[cnt].id = cnt;
        }
        else
        {
            int p, x;
            cin >> p >> x;
            ++time, h[n + time] = x;
            seqp[time] = p, seqv0[time] = a[p], seqv1[time] = x, a[p] = x;
        }
    }
    for (int i = 1; i <= n; i++)
        a[i] = h[i];
    sort(h + 1, h + n + time + 1);
    tot = unique(h + 1, h + n + time + 1) - h - 1;
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(h + 1, h + tot + 1, a[i]) - h;
        a[i] = pos;
    }
    for (int i = 1; i <= time; i++)
    {
        int pos = lower_bound(h + 1, h + tot + 1, seqv0[i]) - h;
        seqv0[i] = pos;
    }
    for (int i = 1; i <= time; i++)
    {
        int pos = lower_bound(h + 1, h + tot + 1, seqv1[i]) - h;
        seqv1[i] = pos;
    }
    sort(c + 1, c + cnt + 1, cmp);
    int L = 0, R = 0, T = 0;
    for (int i = 1; i <= cnt; i++)
    {
        while (T > c[i].t)
        {
            if (seqp[T] >= L&&seqp[T] <= R)
                del(seqv1[T]), add(seqv0[T]);
            a[seqp[T]] = seqv0[T];
            T--;
        }
        while (T < c[i].t)
        {
            T++;
            if (seqp[T] >= L&&seqp[T] <= R)
                del(seqv0[T]), add(seqv1[T]);
            a[seqp[T]] = seqv1[T];
        }
        while (L > c[i].l)
            add(a[--L]);
        while (R < c[i].r)
            add(a[++R]);
        while (L < c[i].l)
            del(a[L++]);
        while (R > c[i].r)
            del(a[R--]);
        for(int j = 1; j <= 100000; j++)
            if (!num2[j])
            {
                ans[c[i].id] = j;
                break;
            }
    }
    for (int i = 1; i <= cnt; i++)
        cout << ans[i] << '\n';
    return 0;
}
